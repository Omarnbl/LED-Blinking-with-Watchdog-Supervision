#include "WDGM.h"
#include "Std_Types.h"
static volatile uint8 ledm_manage_call_count;
static volatile unsigned long last_check_time_of_LEDM_call;
static volatile WDGM_StatusType wdgm_status;
static volatile uint8 main_function_status = 1;
static volatile uint8 counter;
extern volatile uint8 number_of_call_main_function;
volatile unsigned long counter_for_100ms;

void WDGM_Init(void){
	ledm_manage_call_count = 0;
	last_check_time_of_LEDM_call = 0;
	wdgm_status = OK;
	counter = 0;

}

void WDGM_MainFunction(void){
	// calc the current time;
	if(counter_for_100ms >= 10){
		GPIO_Write(3, main_function_status);
		main_function_status = !main_function_status;
		if(ledm_manage_call_count >= 8 && ledm_manage_call_count <= 12){
			wdgm_status = OK;
			GPIO_Write(2, wdgm_status);
		}
		else{
			wdgm_status = NOK;
			GPIO_Write(2, wdgm_status);
		}
		counter_for_100ms=0;
		ledm_manage_call_count = 0;

//	uint8 current_time = timer1_milliseconds; // timer1_miliscindes = 250ms -> currenttime   lastchek = 140
//		last_check_time_of_LEDM_call = current_time;
//		counter = 0;
	}

//	if(WDGM_PovideSuppervisionStatus() == OK)
//		GPIO_Write(1, 1);
//	else
//		GPIO_Write(1, 0);

	number_of_call_main_function++;
}


WDGM_StatusType WDGM_PovideSuppervisionStatus(void){
//	if(wdgm_status == OK) wdgm_status = NOK;
//	else wdgm_status = OK;
//	GPIO_Write(3, main_function_status);
	return wdgm_status;
}

void WDGM_AlivenessIndication(void){
	ledm_manage_call_count++;
}
