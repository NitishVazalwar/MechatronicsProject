#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "delay.h" 


#define BLINK_DELAY_MS 5000

void set_to_output()
{
	DDRB |= _BV(DDB5);
}

void led_is_on()
{
	 PORTB |= _BV(PORTB5); 
}


void led_is_off()
{
	 PORTB &= ~_BV(PORTB5);
}
 
int main (void)
{

printf("\n\rPort set to output");
 /* set pin 5 of PORTB for output*/
 set_to_output();
 
 while(1) 
 {
printf("\n\rLed is on now");
  /* set pin 5 high to turn led on */
 led_is_on();
  _delay_ms(BLINK_DELAY_MS);
//	Delay(5000);
 printf("\n\rLed is off now");
  /* set pin 5 low to turn led off */
 led_is_off();
  _delay_ms(BLINK_DELAY_MS);
//	Delay(5000);
 }
 return 0;
}
