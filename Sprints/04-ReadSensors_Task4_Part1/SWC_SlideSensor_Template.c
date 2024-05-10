/**
 *
 * \file SWC_SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/11/2024 05:30 AM
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
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_GetPosition
 *
 */

void RE_GetPosition (uint8* Arg_position)
{
	Adc_ReadGroup(Group_2,Arg_position);
	Std_ReturnType status;

}

