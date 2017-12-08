void setup() {
 
  pinMode(A0, INPUT);
  Serial.begin(9600); // needed to communicate
}

void loop() {
 
  int sensorLevel = analogRead(A0);
  Serial.print("Sensor Value = ");
  Serial.print(sensorLevel);
  Serial.println();
}
