
 int onOff = LOW;
 int  timer;
 int preTimer;
 int difTime;
 int prevState = 0;
 int counter = 0;

void setup() {
pinMode(3,INPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int of = buttonCheck();
  digitalWrite(4,of);
  
}

int buttonCheck(){
  
 timer = millis();
 int buttonState = digitalRead(3);

 if((prevState == 1) and (buttonState == 0) and (timer-preTimer > 10))
 {
  onOff = !onOff;
  //Serial.println(onOff);
  preTimer = timer;
 }
 
  prevState = buttonState;
  return(onOff);
}

