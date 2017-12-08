#include <Servo.h>

Servo leftArm;
Servo rightArm;
Servo leftShoulder;
Servo rightShoulder;

void setup() {
  leftArm.attach(9);
  rightArm.attach(10);
  leftShoulder.attach(3);
  rightShoulder.attach(5);
}

void loop() {
//for(int ii = 0; ii<180; ii++){
  leftArm.write(1650);
  rightArm.write(160);
  leftShoulder.write(160);
  rightShoulder.write(160);
  delay(2000);

//for(int ii = 180; ii>0; ii--){
  leftArm.write(10);
  rightArm.write(10);
  leftShoulder.write(10);
  rightShoulder.write(10);
  delay(2000);



}
