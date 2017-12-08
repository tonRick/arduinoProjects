void setup() {
  // put your setup code here, to run once:
  pinMode(14,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pressureVal = analogRead(14);
  Serial.println(pressureVal);
}
