#include "Clock.h"
#include "..\\18c.h"

unsigned long clock = 0;

void initClock(){
    clock = 0;
    OpenTimer0(TIMER_INT_OFF & T0_8BIT & T0_SOURCE_INT & T0_PS_1_8);
}

/**
 *	Return the microcontroller's clock since power-up.
 *	1 clock = 1.024 mSec
 */
unsigned long getCLOCK(){
	if(hasTimer0OverflowFlag()){
		clearTimer0OverflowFlag();
		clock++;
	}
	return clock;
}

/////////////////////////////
//These functions for internal use only.
////////////////////////////
char hasTimer0OverflowFlag(){
	return INTCONbits.TMR0IF;
}

void clearTimer0OverflowFlag(){
	INTCONbits.TMR0IF = 0;
}
