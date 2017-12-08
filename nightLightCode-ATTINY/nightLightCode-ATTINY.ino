
/*Example code for miniturization workshop
This code reads a value from a flex sensor and 
uses this to control the intensity of an LED

Tiny Migrates the code to an ATTiny 85

4/11/2017
Dan Godrick
*/

//Define your pins for output
int aInput = A2; //Pin 
int LEDpin = 0;  //Make sure to choose a pin that can PWM!

//Initialize math variables
int reading = 0;
int intensity = 0;

void setup() {
  //Serial.begin(9600);//No Serial on Tiny 
  pinMode(aInput,INPUT);
  pinMode (LEDpin,OUTPUT);
}

void loop() {
  //Get readings fron the flex sensor
  reading = analogRead(aInput);
  // if the reading is below 200, there is no need for light
  if (reading <=300){
    digitalWrite(LEDpin,LOW);
  } 
  //if the reading is >200, we want the light on a varying intensity
  else
  {
  //Based off of my circuit, the light readings vary from 0 to about 755
  intensity = map(reading, 0,800,0,255);
  
  //Serial.print("LED PWM = "); //No Serial on Tiny
  //Serial.println(reading);    //No Serial on Tiny
  analogWrite(LEDpin,intensity);
  }
  
}
