/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/16/2024 12:34 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"


/**
 *
 * Runnable RE_AutoHeight
 *
 * Triggered By:
 *
 */
boolean IsAdjustReadNeeded(uint8 Arg_position,uint8 Arg_weight,uint8* step)
  {
	  boolean AdjustMotor= FALSE;
	  switch(Arg_position)
	  {
		  case SENSOR_POSITION_STEP_0:
		  if(Arg_weight>60)
		  {
			  step=MOTOR_STEP_PLUS;
			  AdjustMotor=TRUE;
		  }
		  break;
		   case SENSOR_POSITION_STEP_1:
		   if(Arg_weight > 80)
		   {
			   step=MOTOR_STEP_PLUS;
			  AdjustMotor=TRUE;
		   }
		   else if(Arg_weight>=60 && Arg_weight<=80)
		  {
			  /*position OK*/
		  }
		  else
		  {
			  step=MOTOR_STEP_MINUS;
			  AdjustMotor=TRUE;
		  }
		  break;
		  case SENSOR_POSITION_STEP_2:
		  if(Arg_weight < 100)
		  {
			  step=MOTOR_STEP_PLUS;
			  AdjustMotor=TRUE;
			  
		  }
		  else if(Arg_weight<=100 && Arg_weight>=80)
		  {
			/*Position OK*/
		  }
		  else 
		  {
			  step=MOTOR_STEP_PLUS;
			  AdjustMotor=TRUE;  
		  }
		  break;
		  case SENSOR_POSITION_STEP_3;
		  if(Arg_weight<100)
		  {
			  step=MOTOR_STEP_MINUS;
			  AdjustMotor=TRUE;  
		  }
		  break;
		  
		 default:
		  /*Nothing*/
		  break;
	  }
	  return AdjustMotor;
	  
  }
void RE_AutoHeight (void)
{
	Std_ReturnType status;
	Impl_IOPositionSensorRead Arg_Position;
	Impl_IOPositionSensorRead Position;
	uint16 Arg_weight;

	/* Server Call Points */
	
	status = Rte_Call_rpHeightSensor_Opr_HeightSensorGetPosition(&Position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustNeed = (Position,Arg_weight,&Arg_Position);
	if(AdjustNeed==TRUE)
	{
		Rte_Call_rpHeightMotor_Opr_GetPosition(Arg_Position);
	}
}


/**
 *
 * Runnable RE_AutoIncline
 *
 * Triggered By:
 *
 */

void RE_AutoIncline (void)
{
	Std_ReturnType status;
	Impl_IOPositionSensorRead Arg_Position;
	uint8 Arg_Position0;
	uint16 Arg_weight;

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_GetPosition(Arg_Position);
	status = Rte_Call_rpInclineSensor_Opr_InclineSensorGetPosition(&Arg_Position0);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustNeed = (Arg_Position0,Arg_weight,&Arg_Position);
	if(AdjustNeed==TRUE)
	{
		Rte_Call_rpInclineMotor_Opr_GetPosition(Arg_Position);
	}
	
}


/**
 *
 * Runnable RE_AutoSlide
 *
 * Triggered By:
 *
 */

void RE_AutoSlide (void)
{
	Std_ReturnType status;
	Impl_IOPositionSensorRead Arg_Position2;
	uint8 Position;
	uint16 Arg_weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_Opr_GetPositon(&Position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustNeed = (Position,Arg_weight,&Arg_Position2);
	if(AdjustNeed==TRUE)
	{
		Rte_Call_rpSlideMotor_Opr_GetPositon(Arg_Position2);
	}
}

