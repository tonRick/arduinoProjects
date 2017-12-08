/* Daniel Godrick
Sept 23rd
Sin Wave Maker

Uses code from: 
http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/

To create a sin wave for a project

*/
#include <avr/interrupt.h> // Include the interrupt library to control the output at a detailed level

#define PI2  6.283185 //Used throughout
#define AMP  127 //127 is the middle amplitude (0-255)
#define OFFSET  128 //All values have to be > 0 

//Define the lookup table
#define LENGTH  256 //length of wave lookup table
byte wave[LENGTH]; //storage for waveform - byte stores as a 8 bit unsigned number 0-255

void setup(){
  for (int ii = 0; ii < LENGTH; ii++){
    float v = (AMP*sin(ii*PI2/LENGTH)); //computes value
    wave[ii] = int(v + LENGTH); //stores the value as an integer
  }
  pinMode(9,OUTPUT);
  
  //Set Timer 1 to 8 bit fast pwm
  TCCR1B = (1 << CS10); //Prescaler to 16 MHz
  TCCR1A |= (1 << COM1A1); //Pin low when TCNT = OCR1A
  TCCR1A |= (1 << WGM10); //8-bit fast PWM
  TCCR1B != (1 <<WGM12);
  
  //Set Timer 2 to call ISR
  
  TCCR2A = 0; //No options in control register A
  TCCR2B = (1 << CS21); //set prescaler to divide by 8
  TIMSK2 = (1 << OCIE2A); //Call ISR when TCNT2 = OCRA2
  OCR2A = 32; //Frequency of generated wave
  sei(); //enable interrupts to generate wave
}
  void loop(){//Nothing to do in loop
  }
  
  //function ISR - called when TCNT2 = OCR2A
  
  ISR(TIMER2_COMPA_vect){
    static byte index = 0;
    OCR1AL = wave[index++];
    asm("NOP;NOP"); //NOP is no operation, which is 1 machine cycle 62.5 ns!
    TCNT2 = 6;
  }
    
