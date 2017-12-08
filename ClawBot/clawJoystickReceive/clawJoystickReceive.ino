
//Script Written by Dan Godrick
//Dec 2014
//Using Jeremy Blum's Exploring Arduino as a baseline


//Variable declarations - Red, Green, Blue values will be used to 
//control intensity and color. Pins 3,5,6 will be used as PWM control

//Define Control Pins
const int dirPinL = 12;
const int dirPinR = 13;
const int speedPinL = 3;
const int speedPinR = 11;
const int clawPin = 9;
const int armPin = 10;


int perL = 0;
int perR = 0;
int dirL = 0;
int dirR = 0;
int clawState = 0; //claw 0 closed, 1 open
int armState = 0; //arm 0 stored, 1 deployed
int readVar = 0; //Initialize readVar to 0. Stop and Store


int readVal1 = 50;
int readVal2 = 0;
int readVal1p = 0;
int readVal2p = 0;


void setup()
{
  Serial.begin(115200); //set for Bluetooth communication
  Serial.println("Please enter 2 numbers separated by commas");
  digitalWrite(dirPinR,0); //Low is forward
  digitalWrite(dirPinL,0); //Low is forward
  analogWrite(speedPinL,perL);
  analogWrite(speedPinR,perR);
}

void loop()
{
  getData(); //First get the data from the Bluetooth

}

void getData(){
  while (Serial.available()>0) //If there is information available
  {
    readVal1=  Serial.parseInt();
    readVal2 = Serial.parseInt();
    if (Serial.read() == '\n') //newline sets values
    {
      Serial.print(readVal1);
      Serial.print(",");
      Serial.print(readVal2);      
    }
      setDirection();
      setSpeeds();
  }
}

void setDirection(){
  if (readVal1 >= 0){
    digitalWrite(dirPinR,0); //Low is forward
  } else if (readVal1 < 0){
    digitalWrite(dirPinR,1); //1 is Reverse
  }
  if (readVal2 >= 0){
    digitalWrite(dirPinL,0); //Low is Forward
  }else if (readVal2 < 0){
    digitalWrite(dirPinL,1); //High is reverese
  }
}

void setSpeeds(){
  readVal1 = abs(readVal1);//only interested in magnitude 
  readVal2 = abs(readVal2);//only interested in magnitude 
  readVal1 = map(readVal1, 0,50,0,250); // map to make quicker
  readVal2 = map(readVal2, 0,50,0,250); // map to make quicker
  
  perL = readVal1;
  perR = readVal2;
  Serial.print('\t');
  Serial.print(perL);
  Serial.print(",");
  Serial.println(perR);
  analogWrite(speedPinL,perL);
  analogWrite(speedPinR,perR);
}

