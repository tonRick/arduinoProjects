
 int buttonState = 0;
 int onOff = LOW;
 int timer;
 int preTimer;
 int difTime;
 int prevState = 0;

void setup() {
pinMode(13,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 timer = millis();
 buttonState = digitalRead(13);

 if((prevState == 1) and (buttonState == 0) and (timer-preTimer > 50))
 {
  onOff = !onOff;
  Serial.println(onOff);
  preTimer = timer;
 }
prevState = buttonState;
}
