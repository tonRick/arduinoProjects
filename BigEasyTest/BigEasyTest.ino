
/*Big Easy Driver Code
  Written by Dan Godrick
  11/18/2016

This code is intended to get the Big Easy Stepper driver from SparkFun
https://www.sparkfun.com/products/12859

working quickly and easily

*/


//Define pins for stepping and direction

#define dirPin 13
#define stepPin 2

int dir = 0;

void setup() {  
  Serial.begin(115200);
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(dirPin,dir); //set the initial Direction
  digitalWrite(stepPin,LOW); // initialize the stepPin to low
}

void loop() {

//20 rotations
 for (int ii = 0; ii< 2; ii++){
  oneForward();
  delay(100); //wait a touch before reversing
 }
  oneBack();
  delay(500); //wait a bit before going forward again. 
    
}

//one revolution
void oneForward(){
   //Set the direction on the board at the start 

  for(int ii = 0; ii <=3200; ii++){
    digitalWrite(dirPin, HIGH);
    stepOnce(); //step one time
    
  }
}

void oneBack(){
  
  for(int ii = 0; ii <=3200; ii++){
    digitalWrite(dirPin,LOW); //reverse direction
    stepOnce(); //step one time
    //Serial.println(ii);
  }
}

void stepOnce(){
  digitalWrite(stepPin,HIGH); //The rising edge of the High causes the motor to step
  delayMicroseconds(200); //slow forward
  digitalWrite(stepPin,LOW); // set back to low to get ready for the next step
  delayMicroseconds(200); //slow forward
  //good to delay to let the motor respond
}

