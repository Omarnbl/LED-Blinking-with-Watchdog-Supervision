/*
 * TIM0DRV.h
 *
 *  Created on: Jun 22, 2024
 *      Author: Hazem
 */

#ifndef TIM0DRV_H_
#define TIM0DRV_H_


#include <avr/io.h>
#include <avr/interrupt.h>

// Define Timer1 prescaler values
typedef enum {
    TIMER0_PRESCALER_1 = (1 << CS10),
    TIMER0_PRESCALER_8 = (1 << CS11),
    TIMER0_PRESCALER_64 = (1 << CS11) | (1 << CS10),
    TIMER0_PRESCALER_256 = (1 << CS12),
    TIMER0_PRESCALER_1024 = (1 << CS12) | (1 << CS10)
} timer0_prescale_t;

// Function to initialize Timer1 in CTC mode
void timer0_init_ctc(uint16_t A_compare_value, uint16_t B_compare_value,  timer0_prescale_t prescaler);

// Function to start Timer1
void timer0_start(void);

// Function to stop Timer1
void timer0_stop(void);

// Function to set the A compare value
void timer0_set_A_compare_value(uint16_t compare_value);

// Function to set the B compare value
void timer0_set_B_compare_value(uint16_t B_compare_value);

// Function to enable the A compare match interrupt
void timer0_enable_A_compare_interrupt(void);

// Function to enable the B compare match interrupt
void timer0_enable_B_compare_interrupt(void);


// ISR for Timer1 A compare match
ISR(TIMER0_COMPA_vect);

// ISR for Timer1 B compare match
ISR(TIMER0_COMPB_vect);
#endif /* TIM0DRV_H_ */
