/*
 * GPIO.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Hazem
 */


#include "GPIO.h"
#include "Std_Types.h"

#define DDRD   (*(volatile unsigned long *)(0x2A))
#define PORTD (*(volatile unsigned long *)(0x2B))

void GPIO_Init(void) {
    // Set pin PD5 (assuming it's the LED pin) as output
    DDRD |= (1 << 5);
    DDRD |= (1 << 4);
    DDRD |= (1 << 3);
    DDRD |= (1 << 2);
    DDRD |= (1 << 1);
    DDRD |= (1 << 0);

}

void GPIO_Write(uint8 pin, uint8 value) {
    if (value) {
        PORTD |= (1 << pin);
    } else {
        PORTD &= ~(1 << pin);
    }
}
