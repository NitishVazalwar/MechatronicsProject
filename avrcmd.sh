#!/bin/sh
# These commmands run to compile a .o file
#Author:Nitish S. Vazalwar
#and .hex file on one program 
avr-gcc -mmcu=atmega328p one.c -o one.elf
#file is converted to hex now 
avr-objcopy -j.text -O ihex one.hex
#final step is use avrdude
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:one.elf

