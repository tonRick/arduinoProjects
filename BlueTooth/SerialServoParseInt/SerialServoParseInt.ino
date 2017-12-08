/* Serial Parse Sketch

This example sketch shows how to customize the Serial.parseInt
functions


Created by: Daniel Godrick
date: 12/15/2014

With help from the Arduino Cookbook, by Michael Margolis and 
the servo from the SparkFun inventors kit! 
Hook this servo up to 5v, gnd, and pin 9

Also - make sure that the Serial Monitor is set to "No Line Ending"

*/


#include <Servo.h>

const int servoPin = 9; //We will ttach servo input to pin 9
Servo servo1;// Create a servo 
int angle = 10; //Intialize an angle variable. Servos often chatter at
// values of zero, so this is set to 10

void setup()
{
  Serial.begin(9600); //Start serial communication
  servo1.attach(servoPin); //Attach the servo to the servo pin
  servo1.write(angle); // Move the servo to the default value
  //Serial.setTimeout(100);
  
}

void loop ()
{
 if (Serial.available() >0 ) //This command ensures that data is available
  {
    angle  = Serial.parseInt(); //If there is integer data, get it!
    //Now, need to constrain the angle so that the servo doesn't break
    angle = constrain(angle,0,180);
    servo1.write(angle); //Write the angle
    Serial.println(angle); //View the data on the Serial monitor
    delay(100); // Delay for readability
  
}
  

}
  
