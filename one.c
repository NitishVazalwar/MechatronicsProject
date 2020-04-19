#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "delay.h" 
#include <stdint.h>

#define BLINK_DELAY_MS 5000
//Delay function
void Delay_function(uint16_t dly)
{
	for(volatile uint16_t i=dly;i<=0;i--)
	{
	;	
	}
}

//pin set to output function
void set_to_output()
{
	DDRB |= _BV(DDB5);
}

//function to turn led on
void led_is_on()
{
	 PORTB |= _BV(PORTB5); 
}

//function to turn led off
void led_is_off()
{
	 PORTB &= ~_BV(PORTB5);
}
 

//Function to convert decimal to binary 

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
	//Delay_function(100);
 printf("\n\rLed is off now");
  /* set pin 5 low to turn led off */
 led_is_off();
  _delay_ms(BLINK_DELAY_MS);
	//Delay_function(100);
 }
 return 0;
}
