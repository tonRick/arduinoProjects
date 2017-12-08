/*  iLamp.ino
 Interactive Lamp Project
 Example code for ENG1400 Interactive Lamp
 
 Original code written by: B. Huang
 Date: 09/22/13
 
 */

// connect the RGB LED to the following pins on the Arduino
// The next three lines declare variables that we can use later in the code
// in place of the actual numbers.
int redLED = 9;
int blueLED = 10;
int greenLED = 11;

int sensorPin = A0;
int potLevel = 0;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(sensorPin, INPUT);
  Serial.begin(9600);  // this line sets up a serial com interface
  // to communicate back to your PC
}                       

void loop()
{
  // this code repeats over and over. Each instruction occurs in roughly 62.5 ns and 
  // this section of code (that is in between curly brackets {} will repeat over and over
  // and over... forever.

   potLevel = analogRead(sensorPin);  // reads in the light level of the sensor. 
                                       // analogRead will return a value between 0 and 1023 

  Serial.print("Sensor value =");      // prints a string to read to Serial comm
  Serial.print(potLevel);            // prints the variable light level to Serial 
  Serial.println();                    // prints a CRLF

  // this part of the code checks the light level to see if it's below a certain threshold
  // value. 512 was picked as an arbitrary level - about 1/2 way in between. 

  if (potLevel <= 512)   
    LEDseq1();  // calls (runs) the LEDseq1() function
  else
    LEDseq2();  // calls (runs) the LEDseq2() function
}

void LEDseq1()
{
  // simple blink routine. this code turns on the BLUE led for 500 ms, then turns it off.
  // 
  // Change, manipulate, or modify this code to create your own light pattern.
  //
  // digitalWrite can be used to turn on (HIGH) or off (LOW) any of the digital
  // pins on the Arduino. These are pins 0 to 13
  //
  digitalWrite(redLED,LOW);//turn off redLED
  digitalWrite(greenLED,LOW);//turn off greenLED
  digitalWrite(blueLED, HIGH);
  delay(500);  // waits for 500 ms
  digitalWrite(blueLED, LOW);
  delay(500);  // waits for 500 ms
}

void LEDseq2()
{
  // simple routine to switch between the three LED colors - with 200 ms in between.
  // 
  // Change, manipulate, or modify this code to create your own light pattern.
  //
  // analogWrite can be used to vary the voltage going out to pins 3, 5, 6, 9, 10, or 11.
  // These pins each have a ~ symbol next to them. 
  // Full on is equvalent to a value of 255, full off is equal to 0.
  //
  // Use any value in between 0 and 255 to change the brightness of the LED or
  // to mix various amounts of each color together.

  analogWrite(redLED, 255);
  analogWrite(blueLED, 0);
  analogWrite(greenLED, 0);

  delay(200);  // waits for 200 ms

  analogWrite(redLED, 0);
  analogWrite(blueLED, 255);
  analogWrite(greenLED, 0);

  delay(200);  // waits for 200 ms

  analogWrite(redLED, 0);
  analogWrite(blueLED, 0);
  analogWrite(greenLED, 255);

  delay(200);  // waits for 200 ms    
}
