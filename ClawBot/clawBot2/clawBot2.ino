
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
int clawState = 0; //claw 0 closed, 1 open
int armState = 0; //arm 0 stored, 1 deployed
int readVar = 0; //Initialize readVar to 0. Stop and Store

void setup() {
  Serial.begin(115200);
  arm.attach(armPin);
  claw.attach(clawPin);
  delay(1000);
  digitalWrite(dirPinR,0);
  digitalWrite(dirPinL,0);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  Serial.println(clawState);
  clawState = 1; //set to 1 to reset claw
  armState = 1;  //set to 1 to reset arm
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
  
  case '7':
  {
    Serial.println("Leftish");
    rightish();
    
  }break;
  
  case '8':
  {
    Serial.println("Rightish");
    leftish();
    
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
  delay(100);
}

void forward()
{

    
  speedL = 100;
  speedR = 100;
  dirL = 0;
  dirR = 0;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(100);
}

void reverse()
{
  speedL = 100;
  speedR = 100;
  dirL = 1;
  dirR = 1;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(100);
}

void leftish(){
   
  speedL = 75;
  speedR = 120;
  dirL = 0;
  dirR = 0;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(100);
}

void rightish(){
   
  speedL = 120;
  speedR = 75;
  dirL = 0;
  dirR = 0;
  digitalWrite(dirPinL,dirL);
  digitalWrite(dirPinR,dirR);
  analogWrite(speedPinL,speedL);
  analogWrite(speedPinR,speedR);
  delay(100);
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
  delay(100);
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
  delay(100);
}


void clawOpen()
{
  if(clawState == 0){
    claw.write(160);
    clawState = 1;
    delay(600);
  }else
  delay(100);
  
}

void clawClose()
{
  if(clawState == 1){
    claw.write(20);
    clawState = 0;
    delay(600);
  }else
  delay(100);
}

void armOpen()
{
  if (armState == 0){
    arm.write(0);
    armState = 1;
    delay(1250);
  }else {
  delay(100);
  }
}

void armClose()
{
  if (armState == 1){
    arm.write(180);
    armState = 0;
    delay(1250);  
  }else{
  delay(100);
  }
}

void clawStore()
{
  armClose();
  clawClose();
}



