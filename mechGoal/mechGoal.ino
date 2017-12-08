
#include <avr/io.h>
#include <util/delay.h>

int main (void){

//We need to use Pins PB0-3 for the LED control
//PB is the switch input

//First define DDRB locations 0-3 as 1 so that these will be outputs
//DDRB location 4 is an input, so this is set low
//PORTB set 1 for port 4 so with pin4's pullup is activated
//Since the pullup is activated, we will look for low to detect pushbutton

  DDRB  =   0b00001111; // Pin 0 on Port B output
  PORTB   = 0b00010000; //setting port high enables pulup


while (1) { //infinite loop

//bitmask for PB4 (1<<4)

//Look for input on register B, but only care about PB4 

//IMPORTANT NOTE: In order for the pullups to remain active, the PORTB pin 4 needs to remain a 1 throughout! 
    if (PINB & (1<<4)){
      PORTB = 0b00011110;          /* Turn on pin3 (500hz red), pin2(RGBred) and pin1(RGBgreen) on PORTB */
      _delay_us(208);                                           /* wait - tested to give ~20% green so orange is output*/
      PORTB = 0b00011100;          /* Turn off pin1 (RGBgreen) bit in PORTB to make orange*/
      _delay_us(808);                                          /*wait*/
      PORTB = 0b00010000;          /* Turn off pin2 (RGBred) and pin3 (500hz) to get 500hz signal*/
      _delay_us(1016);                                           /* wait */
    }else 
    //if the switch is activated - need a blue light and the red light still at 500 hz
    { 
      PORTB = 0b00011001; //turn on blue LED and 500hz red
      _delay_us(1016);                                           /* wait */ 
      PORTB = 0b00010001;          /* Turn off 500hz red keep blue on to dazzle*/
      _delay_us(1016); 
    }
  }
  return(0);
}
