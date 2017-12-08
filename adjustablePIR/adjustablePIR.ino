
/*Very Easy Project to ensure that a PIR sensor works appropriately
The PIR sensor itself is a bit tricky, so it is nice to have some 
simple code to check the functionality and get it working

The Sparkfun PIR is worth the extra cost! 
https://www.sparkfun.com/products/13285

Other PIR sensors (10 for $10) have proven to have many defects

Dan Godrick
9.12.2016

*/


int pirPin = 2; //digital 2

void setup(){
 Serial.begin(9600); 
 pinMode(pirPin, INPUT);
 pinMode(13,OUTPUT);
}


void loop(){
  int pirVal = digitalRead(pirPin);

  if(pirVal == HIGH){ //was motion detected
    Serial.println("Motion Detected"); 
    digitalWrite(13,HIGH);
    delay(2000); 
  } 
    digitalWrite(13,LOW);
  

}
