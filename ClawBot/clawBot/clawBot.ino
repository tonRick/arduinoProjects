
#include <Servo.h>

//Define Servos
Servo claw;
Servo arm;

//Define pins
const int dirPinL = 12;
const int dirPinR = 13;
const int speedPinL = 3;
const int speedPinR = 11;
const int clawPin = 9;
const int armPin = 10;

//Initialize variables

int speedL = 0;
int speedR = 0;
int dirL = 0;
int dirR = 0;
int clawState = 0;
int readVar = 0; //Initialize readVar to 0. Stop and Store

void setup() {
  Serial.begin(115200);
  arm.attach(armPin);
  claw.attach(clawPin);
  delay(3000);
  digitalWrite(dirPinR,0);
  digitalWrite(dirPinL,0);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  Serial.println(clawState);
  clawStore();
}
  
 

void loop() {
 while (Serial.available() > 0)
  {
    readVar = Serial.read();
  }

 switch(readVar)
 {
  default:
  {
    Serial.println("StopMo");
    stopMo();  
  }break;

  case '0':
  {
    Serial.println("StopMo");
    stopMo();
  }break;
    
  case '1':
  {
    stopMo();
    Serial.println("ClawClose");
    clawClose();
    
  }break;
  
  case '2':
  {
    stopMo();
    Serial.println("ClawOpen");
    clawOpen();
    
  }break;
  
  case '3':
  {
    stopMo();
    Serial.println("ArmClose");
    clawStore();
    
  }break;
  
  case '4':
  {
    stopMo();
    Serial.println("ArmOpen");
    armOpen();
    
  }break;
  
  case '5':
  {
    Serial.println("Forward");
    forward();
    
  }break;

  case '6':
  {
    Serial.println("Reverse");
    reverse();
    
  }break;

  case 'l':
  {
    Serial.println("Left");
    lRotate();
    
  }break;

  case 'r':
  {
    Serial.println("Right");
    rRotate();
    
  }break;


 }
  
}

void stopMo()
{
  speedL = 0;
  speedR = 0;
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(250);
}

void forward()
{
//  if (clawState != 0)
//  {
//    clawStore();
//  }
    
  speedL = 100;
  speedR = 100;
  dirL = 1;
  dirR = 1;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(250);
}

void reverse()
{
//  if (clawState != 0)
//  {
//    clawStore();
//  }
//    
  speedL = 100;
  speedR = 100;
  dirL = 0;
  dirR = 0;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(250);
}

void lRotate()
{
    
  speedL = 100;
  speedR = 100;
  dirL = 0;
  dirR = 1;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(250);
}

void rRotate()
{

    
  speedL = 100;
  speedR = 100;
  dirL = 1;
  dirR = 0;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(250);
}


void clawOpen()
{
  claw.write(160);
  clawState = 1;
  delay(600);
  
}

void clawClose()
{
  claw.write(20);
  clawState = 1;
  delay(600);
}

void armOpen()
{
  arm.write(0);
  clawState = 1;
  delay(1250);
}

void armClose()
{
  arm.write(180);
  clawState = 1;
  delay(1250);
}

void clawStore()
{
  clawClose();
  armClose();
  clawState = 0;
}



