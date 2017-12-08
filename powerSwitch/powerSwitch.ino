void setup() {
  pinMode(14,INPUT);
  pinMode(13,OUTPUT);
 
}

void loop() {
int lightVar = analogRead(14);
Serial.println(lightVar);
if(lightVar >300){
  digitalWrite(13,LOW);
} else if 

  
}
