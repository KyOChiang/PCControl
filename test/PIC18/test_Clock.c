#include "unity.h"
#include "Clock.h"
#include "p18f4520.h"
#include "mock_timers.h"
extern unsigned long clock;
void setUp(void){}

void tearDown(void){}

void test_initClock(){
	clock = 1234;
	OpenTimer0_Expect(TIMER_INT_OFF & T0_8BIT & T0_SOURCE_INT & T0_PS_1_8);
	initClock();
	TEST_ASSERT_EQUAL(0,clock);
}

void test_hasTimer0OverflowFlag_given_not_yet_overflowed_should_return_FALSE(){
	INTCONbits.TMR0IF = 0;
	TEST_ASSERT_FALSE(hasTimer0OverflowFlag());
}

void test_hasTimer0OverflowFlag_given_overflowed_should_return_TRUE(){
	INTCONbits.TMR0IF = 1;
	TEST_ASSERT_TRUE(hasTimer0OverflowFlag());
}

void test_clearTimer0OverflowFlag_given_should_set_Timer0_overflow_FLAG_to_0(){
	INTCONbits.TMR0IF = 1;
	clearTimer0OverflowFlag();
	TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}

void test_getCLOCK_should_return_clock_with_1_if_got_Timer0overflowFlag(){
	unsigned long returnCLOCK;
	INTCONbits.TMR0IF = 1;
	OpenTimer0_Expect(TIMER_INT_OFF & T0_8BIT & T0_SOURCE_INT & T0_PS_1_8);
	initClock();
	returnCLOCK = getCLOCK();
	TEST_ASSERT_EQUAL(1,returnCLOCK);
	TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}

void test_getCLOCK_should_not_increment_clock_if_got_no_Timer0overflowFlag(){
	unsigned long returnCLOCK;
	INTCONbits.TMR0IF = 0;
	OpenTimer0_Expect(TIMER_INT_OFF & T0_8BIT & T0_SOURCE_INT & T0_PS_1_8);
	initClock();
	returnCLOCK = getCLOCK();
	TEST_ASSERT_EQUAL(0,returnCLOCK);
	TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}






