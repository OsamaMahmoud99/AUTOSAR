/********************************************************************
 * Automatically generated by ARUnit
 * Filename: Rte_DoorLock_indication_SWC_.c
 * Generated on: Wed May 17 13:3:22 EDT
 ********************************************************************/

#include "string.h"
#include "Rte_DoorLock_indication_SWC.h"

Rte_DE_myuint8 ReadDoorSensor_PP_SRI_DoorState;

Rte_DE_myuint8 DoorLock_indication_RP_SR_DOORState_DoorState;


const Rte_CDS_DoorLock_indication_SWC Rte_Instance_DoorLock_indication_SWC = {
&ReadDoorSensor_PP_SRI_DoorState
};

const Rte_CDS_DoorLock_indication_SWC * const Rte_Inst_DoorLock_indication_SWC = &Rte_Instance_DoorLock_indication_SWC;


Std_ReturnType DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch_Buffer_retcode = RTE_E_OK;

FunctionPtr_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch_Delegate = 0;

myuint8 Rte_IRead_DoorLock_indication_SWC_DoorLock_indication_RP_SR_DOORState_DoorState (void)
{
	return (Rte_Inst_DoorLock_indication_SWC)->DoorLock_indication_RP_SR_DOORState_DoorState->value;
}
Std_ReturnType Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch (myuint8 LedState)
{
	Std_ReturnType __result = DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch_Buffer_retcode;
	if ( Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch_Delegate != 0 ) {
		__result = Rte_Call_DoorLock_indication_SWC_RP_CS_LedSwitch_Led_switch_Delegate(LedState);
	}

	Led_Switch_runnable(LedState);
	return __result;
}
