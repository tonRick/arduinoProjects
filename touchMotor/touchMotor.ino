
int touchVal = 0;
const int touchPin = 14;
const int motorPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(touchPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int ii = 20; ii <255; ii++){
    analogWrite(motorPin,ii);
    touchVal = analogRead(touchPin);
    Serial.println(touchVal);
    delay(50);
  }
  digitalWrite(motorPin,LOW);
  delay(1000);
  

}
