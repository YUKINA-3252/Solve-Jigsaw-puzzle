#include <Servo.h>
Servo rasen;     //廻るペンギンの名前「螺旋(らせん)」
void setup() {
rasen.attach(9);   //PWMにつなぐ。[~]マークの3,5,6,9,10,11。ここでは6。
}

void loop() {
rasen.write(86); //ここの数値が正転・反転、速度を司る。
delay(1000);
rasen.write(90);
delay(1000);
rasen.write(95);
delay(1500);
rasen.write(90);
delay(1000);
}
