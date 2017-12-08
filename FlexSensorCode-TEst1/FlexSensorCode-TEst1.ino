
/*Example code for miniturization workshop
This code reads a value from a flex sensor and 
uses this to control the intensity of an LED

Tiny Migrates the code to an ATTiny 85

4/11/2017
Dan Godrick
*/

//Define your pins for output
int aInput = A1; //Pin 
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
  reading = reading - 777; //Subtract offset
  
  //Based off of my circuit, the readings start near 255 and get lower with more flex
  //Therefore I used the constrain command to set the instensity of my LED
  //I also used 1/2 of the 
  
  intensity = map(reading, 0,1023,0,255);
  
  //Serial.print("LED PWM = "); //No Serial on Tiny
  //Serial.println(reading);    //No Serial on Tiny
  analogWrite(LEDpin,intensity);
  //delay(100);
  
  
}
