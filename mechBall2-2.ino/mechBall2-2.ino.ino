
//Code for Mechatronics Spring 2017 beacon board.
//Beacon board flashes IR led at 500 hz, and controls colors of RGB led

//Version 2-2 reverses logic for RGB to Migrate to Mechatronics Board
//Written by: Dan Godrick

//Include necessary libraries
#include <avr/io.h>
#include <util/delay.h>

//Set delay time variables
#define delayTime1 200 //delay time on for green
#define delayTime2 800 //delay time off for green
#define delayTime3 1000 // delay time for on off (Blue, Red, IR)



int main (void){

//We need to use Pins PB0-2 for the RGB LED - BUT the Logic is reversed! 1 off, 0 on. Can be tricky! 
//PB3 is for the LED control. The Logic is normal: 1 on, 0 off
//PB4 is the switch input

//First define DDRB locations 0-3 as 1 so that these will be OUTPUTS
//DDRB location 4 is an INPUT, so this is set low

DDRB  =   0b00001111; // A 0 on Port B sets as output, 

//PORTB set 1 for port 4 so with pin4's pullup is activated
//Since the pullup is activated, we will look for low to detect pushbutton
//IMPORTANT NOTE: In order for the pullups to remain active, the PORTB pin 4 needs to remain a 1 throughout! 
  
  PORTB   = 0b00010000; //setting port high enables pulup

//Now for the code that does something: 

while (1) { //infinite loop



//Look for input on register B, but only care about PB4 
//Remember the IMPORTANT NOTE: In order for the pullups to remain active, the PORTB pin 4 needs to remain a 1 throughout! 
//bitmask for PB4 (1<<4)
//If the switch is not switched make an orange light. If it is, make the blue light

//First, the orange light condition

   if (PINB & (1<<4)){
    
 // Turn on pin3 500hz red, pin1 RGB Green(reverse), pin2 RGB Red(reverse). Turn off pin 0 RGB Blue (reverse)
      PORTB =   0b00010001; 

// Wait - duty cycle of ~10% RGB green 50% RGB red gives a nice orange as output              
// So first turn off the green
      _delay_us(delayTime1);                                             
      PORTB = 0b00010111;    

//Then wait and turn off the RGB red and IR. Then wait at the end for a 500 hz signal
      _delay_us(delayTime2); 
      PORTB = 0b00011011;
      _delay_us(delayTime3);                                           
   
    }else 

//If the switch is activated - then we need a blue light and the IR light still at 500 hz
     { 
       //pin3 IR 500 High turns on. Remember the RGB is reversed so a 0 on OB 0 turns on the Blue LED
      PORTB = 0b00011110;      
      _delay_us(delayTime3);                                           /* wait */ 
      
       /* Turn off IR at 500hz. A duty cycle of 50% for Blue will dazzle as well*/
      PORTB = 0b00010111;         
      _delay_us(delayTime3); 
    }
  }
  return(0);
}
