/*Xbee send sketch

Daniel Godrick
1/8/2015

Simple send and receive xBee sketch. These sketches were 
made by modifying sketches from Exploring Arduino by Jeremy Blum

*/
const int button = 12; //define button pin

void setup(){
  pinMode(button, INPUT); //the button will be an input
  Serial.begin(9600); //start a serial line of communication
}

void loop(){
  int onOff = digitalRead(button);//this should read 1 if pressed and 0 if not
  Serial.println(onOff);//Should read '1' if pressed, '0' if not
  delay(50); //delay for readability
}
