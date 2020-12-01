#include <Servo.h>
Servo servo1; 
Servo servo2;
// Objek yang dibuat maksimum 8 objek servo
int degree = 0; // posisi servo
void setup() {
  // put your setup code here, to run once:
  servo1.attach(9); // pin 9 arduino
  servo2.attach(7); // pin 7 arduino
}

void loop() {
  // put your main code here, to run repeatedly:
  for(degree = 0; degree < 180; degree++) {
    servo1.write(degree); // sesuai nilai variabel sudut
    servo2.write(degree);
    delay(15); // delay selama 15ms setiap posisi mencapai 1 derajat
  }
  for(degree = 180; degree >= 1; degree--) {
    servo1.write(degree);
    servo2.write(degree);
    delay(15);
  }
}
