/*
 * LEDM.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Hazem
 */




#include "ledm.h"
#include "gpio.h"
#include "WDGM.h"
#include <stdint.h>
#include <util/delay.h>

#define LED_PIN 4  // Assuming the LED is connected to GPIO pin 5
volatile uint8_t ledState = 1;
//static volatile unsigned long last_toggle_led = 0;
volatile unsigned long counter_for_500ms;
#include "WDGM.h"


void LEDM_Init(void) {
    GPIO_Init();
    GPIO_Write(LED_PIN, ledState);  // Ensure LED is off initially
}

void LED_Manage(void) {
    // Toggle LED state to ON
//    ledState = 1;
//    GPIO_Write(LED_PIN, ledState);  // Turn LED on

//    // Busy-wait to simulate delay
//    for (volatile uint32_t i = 0; i < 250000; i++) {
//      // Do nothing, just delay
//    }
    if(counter_for_500ms >= 50){
    	ledState = !ledState;
    	GPIO_Write(LED_PIN, ledState);  // Turn LED off
//    	last_toggle_led = timer1_milliseconds;
    	counter_for_500ms =0 ;
    }
	WDGM_AlivenessIndication();

// Toggle LED state to OFF

//    // Busy-wait to simulate delay
//    for (volatile uint32_t i = 0; i < 250000; i++) {
//        // Do nothing, just delay
//    }

//    _delay_ms(500);

}
