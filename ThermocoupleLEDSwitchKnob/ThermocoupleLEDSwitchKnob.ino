//Thermocouple breakout board test. 
// The example code was used as a baseline for this testing. 

//SS    pin 10 (slave select)
//Mosi  Pin 11 - only slave so not connected
//Miso  Pin 12
//SCK   Pin 13

//Example used VCC as pin 14 (ao -) I tried with 3.3V source
//but readings were a little higher than expected. 

//GND Example used pin 15, but GND works

#include <SparkFunMAX31855k.h>
#include <SPI.h> // needed for SPI communications

const int CS = 10;
const int VCC = 14;
const int GND = 15; //Set ground to be pin 15 for geometry
const int LEDPin = 2;
const int tailPin =3;
const int potPin = A3;
//Other pins are defined for SPI communication 

//Uses pin 15 for Ground - geometry
SparkFunMAX31855k probe(CS,VCC,GND);
float tempF; 
bool  ySis;//1 means hot, 0 means cool
float ySisBand = 2.5; //sets the hysterisis band 
float setPoint = 75; // default

void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(tailPin,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
  Serial.println("\nStart\n");
  delay(50); //for settling
}

void loop() {
  getSetPoint();
  getCJT();
  getTempF();
  testTemp();
  delay(50); 
}

void getSetPoint(){
  int potRead = analogRead(potPin);
  setPoint = map(potRead,0,1023,65,95); 
  Serial.print(setPoint);
}
  
void testTemp(){
//Add Hysterisis functionality. First test if it's cool? 
if (ySis == 0){
 if (tempF > (setPoint + ySisBand)){
    digitalWrite(LEDPin,HIGH);
    digitalWrite(tailPin,HIGH);
    ySis = !ySis;
  }else{
    digitalWrite(LEDPin,LOW);
    digitalWrite(tailPin,LOW);
  }
}else if (ySis == 1){
  if (tempF < (setPoint - ySisBand)){
    digitalWrite(LEDPin,LOW);
    digitalWrite(tailPin,LOW);
    ySis = !ySis;
  }else{
    digitalWrite(LEDPin,HIGH);
    digitalWrite(tailPin,HIGH);
  }
 }
}

void getCJT(){
    tempF = probe.readCJT();//read the CJT
  if (!isnan(tempF)){
    Serial.print ("\tCJT Temp (C) = ");
    Serial.print(tempF);
  }
}

void getTempF(){
  tempF = probe.readTempF();//read the probe
  if (!isnan(tempF)){
    Serial.print("\t TempF = ");
    Serial.print(tempF);
    Serial.print("\t HotOrNot= ");
    Serial.println(ySis);

  }  
}

