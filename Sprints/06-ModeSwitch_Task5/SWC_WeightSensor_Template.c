/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 06:20 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_WeightSensor.h"


/**
 *
 * Runnable RE_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_Opr_GetWeight
 *
 */

void RE_GetWeight (uint16* Arg_weight)
{
	Impl_IOWeightSensorRead Arg_Weight;

	/* Server Call Points */
    Rte_Call_rpHwAbsWeight_Opr_GetWeight(&Arg_Weight);
	Arg_weight= (SensorWeightType)(Arg_Weight/1000);
	
}

