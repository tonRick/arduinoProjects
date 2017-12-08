
//Mech Ball 22 reverses logic for RGB to Migrate to Mechatronics Board

#include <avr/io.h>
#include <util/delay.h>

#define delayTime1 200 //delay time on for green
#define delayTime2 810 //delay time off for green
#define delayTime3 1010 // delay time for on off (Blue and Red)



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
      PORTB =   0b00010001;           // Turn on pin3 500hz red, pin1 RGB Green(reverse), pin2 RGB Red(reverse). Turn off pin 0 RGB Blue (reverse)
//      //PORTB = 0b00011110;          /* Test Turn on pin3 (500hz red), pin2(RGBred) and pin1(RGBgreen) on PORTB */
      _delay_us(delayTime1);                                           /* wait - tested to give ~20% green so orange is output*/
      PORTB = 0b00010111;            //Turn off pin1 RGB green to make orange
//    PORTB = 0b00011100;          /* Turn off pin1 (RGBgreen) bit in PORTB to make orange*/
      _delay_us(delayTime2);                                          /*wait*/
      PORTB = 0b00011011;           //Turn off pin3 500hz Red to get 500 hz signal
//      PORTB = 0b00010000;          /* Turn off pin2 (RGBred) and pin3 (500hz) to get 500hz signal*/
      _delay_us(delayTime3);                                           /* wait */
    }else 
    //if the switch is activated - need a blue light and the red light still at 500 hz
    { 
      PORTB = 0b00011110;       //pin 3 500 Hz red and turn on RGB blue LED (reverse)
      _delay_us(delayTime3);                                           /* wait */ 
      PORTB = 0b00010111;          /* Turn off 500hz red keep blue on to dazzle*/
      _delay_us(delayTime3); 
    }
  }
  return(0);
}
