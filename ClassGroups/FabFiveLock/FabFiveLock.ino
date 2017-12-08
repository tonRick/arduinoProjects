void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  char lock=  Serial.read();
  if (lock == '1')
    {//Serial.print("line");
    digitalWrite(13,HIGH);
    delay(7000);
    digitalWrite(13,LOW);
    
  }else if (lock == '0'){
    digitalWrite(13,LOW);
  }
}}

