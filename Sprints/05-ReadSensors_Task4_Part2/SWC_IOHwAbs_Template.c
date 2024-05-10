/**
 *
 * \file SWC_IOHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IOHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/15/2024 11:40 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_IOHwAbs.h"
#include "Adc.h"
#include "Spi.h"

/**
 *
 * Runnable RE_HeightMotorSetForward
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Opr_HeightMotorForward
 *
 */
static Adc_ValueGroupType IoHwAb_PositionSensorReadings[ADC_GRO_NUM_CHANNELS]=
{
	0, /*height*/
	0, /*slide*/
	0  /*incline*/
}
void RE_HeightMotorSetForward (void)
{
	Dio_WriteChannel(DioConfig_DioChannel_HeightMotorCh,STD_HIGH);

}


/**
 *
 * Runnable RE_HeightMotorSetReverse
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotorReverse_Opr_HeightMotorReverse
 *
 */

void RE_HeightMotorSetReverse (void)
{
   Dio_WriteChannel(DioConfig_DioChannel_HeightMotorCh,STD_LOW);

}


/**
 *
 * Runnable RE_HeightSensorGetPositon
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_Opr_HeightSensorGetPosition
 *
 */

void RE_HeightSensorGetPositon (Impl_IOPositionSensorRead* Arg_Height)
{
	Std_ReturnType status;
    status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorReadings[0]);  //in another project we can use different ADC groups
	if(status==E_OK)
	{
		Arg_Height=(IoPositionSensorReadingType)IoHwAb_PositionSensorReadings[0];
	}
	else 
	{
		
	}
}


/**
 *
 * Runnable RE_IoHwAbsGetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_Opr_GetWeight
 *
 */

void RE_IoHwAbsGetWeight (Impl_IOWeightSensorRead* Arg_Weight)
{
	Std_ReturnType status;
    status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor,&SpiData);
	if(statues==E_OK)
	{
		Arg_Weight=(IoWeightSensorReadingType)SpiData;
	}
	else
	{
		
	}
}


/**
 *
 * Runnable RE_SlideMotorSetForward
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_SLideMotorForward
 *
 */

void RE_SlideMotorSetForward (void)
{
	Dio_WriteChannel(DioConfig_DioChannel_SlideMotorCh,STD_HIGH);

}


/**
 *
 * Runnable RE_SlideMotorSetReverse
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotorReverse_Opr_SlideMotorReverse
 *
 */

void RE_SlideMotorSetReverse (void)
{
	Dio_WriteChannel(DioConfig_DioChannel_SlideMotorCh,STD_LOW);
}


/**
 *
 * Runnable RE_InclineMotorSetForward
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_InclineMotorForward
 *
 */

void RE_InclineMotorSetForward (void)
{
    Dio_WriteChannel(DioConfig_DioChannel_InclineMotorCh,STD_HIGH);

}


/**
 *
 * Runnable RE_InclineMotorSetReverse
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotorReverse_Opr_InclineMotorReverse
 *
 */

void RE_InclineMotorSetReverse (void)
{
    Dio_WriteChannel(DioConfig_DioChannel_InclineMotorCh,STD_LOW); 
}


/**
 *
 * Runnable RE_InclineSensorGetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineSensor_Opr_IOHwAbsIncline
 *
 */

void RE_InclineSensorGetPosition (Impl_IOPositionSensorRead* Arg_Incline)
{
	Std_ReturnType status;
    status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorReadings[1]);
	if(status==E_OK)
	{
		Arg_Incline=(IoPositionSensorReadingType)IoHwAb_PositionSensorReadings[1];
	}
	else
	{
		
	}
}


/**
 *
 * Runnable RE_SlideSensorGetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_IOHwAbsSlide
 *
 */

void RE_SlideSensorGetPosition (Impl_IOPositionSensorRead* Arg_Slide)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorReadings[2]);
	if(status==E_OK)
	{
		Arg_Slide=(IoPositionSensorReadingType)IoHwAb_PositionSensorReadings[2];
	}
	else
	{
		
	}

}

