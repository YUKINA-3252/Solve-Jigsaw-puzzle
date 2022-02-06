#!/usr/bin/env python

import rospy
import math
from std_msgs.msg import UInt16

L1 = 150
L2 = 170
def angle(x, y):
        theta_1 = round((math.atan2(y, x) - math.acos((L1 * L1 - L2 * L2 + x * x + y * y) / (2 * L1 * math.sqrt(x * x + y * y)))) * 180 / math.pi)
        theta_2 = round((math.pi - math.acos((L1 * L1 + L2 * L2 - x * x - y * y) / (2 * L1 * L2))) * 180 / math.pi)
        return [theta_1, theta_2]

def main():
    rospy.init_node("publisher")

    msg1 = UInt16()
    msg2 = UInt16()
    pub1 = rospy.Publisher("servo1", UInt16, queue_size=10)
    pub2 = rospy.Publisher("servo2", UInt16, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        
        msg1.data = angle(-200, 130)[0]
        msg2.data = angle(-200, 130)[1]
        pub1.publish(msg1)
        pub2.publish(msg2)

        rate.sleep()


if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException: pass
