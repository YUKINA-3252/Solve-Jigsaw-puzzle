# coding: utf-8
import cv2, sys, math
import numpy as np
img_1 = cv2.imread("./picture/1.png", 0)
img_original_1 = cv2.imread("./picture/1.png")
img_2 = cv2.imread("./picture/2.png", 0)
img_original_2 = cv2.imread("./picture/2.png")
img_3 = cv2.imread("./picture/3.png", 0)
img_original_3 = cv2.imread("./picture/3.png")
img_4 = cv2.imread("./picture/4.png", 0)
img_original_4 = cv2.imread("./picture/4.png")
img_5 = cv2.imread("./picture/5.png", 0)
img_original_5 = cv2.imread("./picture/5.png")
img_6 = cv2.imread("./picture/6.png", 0)
img_original_6 = cv2.imread("./picture/6.png")
img_7 = cv2.imread("./picture/7.png", 0)
img_original_7 = cv2.imread("./picture/7.png")
img_8 = cv2.imread("./picture/8.png", 0)
img_original_8 = cv2.imread("./picture/8.png")
img_9 = cv2.imread("./picture/9.png", 0)
img_original_9 = cv2.imread("./picture/9.png")
img_10 = cv2.imread("./picture/10.png", 0)
img_original_10 = cv2.imread("./picture/10.png")
img_11 = cv2.imread("./picture/11.png", 0)
img_original_11 = cv2.imread("./picture/11.png")
img_12 = cv2.imread("./picture/12.png", 0)
img_original_12 = cv2.imread("./picture/12.png")
img_13 = cv2.imread("./picture/13.png", 0)
img_original_13 = cv2.imread("./picture/13.png")
img_14 = cv2.imread("./picture/14.png", 0)
img_original_14 = cv2.imread("./picture/14.png")
img_15 = cv2.imread("./picture/15.png", 0)
img_original_15 = cv2.imread("./picture/15.png")
img_16 = cv2.imread("./picture/16.png", 0)
img_original_16 = cv2.imread("./picture/16.png")
img_17 = cv2.imread("./picture/17.png", 0)
img_original_17 = cv2.imread("./picture/17.png")
img_18 = cv2.imread("./picture/18.png", 0)
img_original_18 = cv2.imread("./picture/18.png")
img_19 = cv2.imread("./picture/19.png", 0)
img_original_19 = cv2.imread("./picture/19.png")
img_20 = cv2.imread("./picture/20.png", 0)
img_original_20 = cv2.imread("./picture/20.png")
img_21 = cv2.imread("./picture/21.png", 0)
img_original_21 = cv2.imread("./picture/21.png")
img_22 = cv2.imread("./picture/22.png", 0)
img_original_22 = cv2.imread("./picture/22.png")
img_23 = cv2.imread("./picture/23.png", 0)
img_original_23 = cv2.imread("./picture/23.png")
img_24 = cv2.imread("./picture/24.png", 0)
img_original_24 = cv2.imread("./picture/24.png")
img_25 = cv2.imread("./picture/25.png", 0)
img_original_25 = cv2.imread("./picture/25.png")
img_26 = cv2.imread("./picture/26.png", 0)
img_original_26 = cv2.imread("./picture/26.png")
img_27 = cv2.imread("./picture/27.png", 0)
img_original_27 = cv2.imread("./picture/27.png")
img_28 = cv2.imread("./picture/28.png", 0)
img_original_28 = cv2.imread("./picture/28.png")
img_29 = cv2.imread("./picture/29.png", 0)
img_original_29 = cv2.imread("./picture/29.png")
img_30 = cv2.imread("./picture/30.png", 0)
img_original_30 = cv2.imread("./picture/30.png")

piece = 30 # ピース数
#piece_width =
Unevenness = []
class Edge:
    def __init__(self, img, img_original):
        self.ret, self.img_thresh = cv2.threshold(img, 100, 255, cv2.THRESH_BINARY)
        self.height, self.width = self.img_thresh.shape[:2]
        #print("width: " + str(self.width))
        #print("height: " + str(self.height))

        """
        re_img = cv2.resize(img_thresh, dsize = (width, height))
        height2, width2 = re_img.shape[:2]
        """
        self.contours = cv2.findContours(self.img_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]
        self.output = cv2.drawContours(img_original, self.contours, -1, (0,0,255), 1)
        self.array = np.zeros((self.height, self.width), dtype = int) # 画素値を格納する配列
        self.array = img_original[:, :]

        # ラスタ走査をして最初に画素値が0になるところを探す
        self.array_dash = np.zeros((self.height, self.width), dtype = int)
        for i in range(self.height):
            for j in range(self.width):
                if self.array[i, j][0] == 0:
                    if self.array[i, j][1] == 0:
                        if self.array[i, j][2] == 255:
                            self.array_dash[i, j] = 1
        self.ys, self.xs = np.where(self.array_dash == 1)[0][0], np.where(self.array_dash == 1)[1][0]

        # 輪郭を抽出する
        self.check = np.zeros((self.height, self.width), dtype = int) # 抽出したかどうかを格納
        self.check[self.ys, self.xs] = 1
        self.x = self.xs
        self.y = self.ys # 今走査するピクセル
        self.table = [[-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1], [1, 0], [1, 1], [0, 1]]
        self.edge = [] # 輪郭情報を保持
        self.count = 0
        self.coord = []
        while True:
            for i in range(8):
                if self.array_dash[self.y + self.table[i][0], self.x + self.table[i][1]] == 1:
                    if self.check[self.y + self.table[i][0], self.x + self.table[i][1]] == 0:
                        self.edge.append(i + 1)
                        self.check[self.y + self.table[i][0], self.x + self.table[i][1]] = 1
                        self.y = self.y + self.table[i][0]
                        self.x = self.x + self.table[i][1]
                        self.coord.append([self.y, self.x])
                        self.count += 1
                        break
                if i == 7:
                    num = 1
                    while True:
                        if self.x + num < self.width - 2:
                            test = 0
                        for j in range(8):
                            if self.array_dash[self.y + self.table[j][0], self.x + num + self.table[j][1]] == 1 and self.check[self.y + self.table[j][0], self.x + num + self.table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            self.x = self.x + num
                            break
                        if self.y + num < self.height - 2:
                            test = 0
                        for j in range(8):
                            if self.array_dash[self.y + num + self.table[j][0], self.x + self.table[j][1]] == 1 and self.check[self.y + num + self.table[j][0], self.x + self.table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            self.y = self.y + num
                            break
                        if self.x - num >= 1:
                            test = 0
                        for j in range(8):
                            if self.array_dash[self.y + self.table[j][0], self.x - num + self.table[j][1]] == 1 and self.check[self.y + self.table[j][0], self.x - num + self.table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            self.x = self.x - num
                            break
                        if self.y - num >= 1:
                            test = 0
                        for j in range(8):
                            if self.array_dash[self.y - num + self.table[j][0], self.x + self.table[j][1]] == 1 and self.check[self.y - num + self.table[j][0], self.x + self.table[j][1]] == 0:
                                test = 1
                                break
                        if test == 1:
                            self.y = self.y - num
                            break
                        num += 1
                
            if self.count == 1000:
                self.check[self.ys, self.xs] = 0
            if self.count > 1000:
                if self.check[self.ys, self.xs] == 1:
                    break

        # 局所曲率符号を求める
        self.C_a = []
        self.C_a.append(self.edge[0] - self.edge[len(self.edge) - 1])
        for i in range(len(self.edge) - 1):
            self.C_a.append((self.edge[i + 1] - self.edge[i] + 11) % 8 - 3)

        # G-オペレーションを求める
        #M = len(edge)
        #M = 100
        self.M = 350
        self.G = []
        self.G_np = np.zeros(len(self.edge))
        for i in range(len(self.edge)):
            self.G_dash = self.M * self.C_a[i]
            for k in range(1, self.M):
                a = i - k
                b = i + k
                if a < 0:
                    a += self.M
                if b >= self.M:
                    b -= self.M
                self.G_dash = self.G_dash + ((self.M - k) * (self.C_a[a] + self.C_a[b]))
                # G[i] = G_dash
            self.G.append(self.G_dash)
            self.G_np[i] = self.G_dash

        #print(self.G)
        self.G_abs = np.abs(self.G_np)
        self.num_0 = 0 # 連続する0の数
        self.index_100 = [] # 200以上の数の数とインデックスのタプルを格納
        self.index_average = []
        self.angle = [] # 角の座標
        self.angle_four = [] # ４つの角を抽出
        G_index = 0 # Gを調べるインデクス
        while True:
            G_sum = 0
            if G_index + 49 < len(self.G) - 1:
                for j in range(50):
                    G_sum += self.G_abs[G_index + j]
                G_ave = G_sum // 50
                if G_ave > 100:
                    self.angle.append((self.coord[G_index + 25][0], self.coord[G_index + 25][1]))
                G_index += 50
            else:
                count_num = 0
                while True:
                    G_sum += self.G_abs[G_index]
                    count_num += 1
                    if G_index == len(self.G) - 1:
                        break
                    G_index += 1
                G_ave = G_sum // count_num
                if G_ave > 100:
                    self.angle.append((self.coord[G_index - count_num + count_num // 2][0], self.coord[G_index - count_num + count_num // 2][1]))
                break
                   
                
        """
        for i in range(len(self.G)):
            if self.G_abs[i] >= 200:
                self.index_100.append((self.G_np[i], i))
                self.index_average.append(i)
                if self.num_0 >= 30:
                    self.index_100.sort(reverse = True)
                    #angle.append([coord[index_average[len(index_average) // 2]][0], coord[index_average[len(index_average) // 2]][1]])
                    index = 0
                    while True:
                        if index + 1 < len(self.index_100):
                            if self.index_100[index][0] == self.index_100[index + 1][0]:
                                index = index + 1
                            else:
                                break
                        else:
                            break
                    self.angle.append([self.coord[self.index_100[index][1]][0], self.coord[self.index_100[index][1]][1]])
                    self.num_0 = 0
                    self.index_100 = []
                    self.index_average = []
            elif  self.G_abs[i] < 200:
                self.num_0 += 1
        """
        #print(self.angle)
        # 4つの角を抽出
        """
        distance = 0
        angle_index = 0
        for i in range(len(self.angle)):
            distance_dash = math.sqrt(self.angle[i][0] ** 2 + self.angle[i][1] ** 2) + 2 * self.angle[i][1] 
            if distance < distance_dash:
                distance = distance_dash
            angle_index = i
        """
        """
        self.angle.sort()
        angle_first = []
        for i in range(7):
            angle_first.append(self.angle[i])
        angle_first.sort(key = lambda x : x[1])
        """
        angle_first = []
        for i in range(len(self.angle)):
            if self.angle[i][0] < self.height // 3 and self.angle[i][1] < self.width // 3:
                angle_first.append(self.angle[i])
        if len(angle_first) > 0:
            distance = math.sqrt(angle_first[0][0] ** 2 + angle_first[0][1] ** 2)
            ans_angle = angle_first[0]
            for i in range(1, len(angle_first)):
                distance_dash = math.sqrt(angle_first[i][0] ** 2 + angle_first[i][1] ** 2)
                if distance_dash < distance:
                    distance = distance_dash
                    ans_angle = angle_first[i]
        else:
            self.angle.sort()
            for i in range(7):
                angle_first.append(self.angle[i])
            angle_first.sort(key = lambda x : x[1])
            ans_angle = angle_first[0]
        #print(ans_angle)
        self.angle_four.append(ans_angle) # 1つめの角
        for i in range(3):
            self.angle_dash = [] # 次の角となる候補を(座標の差分, j)のタプル格納
            if i % 2 == 0:
                for j in range(len(self.angle)):
                    if abs(self.angle_four[i][1] - self.angle[j][1]) < 35:
                        self.angle_dash.append((abs(self.angle_four[i][0] - self.angle[j][0]), j))
            else:
                for j in range(len(self.angle)):
                    if abs(self.angle_four[i][0] - self.angle[j][0]) < 35:
                        self.angle_dash.append((abs(self.angle_four[i][1] - self.angle[j][1]), j))
            self.angle_dash.sort(reverse = True)
            self.angle_four.append(self.angle[self.angle_dash[0][1]])

            for i in range(len(self.angle)):
                cv2.circle(img_original, (self.angle[i][1], self.angle[i][0]), 10, (0, 255, 0), 1)
            for i in range(len(self.angle_four)):
                cv2.circle(img_original, (self.angle_four[i][1], self.angle_four[i][0]), 10, (255, 0, 0), 1)

        #print(self.angle_four)
        # 凹凸を調べる
        # 凹凸、直線情報を[直線、凸の数、凹の数]で格納
        self.unevenness = [[0, 0, 0], [0, 0, 0, 0]]# 直線なら0、凸なら1、凹なら-1を格納
        for i in range(4):
            self.six = [] # 直線を6等分した座標を格納
            self.diff = [] # 直線との距離
            if i < 3:
                divide_x = (self.angle_four[i + 1][1] - self.angle_four[i][1]) // 6 # x方向の6等分した分の長さ
                divide_y = (self.angle_four[i + 1][0] - self.angle_four[i][0]) // 6 # y方向の6等分した分の長さ
            else:
                divide_x = (self.angle_four[0][1] - self.angle_four[i][1]) // 6 # x方向の6等分した分の長さ
                divide_y = (self.angle_four[0][0] - self.angle_four[i][0]) // 6 # y方向の6等分した分の長さ
            for j in range(6):
                self.six.append([self.angle_four[i][0] + divide_y * (j + 1), self.angle_four[i][1] + divide_x * (j + 1)])
                self.rinkaku = [] # 輪郭のx or y座標を格納
                if i % 2 == 0:
                    # 左端から走査
                    for k in range(self.width):
                        if self.array_dash[self.six[j][0], k] == 1:
                            self.rinkaku.append((abs(self.six[j][1] - k), self.six[j][1] - k))
                            break
                    # 右端から走査
                    for k in range(self.width):
                        if self.array_dash[self.six[j][0], self.width - 1 - k] == 1:
                            self.rinkaku.append((abs(self.six[j][1] - (self.width - 1 - k)), (self.width - 1 - k) - self.six[j][1]))
                            break
                    
                else:
                    # 上端から走査
                    for k in range(self.height):
                        if self.array_dash[k, self.six[j][1]] == 1:
                            self.rinkaku.append((abs(self.six[j][0] - k), self.six[j][0] - k))
                            break
                    # 下端から走査
                    for k in range(self.height):
                        if self.array_dash[self.height - 1 - k, self.six[j][1]] == 1:
                            self.rinkaku.append((abs(self.six[j][0] - (self.height - 1 - k)), (self.height - 1 - k) - self.six[j][0]))
                            break
                self.rinkaku.sort()
                if len(self.rinkaku) > 0:
                    self.diff.append(self.rinkaku[0])
            self.diff.sort(reverse = True)
            #print(self.diff)
            if abs(self.diff[0][1] - self.diff[1][1]) > 150:
                if abs(self.diff[0][1]) < 40:
                    self.unevenness[0][0] += 1
                    self.unevenness[1][i] = 0
                elif self.diff[1][1] > 0:
                    self.unevenness[0][1] += 1
                    self.unevenness[1][i] = 1
                else:
                    self.unevenness[0][2] += 1
                    self.unevenness[1][i] = -1
            else:
                if abs(self.diff[0][1]) < 40:
                    self.unevenness[0][0] += 1
                    self.unevenness[1][i] = 0
                elif self.diff[0][1] > 0:
                    self.unevenness[0][1] += 1
                    self.unevenness[1][i] = 1
                else:
                    self.unevenness[0][2] += 1
                    self.unevenness[1][i] = -1
        # グループ分け
        if self.unevenness[0][0] == 0:
            if self.unevenness[0][1] == 0:
                self.unevenness.append(1)
            elif self.unevenness[0][1] == 1:
                self.unevenness.append(2)
            elif self.unevenness[0][1] == 2:
                if self.unevenness[1][2] == -1:
                    self.unevenness.append(3)
                else:
                    self.unevenness.append(4)
            elif self.unevenness[0][1] == 3:
                self.unevenness.append(5) 
            else:
                self.unevenness.append(6)
        elif self.unevenness[0][0] == 1:
            if self.unevenness[0][1] == 0:
                self.unevenness.append(7)
            elif self.unevenness[0][1] == 1:
                if self.unevenness[1][0] == 1:
                    self.unevenness.append(8)
                elif self.unevenness[1][2] == -1:
                    self.unevenness.append(9)
                else:
                    self.unevenness.append(10)
            elif self.unevenness[0][1] == 2:
                if self.unevenness[1][3] == -1:
                    self.unevenness.append(11)
                elif self.unevenness[1][0] == 1:
                    self.unevenness.append(12)
                else:
                    self.unevenness.append(13)
            else:
                self.unevenness.append(14)
        else:
            if self.unevenness[0][1] == 0:
                self.unevenness.append(15)
            elif self.unevenness[0][1] == 1:
                if self.unevenness[1][2] == -1:
                    self.unevenness.append(16)
                else:
                    self.unevenness.append(17)
            else:
                self.unevenness.append(18)
        # 角感距離を格納
        self.unevenness.append([])
        self.unevenness[3].append(self.angle_four[1][0] - self.angle_four[0][0])
        self.unevenness[3].append(self.angle_four[2][1] - self.angle_four[1][1])
        self.unevenness[3].append(-self.angle_four[3][0] + self.angle_four[2][0])
        self.unevenness[3].append(-self.angle_four[0][1] + self.angle_four[3][1])
        #print(self.unevenness)
        Unevenness.append(self.unevenness)
        #cv2.imshow("original_img", img_original)
        #cv2.imshow("img_nichi", img_thresh)
        #cv2.imshow("img_thresh", img_thresh)
        #cv2.waitKey()
        #cv2.destroyAllWindows()
edge1 = Edge(img_1, img_original_1)
edge2 = Edge(img_2, img_original_2) 
edge3 = Edge(img_3, img_original_3) 
edge4 = Edge(img_4, img_original_4) 
edge5 = Edge(img_5, img_original_5) 
edge6 = Edge(img_6, img_original_6)
edge7 = Edge(img_7, img_original_7)
edge8 = Edge(img_8, img_original_8)
edge9 = Edge(img_9, img_original_9)
edge10 = Edge(img_10, img_original_10)
edge11 = Edge(img_11, img_original_11)
edge12 = Edge(img_12, img_original_12)
edge13 = Edge(img_13, img_original_13)
edge14 = Edge(img_14, img_original_14)
edge15 = Edge(img_15, img_original_15) 
edge16 = Edge(img_16, img_original_16)
edge17 = Edge(img_17, img_original_17)
edge18 = Edge(img_18, img_original_18)
edge19 = Edge(img_19, img_original_19)
edge20 = Edge(img_20, img_original_20)
edge21 = Edge(img_21, img_original_21)
edge22 = Edge(img_22, img_original_22)
edge23 = Edge(img_23, img_original_23) 
edge24 = Edge(img_24, img_original_24)
edge25 = Edge(img_25, img_original_25) 
edge26 = Edge(img_26, img_original_26)
edge27 = Edge(img_27, img_original_27)
edge28 = Edge(img_28, img_original_28)
edge29 = Edge(img_29, img_original_29)
edge30 = Edge(img_30, img_original_30)

# パズルを解く
#print(Unevenness)
check_pazzle = np.zeros(30, dtype = int)
pazzle = []
pazzle_dash = []
# 1ピース目
for i in range(piece):
    if Unevenness[i][0][0] == 2:
        if Unevenness[i][3][0] < Unevenness[i][3][1]:
            pazzle = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
            pazzle_dash.append((i, Unevenness[i][2]))
            pazzle[4][0] = (i, Unevenness[i][2])
            check_pazzle[i] = 1
            break
        elif Unevenness[i][3][0] > Unevenness[i][3][1]:
            pazzle = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
            pazzle_dash.append((i, Unevenness[i][2]))
            pazzle[5][0] = (i, Unevenness[i][2])
            check_pazzle[i] = 1 
            break

choice = [] # 次に考えられる選択肢

# Unevenness[i][1]、Unevenness[i][3]を回転
def revolution():
    for i in range(30):
        temp0 = Unevenness[i][1][0]
        temp1 = Unevenness[i][1][1]
        temp2 = Unevenness[i][1][2]
        temp3 = Unevenness[i][1][3]
        Unevenness[i][1][0] = temp3
        Unevenness[i][1][1] = temp0
        Unevenness[i][1][2] = temp1
        Unevenness[i][1][3] = temp2
        Temp0 = Unevenness[i][3][0]
        Temp1 = Unevenness[i][3][1]
        Temp2 = Unevenness[i][3][2]
        Temp3 = Unevenness[i][3][3]
        Unevenness[i][3][0] = Temp3
        Unevenness[i][3][1] = Temp0
        Unevenness[i][3][2] = Temp1
        Unevenness[i][3][3] = Temp2
def revolution2():
    for i in range(30):
        temp0 = Unevenness[i][1][0]
        temp1 = Unevenness[i][1][1]
        temp2 = Unevenness[i][1][2]
        temp3 = Unevenness[i][1][3]
        Unevenness[i][1][0] = temp1
        Unevenness[i][1][1] = temp2
        Unevenness[i][1][2] = temp3
        Unevenness[i][1][3] = temp0
        Temp0 = Unevenness[i][3][0]
        Temp1 = Unevenness[i][3][1]
        Temp2 = Unevenness[i][3][2]
        Temp3 = Unevenness[i][3][3]
        Unevenness[i][3][0] = Temp1
        Unevenness[i][3][1] = Temp2
        Unevenness[i][3][2] = Temp3
        Unevenness[i][3][3] = Temp0
def revolution_dash(i):
    temp0 = Unevenness[i][1][0]
    temp1 = Unevenness[i][1][1]
    temp2 = Unevenness[i][1][2]
    temp3 = Unevenness[i][1][3]
    Unevenness[i][1][0] = temp3
    Unevenness[i][1][1] = temp0
    Unevenness[i][1][2] = temp1
    Unevenness[i][1][3] = temp2
    Temp0 = Unevenness[i][3][0]
    Temp1 = Unevenness[i][3][1]
    Temp2 = Unevenness[i][3][2]
    Temp3 = Unevenness[i][3][3]
    Unevenness[i][3][0] = Temp3
    Unevenness[i][3][1] = Temp0
    Unevenness[i][3][2] = Temp1
    Unevenness[i][3][3] = Temp2
def revolution_reverse(i):
    temp0 = Unevenness[i][1][0]
    temp1 = Unevenness[i][1][1]
    temp2 = Unevenness[i][1][2]
    temp3 = Unevenness[i][1][3]
    Unevenness[i][1][0] = temp1
    Unevenness[i][1][1] = temp2
    Unevenness[i][1][2] = temp3
    Unevenness[i][1][3] = temp0
    Temp0 = Unevenness[i][3][0]
    Temp1 = Unevenness[i][3][1]
    Temp2 = Unevenness[i][3][2]
    Temp3 = Unevenness[i][3][3]
    Unevenness[i][3][0] = Temp1
    Unevenness[i][3][1] = Temp2
    Unevenness[i][3][2] = Temp3
    Unevenness[i][3][3] = Temp0
    
j = 0
test = 0
while j < 29:
   c = 0
   if test == 1:
        while True:
            a = 0
            for b in range(len(choice[j - 1][0])):
                if choice[j - 1][1][b] == 1:
                    a = b
                else:
                    break
            a += 1
            if a != len(choice[j - 1][0]):
                choice[j - 1][1][a] = 1
                pazzle_dash.append((choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2]))
                if j <= 4:
                    l = 5
                    m = j 
                elif j <= 9:
                    l = -1 * j + 9
                    m = 4
                elif j <= 13:
                    l = 0
                    m = -1 * j + 13
                elif j <= 16:
                    l = j - 13
                    m = 0
                pazzle[l][m] = (choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2])
                print(pazzle)
                for i in range(len(choice[j - 1][0])):
                    check_pazzle[choice[j - 1][0][i]] = 0
                check_pazzle[choice[j - 1][0][a]] = 1
                c = 1
                break
            else:
                j -= 1
                if j == 3 or j == 8 or j == 12 or j == 16:
                    revolution2()
                del choice[j]
                del pazzle_dash[-1]
                if j > 0:
                    for i in range(len(choice[j - 1][0])):
                        check_pazzle[choice[j - 1][0][i]] = 0
        if c == 1:
            test = 0
            continue
   if j <= 16:
        choice.append(([], []))
        if j <= 3:
            k = 2
        elif j >= 4 and j <= 8:
            k = 3
        elif  j >= 13 and j <= 16:
            k = 1
        elif j >= 9 and j <= 12:
            k = 0
        for i in range(30):
            if Unevenness[pazzle_dash[j][0]][1][k] == -1:
                next = 1
            elif Unevenness[pazzle_dash[j][0]][1][k] == 1:
                next = -1

            if j == 3 or j == 8 or j == 12:
                if check_pazzle[i] == 0:
                    if Unevenness[i][0][0] == 2:
                        if j == 3:
                            n = 3
                        elif j == 8:
                            n = 0
                        elif j == 12:
                            n = 1
                        if Unevenness[i][1][n] == next:
                            if j == 12 or j == 8 or j == 3:
                                if Unevenness[i][3][1] + Unevenness[i][3][3] > Unevenness[i][3][0] + Unevenness[i][3][2]:
                                    choice[j][0].append(i)


            else:
                if check_pazzle[i] == 0:
                    if Unevenness[i][0][0] == 1:
                        if j <= 2:
                            n = 0
                        elif j >= 3 and j <= 7:
                            n = 1
                        elif  j >= 8 and j <= 12:
                            n = 2
                        elif j >= 13 and j <= 16:
                            n = 3
                        if Unevenness[i][1][n] == next:
                            if j != 16:
                                if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                            else:
                                if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    next_dash = Unevenness[pazzle[5][0][0]][1][2] * -1
                                    if Unevenness[i][1][1] == next_dash:
                                        choice[j][0].append(i)
        for i in range(len(choice[j][0])):
            choice[j][1].append(0)

        # 候補がなかった場合
        if len(choice[j][0]) == 0:
            del choice[j]
            del pazzle_dash[-1]
            if j > 0:
                for i in range(len(choice[j - 1][0])):
                    check_pazzle[choice[j - 1][0][i]] = 0
                while True:
                    a = 0
                    for b in range(len(choice[j - 1][0])):
                        if choice[j - 1][1][b] == 1:
                            a = b
                        else:
                            break
                    a += 1
                    if a != len(choice[j - 1][0]):
                        choice[j - 1][1][a] = 1
                        pazzle_dash.append((choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2]))
                        if j <= 4:
                            l = 5
                            m = j
                        elif j <= 9:
                            l = -1 * j + 9
                            m = 4
                        elif j <= 13:
                            l = 0
                            m = -1 * j + 13
                        elif j <= 16:
                            l = j - 13
                            m = 0
                        pazzle[l][m] = (choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2])
                        for i in range(len(choice[j - 1][0])):
                            check_pazzle[choice[j - 1][0][i]] = 0
                        check_pazzle[choice[j - 1][0][a]] = 1
                        c = 1
                        break
                    else:
                        j -= 1
                        if j == 3 or j == 8 or j == 12 or j == 16:
                            revolution2()
                        del choice[j]
                        del pazzle_dash[-1]
                        if j > 0:
                            for i in range(len(choice[j - 1][0])):
                                check_pazzle[choice[j - 1][0][i]] = 0
        if c == 1:
            continue
        a = 0
        for i in range(len(choice[j][0])):
            if choice[j][1][i] == 1:
                a = i
        pazzle_dash.append((choice[j][0][a], Unevenness[choice[j][0][a]][2]))
        choice[j][1][a] = 1
        if j <= 3:
            l = 5
            m = j + 1
        elif j >= 3 and j <= 8:
            l = -1 * j + 8
            m = 4
        elif j >= 9 and j <= 12:
            l = 0
            m = -1 * j + 12
        elif j >= 13 and j <= 16:
            l = j - 12
            m = 0
        pazzle[l][m] = (choice[j][0][a], Unevenness[choice[j][0][a]][2])
        for i in range(len(choice[j][0])):
            check_pazzle[choice[j][0][i]] = 0
        check_pazzle[choice[j][0][a]] = 1
        if j == 3 or j == 8 or j == 12 or j == 16:
            revolution()
        j += 1

   ###########################################################
   else:
        choice.append(([], [], []))
        if j == 17 or j == 18 or j == 20 or j == 21 or j == 23 or j == 25:
            for i in range(30):
                if j == 17 or j == 20 or j == 21:
                    e = 3
                elif j == 18:
                    e = 2
                elif j == 23:
                    e = 0
                elif j == 25:
                    e = 1
                if Unevenness[pazzle_dash[j][0]][1][e] == -1:
                    next1 = 1 # j = 17、18のときは左、j = 20,21のときは下、j = 23のときは右
                elif Unevenness[pazzle_dash[j][0]][1][e] == 1:
                    next1 = -1
                if j >= 17 and j <= 18:
                    l = 5
                    m = j - 16
                elif j >= 20 and j <= 21:
                    l = -1 * j + 23
                    m = 4
                elif j >= 22 and j <= 23:
                    l = 0
                    m = -1 * j + 25
                elif j == 25:
                    l = 2
                    m = 0
                if Unevenness[pazzle[l][m][0]][1][3] == -1:
                    next2 = 1 # j = 17,18のときは下、j = 20,21のときは右
                elif Unevenness[pazzle[l][m][0]][1][3] == 1:
                    next2 = -1
        
                if check_pazzle[i] == 0:
                    if Unevenness[i][0][0] == 0:
                        if next1 == -1 and next2 == -1:
                            if Unevenness[i][2] == 2:
                                if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    if (j >= 17 and j <= 18) or j == 25:
                                        choice[j][2].append(-1)
                                    elif (j >= 20 and j <= 21) or j == 23:
                                        choice[j][2].append(1)
                                elif  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    if j == 23 or j == 22 or j == 25:
                                        choice[j][2].append(2)
                                    else:
                                        choice[j][2].append(0)
                            elif Unevenness[i][2] == 3:
                                if j == 23 or j == 17 or j == 18:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][0].append(1)
                                        else:
                                            choice[j][0].append(-1)
                                else:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(2)
                                        else:
                                            choice[j][2].append(0)
                        elif next1 == 1 and next2 == 1:
                            if Unevenness[i][2] == 3:
                                if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    if j >= 17 and j <= 18:
                                        choice[j][2].append(1)
                                    elif (j >= 20 and j <= 21) or j == 23:
                                        choice[j][2].append(-1)
                                if j == 25:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                            elif Unevenness[i][2] == 5:
                                if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    if (j >= 17 and j <= 18) or j == 25:
                                        choice[j][2].append(1)
                                    elif (j >= 20 and j <= 21) or j == 23:
                                        choice[j][2].append(-1)
                                if j == 23 or j == 25:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                        elif next1 == 1 and next2 == -1:
                            if Unevenness[i][2] == 2:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][2].append(-1)
                                        else:
                                            choice[j][2].append(1)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(0)
                                        else:
                                            choice[j][2].append(2)
                            elif Unevenness[i][2] == 3:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][2].append(2)
                                        else:
                                            choice[j][2].append(0)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(-1)
                                        else:
                                            choice[j][2].append(1)
                            elif Unevenness[i][2] == 4:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            elif Unevenness[i][2] == 5:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][2].append(2)
                                        else:
                                            choice[j][2].append(0)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(-1)
                                        else:
                                            choice[j][2].append(1)
                        elif next1 == -1 and next2 == 1:
                            if (j >= 17 and j <= 18) or j == 23:
                                if Unevenness[i][2] == 2:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][2].append(0)
                                        else:
                                            choice[j][2].append(2)
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        if j == 25:
                                            choice[j][0].append(i)
                                            choice[j][2].append(1)
                            if Unevenness[i][2] == 3:
                                if j == 23:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                else:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(1)
                                        else:
                                            choice[j][2].append(-1)
                            elif Unevenness[i][2] == 4:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                            elif Unevenness[i][2] == 5:
                                if (j >= 17 and j <= 18) or j == 23:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 23:
                                            choice[j][2].append(1)
                                        else:
                                            choice[j][2].append(-1)
                                elif (j >= 20 and j <= 21) or j == 25:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 25:
                                            choice[j][2].append(2)
                                        else:
                                            choice[j][2].append(0)
        elif j == 19 or j == 22 or j == 24 or j == 26 or j == 27:
            for i in range(30):
                if j == 19 or j == 27:
                    a = 2
                elif j == 22:
                    a = 3
                elif j == 24:
                    a = 0
                elif j == 26:
                    a = 1
                if Unevenness[pazzle_dash[j][0]][1][a] == -1:
                    next1 = 1 # j = 19のとき左、j = 22のとき下、j = 24のとき右、j = 26のとき上, j = 27のとき左
                elif Unevenness[pazzle_dash[j][0]][1][a] == 1:
                    next1 = -1
                if j == 19:
                    l = 5
                    m = 3
                elif j == 22:
                    l = 1
                    m = 4
                elif j == 24:
                    l = 0
                    m = 1
                elif j == 26:
                    l = 3
                    m = 0
                elif j == 27:
                    l = 4
                    m = 2
                if Unevenness[pazzle[l][m][0]][1][3] == -1:
                    next2 = 1 # j = 19のとき下、j = 22のとき右、j = 24のとき上,j = 26のとき左,j = 27のとき下
                elif Unevenness[pazzle[l][m][0]][1][3] == 1:
                    next2 = -1
                if j == 19:
                    l = 4
                    m = 4
                elif j == 22:
                    l = 0
                    m = 3
                elif j == 24:
                    l = 1
                    m = 0
                elif j == 26:
                    l = 4
                    m = 1
                elif j == 27:
                    l = 3
                    m = 3
                if j == 27:
                    k = 0
                else:
                    k = 3
                if Unevenness[pazzle[l][m][0]][1][k] == -1:
                    next3 = 1 # j = 19のとき右、j = 22のとき上、j = 24のとき左,j = 26のとき下,j = 27のとき右
                elif Unevenness[pazzle[l][m][0]][1][k] == 1:
                    next3 = -1
                
                if check_pazzle[i] == 0:
                    if Unevenness[i][0][0] == 0:
                        if next1 == -1 and next2 == -1 and next3 == -1:
                            if Unevenness[i][2] == 2:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(0)
                                        elif j == 24:
                                            choice[j][2].append(2)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(1)
                                        elif j == 26:
                                            choice[j][2].append(-1)
                        elif next1 == -1 and next2 == -1 and next3 == 1:
                            if Unevenness[i][2] == 2:
                                if j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(0)
                                        elif j == 26:
                                            choice[j][2].append(2)
                                elif j == 19 or j == 24:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 24:
                                            choice[j][2].append(1)
                                        elif j == 19:
                                            choice[j][2].append(-1)
                            elif Unevenness[i][2] == 3:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(-1)
                                        elif j == 24:
                                            choice[j][2].append(1)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(0)
                                        elif j == 26:
                                            choice[j][2].append(2)
                            elif Unevenness[i][2] == 5:
                                if j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(2)
                        elif next1 == -1 and next2 == 1 and next3 == -1:
                            if Unevenness[i][2] == 2:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(2)
                                        elif j == 24:
                                            choice[j][2].append(0)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(-1)
                                        elif j == 26:
                                            choice[j][2].append(1)
                            elif Unevenness[i][2] == 4:
                                if j == 24 or j == 19:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                                else:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                        elif next1 == -1 and next2 == 1 and next3 == 1:
                            if Unevenness[i][2] == 3:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(2)
                                        elif j == 24:
                                            choice[j][2].append(0)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(-1)
                                        elif j == 26:
                                            choice[j][2].append(1)
                            elif Unevenness[i][2] == 5:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(-1)
                                        elif j == 24:
                                            choice[j][2].appned(1)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(0)
                                        elif j == 26:
                                            choice[j][2].append(2)
                        elif next1 == 1 and next2 == -1 and next3 == -1:
                            if Unevenness[j][2] == 2:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(1)
                                        elif j == 24:
                                            choice[j][2].append(-1)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(2)
                                        elif j == 26:
                                            choice[j][2].append(0)
                            elif Unevenness[j][2] == 3:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(0)
                                        elif j == 24:
                                            choice[j][2].append(2)
                                if j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(2)
                                        elif j == 26:
                                            choice[j][2].append(-1)
                        elif next1 == 1 and next2 == -1 and next3 == 1:
                            if Unevenness[i][2] == 4:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            if Unevenness[i][2] == 5:
                                if j == 19 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                elif j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(0)
                                        choice[j][2].append(-1)
                        elif next1 == 1 and next2 == 1 and next3 == -1:
                            if Unevenness[i][2] == 3:
                                if j == 26:
                                    if  Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                else:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(1)
                                        elif j == 22:
                                            choice[j][2].append(2)
                                        elif j == 24:
                                            choice[j][2].append(-1)
                            if j == 19 or j == 26 or j == 27:
                                if Unevenness[i][2] == 5:
                                    if j == 19:
                                        if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                            choice[j][0].append(i)
                                            choice[j][2].append(1)
                                    elif Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 27:
                                            choice[j][2].append(1)
                                        elif j == 26:
                                            choice[j][2].append(0)
                        elif next1 == 1 and next2 == 1 and next3 == 1:
                            if Unevenness[i][2] == 5:
                                if j == 19 or j == 24 or j == 27:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 19 or j == 27:
                                            choice[j][2].append(2)
                                        elif j == 24:
                                            choice[j][2].append(0)
                                elif j == 22 or j == 26:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        if j == 22:
                                            choice[j][2].append(-1)
                                        elif j == 26:
                                            choice[j][2].append(1)
        elif j == 28:
            for i in range(30):
                next1 = Unevenness[pazzle[3][2][0]][1][3] * -1 # 下
                next2 = Unevenness[pazzle[2][1][0]][1][2] * -1 # 左
                next3 = Unevenness[pazzle[1][2][0]][1][1] * -1 # 上
                next4 = Unevenness[pazzle[2][3][0]][1][0] * -1 # 右
                if check_pazzle[i] == 0:
                    if Unevenness[i][0][0] == 0:
                        if next1 == -1 and next2 == -1 and next3 == -1 and next4 == 1:
                            if Unevenness[i][2] == 2:
                                if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    choice[j][2].append(-1)
                        elif next1 == -1 and next2 == -1 and next3 == 1 and next4 == -1:
                            if Unevenness[i][2] == 2:
                                if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                    choice[j][0].append(i)
                                    choice[j][2].append(0)
                            elif next1 == -1 and next2 == -1 and next3 == 1 and next4 == 1:
                                if Unevennss[i][2] == 3:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(-1)
                            elif next1 == -1 and next2 == 1 and next3 == -1 and next4 == -1:
                                if Unevenness[i][2] == 2:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            elif next1 == -1 and next2 == 1 and next3 == -1 and next4 == 1:
                                if Unevenness[i][2] == 4:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                            elif next1 == -1 and next2 == 1 and next3 == 1 and next4 == -1:
                                if Unevenness[i][2] == 3:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                            elif next1 == -1 and next2 == 1 and next3 == 1 and next4 == 1:
                                if Unevenness[i][2] == 5:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                            elif next1 == 1 and next2 == -1 and next3 == -1 and next4 == -1:
                                if Unevenness[i][2] == 2:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(2)
                            elif next1 == 1 and next2 == -1 and next3 == -1 and next4 == 1:
                                if Unevenness[i][2] == 3:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(2)
                            elif next1 == 1 and next2 == -1 and next3 == 1 and next4 == -1:
                                if Unevenness[i][2] == 4:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            elif next1 == 1 and next2 == -1 and next3 == 1 and next4 == 1:
                                if Unevenness[i][2] == 5:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(-1)
                            elif next1 == 1 and next2 == 1 and next3 == -1 and next4 == -1:
                                if Unevenness[i][2] == 3:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            elif next1 == 1 and next2 == 1 and next3 == -1 and next4 == 1:
                                if Unevenness[i][2] == 5:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(2)
                            elif next1 == 1 and next2 == 1 and next3 == 1 and next4 == -1:
                                if Unevenness[i][2] == 5:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] < Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(1)
                            elif next1 == 1 and next2 == 1 and next3 == 1 and next4 == 1:
                                if Unevenness[i][2] == 6:
                                    if Unevenness[i][3][0] + Unevenness[i][3][2] > Unevenness[i][3][1] + Unevenness[i][3][3]:
                                        choice[j][0].append(i)
                                        choice[j][2].append(0)
                                                 
        for i in range(len(choice[j][0])):
            choice[j][1].append(0)
        if len(choice[j][0]) > 0:
            # 回転させる
            if choice[j][2][0] == 1:
                revolution_dash(choice[j][0][0])
            elif choice[j][2][0] == 2:
                revolution_dash(choice[j][0][0])
                revolution_dash(choice[j][0][0])
            elif choice[j][2][0] == -1:
                revolution_reverse(choice[j][0][0])
            elif choice[j][2][0] == -2:
                revolution_reverse(choice[j][0][0])
                revolution_reverse(choice[j][0][0])

        # 候補がなかった場合
        if len(choice[j][0]) == 0:
            del choice[j]
            del pazzle_dash[-1]

            for i in range(len(choice[j - 1][0])):
                check_pazzle[choice[j - 1][0][i]] = 0

            while True:
                 # 回転を戻す
                if len(choice[j - 1]) == 3:
                    d = 0
                    for i in range(len(choice[j - 1][0])):
                        if choice[j - 1][1][i] == 1:
                            d = i
                    if choice[j - 1][2][d] == 1:
                        revolution_reverse(choice[j - 1][0][d])
                    elif choice[j - 1][2][d] == 2:
                        revolution_reverse(choice[j - 1][0][d])
                        revolution_reverse(choice[j - 1][0][d])
                    elif choice[j - 1][2][d] == -1:
                        revolution_dash(choice[j - 1][0][d])
                    elif choice[j - 1][2][d] == -2:
                        revolution_dash(choice[j - 1][0][d])
                        revolution_dash(choice[j - 1][0][d])
            
                a = 0
                for b in range(len(choice[j - 1][0])):
                    if choice[j - 1][1][b] == 1:
                        a = b
                    else:
                        break
                a += 1
                if a != len(choice[j - 1][0]):
                    choice[j - 1][1][a] = 1
                    pazzle_dash.append((choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2]))
                    if j >= 17 and j <= 19:
                        l = 4
                        m = j - 17
                    elif j >= 20 and j <= 22:
                        l = -1 * j + 24
                        m = 3
                    elif j >= 23 and j <= 24:
                        l = 1
                        m = -1 * j + 26
                    elif j >= 25 and j <= 26:
                        l = j - 24
                        m = 1
                    elif j == 27:
                        l = 3
                        m = 1
                    elif j == 28:
                        l = 3
                        m = 2
                    pazzle[l][m] = (choice[j - 1][0][a], Unevenness[choice[j - 1][0][a]][2])
                    for i in range(len(choice[j - 1][0])):
                        check_pazzle[choice[j - 1][0][i]] = 0
                    check_pazzle[choice[j - 1][0][a]] = 1
                    # 回転させる
                    if choice[j - 1][2][a] == 1:
                        revolution_dash(choice[j - 1][0][a])
                    elif choice[j - 1][2][a] == 2:
                        revolution_dash(choice[j - 1][0][a])
                        revolution_dash(choice[j - 1][0][a])
                    elif choice[j - 1][2][a] == -1:
                        revolution_reverse(choice[j - 1][0][a])
                    elif choice[j - 1][2][a] == -2:
                        revolution_reverse(choice[j - 1][0][a])
                        revolution_reverse(choice[j - 1][0][a])
                    c = 1
                    break
                else:
                    j -= 1
                    del choice[j]
                    del pazzle_dash[-1]
                    if j > 0:
                        for i in range(len(choice[j - 1][0])):
                            check_pazzle[choice[j - 1][0][i]] = 0
                    if j == 16:
                        revolution2()
                        test = 1
                        break
            
        if c == 1 or test == 1:
            continue
        a = 0
        for i in range(len(choice[j][0])):
            if choice[j][1][i] == 1:
                a = i
        pazzle_dash.append((choice[j][0][a], Unevenness[choice[j][0][a]][2]))
        choice[j][1][a] = 1
        if j >= 17 and j <= 19:
            l = 4
            m = j - 16
        elif j >= 20 and j <= 22:
            l = -1 * j + 23
            m = 3
        elif j >= 23 and j <= 24:
            l = 1
            m = -1 * j + 25
        elif j >= 25 and j <= 26:
            l = j - 23
            m = 1
        elif j == 27:
            l = 3
            m = 2
        elif j == 28:
            l = 2
            m = 2
        pazzle[l][m] = (choice[j][0][a], Unevenness[choice[j][0][a]][2])
        for i in range(len(choice[j][0])):
            check_pazzle[choice[j][0][i]] = 0
        check_pazzle[choice[j][0][a]] = 1
        j += 1
             
print(Unevenness)
print(choice)
print(pazzle_dash)
print(pazzle)
print(check_pazzle)
print(Unevenness[6], Unevenness[11])
