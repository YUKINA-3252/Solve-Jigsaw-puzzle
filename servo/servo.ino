/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <VarSpeedServo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

#define SERVO_PULSE_MIN_US 500
#define SERVO_PULSE_MAX_US 2500

ros::NodeHandle  nh;

VarSpeedServo myservo1, myservo2, myservo3, myservo4;


void servo1_cb( const std_msgs::UInt16& cmd_msg){
  //myservo1.write(cmd_msg.data, 10, true); //set servo angle, should be from 0-180  
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led 
  myservo1.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
   delay(3000);
   myservo2.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
   delay(3000);
   myservo4.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
   delay(3000);
   myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
   delay(3000);
   myservo3.write(0, 10, true);    // サーボモーターを0度の位置まで動かす
   delay(3000);
   myservo1.write(cmd_msg.data, 10, true); //set servo angle, should be from 0-180
   delay(3000);  
   digitalWrite(13, HIGH-digitalRead(13));  //toggle led
 
}
void servo2_cb(const std_msgs::UInt16& cmd_msg){
  myservo2.write(cmd_msg.data, 10, true); //set servo angle, should be from 0-180  
  delay(3000);
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led
  myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
  delay(3000);
}

void servo3_cb(const std_msgs::UInt16& cmd_msg){
  myservo4.write(cmd_msg.data, 10, true);
  delay(3000);
  myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
  delay(3000);
    
}


ros::Subscriber<std_msgs::UInt16> sub1("servo1", servo1_cb);
ros::Subscriber<std_msgs::UInt16> sub2("servo2", servo2_cb);
ros::Subscriber<std_msgs::UInt16> sub3("servo3", servo3_cb);

void setup(){
  myservo1.attach(6, SERVO_PULSE_MIN_US, SERVO_PULSE_MAX_US); //attach it to pin 9
  myservo2.attach(7, SERVO_PULSE_MIN_US, SERVO_PULSE_MAX_US); 
  myservo3.attach(8, SERVO_PULSE_MIN_US, SERVO_PULSE_MAX_US);
  myservo4.attach(9, SERVO_PULSE_MIN_US, SERVO_PULSE_MAX_US);

  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub1);
  delay(1000);
  nh.subscribe(sub2);
  delay(1000);
  nh.subscribe(sub3);
  delay(1000);
}

int test = 0;
void loop(){
  /*
  if (test == 0){
    myservo1.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
    myservo2.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
    myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
    myservo3.write(0, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
    nh.spinOnce();
    myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
    myservo3.write(0, 10, true);    // サーボモーターを0度の位置まで動かす
    delay(1000);
  }
  test++;
  */
  if (test == 0){
    nh.spinOnce();
    delay(1);
  }
  test++;
}
