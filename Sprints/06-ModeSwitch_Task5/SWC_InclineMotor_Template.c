/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 10:56 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotorGetMove
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_InclineMotorIOSetForward
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_InclineMotorIOSetReverse
 *
 */

void RE_InclineMotorGetMove (Impl_StepMotorStepSize Step)
{
	/* Server Call Points */
	if(Step == MOTOR_STEP_PLUS)
	{
	 Rte_Call_rpIOInclineMotor_Opr_InclineMotorForward();
	}
	if(Step == MOTOR_STEP_MINUS)
	{
	 Rte_Call_rpInclineMotorReverse_Opr_InclineMotorReverse();
	}	
	
 
	
}

