void setup() {
 pinMode(3,OUTPUT);

}

void loop() {
  digitalWrite(3,HIGH);
  delayMicroseconds(900);
  digitalWrite(3,LOW);
  delayMicroseconds(900);
  
}
