#ifndef UartLoopBack_H
#define UartLoopBack_H

typedef enum{
	WAIT_DATA,
	WAIT_TO_TX
}LoopbackState;

typedef struct LoopbackData LoopbackData;
struct LoopbackData{
	LoopbackState state;
	char dataByte;
};
void initUartLoopback(LoopbackData *data);
void uartLoopbackSM(LoopbackData *data);

#endif // UartLoopBack_H
