
#include <Servo.h>

Servo danServo;
int angle = 10;

void setup(){
  danServo.attach(9);
  Serial.begin(9600);
  danServo.write(angle);
}

void loop(){
  if (Serial.available() > 0){
    angle = Serial.parseInt();
  } 
  if (angle >= 180){
    angle = 180;
  }else if (angle <= 0){
    angle = 0;
  }
  Serial.println(angle);
  danServo.write(angle);
  delay(10);
}
