
#include<MicroView.h>

MicroViewWidget *redW, *greenW, *blueW;

const float pi = 3.14159265;
int red = 6;
int green = 5;
int blue = 3;

int fadeStep = 10; //fading steps
int dly = 10;    // delay of 30 ms

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
  float ii;

  for (ii = 0; ii < 256; ii++){

    float y = sin(ii*2*pi/255)*128 + 128;
    analogWrite(red,y);
    redW -> setValue(y);
    uView.display();
    delay(dly);
  }

}

