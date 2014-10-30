#include <stdio.h>
#include <stdlib.h>
#include "Blinky.h"
#include "..\\18c.h"
#if !(defined(_XC) || defined(_18CXX))
#include <usart.h> //For PC compilation
#endif // !(defined(_XC) || defined(_18CXX))

#pragma config OSC = INTIO67, DEBUG = ON, WDT = OFF, LVP = OFF

void onLED(){
    PORTCbits.RC0 = 1;
}

void offLED(){
    PORTCbits.RC0 = 0;
}

void makeDelay(int loop){
    int i = 0;
    for(i = 0; i < loop; i++);
}

void configureLED(){
    TRISCbits.RC0 = 0;
}

void blinkySM(){
}




