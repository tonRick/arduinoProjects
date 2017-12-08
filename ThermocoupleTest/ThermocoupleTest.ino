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
//Other pins are defined for SPI communication 

//Doesn't use pin 15 for Ground
SparkFunMAX31855k probe(CS,VCC,NONE);
float tempF;

void setup() {
  Serial.begin(9600);
  Serial.println("\nStart\n");
  delay(50); //for settling
}

void loop() {
  getCJT();
  getTempF();

  delay(50); 
}

void getCJT(){
    tempF = probe.readCJT();//read the CJT
  if (!isnan(tempF)){
    Serial.print ("CJT Temp (C) = ");
    Serial.print(tempF);
  }
}

void getTempF(){
  tempF = probe.readTempF();//read the probe
  if (!isnan(tempF)){
    Serial.print("\t TempF = ");
    Serial.println(tempF);
  }  
}

