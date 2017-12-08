/*
  LiquidCrystal Library - Cursor
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD and
 uses the cursor()  and noCursor() methods to turn
 on and off the cursor.
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/LiquidCrystalCursor

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String firstLine = ("Where is Dan G?");
String secondLine = ("At Lunch");
int lenOne = firstLine.length();
int lenTwo = secondLine.length();
  
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.clear();
  delay(1000);
  int maxLen = max(lenOne,lenTwo);
  lcd.begin(maxLen,2);//Initialize the size of the screen
}

void loop() {
  // Turn off the cursor:
  int lenOne = firstLine.length();
  int lenTwo = secondLine.length();
  int maxLen = max(lenOne,lenTwo);
 
for (int ii = 1; ii < maxLen; ii++){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(firstLine);
  if (maxLen - ii == 1){
    lcd.setCursor(maxLen-ii-1,2);
    lcd.print(secondLine);
    delay(5000);
  }else{
    lcd.setCursor(maxLen-ii,2);
    lcd.print(secondLine);
    delay(250);
   }
  }
  // Print a message to the LCD.
  
}
