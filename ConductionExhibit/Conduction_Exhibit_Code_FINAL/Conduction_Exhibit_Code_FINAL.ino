/*

LCD Screen pin out in circuit 

 1 to GND
  2 to 5V
  3 to the center pin on the potentiometer
  4 to Arduino digital pin 6
  5 to GND
  6 to Arduino digital pin 7
  7 (no connection)
  8 (no connection)
  9 (no connection)
  10 (no connection)
  11 to Arduino  digital pin 9
  12 to Arduino  digital pin 10
  13 to Arduino  digital pin 11
  14 to Arduino  digital pin 12
  15 to Arduino  digital pin 13
  16 to GND
*/

#include <LiquidCrystal.h>

// See http://arduino.cc/en/Reference/LiquidCrystal
// for more information:

LiquidCrystal lcd(6,7,9,10,11,12);                            /* Allows the arduino to recognize the LCD Screen */

int button = 2;                                               /**/
int screen1 = 4;                                              /**/
int screen2 = 5;                                              /**/
int backlight = 13;                                           /* Assorted pin declarations in relation to the arduino */
int therm = A1;                                               /**/
int value = 0;                                                /**/



void setup(){
  
  Serial.begin(9600);                                         /* Initialize Serial Port */
  lcd.begin(16, 2);                                           /* Initialize LCD Screen */
  lcd.clear();                                                /* Clears previous data from LCD Screen */
  
  pinMode(button, INPUT);                                     /**/
  pinMode(therm, INPUT);                                      /**/      
  pinMode(screen1, OUTPUT);                                   /* Arduino organization. Enforces whether a pin is acting as an input or output */
  pinMode(screen2, OUTPUT);                                   /**/
  pinMode(backlight, OUTPUT);                                 /**/


}

void loop(){
  
  int onOff = digitalRead(button);                            /* If button was pushed, onOff = 1. If not, onOff = 0 */
  Serial.println(analogRead(therm));                          /* Prints the voltage to the serial port for testing */
  if (onOff == LOW){                                          /* If the button was pushed, begin loop */
    long unsigned timer = millis() + 5000;                    /* Create time from the current millisecond count plus 5000 ms */
    while(timer >= millis()){                                 /* Continue loop for 5 seconds after button push */
    
        digitalWrite(screen1, LOW);                           /**/
        digitalWrite(screen2, LOW);                           /* Turns on the LCD Screen */
        digitalWrite(backlight, HIGH);                        /**/
        
        value = .787 * analogRead(therm);                     /* Calibrates voltage read to correct temperature in degrees Farenheit */
        
        lcd.setCursor(2,0);                                   /**/
        lcd.print("Temperature");                             /**/
        lcd.setCursor(1,1);                                   /* Writes the words and values to be displayed on the LCD Screen */
        lcd.print(value);                                     /**/
        lcd.setCursor(5,1);                                   /**/
        lcd.print("Fahrenheit");                              /**/
    }
      digitalWrite(screen1, HIGH);                            /**/
      digitalWrite(screen2, HIGH);                            /* Turns off the LCD Screen */
      digitalWrite(backlight, LOW);                           /**/
  }

      else
      digitalWrite(screen1, HIGH);                            /**/
      digitalWrite(screen2, HIGH);                            /* Ensures that the LCD Screen is off */
      digitalWrite(backlight, LOW);                           /**/
      
}

