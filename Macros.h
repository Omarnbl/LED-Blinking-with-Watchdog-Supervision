/*
 * Macros.h
 *
 *  Created on: Jun 23, 2024
 *      Author: Hazem
 */

#ifndef MACROS_H_
#define MACROS_H_

/*    ----------------WATCH DOG MACROS------------------*/
// Macros for each bit
#define WDE     3  // Watchdog System Reset Enable WDE: Set to 1, bit position 3 (Watchdog System Reset Enab
#define WDCE    4  // Watchdog Change Enable // WDCE: Set to 1, bit position 4 (Watchdog Change Enable)
#define WDRF    3  // Watchdog Reset Flag

// Watchdog Timer Prescaler Macros
#define WDP0    0  // Watchdog Timer Prescaler bit 0 WDP0: Set to 1, bit position 0 (Part of prescaler setting
#define WDP1    1  // Watchdog Timer Prescaler bit 1 WDP1: Set to 0, bit position 1 (Part of prescaler setting
#define WDP2    2  // Watchdog Timer Prescaler bit 2 WDP2: Set to 1, bit position 2 (Part of prescaler setting
#define WDP3    5  // Watchdog Timer Prescaler bit 3 WDP3: Set to 0, bit position 5 (Part of prescaler setting
#define WDIE    6 // WDIE: Set to 0, bit position 6 (Watchdog Interrupt Enable

/*    ----------------GPIO------------------*/
#define DDRD   (*(volatile unsigned long *)(0x2A))
#define PORTD (*(volatile unsigned long *)(0x2B))
/*    ----------------PINS------------------*/
#define TIM0_PIN 0
#define WDG_ResetCounter_PIN 1
#define LedManage_PIN 2
#define WDGM_MainFunction_PIN 3
#define LED_PIN 4  // Assuming the LED is connected to GPIO pin 5
#define MCU_Reset_Pin 5
#endif /* MACROS_H_ */
