
#ifndef _BLINKY_H
#define	_BLINKY_H

#define PIN_LOW 0
#define PIN_HIGH 1
#define PIN_INPUT 1
#define PIN_OUTPUT 0

void onLED();
void offLED();
void makeDelay(int loop);
void configureLED();
void blinkySM();
#endif	

