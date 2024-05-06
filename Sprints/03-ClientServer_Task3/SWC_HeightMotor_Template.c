/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/6/2024 11:21 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_HeightMotor_Move_Opr_Move
 *
 */

void HeightMotor_Move (StepMotorStepType step)
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

