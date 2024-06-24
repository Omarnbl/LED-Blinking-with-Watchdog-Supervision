/*
 * TIM0DRV.c
 *
 *  Created on: Jun 22, 2024
 *      Author: Hazem
 */


# include "TIM0DRV.h"

extern volatile unsigned long counter_for_20ms = 0;
extern volatile unsigned long counter_for_100ms = 0;
extern volatile unsigned long counter_for_500ms = 0;

void timer0_init_ctc(uint16_t A_compare_value, uint16_t B_compare_value,  timer0_prescale_t prescaler) {
    // Set Timer0 to CTC mode (Clear Timer on Compare Match)
    TCCR0A |= (1 << WGM01);
    // Set the compare values
    OCR0A = A_compare_value;
    OCR0B = B_compare_value;
    // Set the prescaler
    TCCR0B |= prescaler;
}


void timer0_start(void) {
    // Enable Timer0 by setting the appropriate bits in TCCR0B
    TCCR0B |= (1 << CS00);
}


void timer0_stop(void) {
    // Disable Timer0 by clearing the prescaler bits in TCCR0B
    TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}


void timer0_set_A_compare_value(uint16_t A_compare_value) {
    // Set the compare value
    OCR0A = A_compare_value;
}


void timer0_set_B_compare_value(uint16_t B_compare_value) {
    // Set the compare value
    OCR0B = B_compare_value;
}


void timer0_enable_A_compare_interrupt(void) {
    // Enable the Output Compare A Match Interrupt
    TIMSK0 |= (1 << OCIE0A);
}


void timer0_enable_B_compare_interrupt(void) {
    // Enable the Output Compare B Match Interrupt
    TIMSK0 |= (1 << OCIE0B);
}


// ISR for Timer0 compare match A
ISR(TIMER0_COMPA_vect) {
	counter_for_20ms++;
	counter_for_100ms++;
	counter_for_500ms++;
}


// ISR for Timer0 compare match B
ISR(TIMER0_COMPB_vect) {

}
