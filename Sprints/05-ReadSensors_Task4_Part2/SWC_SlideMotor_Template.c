/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 10:53 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable RE_GetForward
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_SlideMotor_SetForrward
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_SlideMotorSetReverse
 *
 */

void RE_SlideMotorGetMove (Impl_StepMotorStepSize Step)
{
	/* Server Call Points */
	if(Step == MOTOR_STEP_PLUS)
	{
	 Rte_Call_rpIOSlideMotor_Opr_SLideMotorForward();
	}
	if(Step == MOTOR_STEP_MINUS)
	{
	Rte_Call_rpSlideMotorReverse_Opr_SlideMotorReverse();
	}	
	
}

