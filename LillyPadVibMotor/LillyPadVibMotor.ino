void setup() {
  // put your setup code here, to run once:
 pinMode(A2,OUTPUT);
 Serial.begin(9600);
 
}

void loop() {
  for(int ii = 0; ii < 255; ii++){
    analogWrite(A2,ii);
    delay(5);
  }
    
}
