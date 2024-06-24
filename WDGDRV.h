/*
 * WDGDRV.h
 *
 *  Created on: Jun 19, 2024
 *      Author: hazem
 */

#ifndef WDGDRV_H_
#define WDGDRV_H_

/*
    1- Configure the watchdog driver with a maximum timeout value of 50ms.
    2- Disable window mode.
    3- Enable the early interrupt feature.
    4- Activate the watchdog.
*/
void WDGDrv_Init(void);

/*
    1- Check if WDGM_MainFunction is not stuck.
    2- Check if WDGM state is OK using WDGM_ProvideSupervisionStatus.
    3- Refresh the watchdog timer if conditions are met; otherwise, allow reset.
*/
//void WDGDrv_IsrNotification(void);

// ISR for Timer1 compare match
ISR(TIMER1_COMPB_vect);



#endif /* WDGDRV_WDGDRV_H_ */
