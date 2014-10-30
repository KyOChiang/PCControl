#ifndef _CLOCK_H_
#define _CLOCK_H_

#if defined(__XC) || defined(__18CXX)
#else
#define TIMER_INT_OFF  0b01111111  //Disable TIMER Interrupt
#define T0_8BIT        0b11111111  //Timer0 is configured as an 8-bit timer/counter
#define T0_PS_1_8      0b11110010  //1:8 Prescale value
#define T0_SOURCE_INT  0b11011111  //Internal instruction cycle clock (CLKO) acts as source of clock
#endif

void initClock();
unsigned long getCLOCK();
char hasTimer0OverflowFlag();
void clearTimer0OverflowFlag();
#endif //_CLOCK_H_