/**
 *
 * \file SWC_SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 06:14 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideSensor.h"


/**
 *
 * Runnable RE_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_GetPositon
 *
 */

void RE_GetPosition (uint8* Position)
{
	Std_ReturnType status;
	Impl_IOPositionSensorRead Arg_Slide;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_Opr_IOHwAbsSlide(&Arg_Slide);
	if(Arg_Slide==0)
	{
		Position=SENSOR_POSITION_STEP_0;
	}
	else if(Arg_Slide==1)
	{
		Position=SENSOR_POSITION_STEP_1;
	}
	else if(Arg_Slide==2)
	{
		Position=SENSOR_POSITION_STEP_2;
	}
	else if(Arg_Slide==3)
	{
		Position=SENSOR_POSITION_STEP_3;
	}
	
}

