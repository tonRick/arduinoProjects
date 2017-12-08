
/*Code for Wireless Doorbell
 * This code receives an input from the Serial and plays a Song. 
 * It has been changed to play the third song on the card
 */

#include <SPI.h>           // SPI library
#include <SdFat.h>         // SDFat Library
#include <SdFatUtil.h>     // SDFat Util Library
#include <SFEMP3Shield.h>  // Mp3 Shield Library

SdFat sd; // Create object to handle SD functions

SFEMP3Shield MP3player; 

const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off) - set to max
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max

#define TRIGGER_COUNT 8
int triggerPins[TRIGGER_COUNT] = {5, A0, 10, A1, A2, A3, A4};//A0 and 10 positions switched changed from default code
int stopPin = A5; // This pin triggers a track stop.
int lastTrigger = 0; // This variable keeps track of which tune is playing
const int LED = 10;//attach LED to pin 10
char data = '0';//initialize as off


void setup() {
  Serial.begin(9600);
  for (int i=0; i<TRIGGER_COUNT; i++)
  {
    pinMode(triggerPins[i], INPUT_PULLUP);
  }
  pinMode(stopPin, INPUT_PULLUP);

  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}

void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available() > 0 ) //is there Serial data?
  {
    data = Serial.read();//if there is, read the data
     MP3player.stopTrack();
    if (data == '1'){//
    MP3player.playTrack(3);//This is a clip of "My House"
    delay(4000);
    }
    else if (data == '2'){
    MP3player.playTrack(2);//This is a clip of ...
    delay(4000);
    }
   else if (data == '3'){
    MP3player.playTrack(2);//This is a clip of ...
    delay(4000);
    }
    else {
    MP3player.stopTrack();
    }
}
}


// initSD() initializes the SD card and checks for an error.
void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}

// initMP3Player() sets up all of the initialization for the
// MP3 Player Shield. It runs the begin() function, checks
// for errors, applies a patch if found, and sets the volume/
// stero mode.
void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}
