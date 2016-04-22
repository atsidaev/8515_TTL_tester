all:
	avr-gcc -o tester.elf -mmcu=atmega8515 -Os tester.c
