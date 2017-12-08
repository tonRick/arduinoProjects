/* Interactive LED Project
 Example code for ENG1400 Interactive LED
 
 Code modified by: D. Godrick
 Using example from B. Huang at SparkFun
 Date: 08/22/14
 
 */
 
int sensorPin = A0;

void setup(){
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);  //needed to communicate
}                       

void loop(){
  int potLevel = analogRead(sensorPin); 
  Serial.print("Sensor value =");    
  Serial.print(potLevel);             
  Serial.println();                  
}

