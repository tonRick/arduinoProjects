/* SD card sketch by Daniel Godrick with input from Sparkfun and
 *  the Arduino website
 *  October 20,2015
 */

#include <SPI.h>
#include <SD.h>

/* These libraries define the 
 *  MOSI  = pin 11 Master out slave in
 *  MISO  = pin 12 Master in slave out
 *  CLK   = pin 13 Clock
 *  
 *  on the Sparkfun Shield, the CS (chip select) pin 8
 */ 

Sd2Card card; // SD utility about type of card 
SdVolume volume; // SD utility allows card size information 
SdFile file; //SD utility to describe files
const int chipSelect = 8;
File myFile; //name a file


void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(13,INPUT);

  Serial.println("\nInitializing Card...  ");

  //let's check the card at 1/2 speed so we know that it is working
  //students have trouble with full speed and cheap SD cards
  if(!card.init(SPI_HALF_SPEED, chipSelect)){
    Serial.println("Initialization Failed. You Lose");
    return;
  }else {
    Serial.println("Card Found. You Win");
    Serial.print("\nCard type:");
    switch(card.type()){
      case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
      case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
      case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
      default: 
      Serial.println("Huh? What did you put in?");
      break;
    }
  //volume partition
    //now to check the format (FAT) and see the space
    if(!volume.init(card)){
      Serial.println("No FAT partition.\n Check format");
      return; //to end code execution after this point if error
    }
  uint32_t volumeSize; //unsigned integer for big numbers!
  Serial.print("Volume is FAT");
  Serial.println(volume.fatType());
  uint32_t blocksPer = volume.blocksPerCluster();
  Serial.println(blocksPer);
  volumeSize = volume.blocksPerCluster();
  uint32_t clusterCount = (volume.clusterCount());
  Serial.println(clusterCount);
  volumeSize *= volume.clusterCount();
  volumeSize *= 512;
  Serial.print("Volume size (bytes) = ");
  Serial.println(volumeSize);
  Serial.print("Volume size (kBytes) = ");
  Serial.println(volumeSize/1024);
  Serial.print("Volume size (mBytes) = ");
  Serial.println(volumeSize/1024/1024);

  Serial.println("\nFiles found on the card");
  file.openRoot(volume);
  file.ls(LS_R | LS_DATE | LS_SIZE);

  SD.begin(chipSelect);//Start the SD reading functionality


  if (SD.exists("DATALOG.txt")) {
    Serial.println("DATALOG.txt exists.");
  } else {
    Serial.println("DATALOG.txt doesn't exist.");
  }

  }

  SD.remove("DATALOG.TXT");
  file.openRoot(volume);
  file.ls(LS_R | LS_DATE | LS_SIZE);
    
  delay(1000);



}

void loop() {

//Create debounced button for dataLogging

 int buttonState;

 buttonState = digitalRead(13);
  
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
    delay(2000);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}


