
const int pot = 0;

int val;
//int timeStart=millis();
int timeLast = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int timeNow = millis();
  if((timeNow - timeLast) >= 1000){ 
    val = map(analogRead(pot),0,1023,0,255);
    Serial.print(timeNow);
    Serial.print(", ");
    Serial.println(val);
    timeLast = timeNow;
 }
}
