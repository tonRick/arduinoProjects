
//Attach to pin 2

const int pingPin = 2;
float v = 331.5 + 0.6*20;//m/s used to convert to distance

void setup() {
  Serial.begin(115200);//Fast for fast response
  //pinMode switches from write to read, so in Loop
}

void loop() {
  int d = distanceCm();
  Serial.println(d,DEC);
  delay(200);
  
}

float distanceCm(){
//Send Pulse  
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin,LOW);
  delayMicroseconds(3);// Let Pin settle
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(5); //5 musec beep - from instructions
  digitalWrite(pingPin,LOW);

//Receive Pulse
  pinMode(pingPin,INPUT);
  float tUs = pulseIn(pingPin,HIGH); //measures time for pin to low
  float t = tUs / 1000.0/1000.0/2; //convert to seconds
  float d = t*v;//m
  return d*100;

}

