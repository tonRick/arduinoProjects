#include <Servo.h>

Servo myServo;


void setup() {
  Serial.begin(115200);
  myServo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
  int angle = Serial.parseInt();
  angle = constrain(angle,10,165);
  myServo.write(angle);
  Serial.println(angle);
  }
  
}
