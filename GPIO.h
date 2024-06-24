/*
 * GPIO.h
 *
 *  Created on: Jun 10, 2024
 *      Author: Hazem
 */

#ifndef GPIO_H_
#define GPIO_H_


// Initialize GPIO configuration for the pin controlling the LED.
void GPIO_Init(void);

// Write a specific value (0 or 1) to the pin to turn the LED on or off.
void GPIO_Write(unsigned char PinId, unsigned char PinData);


#endif /* GPIO_H_ */
