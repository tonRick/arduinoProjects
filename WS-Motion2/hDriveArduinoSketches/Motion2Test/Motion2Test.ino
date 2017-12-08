
/*10/27/2015
Motion 2 Workshop

Written by Dan Godrick

Sparkfun MotorShield 
QRD1114 light sensors

*/


//Declare variables

//OUPUT Pins
const int lDirPin = 13;   //DirB left motor
const int rDirPin = 12;   //DirA right motor
const int lSpeedPin = 11; //PWMB left motor speed
const int rSpeedPin = 3;  //PWMA right motor speed

//INPUT Pins
const int lReadPin = 14;//a0 left sensor
const int mReadPin = 15;//a1 middle sensor
const int rReadPin = 16;//a2 right sensor


void setup()
{
  //Set PinMode to OUTPUT)
  pinMode(lDirPin,OUTPUT); 
  pinMode(rDirPin,OUTPUT);
  pinMode(lSpeedPin,OUTPUT);
  pinMode(rSpeedPin,OUTPUT);

  //Set read pins to INPUT
  pinMode(lReadPin,INPUT);
  pinMode(mReadPin,INPUT);
  pinMode(rReadPin,INPUT);

  //Start Serial for debugging and readings
  Serial.begin(9600);

  //Print header for sensors check
  Serial.print("Left");
  Serial.print("\t");
  Serial.print("Mid");
  Serial.print("\t"); 
  Serial.println("Right");
}

void loop()
{
  getSensorData(); //function to get sensor data
  testMotion();
  //doARectangle(); //function to check motors
}

void doARectangle()
{
  delay(2000);
  goForward();
  pause();
  turnLeft();
  pause();
  goForward();
  pause();
  turnLeft();
  pause();
  goForward();
  pause();
  turnLeft();
  pause();
  goForward();
  delay(10000);
}

void getSensorData()
{
  for (int ii = 0; ii <=300; ii++){
  int lRead = analogRead(lReadPin);
  int mRead = analogRead(mReadPin);
  int rRead = analogRead(rReadPin);
  Serial.print(lRead);
  Serial.print("\t");
  Serial.print(mRead);
  Serial.print("\t");
  Serial.println(rRead);
  delay(10);
  }
}

void testMotion()
{
  delay(2000);
  goForward();
  pause();
  turnLeft();
  pause();
  goForward();
  pause();
  turnRight();
  pause();
  goBack();
  pause();
}

void goForward()
{
  digitalWrite(lDirPin,LOW);
  digitalWrite(rDirPin,LOW);
  analogWrite(lSpeedPin,128);
  analogWrite(rSpeedPin,128);
  delay(2000);
}

void goBack()
{
  digitalWrite(lDirPin,HIGH);
  digitalWrite(rDirPin,HIGH);
  analogWrite(lSpeedPin,128);
  analogWrite(rSpeedPin,128);
  delay(2000);
}

void turnLeft()
{
  digitalWrite(lDirPin,LOW);
  digitalWrite(rDirPin,HIGH);
  analogWrite(lSpeedPin,128);
  analogWrite(rSpeedPin,128);
  delay(500);
}

void turnRight()
{
  digitalWrite(lDirPin,HIGH);
  digitalWrite(rDirPin,LOW);
  analogWrite(lSpeedPin,128);
  analogWrite(rSpeedPin,128);
  delay(500);
}

void pause()
{
  digitalWrite(lDirPin,LOW);
  digitalWrite(rDirPin,LOW);
  digitalWrite(lSpeedPin,LOW);
  digitalWrite(rSpeedPin,LOW);
  delay(2000);
}
