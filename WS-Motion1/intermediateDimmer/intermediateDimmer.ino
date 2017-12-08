
int writePin = 11;

void setup(){
  pinMode(11,OUTPUT);
}

void loop(){
  int ii = 0;
  for (ii == 0; ii <= 255; ii++){
    analogWrite(writePin,ii);
    delay(10);
  }
}
