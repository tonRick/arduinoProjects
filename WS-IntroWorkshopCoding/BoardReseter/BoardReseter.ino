void setup(){
  pinMode(13,OUTPUT);
}
void loop(){
  int ii = 0;
  for (int ii = 0; ii < 20; ii++){
    digitalWrite(13,HIGH);
    delay(ii*20);
    digitalWrite(13,LOW);
    delay(ii*10);
  }
}
