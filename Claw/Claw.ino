
#include <Servo.h>

const int clawPin = 9;
const int movePin = 10;

Servo clawServo;
Servo moveServo;

//Claw - 160 degrees is open, 

void setup()
{
  clawServo.attach(clawPin);
  moveServo.attach(movePin);
  store();
  delay(2000);
  fromUnder();
  openClaw();
  closeClaw();
  delay(1250);
  store();
  
}

void loop()
{
}

void openClaw()
{
  clawServo.write(160);
  delay(1500);
}

void closeClaw()
{
  clawServo.write(40);//Close claw with 40 degree so no stress
  delay(1500);
}

void fromUnder()
{
  moveServo.write(175);
  delay(1500);
}

void store()
{
  moveServo.write(0);
  delay(1500);
}
