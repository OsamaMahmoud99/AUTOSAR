/**
 *
 * \file ChrgIf_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: ChrgIf
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/3/2024 08:13 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_ChrgIf.h"


/**
 *
 * Runnable ChrgIf_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_ChrgIf_MainFunction_100ms
 *
 */

void ChrgIf_MainFunction (void)
{
	Std_ReturnType status;
	BatteryLevelType BatteryLevel;

	/* Data Send Points */
	status = Rte_Write_pp_BatteryInfo_BatteryLevel(BatteryLevel);
	
	/* Add your logic */
	
}

