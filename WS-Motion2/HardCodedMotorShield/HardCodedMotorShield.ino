/*
 5/22/2012
  Timothy Holmberg
  SparkFun Electronics
  
  This code includes the ddition of fade in and out PWM. Also a stop feature. And the addition of individual functions for motor control 
  
  This was a revision of the example sketch that originated from Pete Dokter's code for Arduino that shows very basically how to control an Ardumoto 
  motor driver shield with a 5V Arduino controller board. http://www.sparkfun.com/datasheets/DevTools/Arduino/Ardumoto_test_3.pde
  
  This also includes parts of the Fading Example,  Created 1 Nov 2008 By David A. Mellis, modified 30 Aug 2011 By Tom Igoe http://arduino.cc/en/Tutorial/Fading
 
*/

int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //direction control for motor outputs 3 and 4 is on digital pin 13
int val = 0;     //value for fade
int powera = 160;
int powerb = powera*1.1; //motor variation

void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  
  analogWrite(pwm_a, powera);  //set both motors to run at 0 duty cycle
  analogWrite(pwm_b, powerb); 
}

void loop()
{ 
  forward();      //start full speed forward
  delay(4000);    
  left(); //Turn 90 degrees to the left
  delay (600);
  stopped();      // stop  
}


/* Let's take a moment to talk about these functions. The forw and back functions are simply designating the direction the motors will turn once they are fed a PWM signal.
If you only call the forw, or back functions, you will not see the motors turn. On a similar note the fade in and out functions will only change PWM, so you need to consider
the direction you were last set to. In the code above, you might have noticed that I called forw and fade in the same grouping. You will want to call a new direction, and then
declare your pwm fade. There is also a stop function. 
*/

void forward() {//full speed forward 
  digitalWrite(dir_a, HIGH);  //Set A-motor direction
  digitalWrite(dir_b, HIGH);  //Set B-Motor direction 
  analogWrite(pwm_a, powera);    //set a-motor to run at  duty cycle
  analogWrite(pwm_b, powerb);    //set b-motor to run at  duty cycle (motor variation);
}

void left(){ 
  digitalWrite(dir_a, LOW);  //Set A-motor direction
  digitalWrite(dir_b, HIGH);  //Set B-Motor direction 
  analogWrite(pwm_a, powera);    //set a-motor to run at  duty cycle
  analogWrite(pwm_b, powerb);    //set b-motor to run at duty cycle (motor variation);
}

void stopped(){ //stop
 
  digitalWrite(dir_a, LOW); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 0% duty cycle 
  analogWrite(pwm_b, 0); 
  delay(1000);  
}

