
/*
 * Intro Workshop with Photo Sensitive Resistor
 * Daniel Godrick
 */

const int sensor = 14; //14 is A0
const int LEDPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(LEDPin,OUTPUT);
}

void loop() {
  int value = analogRead(sensor);
  Serial.print("Light Level is: ");
  Serial.print(value);
  Serial.println();
  digitalWrite(LEDPin,1);
  delay(value);
  digitalWrite(LEDPin,0);
  delay(value);
  
}
