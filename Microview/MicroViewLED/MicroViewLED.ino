

#include<MicroView.h>
int LED = A2;

void setup() {
  pinMode(LED,OUTPUT);
  uView.begin();
  uView.clear(PAGE);
}

void loop() {
  digitalWrite(LED,HIGH);
   uView.clear(PAGE);
   uView.begin();
  uView.print("ON YES!");
  uView.display();
  delay(1000);
  digitalWrite(LED,LOW);
   uView.clear(PAGE);
    uView.begin();
  uView.print("OFF NO!");
  uView.display();
  delay(1000);
  
}
