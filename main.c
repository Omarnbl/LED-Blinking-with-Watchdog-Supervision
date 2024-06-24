/*
 * main.c
 *
 *  Created on: Jun 19, 2024
 *      Author: Hazem
 */


#include <avr/io.h>
#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "GPIO.h"
#include "WDGM.h"
#include "WDGDRV.h"
#include "LEDM.h"
#include "TIMDRV.h"
#include <util/delay.h>
#include "TIM0DRV.h"
volatile unsigned long counter_for_20ms;

int main(void) {

    GPIO_Init();
	GPIO_Write(5, 1); //START POINT OF THE CODE
    LEDM_Init();
    WDGDrv_Init();
    WDGM_Init();

//	SREG |= 1 << 7;
	// Enable global interrupts
	sei();
	timer1_init_ctc(49, 10, TIMER1_PRESCALER_1024); // Initialize Timer1 in CTC mode with a compare value
	timer1_enable_A_compare_interrupt(); // Enable the compare match interrupt
//	timer1_enable_B_compare_interrupt();
	timer0_init_ctc(10, 10, TIMER0_PRESCALER_1024); // Initialize Timer1 in CTC mode with a compare value
	timer0_enable_A_compare_interrupt(); // Enable the compare match interrupt
//	timer1_enable_B_compare_interrupt();
	volatile unsigned long last_wdgm_check_time = 0;

    while (1) {
        LED_Manage();
        _delay_ms(10);
        LED_Manage();
        _delay_ms(10);
        WDGM_MainFunction();
//        if ((counter_for_20ms) >= 2) {
////				last_wdgm_check_time = timer1_milliseconds;
//				counter_for_20ms=0;
//		}
        //Set PD5 low and PD4 high

     }

    return 0;
}
