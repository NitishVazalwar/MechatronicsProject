#include <avr/io.h>
#include <util/delay.h>
#include "delay.h" 
#include "strmap.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/********************************************************************************
Macros and Defines
********************************************************************************/
#define BLINK_DELAY_MS 5000
#define OPERAND 8
#define NUMBER 32

#define SIZE 26

/********************************************************************************
Function Prototypes
********************************************************************************/


/********************************************************************************
macros for modes, uncomment the mode you want
********************************************************************************/
#define BINARY_MODE 1
//#define BLINK_MODE 0
//#define MORSE_MODE 2
/********************************************************************************
morse mode related
********************************************************************************/
struct DataItem {
   char* data;   
   char key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(char key) {
   return key % SIZE;
}

struct DataItem *search(char key) {
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(char key,char* data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}
/********************************************************************************
led related and delay
********************************************************************************/

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

/********************************************************************************
binary  mode related
********************************************************************************/ 

//Function to convert decimal to binary 
int decToBinary(int dec,int *array)
{
    /* https://www.programmingsimplified.com/c/source-code/c-program-convert-decimal-to-binary */
    int shift, check;
    int a = 0;
    printf("0b");
    for (shift = OPERAND-1; shift >= 0; shift--)
    {
        check = dec >> shift;
/*
9 
==1001
0001
0001
0010
0001    Documentation example
0100
0001
1001
0001
*/
        if (check & 1)
          {  a = 1;
	    printf("1");}
        else
           { a = 0;
	    printf("0");}
// Check 
       array[shift] = a;

    }
 
	
   	printf(" ");
	return(0);
}

/********************************************************************************
main 
********************************************************************************/
int main (void)
{
	int buffer[OPERAND];

  printf("\n\rPort set to output");
 /* set pin 5 of PORTB for output*/
 set_to_output();
 
// while(1) 
 {
	//START BIT
 	led_is_on();
 	_delay_ms(5*BLINK_DELAY_MS);
	led_is_off();
	_delay_ms(5*BLINK_DELAY_MS); 
// printf("\n\rLed is on now");
//   /* set pin 5 high to turn led on */
//  led_is_on();
//   _delay_ms(BLINK_DELAY_MS);
// 	//Delay_function(100);
//   	//Delay_fn(100);

//  printf("\n\rLed is off now");
//   /* set pin 5 low to turn led off */
//  led_is_off();
//   _delay_ms(BLINK_DELAY_MS);
// 	//Delay_function(100);
//   	//Delay_fn(100);
//  }

	#ifdef BINARY_MODE

 	decToBinary(NUMBER,buffer);
	
 	//binary number is stored in array
 	for (int j=0;j<OPERAND;j++)
 	{
 		if(buffer[j]==1)
 		{
 			led_is_on();
 			_delay_ms(BLINK_DELAY_MS);
			led_is_off();
			_delay_ms(BLINK_DELAY_MS);
 		}
 		else
 		{
 			led_is_off();
 			_delay_ms(BLINK_DELAY_MS);
 		}

 	}
 	#endif

 	#ifdef BLINK_MODE
 		for (int a=0; a<4;a++){
 		led_is_on();
 		_delay_ms(5*BLINK_DELAY_MS);
 		led_is_off();
 		_delay_ms(5*BLINK_DELAY_MS);
 	}

 	return 0;
 	#endif

 	#ifdef MORSE_MODE
	 dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = "";  
   dummyItem->key = '\0'; 

   insert('a', ".-");
   insert('b', ".-.-");
   insert('c',"--.");

   char *morse;
   morse=(char *)malloc(1000*sizeof(char));
   // item = search('a');
   // morse= strcat(morse,item->data);
   // item = search('b');
   // morse= strcat(morse,item->data);
   // printf("%s",morse);

   char word[5]="aa";
   for(int i=0;word[i]!='\0';i++)
   {
   	item =search(word[i]);
   	morse=strcat(morse,item->data);
   }
   printf("%s",morse);

    while(* morse !='\0')
   {
   	if(*morse=='-'){led_is_on();_delay_ms(BLINK_DELAY_MS);led_is_off();}
   	else{led_is_off();_delay_ms(BLINK_DELAY_MS);}
   	morse++;
   }


   #endif


 	led_is_on();
 	//_delay_ms(0.5*BLINK_DELAY_MS);
	//led_is_off();
	//_delay_ms(0.5*BLINK_DELAY_MS);
	//STOP BIT   
 }
 	
 return 0;
}
