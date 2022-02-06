#!/usr/bin/env python
# coding: utf-8
import rospy
from sensor_msgs.msg import Image 
from cv_bridge import CvBridge
import cv2, sys, math
import numpy as np

Unevenness = [[-1, 0, 0, 1], [1, 0, 1, -1], [-1, 0, -1, 1], [1, -1, 0, 1], [0, 0, 1, -1],
                  [1, -1, 0, -1], [-1, 1, -1, 1], [-1, -1, 1, -1], [1, -1, 1, -1], [0, 1, -1, 1],
                  [-1, 1, 0, -1], [1, -1, 1, -1], [-1, 1, -1, -1], [-1, 1, 1, -1], [0, -1, 1, 1],
                  [-1, 1, 0, 1], [-1, 1, 1, 1], [1, 1, 1, -1], [-1, 1, -1, 1], [0, -1, 1, -1],
                  [1, -1, 0, -1], [1, -1, -1, -1], [-1, 1, -1, 1], [1, -1, 1, -1], [0, 1, -1, 1],
                  [-1, 1, 0, 0], [-1, 1, 1, 0], [1, -1, 1, 0], [-1, 1, -1, 0], [0, -1, 1, 0]]
test = np.zeros((30), dtype = int)

def process_image(msg):
    try:
        bridge = CvBridge()
        orig = bridge.imgmsg_to_cv2(msg, "bgr8")
        img = cv2.cvtColor(orig, cv2.COLOR_BGR2GRAY)
        ret, img_thresh = cv2.threshold(img, 50, 255, cv2.THRESH_BINARY)
        cv2.imshow('image', img_thresh)
        cv2.waitKey(1)
        height, width = img_thresh.shape[:2]
        contours = cv2.findContours(img_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]
        output = cv2.drawContours(orig, contours, -1, (0,0,255), 1)
        cv2.imshow('image1', orig)
        cv2.waitKey(1)
        array = np.zeros((height, width), dtype = int) # 画素値を格納する配列
        array = orig[:, :]
        
        # ラスタ走査をして最初に画素値が0になるところを探す
        array_dash = np.zeros((height, width), dtype = int)
        for i in range(height):
            for j in range(width):
                if array[i, j][0] == 0:
                    if array[i, j][1] == 0:
                        if array[i, j][2] == 255:
                            array_dash[i, j] = 1
        ys, xs = np.where(array_dash == 1)[0][0], np.where(array_dash == 1)[1][0]

        # 輪郭を抽出する
        check = np.zeros((height, width), dtype = int) # 抽出したかどうかを格納
        check[ys, xs] = 1
        x = xs
        y = ys # 今走査するピクセル
        table = [[-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1], [1, 0], [1, 1], [0, 1]]
        edge = [] # 輪郭情報を保持
        count = 0
        coord = []
        while True:
            for i in range(8):
                if array_dash[y + table[i][0], x + table[i][1]] == 1:
                    if check[y + table[i][0], x + table[i][1]] == 0:
                        edge.append(i + 1)
                        check[y + table[i][0], x + table[i][1]] = 1
                        y = y + table[i][0]
                        x = x + table[i][1]
                        coord.append([y, x])
                        count += 1
                        break
                if i == 7:
                    num = 1
                    while True:
                        if x + num < width - 2:
                            test = 0
                        for j in range(8):
                            if array_dash[y + table[j][0], x + num + table[j][1]] == 1 and check[y + table[j][0], x + num + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            x = x + num
                            break
                        if y + num < height - 2:
                            test = 0
                        for j in range(8):
                            if array_dash[y + num + table[j][0], x + table[j][1]] == 1 and check[y + num + table[j][0], x + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            y = y + num
                            break
                        if x - num >= 1:
                            test = 0
                        for j in range(8):
                            if array_dash[y + table[j][0], x - num + table[j][1]] == 1 and check[y + table[j][0], x - num + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            x = x - num
                            break
                        if y - num >= 1:
                            test = 0
                        for j in range(8):
                            if array_dash[y - num + table[j][0], x + table[j][1]] == 1 and check[y - num + table[j][0], x + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            y = y - num
                            break
                        num += 1

            if count == 1000:
                check[ys, xs] = 0
            if count > 1000:
                if check[ys, xs] == 1:
                    break
        # 局所曲率符号を求める
        C_a = []
        C_a.append(edge[0] - edge[len(edge) - 1])
        for i in range(len(edge) - 1):
            C_a.append((edge[i + 1] - edge[i] + 11) % 8 - 3)
        # G-オペレーションを求める
        #M = len(edge)
        #M = 100
        M = 350
        G = []
        G_np = np.zeros(len(edge))
        for i in range(len(edge)):
            G_dash = M * C_a[i]
            for k in range(1, M):
                a = i - k
                b = i + k
                if a < 0:
                    a += M
                if b >= M:
                    b -= M
                G_dash = G_dash + ((M - k) * (C_a[a] + C_a[b]))
                # G[i] = G_dash
            G.append(G_dash)
            G_np[i] = G_dash
        G_abs = np.abs(G_np)
        num_0 = 0 # 連続する0の数
        index_100 = [] # 200以上の数の数とインデックスのタプルを格納
        index_average = []
        angle = [] # 角の座標
        angle_four = [] # ４つの角を抽出
        G_index = 0 # Gを調べるインデクス
        while True:
            G_sum = 0
            if G_index + 49 < len(G) - 1:
                for j in range(50):
                    G_sum += G_abs[G_index + j]
                G_ave = G_sum // 50
                if G_ave > 100:
                    angle.append((coord[G_index + 25][0], coord[G_index + 25][1]))
                G_index += 50
            else:
                count_num = 0
                while True:
                    G_sum += G_abs[G_index]
                    count_num += 1
                    if G_index == len(G) - 1:
                        break
                    G_index += 1
                G_ave = G_sum // count_num
                if G_ave > 100:
                    angle.append((coord[G_index - count_num + count_num // 2][0], coord[G_index - count_num + count_num // 2][1]))
                break
            
        angle_first = []
        for i in range(len(angle)):
            if angle[i][0] < height // 3 and angle[i][1] < width // 3:
                angle_first.append(angle[i])
        if len(angle_first) > 0:
            distance = math.sqrt(angle_first[0][0] ** 2 + angle_first[0][1] ** 2)
            ans_angle = angle_first[0] 
            for i in range(1, len(angle_first)):
                distance_dash = math.sqrt(angle_first[i][0] ** 2 + angle_first[i][1] ** 2)
                if distance_dash < distance:
                    distance = distance_dash
                    ans_angle = angle_first[i]
        else:
            angle.sort()
            for i in range(7):
                angle_first.append(angle[i])
            angle_first.sort(key = lambda x : x[1])
            ans_angle = angle_first[0]
        #print(ans_angle)
        angle_four.append(ans_angle) # 1つめの角
        for i in range(3):
            angle_dash = [] # 次の角となる候補を(座標の差分, j)のタプル格納
            if i % 2 == 0:
                for j in range(len(angle)):
                    if abs(angle_four[i][1] - angle[j][1]) < 35:
                        angle_dash.append((abs(angle_four[i][0] - angle[j][0]), j))
            else:
                for j in range(len(angle)):
                    if abs(angle_four[i][0] - angle[j][0]) < 35:
                        angle_dash.append((abs(angle_four[i][1] - angle[j][1]), j))
            angle_dash.sort(reverse = True)
            angle_four.append(angle[angle_dash[0][1]])
            """
            for i in range(len(angle)):
                cv2.circle(orig, (angle[i][1], angle[i][0]), 50, (0, 255, 0), 1)
            for i in range(len(angle_four)):
                cv2.circle(orig, (angle_four[i][1], angle_four[i][0]), 50, (255, 0, 0), 1)
            """
        unevenness = [[0, 0, 0], [0, 0, 0, 0]]# 直線なら0、凸なら1、凹なら-1を格納
        for i in range(4):
            six = [] # 直線を6等分した座標を格納
            diff = [] # 直線との距離
            if i < 3:
                divide_x = (angle_four[i + 1][1] - angle_four[i][1]) // 6 # x方向の6等分した分の長さ
                divide_y = (angle_four[i + 1][0] - angle_four[i][0]) // 6 # y方向の6等分した分の長さ
            else:
                divide_x = (angle_four[0][1] - angle_four[i][1]) // 6 # x方向の6等分した分の長さ
                divide_y = (angle_four[0][0] - angle_four[i][0]) // 6 # y方向の6等分した分の長さ
            for j in range(6):
                six.append([angle_four[i][0] + divide_y * (j + 1), angle_four[i][1] + divide_x * (j + 1)])
                rinkaku = [] # 輪郭のx or y座標を格納
                if i % 2 == 0:
                    # 左端から走査
                    for k in range(width):
                        if array_dash[six[j][0], k] == 1:
                            rinkaku.append((abs(six[j][1] - k), six[j][1] - k))
                            break
                    # 右端から走査
                    for k in range(width):
                        if array_dash[six[j][0], width - 1 - k] == 1:
                            rinkaku.append((abs(six[j][1] - (width - 1 - k)), (width - 1 - k) - six[j][1]))
                            break
                else:
                    # 上端から走査
                    for k in range(height):
                        if array_dash[k, six[j][1]] == 1:
                            rinkaku.append((abs(six[j][0] - k), six[j][0] - k))
                            break
                    # 下端から走査
                    for k in range(height):
                        if array_dash[height - 1 - k, six[j][1]] == 1:
                            rinkaku.append((abs(six[j][0] - (height - 1 - k)), (height - 1 - k) - six[j][0]))
                            break
                rinkaku.sort()
                if len(rinkaku) > 0:
                    diff.append(rinkaku[0])
            diff.sort(reverse = True)
            if abs(diff[0][1] - diff[1][1]) > 150:
                if abs(diff[0][1]) < 40:
                    unevenness[0][0] += 1
                    unevenness[1][i] = 0
                elif diff[1][1] > 0:
                    unevenness[0][1] += 1
                    unevenness[1][i] = 1
                else:
                    unevenness[0][2] += 1
                    unevenness[1][i] = -1
            else:
                if abs(diff[0][1]) < 40:
                    unevenness[0][0] += 1
                    unevenness[1][i] = 0
                elif diff[0][1] > 0:
                    unevenness[0][1] += 1
                    unevenness[1][i] = 1
                else:
                    unevenness[0][2] += 1
                    unevenness[1][i] = -1
        # グループ分け
        if unevenness[0][0] == 0:
            if unevenness[0][1] == 0:
                unevenness.append(1)
            elif unevenness[0][1] == 1:
                unevenness.append(2)
            elif unevenness[0][1] == 2:
                if unevenness[1][2] == -1:
                    unevenness.append(3)
                else:
                    unevenness.append(4)
            elif unevenness[0][1] == 3:
                unevenness.append(5) 
            else:
                unevenness.append(6)
        elif unevenness[0][0] == 1:
            if unevenness[0][1] == 0:
                unevenness.append(7)
            elif unevenness[0][1] == 1:
                if unevenness[1][0] == 1:
                    unevenness.append(8)
                elif unevenness[1][2] == -1:
                    unevenness.append(9)
                else:
                    unevenness.append(10)
            elif unevenness[0][1] == 2:
                if unevenness[1][3] == -1:
                    unevenness.append(11)
                elif unevenness[1][0] == 1:
                    unevenness.append(12)
                else:
                    unevenness.append(13)
            else:
                unevenness.append(14)
        else:
            if unevenness[0][1] == 0:
                unevenness.append(15)
            elif unevenness[0][1] == 1:
                if unevenness[1][2] == -1:
                    unevenness.append(16)
                else:
                    unevenness.append(17)
            else:
                unevenness.append(18)
        # 角感距離を格納
        unevenness.append([])
        unevenness[3].append(angle_four[1][0] - angle_four[0][0])
        unevenness[3].append(angle_four[2][1] - angle_four[1][1])
        unevenness[3].append(-angle_four[3][0] + angle_four[2][0])
        unevenness[3].append(-angle_four[0][1] + angle_four[3][1])
        #print(self.unevenness)
        #Unevenness.append(unevenness)
        print(unevenness)
        
    except Exception as err:
        print err

def start_node():
    rospy.init_node('img_proc')
    rospy.loginfo('img_proc node started')
    rospy.Subscriber("usb_cam/image_raw", Image, process_image)
    #rospy.spin()

######################################################################3
if __name__ == '__main__':
    """
    try:
        start_node()
    except rospy.ROSInterruptException:
        pass
    """
    deviceid = 0 # it depends on the order of USB connection. 
    capture = cv2.VideoCapture(deviceid)

    ret, frame = capture.read()
    cv2.imwrite('test.jpg', frame)
    img_original = cv2.imread('test.jpg')
    #cv2.imshow('1', img_original)
    #cv2.waitKey()

    img = cv2.cvtColor(img_original, cv2.COLOR_BGR2GRAY)
    ret, img_thresh = cv2.threshold(img, 150, 255, cv2.THRESH_BINARY)
    cv2.imshow('image', img_thresh)
    cv2.waitKey()
    height, width = img_thresh.shape[:2]
    height1, width1 = img_original.shape[:2]
    print(height, width, height1, width1)
    contours = cv2.findContours(img_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]
    output = cv2.drawContours(img_original, contours, -1, (0,0,255), 1)
    cv2.imshow('image1', img_original)
    cv2.waitKey()
    array = np.zeros((height, width), dtype = int) # 画素値を格納する配列
    array = img_original[:, :]
 
    # ラスタ走査をして最初に画素値が0になるところを探す
    array_dash = np.zeros((height, width), dtype = int)
    for i in range(height):
        for j in range(width):
            if array[i, j][0] == 0:
                if array[i, j][1] == 0:
                    if array[i, j][2] == 255:
                        array_dash[i, j] = 1
    ys = np.where(array_dash == 1)[0][0]
    xs = np.where(array_dash == 1)[1][0]

    # 輪郭を抽出する
    check = np.zeros((height, width), dtype = int) # 抽出したかどうかを格納
    check[ys, xs] = 1
    x = xs
    y = ys # 今走査するピクセル
    table = [[-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1], [1, 0], [1, 1], [0, 1]]
    edge = [] # 輪郭情報を保持
    count = 0
    coord = []
    while True:
        for i in range(8):
            if array_dash[y + table[i][0], x + table[i][1]] == 1:
                if check[y + table[i][0], x + table[i][1]] == 0:
                    edge.append(i + 1)
                    check[y + table[i][0], x + table[i][1]] = 1
                    y = y + table[i][0]
                    x = x + table[i][1]
                    coord.append([y, x])
                    count += 1
                    break
            if i == 7:
                num = 1
                while True:
                    if x + num < width - 2:
                        test = 0
                        for j in range(8):
                            if array_dash[y + table[j][0], x + num + table[j][1]] == 1 and check[y + table[j][0], x + num + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            x = x + num
                            break
                    if y + num < height - 2:
                        test = 0
                        for j in range(8):
                            if array_dash[y + num + table[j][0], x + table[j][1]] == 1 and check[y + num + table[j][0], x + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            y = y + num
                            break
                    if x - num >= 1:
                        test = 0
                        for j in range(8):
                            if array_dash[y + table[j][0], x - num + table[j][1]] == 1 and check[y + table[j][0], x - num + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            x = x - num
                            break
                    if y - num >= 1:
                        test = 0
                        for j in range(8):
                            if array_dash[y - num + table[j][0], x + table[j][1]] == 1 and check[y - num + table[j][0], x + table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            y = y - num
                            break
                    num += 1

        if count == 1000:
            check[ys, xs] = 0
        if count > 1000:
            if check[ys, xs] == 1:
                break
    # 局所曲率符号を求める
    C_a = []
    C_a.append(edge[0] - edge[len(edge) - 1])
    for i in range(len(edge) - 1):
        C_a.append((edge[i + 1] - edge[i] + 11) % 8 - 3)
    # G-オペレーションを求める
    #M = len(edge)
    #M = 100
    M = 350
    G = []
    G_np = np.zeros(len(edge))
    for i in range(len(edge)):
        G_dash = M * C_a[i]
        for k in range(1, M):
            a = i - k
            b = i + k
            if a < 0:
                a += M
            if b >= M:
                b -= M
            G_dash = G_dash + ((M - k) * (C_a[a] + C_a[b]))
            # G[i] = G_dash
        G.append(G_dash)
        G_np[i] = G_dash
    G_abs = np.abs(G_np)
    num_0 = 0 # 連続する0の数
    index_100 = [] # 200以上の数の数とインデックスのタプルを格納
    index_average = []
    angle = [] # 角の座標
    angle_four = [] # ４つの角を抽出
    G_index = 0 # Gを調べるインデクス
    while True:
        G_sum = 0
        if G_index + 49 < len(G) - 1:
            for j in range(50):
                G_sum += G_abs[G_index + j]
            G_ave = G_sum // 50
            if G_ave > 100:
                angle.append((coord[G_index + 25][0], coord[G_index + 25][1]))
            G_index += 50
        else:
            count_num = 0
            while True:
                G_sum += G_abs[G_index]
                count_num += 1
                if G_index == len(G) - 1:
                    break
                G_index += 1
            G_ave = G_sum // count_num
            if G_ave > 100:
                angle.append((coord[G_index - count_num + count_num // 2][0], coord[G_index - count_num + count_num // 2][1]))
            break

    angle_first = []
    for i in range(len(angle)):
        if angle[i][0] < height // 3 and angle[i][1] < width // 3:
            angle_first.append(angle[i])
    if len(angle_first) > 0:
        distance = math.sqrt(angle_first[0][0] ** 2 + angle_first[0][1] ** 2)
        ans_angle = angle_first[0] 
        for i in range(1, len(angle_first)):
            distance_dash = math.sqrt(angle_first[i][0] ** 2 + angle_first[i][1] ** 2)
            if distance_dash < distance:
                distance = distance_dash
                ans_angle = angle_first[i]
    else:
        angle.sort()
        for i in range(7):
            angle_first.append(angle[i])
        angle_first.sort(key = lambda x : x[1])
        ans_angle = angle_first[0]
        #print(ans_angle)
    angle_four.append(ans_angle) # 1つめの角
    for i in range(3):
        angle_dash = [] # 次の角となる候補を(座標の差分, j)のタプル格納
        if i % 2 == 0:
            for j in range(len(angle)):
                if abs(angle_four[i][1] - angle[j][1]) < 35:
                    angle_dash.append((abs(angle_four[i][0] - angle[j][0]), j))
        else:
            for j in range(len(angle)):
                if abs(angle_four[i][0] - angle[j][0]) < 35:
                    angle_dash.append((abs(angle_four[i][1] - angle[j][1]), j))
        angle_dash.sort(reverse = True)
        angle_four.append(angle[angle_dash[0][1]])
   
        for i in range(len(angle)):
            cv2.circle(img_original, (angle[i][1], angle[i][0]), 10, (0, 255, 0), 1)
        for i in range(len(angle_four)):
            cv2.circle(img_original, (angle_four[i][1], angle_four[i][0]), 10, (255, 0, 0), 1)

    cv2.imshow('image1', img_original)
    cv2.waitKey()
    unevenness = [[0, 0, 0], [0, 0, 0, 0]]# 直線なら0、凸なら1、凹なら-1を格納
    for i in range(4):
        six = [] # 直線を6等分した座標を格納
        diff = [] # 直線との距離
        if i < 3:
            divide_x = (angle_four[i + 1][1] - angle_four[i][1]) // 6 # x方向の6等分した分の長さ
            divide_y = (angle_four[i + 1][0] - angle_four[i][0]) // 6 # y方向の6等分した分の長さ
        else:
            divide_x = (angle_four[0][1] - angle_four[i][1]) // 6 # x方向の6等分した分の長さ
            divide_y = (angle_four[0][0] - angle_four[i][0]) // 6 # y方向の6等分した分の長さ
        for j in range(6):
            six.append([angle_four[i][0] + divide_y * (j + 1), angle_four[i][1] + divide_x * (j + 1)])
            rinkaku = [] # 輪郭のx or y座標を格納
            if i % 2 == 0:
                # 左端から走査
                for k in range(width):
                    if array_dash[six[j][0], k] == 1:
                        rinkaku.append((abs(six[j][1] - k), six[j][1] - k))
                        break
                # 右端から走査
                for k in range(width):
                    if array_dash[six[j][0], width - 1 - k] == 1:
                        rinkaku.append((abs(six[j][1] - (width - 1 - k)), (width - 1 - k) - six[j][1]))
                        break
            else:
                # 上端から走査
                for k in range(height):
                    if array_dash[k, six[j][1]] == 1:
                        rinkaku.append((abs(six[j][0] - k), six[j][0] - k))
                        break
                # 下端から走査
                for k in range(height):
                    if array_dash[height - 1 - k, six[j][1]] == 1:
                        rinkaku.append((abs(six[j][0] - (height - 1 - k)), (height - 1 - k) - six[j][0]))
                        break
            rinkaku.sort()
            if len(rinkaku) > 0:
                diff.append(rinkaku[0])
        diff.sort(reverse = True)
        if abs(diff[0][1] - diff[1][1]) > 150:
            if abs(diff[0][1]) < 40:
                unevenness[0][0] += 1
                unevenness[1][i] = 0
            elif diff[1][1] > 0:
                unevenness[0][1] += 1
                unevenness[1][i] = 1
            else:
                unevenness[0][2] += 1
                unevenness[1][i] = -1
        else:
            if abs(diff[0][1]) < 40:
                unevenness[0][0] += 1
                unevenness[1][i] = 0
            elif diff[0][1] > 0:
                unevenness[0][1] += 1
                unevenness[1][i] = 1
            else:
                unevenness[0][2] += 1
                unevenness[1][i] = -1
                # グループ分け
    if unevenness[0][0] == 0:
        if unevenness[0][1] == 0:
            unevenness.append(1)
        elif unevenness[0][1] == 1:
            unevenness.append(2)
        elif unevenness[0][1] == 2:
            if unevenness[1][2] == -1:
                unevenness.append(3)
            else:
                unevenness.append(4)
        elif unevenness[0][1] == 3:
            unevenness.append(5) 
        else:
            unevenness.append(6)
    elif unevenness[0][0] == 1:
        if unevenness[0][1] == 0:
            unevenness.append(7)
        elif unevenness[0][1] == 1:
            if unevenness[1][0] == 1:
                unevenness.append(8)
            elif unevenness[1][2] == -1:
                unevenness.append(9)
            else:
                unevenness.append(10)
        elif unevenness[0][1] == 2:
            if unevenness[1][3] == -1:
                unevenness.append(11)
            elif unevenness[1][0] == 1:
                unevenness.append(12)
            else:
                unevenness.append(13)
        else:
            unevenness.append(14)
    else:
        if unevenness[0][1] == 0:
            unevenness.append(15)
        elif unevenness[0][1] == 1:
            if unevenness[1][2] == -1:
                unevenness.append(16)
            else:
                unevenness.append(17)
        else:
            unevenness.append(18)
    # 角感距離を格納
    unevenness.append([])
    unevenness[3].append(angle_four[1][0] - angle_four[0][0])
    unevenness[3].append(angle_four[2][1] - angle_four[1][1])
    unevenness[3].append(-angle_four[3][0] + angle_four[2][0])
    unevenness[3].append(-angle_four[0][1] + angle_four[3][1])
    #print(self.unevenness)
    #Unevenness.append(unevenness)
    print(unevenness)
    index = 0
    for i in range(30):
        if Unevenness[i] == unevenness[1]  and test[i] == 0:
            test[i] = 1
            index = i
            break
    print(index)
