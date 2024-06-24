/*
 * LEDM.h
 *
 *  Created on: Jun 20, 2024
 *      Author: Hazem
 */

#ifndef LEDM_LEDM_H_
#define LEDM_LEDM_H_

// Initialize internal variables for LED management.
void LEDM_Init(void);

/*  1- Manage LED blinking actions using the GPIO_Write function.
    2- Ensure the LED toggles every 500ms.
    3- Call this function every 10ms in the main loop.
*/
void LEDM_Manage(void);

#endif /* LEDM_LEDM_H_ */
