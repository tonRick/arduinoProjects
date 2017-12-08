//Daniel Godrick
//November 5, 2014

//This is a quick and dirty tester of the GPS functionality
// This utilizes the SparkFun shield and the Em-506 GPS chip

// The idea was proposed from the Arduino Workshop by Boxall

void setup(){
  Serial.begin(4800);
}

void loop(){
  byte a;
  if (Serial.available()>0)
  {a = Serial.read();
  Serial.write(a);
  }
}
