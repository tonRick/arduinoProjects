
 int onOff = LOW;
 int  timer;
 int preTimer;
 int difTime;
 int prevState = 0;
 int counter = 0;
 uint32_t dataTimer = 0;
 int dataTimeInterval = 1000;
 uint32_t dataPreTimer = 0;
 
void setup() {
pinMode(3,INPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int of = buttonCheck();
  digitalWrite(4,of);
  getData(of);
  
  
}

int buttonCheck(){
  
 timer = millis();
 int buttonState = digitalRead(3);

 if((prevState == 1) and (buttonState == 0) and (timer-preTimer > 30))
 {
  onOff = !onOff;
  //Serial.println(onOff);
  preTimer = timer;
 }
 
  prevState = buttonState;
  return(onOff);
}

void getData(int of){
  dataTimer = millis();
  if((of == 1) and (dataTimer - dataPreTimer >= dataTimeInterval)){
    Serial.print(dataTimer);
    Serial.print(" ");
    Serial.println(counter);
    counter++;
    dataPreTimer = dataTimer;
    //delay(1000);
  }
}

