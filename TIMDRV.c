/*
 * TIMDRV.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Hazem
 */


#include <TIMDRV.h>

//extern volatile unsigned long counter_for_20ms = 0;
//extern volatile unsigned long counter_for_100ms = 0;
//extern volatile unsigned long counter_for_500ms = 0;

void timer1_init_ctc(uint16 A_compare_value, uint16 B_compare_value,  timer1_prescale_t prescaler) { // A_compare_value = 200 -> 50ms // B_compare_value = 1ms
    // Set Timer1 to CTC mode (Clear Timer on Compare Match)
	// Clear Timer1 Control Registers
	    TCCR1A = 0;
	    TCCR1B = 0;

	TCCR1B |= (1 << WGM12);
    // Set the compare values
    OCR1A = A_compare_value;
    OCR1B = B_compare_value;
    // Set the prescaler
    TCCR1B |= prescaler;
}

void timer1_start(void) {
    // Enable Timer1 by setting the appropriate bits in TCCR1B
    TCCR1B |= (1 << CS10) | (1 << CS11);
}

void timer1_stop(void) {
    // Disable Timer1 by clearing the prescaler bits in TCCR1B
    TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
}

void timer1_set_A_compare_value(uint16 A_compare_value) {
    // Set the compare value
    OCR1A = A_compare_value;
}

void timer1_set_B_compare_value(uint16 B_compare_value) {
    // Set the compare value
    OCR1B = B_compare_value;
}

void timer1_enable_A_compare_interrupt(void) {
    // Enable the Output Compare A Match Interrupt
    TIMSK1 |= (1 << OCIE1A);
}

void timer1_enable_B_compare_interrupt(void) {
    // Enable the Output Compare B Match Interrupt
    TIMSK1 |= (1 << OCIE1B);
}

uint8 flag= 1;
// ISR for Timer1 compare match B
ISR(TIMER1_COMPA_vect) {
    // Toggle LED
//    timer1_milliseconds++;
//	GPIO_Write(2, flag);
//	flag = !flag;
//	counter_for_20ms++;
//	counter_for_100ms++;
//	counter_for_500ms++;
}


//void delay_ms(uint32 delay) {
//    uint32 start_time = timer1_milliseconds; // Get the start time
//    while ((timer1_milliseconds - start_time) < delay) {
//        // Wait until the specified delay has passed
//    }
//}
