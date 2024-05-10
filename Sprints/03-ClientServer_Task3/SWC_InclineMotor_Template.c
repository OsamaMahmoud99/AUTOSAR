/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/6/2024 11:21 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pp_InclineMotor_Move_Opr_Move
 *
 */

void InclineMotor_Move (StepMotorStepType step)
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
