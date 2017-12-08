void setup() {
  Serial.begin(9600);
  pinMode(14,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  int sensorVal = analogRead(14);
  Serial.println(sensorVal,DEC);//send a decimal to processing
  if (sensorVal < 100){ // above threshold turn on green light
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }else{ //below threshold - make red LED brighter  
    sensorVal = map(sensorVal, 0, 1023, 0, 50); //for light
    digitalWrite(9,LOW);
    analogWrite(10,50-sensorVal);
    }
  delay(5);
}
