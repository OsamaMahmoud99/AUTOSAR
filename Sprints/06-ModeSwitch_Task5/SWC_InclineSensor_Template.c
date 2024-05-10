/**
 *
 * \file SWC_InclineSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 06:16 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineSensor.h"


/**
 *
 * Runnable RE_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineSensor_Opr_InclineSensorGetPosition
 *
 */

void RE_GetPosition (uint8* Arg_Position)
{
	Std_ReturnType status;
	Impl_IOPositionSensorRead Arg_Incline;

	/* Server Call Points */
	status = Rte_Call_rpHwAbsIncline_Opr_IOHwAbsIncline(&Arg_Incline);
	if(Arg_Incline==0)
	{
		Arg_Position=SENSOR_POSITION_STEP_0;
	}
	else if(Arg_Incline==1)
	{
		Arg_Position=SENSOR_POSITION_STEP_1;
	}
	else if(Arg_Incline==2)
	{
		Arg_Position=SENSOR_POSITION_STEP_2;
	}
	else if(Arg_Incline==3)
	{
		Arg_Position=SENSOR_POSITION_STEP_3;
	}
	
	
}

