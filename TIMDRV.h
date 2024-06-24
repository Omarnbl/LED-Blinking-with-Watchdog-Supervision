/*
 * TIMDRV.h
 *
 *  Created on: Jun 20, 2024
 *      Author: Hazem
 */

#ifndef TIMDRV_H_
#define TIMDRV_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Std_Types.h"
// Define Timer1 prescaler values
typedef enum {
    TIMER1_PRESCALER_1 = (1 << CS10),
    TIMER1_PRESCALER_8 = (1 << CS11),
    TIMER1_PRESCALER_64 = (1 << CS11) | (1 << CS10),
    TIMER1_PRESCALER_256 = (1 << CS12),
    TIMER1_PRESCALER_1024 = (1 << CS12) | (1 << CS10)
} timer1_prescale_t;

// Function to initialize Timer1 in CTC mode
void timer1_init_ctc(uint16 A_compare_value, uint16 B_compare_value,  timer1_prescale_t prescaler);

// Function to start Timer1
void timer1_start(void);

// Function to stop Timer1
void timer1_stop(void);

// Function to set the A compare value
void timer1_set_A_compare_value(uint16 A_compare_value);

// Function to set the B compare value
void timer1_set_B_compare_value(uint16 B_compare_value);

// Function to enable the A compare match interrupt
void timer1_enable_A_compare_interrupt(void);

// Function to enable the B compare match interrupt
void timer1_enable_B_compare_interrupt(void);

// ISR for Timer1 B compare match
ISR(TIMER1_COMPA_vect);


#endif /* TIMERDRIVER_TIMDRV_H_ */
