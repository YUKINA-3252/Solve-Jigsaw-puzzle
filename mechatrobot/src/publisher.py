#!/usr/bin/env python

import rospy
import math
from std_msgs.msg import UInt16

L = 150
def angle(x, y):
        theta_1 = math.atan2(y, x) - math.acos(math.sqrt(x * x + y * y) / (2 * L))
        theta_2 = math.pi - math.acos((2 * L * L - x * x - y * y) / (2 * L * L))
        return [theta_1, theta_2]
    
def main():
    # ノードを初期化する。
    rospy.init_node("publisher")

    # 送信者を作成する。
    pub1 = rospy.Publisher("servo1", UInt16, queue_size=10)
    pub2 = rospy.Publisher("servo2", UInt16, queue_size=10)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        # トピックを送信する。
        
        msg1.data = angle(200, 200)[0]
        msg2.data = angle(200, 200)[1]
        pub1.publish(msg1)
        pub2.publish(msg2)

        # 0.1 秒スリープする。
        rate.sleep()


if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException: pass
