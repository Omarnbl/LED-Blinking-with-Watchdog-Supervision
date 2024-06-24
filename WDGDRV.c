/*
 * WDGDRV.c
 *
 *  Created on: Jun 19, 2024
 *      Author: hazem
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "Std_Types.h"
#include "WDGM.h"


volatile uint8 number_of_call_main_function;
//#define WDTCSR   (*(volatile unsigned long *)0x60)
//#define MCUSR  (*(volatile unsigned long *) 0x54)

#define WDT_TIMEOUT_MS 64
#define WDT_PRESCALER_VALUE (1<<WDP2) | (1<<WDP0)

//void WDGDrv_Init(void) {
//    cli(); // Disable interrupts temporarily to ensure atomic access to WDT configuration // Make it from scratch
//
//
//    MCUSR &= ~(1<<3); // Clear the Watchdog Reset Flag (WDRF) at bit 3 of the MCUSR register
//
////    // Set up Watchdog for both interrupt and system reset
////    WDTCSR = (0<<0) |  // WDP0: Set to 1, bit position 0 (Part of prescaler settings)
////             (1<<1) |  // WDP1: Set to 0, bit position 1 (Part of prescaler settings)
////             (0<<2) |  // WDP2: Set to 1, bit position 2 (Part of prescaler settings)
////			 (1<<3) |  // WDE: Set to 1, bit position 3 (Watchdog System Reset Enable)
////			 (1<<4) |  // WDCE: Set to 1, bit position 4 (Watchdog Change Enable)
////			 (0<<5) |  // WDP3: Set to 0, bit position 5 (Part of prescaler settings)
////             (0<<6) |  // WDIE: Set to 0, bit position 6 (Watchdog Interrupt Enable)
////             (0<<7);   // WDE: Set to 0, bit position 7 (Watchdog Interrupt Flag)
////
////
//    // Start timed sequence to update WDT configuration
//    WDTCSR |= (1 << WDCE) | (1 << WDE); // Enable configuration changes
//
//    // Configure WDT: System Reset mode with prescaler set for approximately 64ms timeout
//    WDTCSR = (0 << WDP3) | (1 << WDP2) | (0 << WDP1) | (0 << WDP0) | (1 << WDE);
//
//    sei(); // Re-enable interrupts after configuration is complete // Make it from scratch
//}

void WDGDrv_Init(void) {
    cli(); // Disable interrupts temporarily to ensure atomic access to WDT configuration

    MCUSR &= ~(1 << WDRF); // Clear the Watchdog Reset Flag (WDRF)

    // Start timed sequence to update WDT configuration
    WDTCSR |= (1 << WDCE) | (1 << WDE); // Enable configuration changes

    // Configure WDT: System Reset mode with prescaler set for approximately 64ms timeout
    WDTCSR = (0 << WDP3) | (1 << WDP2) | (0 << WDP1) | (0 << WDP0) | (1 << WDE);

    sei(); // Re-enable interrupts after configuration is complete
}

volatile uint8 flag2 = 0;

ISR(TIMER1_COMPB_vect) {
	volatile WDGM_StatusType flag = WDGM_PovideSuppervisionStatus();
	if(number_of_call_main_function >= 2){
		if(flag == OK){
			GPIO_Write(0, 0);
			wdt_reset(); // Reset the watchdog timer
			number_of_call_main_function = 0;
		}
		else{
			GPIO_Write(1, 1);
		}
	}

//	if(flag2 == 1){
//		GPIO_Write(0, 1);
////		wdt_reset(); // Reset the watchdog timer
//		flag2 = 0;
//	}
//	else
//		GPIO_Write(0, 0);


}





