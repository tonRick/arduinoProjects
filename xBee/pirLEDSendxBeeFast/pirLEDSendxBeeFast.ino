
//Written By Daniel Godrick
//July 10, 2017

//Wiring for PIR
//Red to 5V (Uno)
//Green to Ground (Uno)
//Blue to Pin 2(Uno)

#define pirPin 2
#define ledPin 9

const int brightness = 255;
int LEDlevel = 0;




void setup() {
  Serial.begin (9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int pirVal = digitalRead(pirPin);
  if (pirVal == HIGH)
  {
     LEDlevel = 255;
    analogWrite(ledPin,LEDlevel);
    Serial.print(pirVal);
    Serial.print(","); 
    Serial.print(LEDlevel);
    Serial.print('\n');
    delay(100);    
   } 
   else {
    LEDlevel = 0;  
    digitalWrite(ledPin,LOW);
    Serial.print(0);
    Serial.print(","); 
    Serial.print(0);
    Serial.print('\n');
    delay(50);
    Serial.print(0);
    Serial.print(","); 
    Serial.print(0);
    Serial.print('\n');
    delay(100);
    Serial.print(0);
    Serial.print(","); 
    Serial.print(0);
    Serial.print('\n');
    }
}

