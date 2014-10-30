#include "LEDSM.h"
#include "Blinky.h"
#include "Clock.h"

void initLEDdata(LEDdata *data){
	data->state = LED_START;
	data->currentCLOCK = 0;
}

void LEDSM(LEDdata *data){
	unsigned long totalClock = getCLOCK() - data->currentCLOCK;
	switch(data->state){
		case LED_START:
			data->state = LED_OFF;
			data->currentCLOCK = getCLOCK();
			configureLED();
			offLED();
			break;
		case LED_OFF:
			if(totalClock >= HALF_SEC){
				onLED();
				data->state = LED_ON;
				data->currentCLOCK = getCLOCK();
			}
			break;
		case LED_ON:
			if(totalClock >= HALF_SEC){
				offLED();
				data->state = LED_OFF;
				data->currentCLOCK = getCLOCK();
			}
			break;
		default:
			// should not reach here
			break;
	}
}