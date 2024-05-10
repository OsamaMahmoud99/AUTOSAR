/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 10:51 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable RE_MotorMove
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Opr_IOSetForward
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Opr_IOSetReverse
 *
 */

void RE_MotorMove (Impl_StepMotorStepSize Step)
{
	/* Server Call Points */
	if(Step == MOTOR_STEP_PLUS)
	{
	 Rte_Call_rpIOHeightMotor_Opr_HeightMotorForward();	
	}
	if(Step == MOTOR_STEP_MINUS)
	{
	Rte_Call_rpHeightMotorReverse_Opr_HeightMotorReverse();	
	}
	
	
}

