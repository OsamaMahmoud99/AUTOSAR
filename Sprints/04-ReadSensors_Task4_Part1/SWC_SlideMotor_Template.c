/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/11/2024 05:30 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable RE_MoveOperation
 *
 * Triggered By:
 *
 */

void RE_MoveOperation (uint8 Arg_MOTORSTEP)
{
	if(Arg_MOTORSTEP==MOTOR_STEP_MINUS)
	{
		Dio_WriteChannel(Channel_2,OFF);
		status= E_OK;
	}
	else if(Arg_MOTORSTEP==MOTOR_STEP_PLUS)
	{
		Dio_WriteChannel(Channel_2,ON);
		status= E_OK;
	}
	Std_Ret
