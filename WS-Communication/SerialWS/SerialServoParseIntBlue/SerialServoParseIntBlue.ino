/* Serial Parse Sketch

This example sketch shows how to customize the Serial.parseInt
functions


Created by: Daniel Godrick
date: 12/15/2014

With help from the Arduino Cookbook, by Michael Margolis and 
the servo from the SparkFun inventors kit! 
Hook this servo up to 5v, gnd, and pin 9

Also - make sure that the serial monitor is set to "No Line Ending"

*/


#include <Servo.h>

const int servoPin = 9; //attach servo input to pin 9
Servo servo1;// create a servo 
int angle = 10; //intialize an angle variable. Servos often chatter at
// values of zero, so this is set to 10

void setup()
{
  Serial.begin(115200); //start serial communication
  servo1.attach(servoPin); //attach the servo to the servo pin
  servo1.write(angle); // move the servo to the default value
  Serial.setTimeout(100);
  
}

void loop ()
{
  if (Serial.available() >0 ) //This command ensures that data is available
  {
    angle  = Serial.parseInt(); //if there is integer data, get it!
  }
  
  //now, need to constrain the angle so that the servo doesn't break
  angle = constrain(angle,0,180);
  servo1.write(angle); //write the angle
  Serial.println(angle); //So we can see the data on the Serial monitor
  delay(100); // delay for readability
}
  
