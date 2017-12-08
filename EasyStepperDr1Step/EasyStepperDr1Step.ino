/*This code controls a stepper motor with the 
 * EasyDriver board for 1 step
 **************************/

//Only two pins are needed. This puts the EASY in EasyDriver. 
//I chose pins 2 and 3. 
int dirPin = 2;
int stepPin = 3;

//I needed to generate outputs from the Arduino to drive the stepper, 
//so I told Arduino that I needed the pinMode set to output 

void setup() 
{
pinMode(dirPin, OUTPUT); 
pinMode(stepPin, OUTPUT);
}
void loop()
{
 
  digitalWrite(dirPin, LOW);    // Set the direction. A HIGH goes the other way  
  digitalWrite(stepPin, LOW);   // This LOW to HIGH change is what creates the
  digitalWrite(stepPin, HIGH);  // "Rising Edge" so the easydriver knows to when to step.
  delayMicroseconds(500);        // This delay time is close to top speed for my
                                 // particular motor. Any faster the motor stalled.
}

//For more than one step - Try putting the code in a FOR loop! 
