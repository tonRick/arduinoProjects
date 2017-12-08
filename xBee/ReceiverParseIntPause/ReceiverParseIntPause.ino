
//Sketch to read Serial Data

const int ledPin = 9;


void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
  
  
void loop(){
  static int onOff = 0;
  static int val = 0;
  int exDat = 0;
  Serial.setTimeout(100);
  if (Serial.available())
  {
    onOff= Serial.parseInt();
    val = Serial.parseInt();
    while(Serial.available())
      {
      exDat = Serial.read();
      }
  }
  if (onOff == 0)
  {
    val = 0;
    val = constrain(val,0,255);
    val = map(val,0,255,255,0);
  
    analogWrite(ledPin,val);
    Serial.print(onOff);
    Serial.print(',');
    Serial.println(val);
    delay (100); 
  }else if (onOff != 0)
  {
    val = 255;
    val = constrain(val,0,255);
    val = map(val,0,255,255,0);
  
    analogWrite(ledPin,val);
    Serial.print(onOff);
    Serial.print(',');
    Serial.println(val);
    delay (1000); 
    onOff = 0;
    val = 255;
  }
  
      
  
}
