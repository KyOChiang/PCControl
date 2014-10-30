#include "LoopBack.h"
#include "usart.h"
#include "..\\18c.h"

void usartLoopBack(){
	unsigned char data;
	while(!DataRdyUSART());
	data = getcUSART();
	while(BusyUSART());
	putcUSART(data);
}