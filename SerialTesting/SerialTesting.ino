
int LED = 13;
int inByte = 0;
int blinkTimer = 0;
int blinkInterval = 500;

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() >0) {
    inByte = Serial.read();
    inByte ++;
    Serial.write(inByte);
  }
  if(millis() - blinkTimer >= blinkInterval/2){
    digitalWrite(LED,HIGH);
  }
  if (millis() - blinkTimer >= blinkInterval){
    digitalWrite(LED,LOW);
    blinkTimer = millis();
  }
}
