#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 26

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




void Log(void){
	printf("\nAuthor: Nitish Vazalwar");
	printf("\n***********************************************");
	printf("\nTest file of Arduino Avr-gcc .");
	printf("\n***********************************************");
	printf("\nCheck README file on github : https://github.com/NitishVazalwar/MechatronicsProject.git");
	printf("\nTest string is hello");
	printf("\nExpected output is ......-...-..---");
	printf("\nNote:Enter small letters only supported by HASHTABLE");

}





int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = "";  
   dummyItem->key = '\0'; 
//key and data elements according to Morse Code, small letters only
   insert('a', ".-");
   insert('b',"-...");
   insert('c',"-.-.");
   insert('d',"-..");
   insert('e',".");
   insert('f',"..-.");
   insert('g',"--.");
   insert('h',"....");
   insert('i',"..");
   insert('j',".---");
   insert('k',"-.-");
   insert('l',".-..");
   insert('m',"--");
   insert('n',"-.");
   insert('o',"---");
   insert('p',".--.");
   insert('q',"--.-");
   insert('r',".-.");
   insert('s',"...");
   insert('t',"-");
   insert('u',"..-");
   insert('v',"...-");
   insert('w',".--");
   insert('x',"-..-");
   insert('y',"-.--");
   insert('z',"--..");

   char *morse;
   morse=(char *)malloc(1000*sizeof(char));
   Log();
   printf("\nCommencing...");
   printf("\n********************************************************");
   printf("\n\n\n");
   char word[6]="hello";
   
   for(int i=0;word[i]!='\0';i++)
   {
   
   	item =search(word[i]);
   	morse=strcat(morse,item->data);

   }
   printf("%s",morse);
   printf("\n\n\n");
   printf("\n******************************************************");
   printf("\nLED action is");
   while(* morse !='\0')
   {
   	if(*morse=='-'){printf("\nON");}
   	else{printf("\nOFF");}
   	morse++;
   }
}
