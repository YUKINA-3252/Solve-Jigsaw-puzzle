# CMake generated Testfile for 
# Source directory: /home/mech-user/enshu_ws/src/robot-programming/turtleboteus
# Build directory: /home/mech-user/enshu_ws/build/turtleboteus
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_turtleboteus_rostest_test_test-turtlebot.test "/home/mech-user/enshu_ws/build/turtleboteus/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/mech-user/enshu_ws/build/turtleboteus/test_results/turtleboteus/rostest-test_test-turtlebot.xml" "--return-code" "/usr/bin/python2 /opt/ros/melodic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/mech-user/enshu_ws/src/robot-programming/turtleboteus --package=turtleboteus --results-filename test_test-turtlebot.xml --results-base-dir \"/home/mech-user/enshu_ws/build/turtleboteus/test_results\" /home/mech-user/enshu_ws/src/robot-programming/turtleboteus/test/test-turtlebot.test ")
subdirs("gtest")
