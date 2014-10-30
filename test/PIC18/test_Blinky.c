#include "unity.h"
#include "Blinky.h"
#include "p18f4520.h"

void setUp(void){}

void tearDown(void){}

void test_configureLED_set_portc_pin_0_as_output(){
	TRISCbits.RC0 = PIN_INPUT;
	configureLED();
	TEST_ASSERT_EQUAL(PIN_OUTPUT, TRISCbits.RC0);
}

void test_setLED_set_portc_pin_0_to_high(){
	PORTCbits.RC0 = PIN_LOW;
	onLED();
	TEST_ASSERT_EQUAL(PIN_HIGH, PORTCbits.RC0);
}


void test_resetLED_set_portc_pin_0_to_low(){
	PORTCbits.RC0 = PIN_HIGH;
	offLED();
	TEST_ASSERT_EQUAL(PIN_LOW, PORTCbits.RC0);
}


