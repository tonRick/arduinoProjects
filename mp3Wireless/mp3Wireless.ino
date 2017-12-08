/*Xbee receive sketch

Daniel Godrick
1/8/2015

Simple send and receive xBee sketch. These sketches were 
made by modifying sketches from Exploring Arduino by Jeremy Blum

*/

const int LED = 10;//attach LED to pin 13

char data = '0';//initialize as off

void setup(){
  Serial.begin(9600); //start the Serial line
  pinMode(LED,OUTPUT); //set the Led pin to output
  digitalWrite(LED,LOW); // turn LED off
}

void loop()
{
 if (Serial.available() > 0 ) //is there data?
  {
    data = Serial.read();//if there is, read the data
    
    if (data == '1')
    {
      digitalWrite(LED,LOW); //if there is a '1', turn the light on
    }
    else if (data =='0')
    {
      digitalWrite(LED,HIGH); //Turn off if '0'
    }
  }
}
  

