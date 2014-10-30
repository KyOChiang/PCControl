#include <stdio.h>
#include <stdlib.h>
#include "Blinky.h"
#include "LoopBack.h"
#include "UartLoopBack.h"
#include "LEDSM.h"
#include "Clock.h"
#include "SevenSeg.h"
#include "..\\18c.h"
#if !(defined(_XC) || defined(_18CXX))
# include <usart.h> //For PC compilation
#else
# include<usart.h>
#endif // !(defined(_XC) || defined(_18CXX))
#define setFreq8Mhz() (OSCCONbits.IRCF = 7)
#define configureUartTo8Bits9600Baud() OpenUSART(USART_TX_INT_OFF &\
						 USART_RX_INT_OFF &\
						 USART_CONT_RX &\
						 USART_EIGHT_BIT &\
						 USART_ASYNCH_MODE &\
						 USART_ADDEN_OFF &\
						 USART_BRGH_HIGH,\
                                        	 51);

#pragma config OSC = INTIO67, DEBUG = ON, WDT = OFF, LVP = OFF


void main(){
    _7SEG _7SegData;
    LEDdata ledData;
    LoopbackData data;

    setFreq8Mhz();
    configureUartTo8Bits9600Baud();
    
    initClock();
    initLEDdata(&ledData);
    initUartLoopback(&data);
    init7Segment(&_7SegData);

    while(1){
        _7SegmentSM(&_7SegData);
        uartLoopbackSM(&data);
        LEDSM(&ledData);
    }
    CloseSPI();
    CloseUSART();
    
}

//;
    //char readData;

    //initUartLoopback(&data);
    //configureUartTo8Bits9600Baud();
	//while(1){
        //	usartLoopBack();
	//}

    //CloseUSART();
    /*while(1){
	onLED();
	makeDelay();
	offLED();
	makeDelay();
    }*/

// while(1){
// WriteUSART(0x6a);
// makeDelay(1250);
// while(BusyUSART());
// makeDelay(1250);
// }
