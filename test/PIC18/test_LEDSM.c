#include "unity.h"
#include "mock_Clock.h"
#include "LEDSM.h"
#include "Blinky.h"
#include "p18f4520.h"

void setUp(void){}

void tearDown(void){}

void test_initLEDdata(){
	LEDdata data;
	initLEDdata(&data);
	TEST_ASSERT_EQUAL(LED_START,data.state);
}

void test_LEDSM_given_LED_START_should_set_state_to_OFF_and_get_clock_to_currentCLOCK(){
	LEDdata data;
	initLEDdata(&data);
	getCLOCK_ExpectAndReturn(1);
	getCLOCK_ExpectAndReturn(1);
	LEDSM(&data);
	TEST_ASSERT_EQUAL(LED_OFF,data.state);
	TEST_ASSERT_EQUAL(1,data.currentCLOCK);
}

void test_LEDSM_should_not_change_LEDState_to_ON_if_less_than_half_second(){
	LEDdata data = {.state = LED_OFF, .currentCLOCK = 0};
	getCLOCK_ExpectAndReturn(100);
	LEDSM(&data);
	TEST_ASSERT_EQUAL(LED_OFF,data.state);
	TEST_ASSERT_EQUAL(0,data.currentCLOCK);
}

void test_LEDSM_should_change_LEDState_to_ON_if_more_than_half_second(){
	LEDdata data = {.state = LED_OFF, .currentCLOCK = 0};
	getCLOCK_ExpectAndReturn(488);
	getCLOCK_ExpectAndReturn(488);
	LEDSM(&data);
	TEST_ASSERT_EQUAL(LED_ON,data.state);
	TEST_ASSERT_EQUAL(488,data.currentCLOCK);
}

void test_LEDSM_should_not_change_LEDState_to_OFF_if_less_than_half_second(){
	LEDdata data = {.state = LED_ON, .currentCLOCK = 100};
	getCLOCK_ExpectAndReturn(333);
	LEDSM(&data);
	TEST_ASSERT_EQUAL(LED_ON,data.state);
	TEST_ASSERT_EQUAL(100,data.currentCLOCK);
}

void test_LEDSM_should_change_LEDState_to_OFF_if_more_than_half_second(){
	LEDdata data = {.state = LED_ON, .currentCLOCK = 100};
	getCLOCK_ExpectAndReturn(588);
	getCLOCK_ExpectAndReturn(588);
	LEDSM(&data);
	TEST_ASSERT_EQUAL(LED_OFF,data.state);
	TEST_ASSERT_EQUAL(588,data.currentCLOCK);
}