
#include<MicroView.h>

MicroViewWidget *redW, *greenW, *blueW;

int red = 6;
int green = 5;
int blue = 3;

int fadeStep = 10; //fading steps
int dly = 30;    // delay of 30 ms

void setup(){
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  uView.begin();
  uView.clear(PAGE);
  redW= new MicroViewSlider(0,0,0,255);
  
  greenW= new MicroViewSlider(0,20,0,255);
  
  blueW= new MicroViewSlider(0,40,0,255);
}

void loop(){
  int ii;

  for (ii= 0 ; ii < 256; ii = ii +fadeStep){
    redW -> setValue(ii);
    uView.display();
    analogWrite(red,ii);
    delay(dly);
  }
   for (ii= 256 ; ii > -1 ; ii = ii - fadeStep){
    redW -> setValue(ii);
    uView.display();
    analogWrite(red,ii);
    delay(dly);
   }
}

