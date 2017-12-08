
const int button = 12;

void setup(){
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop(){
  boolean onOff = digitalRead(button);
  Serial.println(onOff);
  delay(50);
}
