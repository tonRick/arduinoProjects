
//Example code showing the effects of variable type on output
//Daniel Godrick
//Written: 9/14/2016

//The circuit is just the potentiomenter
//5V one side pin, ground the pin on the other side, 
//A0 pin connected to middle

//Start the Serial monitor
//Pin to 14 is another way to call pin A0

void setup() {
  pinMode(14,INPUT);
  Serial.begin(9600);
}

void loop() {
//First read the pin A0 (pin 14 is pin A0)
  int potRead = analogRead(14);
  
//Display the raw reading to the user
  Serial.print("Sensor = ");
  Serial.print(potRead);
  Serial.print("\t");

//Next try math with integers, multiplying by 180 first
  int angle1 = potRead*180/1023;
  Serial.print("Angle1 = ");
  Serial.print(angle1);
  Serial.print("\t");
//What happens? What happens is the biggest number an integer can
//be in Arduino is 32767, since your reading *180 is often bigger
//than this, the numbers "wrap", or become negative. 

//Now Try dividing first  
  int angle2 = potRead/1023*180;
  Serial.print("Angle2 = ");
  Serial.print(angle2);
  Serial.print("\t");

//What happens now? The reading/1023 is less than one for almost
//all numbers. The numbers get truncated to 0, unless the reading is 
//1023, then the angle is set to 180

//Try this:
  double potA = (double)potRead;
  double angle3 = potA/1023*180;
  Serial.print("Angle3 = ");
  Serial.print(angle3);
  Serial.print("\n");

// Now you should see results that "make sense". You are using
// a variable type that has enough memory to do the math 
// that you would like to do. But at a cost (memory)! 

//delay at the end to slow things down a bit!
  delay(250);
  
}
