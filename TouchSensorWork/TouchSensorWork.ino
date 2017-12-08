
//Sticky touchSensor for Halloween
//By Dan Godrick
//10/31/2016

//Demonstrates one way to keep values from a touchsensor

 
 int value = 0; // read from a touch sensor, but could be anything
 int prev = 0;  // previous value
 int set = 0;   // set value (used for stickyness)
 bool released = 0; //boolean variable to see when the sensor is released (need to know release)
 

 
void setup() {
  Serial.begin(9600); //Serial for logic analysis
  //pinMode(13,OUTPUT); not necessary, used for debugging
  pinMode(14,INPUT);
  

}

void loop() {
  delay(1000); //slowed the code down so I could understand it
  int value = analogRead(14);// reading from the touchsensor

  //First the case before the touch sensor was pushed for the first time
  if((value == 0) && (prev ==0)){
    released = 0;
  }

  //now if there is a value of zero and the previous was non-zero, the sensor was pushed 
  //at some point. If this is the case, then stick the previous value into the set variable
  else if((value == 0)&& (prev != 0)){
    released = 1;// if the current value is 0, and the previous is != then the button is released
    set = prev;
  }
  
  //If the button is still being pushed, set the value to the current value for user feedback
  else if(value != 0){
    released = 0;
    set = value;
  }

//Print out the values and see how it performs
  Serial.print(value);
  Serial.print("\t");
  Serial.print(prev);
  Serial.print("\t");
  Serial.print(released);
  Serial.print("\t");
  Serial.println(set);
  prev = value;
  
}
