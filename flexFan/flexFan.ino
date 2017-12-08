int prevReading = 0;
int reading = 0;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(14,INPUT);
  Serial.begin(9600);
  digitalWrite(13,LOW); //Set low to start
}

void loop() {
  int reading = analogRead(14);
  if(abs(reading-prevReading) > 10){
    Serial.println(reading);
  }
  if(reading < 250){
    digitalWrite(13,HIGH);
    delay(20000);
  } else{
    digitalWrite(13,LOW);
  }
  prevReading = reading;
  
}
