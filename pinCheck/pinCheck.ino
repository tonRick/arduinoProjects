void setup() 
{
  for(int ii = 0; ii<14; ii++)
  {
    pinMode(ii,OUTPUT);
  }

}

void loop() 
{
 for(int ii = 0; ii<14; ii++){
  digitalWrite(ii,HIGH);
  
 }delay(500);
 for(int ii = 0; ii<14; ii++){
  digitalWrite(ii,LOW);
 
 } delay(500);

}
