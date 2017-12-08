

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char led = Serial.read();
  if(led == '0'){
    digitalWrite(13,HIGH);
  }else if(led =='1'){
   digitalWrite(13,LOW); 
  }
}
