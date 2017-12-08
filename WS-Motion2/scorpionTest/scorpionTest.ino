
/* Sensor test code
Written by Dan Godrick
April 16, 2015

The eScorpion robots were designed by Jared Wampler and Daniel Godrick
These were assembled, built and tested by Lauren Darling
and Bennett Salvesen.

Special thanks to the Engineering Excellence Fund and the ITL for
providing the funds necessary for this workshop!

*/


//Motor Pins
const int LM_pin = 3;  //Pin for Left Motor PWM 
const int RM_pin = 11; //Pin for Right Motor PWM
const int LM_dir = 12; //Pin for Left Motor Direction
const int RM_dir = 13; //Pin for Right Motor Direction

//Sensor Pins
const int irPinLeft = 14;
const int irPinCenter = 15;
const int irPinRight = 16;

//Sensor variables
int leftVal; //Variable for reading left sensor
int centerVal; //Variable for reading center sensor
int rightVal; //Variable for reading right sensor



void setup()
{
  //Start Serial
  Serial.begin(9600);
  
  //Set Output Pins
  pinMode(LM_pin,OUTPUT); 
  pinMode(RM_pin,OUTPUT);
  pinMode(LM_dir,OUTPUT); 
  pinMode(RM_dir,OUTPUT);
  
  //Set Input pins
  pinMode(irPinLeft,INPUT); 
  pinMode(irPinCenter,INPUT);
  pinMode(irPinRight,INPUT);
  
  
  //test the motor in setup
  delay(2000); //delay to make sure wheels are off ground
  //motorTest(); 
  
}

void loop()
{
  //After motor tested one time, test sensors
  //Typical readings are 900-1100 for unblocked, 
  // and 250-500 for blocked
  sensorTest();
  
}

void sensorTest()
{
   //Read Sensors
  leftVal = analogRead(irPinLeft);
  centerVal = analogRead(irPinCenter);
  rightVal  = analogRead(irPinRight);
  
  //Display in Serial
  Serial.print(leftVal);
  Serial.print("   ");
  Serial.print(centerVal);
  Serial.print("   ");
  Serial.println(rightVal);
  
  //Wait a little bit
  delay(100);
}
  

void motorTest()
{
 forwardTest();
 reverseTest();
}

void forwardTest()
{
  //Direction Pins Low, forward
  digitalWrite(LM_dir,LOW);
  digitalWrite(RM_dir,LOW);
  lmGo();
  rmGo();
}
void reverseTest()
{
  //Direction Pins HIGH, Reverse
  digitalWrite(LM_dir,HIGH);
  digitalWrite(RM_dir,HIGH);
  lmGo();
  rmGo();
}

void lmGo()
{

  //The for loop spools up the motor.  
  //Important, only go to 170 - do not stress the motor

  
  for(int ii = 0; ii<170; ii++)
  {
    analogWrite(LM_pin,ii);
    delay(50);
  }
  digitalWrite(LM_pin,0); // Once finished, shut off
}

void rmGo()
{
 //The for loop spools up the motor.  
 //Important, only go to 170 - do not stress the motor
 
  for(int ii = 0; ii<170; ii++)
  {
    analogWrite(RM_pin,ii);
    delay(50);
  }
  digitalWrite(RM_pin,LOW);
}
