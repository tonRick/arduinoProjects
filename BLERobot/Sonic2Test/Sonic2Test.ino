#include<Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
}

void loop() {
for (int ii = 0; ii<180; ii++){
  myServo.write(ii);
  delay(10);
}
for (int ii = 180; ii>0; ii--){
  myServo.write(ii);
  delay(10);
}

  
}
