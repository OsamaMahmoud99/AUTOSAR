/**
 *
 * \file SWC_HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 05:59 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightSensor.h"


/**
 *
 * Runnable RE_HeightSensorGetPositon
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_Opr_HeightSensorGetPosition
 *
 */

void RE_HeightSensorGetPositon (Impl_IOPositionSensorRead* Positon)
{
	
	Impl_IOPositionSensorRead Arg_Height;

	/* Server Call Points */
	Rte_Call_rpHeightSensor_Opr_HeightSensorGetPosition(&Arg_Height);
	if(Arg_Height==0)
	{
		Positon=SENSOR_POSITION_STEP_0;
	}
	else if(Arg_Height==1)
	{
		Positon=SENSOR_POSITION_STEP_1;
	}
	else if(Arg_Height==2)
	{
		Positon=SENSOR_POSITION_STEP_2;
	}
	else if(Arg_Height==3)
	{
		Positon=SENSOR_POSITION_STEP_3;
	}
	
	
}

