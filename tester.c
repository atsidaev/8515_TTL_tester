#ifdef __GNUC__
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#define F_CPU 8000000UL
#include <util/delay.h>
#define delay_ms _delay_ms

#else
#include <mega8515.h>
#include <delay.h>
#endif

#ifdef __GNUC__
#define flash const
#else
#define PROGMEM
#endif

char sym[4], seg, res=0;
//flash char znak[]={63,6,91,79,102,109,125,7,127,111, 99,92,9,0,121,113,120,57};
flash char znak[] PROGMEM ={215,17,203,91,29,94,222,19,223,95, 15,216,66,0,206,142,204,198};
flash char razr[] PROGMEM ={128,64,32,16};
char sel=0;

void menu(void);
void search(void);

#define Port_H PORTA
#define Direct_H DDRA
#define Pin_H PINA
#define Port_L PORTC
#define Direct_L DDRC
#define Pin_L PINC
#define Display_P PORTD
#define Display_D DDRD

#ifdef __GNUC__
#define key_UP (PINB | (1 << 2))
#define key_DN (PINB | (1 << 3))
#define key_SEARCH (PINB | (1 << 0))
#define key_TEST (PINB | (1 << 1))
#else
#define key_UP PINB.2
#define key_DN PINB.3
#define key_SEARCH PINB.0
#define key_TEST PINB.1
#endif

/* Pins declaration for IC connector port */
#define BIT_L0 1
#define BIT_L1 2
#define BIT_L2 4
#define BIT_L3 8
#define BIT_L4 16
#define BIT_L5 32
#define BIT_L6 64
#define BIT_L7 128

#define BIT_H0 1
#define BIT_H1 2
#define BIT_H2 4
#define BIT_H3 8
#define BIT_H4 16
#define BIT_H5 32
#define BIT_H6 64
#define BIT_H7 128

#include "test_7400.c"
#include "test_7402.c"
#include "test_7404.c"
#include "test_7406.c"
#include "test_7407.c"
#include "test_7408.c"
#include "test_7410.c"
#include "test_7411.c"
#include "test_7420.c"
#include "test_7427.c"
#include "test_7430.c"
#include "test_7432.c"
#include "test_7438.c"
#include "test_7474.c"
#include "test_7475.c"
#include "test_7486.c"
#include "test_7493.c"
#include "test_74125.c"
#include "test_74138.c"
#include "test_74155.c"
#include "test_74161.c"
#include "test_74166.c"
#include "test_74169.c"
#include "test_74174.c"
#include "test_74175.c"
#include "test_74193.c"
#include "test_74244.c"
#include "test_74245.c"
#include "test_74253.c"
#include "test_74257.c"
#include "test_74295.c"
#include "test_74298.c"
#include "test_74374.c"
#include "test_c4520.c"
#include "test_011.c"
#include "test_019.c"
#include "test_082.c"
#include "test_086.c"

const struct
{
    void (*test)( void );
    char sym[4];
} chips[] = 
{
    { test_7400,    { 0, 0, 13, 13 } }, 
    { test_7402,    { 2, 0, 13, 13 } },
    { test_7404,    { 4, 0, 13, 13 } },
    { test_7406,    { 6, 0, 13, 13 } },
    { test_7407,    { 7, 0, 13, 13 } },
    { test_7408,    { 8, 0, 13, 13 } },        
    { test_7410,    { 0, 1, 13, 13 } }, 
    { test_7411,    { 1, 1, 13, 13 } }, 
    { test_7420,    { 0, 2, 13, 13 } },
    { test_7427,    { 7, 2, 13, 13 } },
    { test_7430,    { 0, 3, 13, 13 } },
    { test_7432,    { 2, 3, 13, 13 } },
    { test_7438,    { 8, 3, 13, 13 } },
    { test_7474,    { 4, 7, 13, 13 } }, 
    { test_7475,    { 5, 7, 13, 13 } },
    { test_7486,    { 6, 8, 13, 13 } },
    { test_7493,    { 3, 9, 13, 13 } },
    { test_74125,   { 5, 2, 1, 13 } },
    { test_74138,   { 8, 3, 1, 13 } },
    { test_74155,   { 5, 5, 1, 13 } },
    { test_74161,   { 1, 6, 1, 13 } },
    { test_74166,   { 6, 6, 1, 13 } }, 
    { test_74169,   { 9, 6, 1, 13 } },
    { test_74174,   { 4, 7, 1, 13 } },
    { test_74175,   { 5, 7, 1, 13 } },
    { test_74193,   { 3, 9, 1, 13 } },
    { test_74244,   { 4, 4, 2, 13 } },
    { test_74245,   { 5, 4, 2, 13 } },
    { test_74253,   { 3, 5, 2, 13 } },
    { test_74257,   { 7, 5, 2, 13 } },
    { test_74295,   { 5, 9, 2, 13 } },
    { test_74298,   { 8, 9, 2, 13 } },
    { test_74374,   { 4, 7, 3, 13 } },
    { test_C4520,   { 0, 2, 17, 13 } },
    { test_011,   { 1, 1, 12, 13 } },
    { test_019,   { 9, 1, 12, 13 } },
    { test_082,   { 2, 8, 12, 13 } },
    { test_086,   { 6, 8, 12, 13 } },
};

#define _ICs (sizeof(chips)/sizeof(chips[0]))

#ifdef __GNUC__
ISR(TIMER0_OVF_vect)
#else
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
#endif
{
	seg++;
	if (seg==0x04) seg=0x00;
	PORTB=~razr[seg];
	Display_P=znak[sym[seg]];    
}


void test(char ic_num)
{
    chips[ic_num].test();
    if (res==1) sym[0]=10;
        else sym[0]=11;
}

void main(void)
{
 
Port_H=0x00;
Direct_H=0x00;

Port_L=0x00;
Direct_L=0x00;

PORTB=0x0F;
DDRB=0xF0;
 
Display_P=0x00;
Display_D=0xFF;

PORTE=0x00;
DDRE=0x00;

TCCR0=0x03;
TCNT0=0x00;
OCR0=0x00;

TIMSK=0x02;

seg=0;
sym[3]=16;
sym[2]=14;
sym[1]=5;
sym[0]=16;

#ifdef __GNUC__
sei();
#else
#asm("sei")
#endif

while (1)
    {
        if (key_UP==0) {
            if (sel< _ICs)
            {
                sel++;
            } else {
                sel=0;
            }
            menu();delay_ms(200);
        }
        while(key_UP==0);
        if (key_DN==0) {
            if (sel>0)
            {
                sel--;
            }
            else {
                sel= _ICs;
            }
             menu();delay_ms(200);
        }     
        while(key_DN==0);
        if (key_SEARCH==0) search();
        while(key_SEARCH==0);
        if (key_TEST==0) 
            {
                if ( sel < _ICs )   // for safety
                    test(sel);
                delay_ms(200);    
            }
    }
}

void menu(void)
    {         
        if ( sel < _ICs )   // for safety
        {
            sym[0] = chips[sel].sym[0];
            sym[1] = chips[sel].sym[1];
            sym[2] = chips[sel].sym[2];
            sym[3] = chips[sel].sym[3];
        }
    } 
    
void search(void)
    {
        int i;
        for ( i = 0; i < _ICs; i ++ )
        {
            test(sel);
            if ( res == 1 )
            {
                sel = i;
                break;
            }
        }
        if ( i >= _ICs )
        {
            sym[0] = sym[1] = sym[2] = sym[3] = 11;
        }
    }                           
      
    
/*else {sym[0]=(Pin_L & 0x0F);
                sym[1]=(Pin_L & 0xF0)>>4;
                sym[2]=(Pin_H & 0x0F);
                sym[3]=(Pin_H & 0xF0)>>4;} */   
