#include <VarSpeedServo.h>      // Servoライブラリの読み込み
//#include <Servo.h>

VarSpeedServo myservo1, myservo2, myservo3, myservo4;          // Servoオブジェクトの宣言
const int SV_PIN1 = 6;   // サーボモーターをデジタルピン7に
const int SV_PIN2 = 7;
const int SV_PIN3 = 8; 
const int SV_PIN4 = 9; 
 void setup(){
 
   myservo1.attach(SV_PIN1);  // サーボの割当(パルス幅500~2400msに指定)
   myservo2.attach(SV_PIN2);
   myservo3.attach(SV_PIN3);
   //
   myservo4.attach(SV_PIN4);
}

 void loop(){
  /*
  rasen.write(85);
  delay(500);
  rasen.write(90);
  delay(1000);
  rasen.write(100);
  delay(2000);
  rasen.write(90);
  delay(1000);
  */

  myservo1.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
  //delay(1000);
  //myservo1.write(180, 10, true);    // サーボモーターを0度の位置まで動かす
  //delay(1000);
  myservo2.write(90, 10, true);    // サーボモーターを0度の位置まで動かす
  delay(1000);
  //myservo2.write(150, 10, true);    // サーボモーターを0度の位置まで動かす
  //delay(1000);
 
  myservo3.write(120, 10, true);    // サーボモーターを0度の位置まで動かす
  delay(1000);
  myservo3.write(0, 10, true);    // サーボモーターを0度の位置まで動かす
  delay(1000);

  //myservo4.write(90);
  //delay(1000);
  

 }
