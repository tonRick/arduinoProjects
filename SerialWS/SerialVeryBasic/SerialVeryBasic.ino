//Quick sketch to demonstrate the basics of Serial Communication

void setup()
{
  Serial.begin(9600); //Start Serial
}

void loop()
{
  int value = Serial.read(); //read from the Serial Monitor
  Serial.println(value); //Display the vvalue
  delay(1000); //Delay for readability
  
}
