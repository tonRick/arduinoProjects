
#include <avr/io.h>
#include <util/delay.h>

int main (void){

//We need to use Pins PB0-3 for the LED control
//PB is the switch input

//First define DDRB locations 0-3 as 1 so that these will be outputs
//DDRB location 4 is an input, so this is set low
//PORTB set 1 for port 4 so with pin4's pullup is activated
//Since the pullup is activated, we will look for low to detect pushbutton

  DDRB  =   0b00001000; // Pin 0 on Port B output
  PORTB   = 0b00010000; //setting port high enables pulup


while (1) { //infinite loop

//bitmask for PB4 (1<<4)

//Look for input on register B, but only care about PB4 

//IMPORTANT NOTE: In order for the pullups to remain active, the PORTB pin 4 needs to remain a 1 throughout! 
      PORTB = 0b00011000;          /* Turn on pin3 (500hz red), pin2(RGBred) and pin1(RGBgreen) on PORTB */
       _delay_us(994);                                           /* wait */
       PORTB = 0b00010000;          /* Turn off pin2 (RGBred) and pin3 (500hz) to get 500hz signal*/
      _delay_us(994);                                           /* wait */
   
  }
  return(0);
}
