/*
 * DoorSensorAbstractionSWC.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Osama
 */


#include "RTE/Rte_DoorSensorAbstractionSWC.h"
#include "MCAL/DIO/DIO.h"

/*****************************************************
 * Port: 		PP_CS_LEDSwitch
 * Interface:	IF_CS_LED
 * Operation:	Led_switch
 *****************************************************/

#define LEDON    0
#define LEDOFF   1

Std_ReturnType Led_Switch_runnable(myuint8 LedState)
{

	if(LedState == LEDON)
	{
		Dio_WriteChannel(LED_ID, LEDON);
		return RTE_E_IF_CS_LED_E_ok;
	}
	else if(LedState == LEDOFF)
	{
		Dio_WriteChannel(LED_ID, LEDOFF);
		return RTE_E_IF_CS_LED_E_ok;
	}
	else
	{
		return RTE_E_IF_CS_LED_E_Not_ok;
	}

}


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	ReadDoorSensor
 * Period:		0.01
 *****************************************************/
void ReadDoorSensor_runnable(void)
{
	myuint8 DoorState;

	DoorState = Dio_ReadChannel(DOOR_ID);

	Rte_IWrite_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SRI_DoorState(DoorState);
}
