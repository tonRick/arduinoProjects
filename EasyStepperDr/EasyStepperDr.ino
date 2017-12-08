/*This code controls a stepper motor with the 
EasyDriver board. It spins forwards and backwards
***************************/
int dirPin = 2;
int stepPin = 3;

void setup() 
{
pinMode(dirPin, OUTPUT);
pinMode(stepPin, OUTPUT);
}
void loop()
{

  int ii;

  digitalWrite(dirPin, LOW);     // Set the direction.
  delay(100);


  for (ii = 0; ii<4000; ii++)       // Iterate for 4000 microsteps.
  {
    digitalWrite(stepPin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(stepPin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(500);      // This delay time is close to top speed for this
  }                              // particular motor. Any faster the motor stalls.

  digitalWrite(dirPin, HIGH);    // Change direction.
  delay(100);


  for (ii = 0; ii<4000; ii++)       // Iterate for 4000 microsteps
  {
    digitalWrite(stepPin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(stepPin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(500);      // This delay time is close to top speed for this
  }                              // particular motor. Any faster the motor stalls.

}
