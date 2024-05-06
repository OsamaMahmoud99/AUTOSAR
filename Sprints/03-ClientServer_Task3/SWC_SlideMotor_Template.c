/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/6/2024 11:21 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_SlideMotor_Move_Opr_Move
 *
 */

void SlideMotor_Move (StepMotorStepType step)
{
	
	if(step==MOTOR_STEP_MINUS)
	{
		Dio_WriteChannel(Channel_2,OFF);
	}
	else if(step==MOTOR_STEP_PLUS)
	{
		Dio_WriteChannel(Channel_2,ON);
	}

}

