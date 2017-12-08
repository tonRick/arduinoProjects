
//Demonstrate the use of Serial.parseInt

void setup()
{
  Serial.begin(9600); //start serial communications
}

void loop()
{
  int value = Serial.parseInt(); //get value from the serial buffer
  Serial.println(value);
  delay(1000);
}


