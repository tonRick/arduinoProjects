
/*10/27/2015
Motion 2 Workshop

Written by Dan Godrick

Sparkfun MotorShield 
QRD1114 light sensors

*/


//Declare variables

const int dirPin1 = 13;//DirB left motor
const int dirPin2 = 12;//DirA right motor
const int pwmPin1 = 11;//PWMB left motor speed
const int pwmPin2 = 3; //PWMA right motor speed

const int lReadPin = 14;//a0 left sensor
const int mReadPin = 15;//a1 middle sensor
const int rReadPin = 16;//a2 right sensor


void setup()
{
  //Set PinMode to OUTPUT)
  pinMode(dirPin1,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(pwmPin1,OUTPUT);
  pinMode(pwmPin2,OUTPUT);

  //Set read pins to INPUT
  pinMode(lReadPin,INPUT);
  pinMode(mReadPin,INPUT);
  pinMode(rReadPin,INPUT);
  
  Serial.begin(9600);

  //Check sensors
  Serial.print("Left");
  Serial.print("\t");
  Serial.print("Mid");
  Serial.print("\t");
  Serial.println("Right");
}

void loop()
{
  getSensorData(); //function to get sensor data
  //testMotion();
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
  int lRead = analogRead(lReadPin);
  int mRead = analogRead(mReadPin);
  int rRead = analogRead(rReadPin);
  Serial.print(lRead);
  Serial.print("\t");
  Serial.print(mRead);
  Serial.print("\t");
  Serial.println(rRead);
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
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  analogWrite(pwmPin1,128);
  analogWrite(pwmPin2,128);
  delay(2000);
}

void goBack()
{
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);
  analogWrite(pwmPin1,128);
  analogWrite(pwmPin2,128);
  delay(2000);
}

void turnLeft()
{
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,HIGH);
  analogWrite(pwmPin1,128);
  analogWrite(pwmPin2,128);
  delay(500);
}

void turnRight()
{
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
  analogWrite(pwmPin1,128);
  analogWrite(pwmPin2,128);
  delay(500);
}

void pause()
{
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  digitalWrite(pwmPin1,LOW);
  digitalWrite(pwmPin2,LOW);
  delay(2000);
}
