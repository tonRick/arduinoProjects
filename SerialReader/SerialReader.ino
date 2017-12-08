
int stateVar = 0;
int readVal1 = 0;
int readVal2 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {

  while (Serial.available()>0) //If there is information available
  {
    stateVar =  Serial.parseInt();
    readVal1 =  Serial.parseInt();
    readVal2 =  Serial.parseInt();
    if (Serial.read() == '\n') //newline sets values
    {
      Serial.print(stateVar);
      Serial.print(",");
      Serial.print(readVal1);
      Serial.print(",");
      Serial.println(readVal2);      
    }
  }
}
