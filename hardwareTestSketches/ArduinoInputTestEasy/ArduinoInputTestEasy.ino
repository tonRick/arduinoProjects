/*
  ReadAnalogSignal
  This script reads an analog input on pin 0, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example is based off of code that is in the public domain.
 */

// the setup routine runs once 
void setup() {
  // we need to initialize serial communication at 9600 bits per second to talk with the Arduino:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // print out the value you read:
  Serial.println(sensorValue);
}
