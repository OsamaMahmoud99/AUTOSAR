/*
 * DoorLock_indication_SWC.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Osama
 */


#include "RTE/Rte_DoorLock_indication_SWC.h"

#define LEDON    0
#define LEDOFF   1
 void DoorLock_indication_runnable(void)
 {
	 unsigned char DoorState = 0;
	 DoorState = Rte_IRead_DoorLock_indication_SWC_DoorLock_indication_RP_SR_DOORState_DoorState();

	 if(DoorState)
	 {
		 Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch(LEDON);
	 }
	 else
	 {
		 Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch(LEDOFF);

	 }
 }
