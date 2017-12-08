#include<SPI.h>
byte input, output, check = 1;
int ii;


void setup() {
  pinMode(13,OUTPUT);//data
  pinMode(11,OUTPUT);//clock
  pinMode(4,OUTPUT);//latch - used to latch the data
  pinMode(2,INPUT); //needs to be an interrupt pin
}

void loop() {
SPI.setBitOrder(MSBFIRST); 
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV2);//runs at 8mHz - why used SPI library
SPI.begin();
SPI.transfer(255); //shift out bytes - this sends 111111111 - data goes to LED output first
SPI.transfer(0); // Moves first over, and then all 0 for the outputs.  
digitalWrite(4,HIGH);
digitalWrite(4,LOW);
Serial.begin(9600);
//attachInterrupt(0,pin_read,RISING);
  
}

//void pin_read(){
//
//  for (ii = 0, ii< 50; ii++){
//    delayMicroseconds(1000); //50 ms - delay doesn't work debouncer
//  } 
//  check = 1
//  for(ii = 0; ii<8; ii++){
//    SPI.transfer(check);
//    SPI.transfer(output);
//    digitalWrite(4,HIGH);
//    digitalWrite(4,LOW);
//    delayMicroseconds(500);
//    if(digitalRead(2) == HIGH){
//      if(bitRead(output, j) ==1);
//      bitWrite(output,0);
//      else
//      bitWrite(output,1);
//    }
//    Check = Check << 1;
//  }
//  SPI.transfer(255);
//  SPI.transfer(output);
//  digitalWrite(4,HIGH);
//  digitalWrite(4,LOW);
//
//  while(digitalRead(2) == HIGH){} //waits for finger to let go
//}
//    }
//  }
//}

