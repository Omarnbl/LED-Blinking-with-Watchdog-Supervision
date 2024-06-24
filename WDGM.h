/*
 * WDGM.h
 *
 *  Created on: Jun 10, 2024
 *      Author: Hazem
 */

#ifndef WDGM_H_
#define WDGM_H_
#include "Std_Types.h"

typedef enum
{
    OK = 0,
    NOK = 1
} WDGM_StatusType;


// Initialize internal variables for watchdog management.
void WDGM_Init(void);

// Provide the status of the LEDM entity to the WDGDrv.
void WDGM_MainFunction(void);

// Called from LEDM_Manage to detect the correct timing of its calls.
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);

/*
    Check the number of calls of LEDM_Manage within a 100ms period.
    Determine the status based on the number of calls.
    Call this function every 20ms.
*/
void WDGM_AlivenessIndication(void);


#endif /* WDGM_H_ */
