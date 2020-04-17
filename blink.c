#include <avr/io.h>
//#include <util/delay.h>
//Other include files here
#include "delay.h"

 
#define BLINK_DELAY_MS 1000
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 DDRB |= _BV(DDB13);
 
 while(1) {
  /* set pin 5 high to turn led on */
  PORTB |= _BV(PORTB13);
  //_delay_ms(BLINK_DELAY_MS);
	Delay(1000); 

  /* set pin 5 low to turn led off */
  PORTB &= ~_BV(PORTB13);
 // _delay_ms(BLINK_DELAY_MS);
	Delay(1000);
 }
 return 0;
}
