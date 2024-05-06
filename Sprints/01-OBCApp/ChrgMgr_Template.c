/**
 *
 * \file ChrgMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: ChrgMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/3/2024 08:13 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_ChrgMgr.h"


/**
 *
 * Runnable ChrgMgr_BatteryLevelHandler
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rp_BatteryInfo_BatteryLevel
 *
 */

void ChrgMgr_BatteryLevelHandler (void)
{
	Std_ReturnType status;
	BatteryLevelType BatteryLevel;

	/* Data Receive Points */
	status = Rte_Read_rp_BatteryInfo_BatteryLevel(&BatteryLevel);
	
}

