#!/usr/bin/env python
# coding: utf-8
import cv2, sys, math, rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
from std_msgs.msg import UInt16

L = 150
img_array = []
contours_array = []
length_array = []
#0
img_2 = cv2.imread("./picture/22.png", 0)
img_array.append(img_2)
#1
img_2_dash = cv2.imread("./picture/8.png", 0)
img_array.append(img_2_dash)
#2
img_3 = cv2.imread("./picture/10.png", 0)
img_array.append(img_3)
#3
img_4 = cv2.imread("./picture/15.png", 0)
img_array.append(img_4)
#4
img_4_dash = cv2.imread("./picture/14.png", 0)
img_array.append(img_4_dash)
#5
img_5 = cv2.imread("./picture/16.png", 0)
img_array.append(img_5)
#6
img_5_dash = cv2.imread("./picture/9.png", 0)
img_array.append(img_5_dash)
#7
img_9 = cv2.imread("./picture/19.png", 0)
img_array.append(img_9)
#8
img_9_dash = cv2.imread("./picture/2.png", 0)
img_array.append(img_9_dash)
#9
img_11 = cv2.imread("./picture/7.png", 0)
img_array.append(img_11)
#10
img_11_dash = cv2.imread("./picture/28.png", 0)
img_array.append(img_11_dash)
#11
img_12 = cv2.imread("./picture/13.png", 0)
img_array.append(img_12)
#12
img_12_dash = cv2.imread("./picture/3.png", 0)
img_array.append(img_12_dash)
#13
img_13 = cv2.imread("./picture/12.png", 0)
img_array.append(img_13)
#14
img_16 = cv2.imread("./picture/1.png", 0)
img_array.append(img_16)
#15
img_16_dash = cv2.imread("./picture/25.png", 0)
img_array.append(img_16_dash)
#16
img_17 = cv2.imread("./picture/30.png", 0)
img_array.append(img_17)
#17
img_17_dash = cv2.imread("./picture/6.png", 0)
img_array.append(img_17_dash)
#18
img_8_dash = cv2.imread("./picture/4.png", 0)
img_array.append(img_8_dash)

index_array = [17, 11, 7, 13, 16,
               8, 4, 1, 3, 12,
               18, 3, 0, 2, 10,
               12, 6, 5, 4, 8,
               8, 1, 4, 3, 12,
               14, 9, 11, 7, 15]
distance_array = [[-250, 145], [-250, 150], [-250, 155], [-250, 160], [-250, 165],
                  [-245, 145], [-245, 150], [-245, 155], [-245, 160], [-245, 165],
                  [-240, 145], [-240, 150], [-240, 155], [-240, 160], [-240, 165],
                  [-235, 145], [-235, 150], [-235, 155], [-235, 160], [-235, 165], 
                  [-230, 145], [-230, 150], [-230, 155], [-230, 160], [-230, 165], 
                  [-225, 145], [-225, 150], [-225, 155], [-225, 160], [-225, 165]]
test_array = [0, 0, 0, 0, 0,
              0, 0, 0, 0, 0,
              0, 0, 0, 0, 0,
              0, 0, 0, 0, 0,
              0, 0, 0, 0, 0,
              0, 0, 0, 0, 0]

rev_array = [180, 180, 180, 180, 180,
             90, 90, 0, 0, 0,
             90, 0, 0, 0, 0,
             90, 0, 0, 90, 0,
             90, 90, 90, 0, 0,
             0, 0, 0, 0, 0]
angle_array = [[152, 149], [156, 153], [160, 157], [166, 163], [177, 174],
               [146, 143], [150, 147], [153, 150], [158, 155], [163, 160],
               [141, 138], [144, 141], [147, 144], [151, 148], [155, 152],
               [137, 134], [140, 137], [143, 140], [146, 143], [149, 146],
               [133, 130], [135, 132], [138, 135], [141, 138], [144, 141],
               [129, 126], [132, 129], [134, 131], [137, 134], [140, 137]]

for i in range(len(img_array)):
    ret, img_thresh = cv2.threshold(img_array[i], 100, 255, cv2.THRESH_BINARY)
    contours = cv2.findContours(img_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]
    contours_array.append(contours)
    length1 = 0
    num1 = 0
    for j in range(len(contours)):
        if length1 < len(contours[j]):
            length1 = len(contours[j])
            num1 = j
    length_array.append(num1)

"""
def angle(x, y):
    theta_2 = round(math.acos((2 * L * L - x * x - y * y) / (2 * L * L)) * 180 / math.pi)
    theta_1 = round(theta_2 + math.atan2(y, x))
    print(math.acos((2 * L * L - x * x - y * y) / (2 * L * L)))
    print(math.atan2(y, x))
    return [theta_1, theta_2]
"""
def arduino(num):
    rospy.init_node("publisher")

    msg1 = UInt16()
    msg2 = UInt16()
    msg3= UInt16()
    pub1 = rospy.Publisher("servo1", UInt16, queue_size=10)
    pub2 = rospy.Publisher("servo2", UInt16, queue_size=10)
    pub3 = rospy.Publisher("servo3", UInt16, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        
        #target = angle(distance_array[num][0], distance_array[num][1])
        msg1.data = angle_array[num][0]
        msg2.data = angle_array[num][1]
        msg3.data = rev_array[num]
        pub1.publish(msg1)
        pub2.publish(msg2)
        pub3.publish(msg3)

        rate.sleep()
        
if __name__ == '__main__':
    deviceid = 0 # it depends on the order of USB connection. 
    capture = cv2.VideoCapture(deviceid)

    ret, frame = capture.read()
    cv2.imwrite('test.jpg', frame)
    img_original = cv2.imread('test.jpg')
    #cv2.imshow('1', img_original)
    #cv2.waitKey()

    img = cv2.cvtColor(img_original, cv2.COLOR_BGR2GRAY)
    ret, img_thresh = cv2.threshold(img, 220, 255, cv2.THRESH_BINARY)
    cv2.imshow('image', img_thresh)
    cv2.waitKey()

    contours2 = cv2.findContours(img_thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[1]
    length2 = 0
    num2 = 0
    for i in range(len(contours2)):
        if len(contours2[i]) > length2:
            length2 = len(contours2[i])
            num2 = i
    output = cv2.drawContours(img_original, contours2, -1, (0,0,255), 1)
    cv2.imshow('image1', img_original)
    cv2.waitKey()
   

    index = 0
    matches = 0
    for i in range(len(img_array)):
        matches_dash = cv2.matchShapes(contours_array[i][length_array[i]], contours2[num2], 1, 0.0)
        if i == 0:
            matches = matches_dash
            index = 0
        else:
            if matches_dash < matches:
                matches = matches_dash
                index = i
    #print(index)
    cv2.imshow('index', img_array[index])
    cv2.waitKey()
    piece = 0
    for i in range(30):
        if index == index_array[i] and test_array[i] == 0:
            piece = i
            break
    #print(piece)
   
    n1 = angle_array[piece][0]
    n2 = angle_array[piece][1]
    n3 = n1 + n2 - 180 + rev_array[piece]
    print(n1)
    print(n2)
    print(n3)
    
    try:
        
        arduino(piece)
    except rospy.ROSInterruptException: pass
    
    
    
    
    
