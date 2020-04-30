#include <avr/io.h>
#include <util/delay.h>
//Other include files here
#include "delay.h"

 
#define BLINK_DELAY_MS 1000

//other declarations and functions
// void set_to_output()
// {
// 	DDRB |= _BV(DDB13);
// }

// void turn_on_led()
// {
// 	PORTB |= _BV(PORTB13);
// }

// void turn_off_led()
// {
// 	 PORTB &= ~_BV(PORTB13);
// }
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 	//set_to_output();
 	DDRB|= _BV(DDB13);
 while(1) {
  /* set pin 5 high to turn led on */
  	//turn_on_led();
  	PORTB |=_BV(PORTB13);
  //_delay_ms(BLINK_DELAY_MS);
	Delay(1000); 

  /* set pin 5 low to turn led off */
	PORTB &=~ _BV(PORTB13);
 	turn_off_led();
 // _delay_ms(BLINK_DELAY_MS);
	Delay(1000);
 }
 return 0;
}
