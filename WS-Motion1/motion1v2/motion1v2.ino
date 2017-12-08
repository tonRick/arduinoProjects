
void setup ()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() 
{
  analogWrite(3,10);
  analogWrite(5,50);
  analogWrite(6,255);
  
  digitalWrite(12,HIGH);
  delay(1);
  digitalWrite(12,LOW);
  delay(4);
//  for (int ii = 100; ii > 0; ii--)
//  {
//    digitalWrite(12,HIGH);
//    delay(ii*5);
//    digitalWrite(12,LOW);
//    delay(ii*5);
//  }
}
