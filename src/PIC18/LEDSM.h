#ifndef _LEDSM_H_
#define _LEDSM_H_
#define HALF_SEC 488
typedef enum{
	LED_OFF,
	LED_ON,
	LED_START
}LEDState;

typedef struct{
	LEDState state;
	unsigned long currentCLOCK;
}LEDdata;
void initLEDdata(LEDdata *data);
void LEDSM(LEDdata *data);
#endif //_LEDSM_H_