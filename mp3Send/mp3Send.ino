/*Xbee send sketch

Daniel Godrick
1/8/2015

Simple send and receive xBee sketch. These sketches were 
made by modifying sketches from Exploring Arduino by Jeremy Blum

*/
const int button = 12; //define button pin
int prev = 0;

void setup(){
  pinMode(button, INPUT); //the button will be an input
  Serial.begin(9600); //start a serial line of communication
}

void loop(){
  int onOff = digitalRead(button);//this should read 1 if pressed and 0 if not
  if( onOff == 1 && prev == 0){
  Serial.println(onOff);//Should read '1' if pressed, '0' if not
  delay(1000);
  //Serial.println("0");
  }
  delay(50); //delay for readability
  prev = onOff;
}
