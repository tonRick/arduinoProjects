void setup() {
  Serial.begin(9600);
  pinMode(14,INPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(9,0);
  analogWrite(11,0);

}

void loop() {
  int pressure = analogRead(14);
  pressure = 1023 - pressure;
  //pressure = map(pressure,0,1023,0,255);
  Serial.println(pressure);
  delay(5); //make it run quickly, but not too quickly
  if (pressure <= 10){
    analogWrite(11,0);
    analogWrite(9,0);
   }else if (pressure < 245){
    analogWrite(11,0);
    analogWrite(9,pressure);
   }else {
    analogWrite(11,200);
    analogWrite(9,0);
   }
}
