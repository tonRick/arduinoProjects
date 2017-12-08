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

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);

  Serial.println("\nInitializing Card...  ");

  //let's check the card at 1/2 speed so we know that it is working
  //students have trouble with full speed and cheap SD cards
  if(!card.init(SPI_FULL_SPEED, chipSelect)){
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
  }
    
  



}

void loop() {
  // put your main code here, to run repeatedly:

}
