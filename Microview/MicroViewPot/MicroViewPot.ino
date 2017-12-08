

#include<MicroView.h>
int LED = A2;
int pot = A0;

MicroViewWidget *widget;
MicroViewWidget *widget2;
int reading = 0; 

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(pot,INPUT);
  digitalWrite(pot,LOW);
  uView.begin();
  uView.clear(PAGE);
  widget = new MicroViewSlider(0,0,0,1024);
  widget2 = new MicroViewSlider(0,20,0,1024,WIDGETSTYLE1);
  uView.display();
}

void loop() {
  int reading = analogRead(pot);
  widget -> setValue(reading);
  widget2 -> setValue(1023 - reading);
  uView.display();
  
}
