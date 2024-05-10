/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/11/2024 05:41 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManager.h"


/**
 *
 * Runnable RE_AutoSetHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_AutoSetHeight_200ms
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
void RE_AutoSetHeight (void)
{
	Std_ReturnType status;
	uint8 step;
	uint8 Arg_position;
	uint8 Arg_weight;
    boolean AdjustRead;

	/* Server Call Points */
	 
	status = Rte_Call_rpHeightSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustRead=IsAdjustReadNeeded(Arg_position,Arg_weight,&step);
	if(AdjustRead==TRUE)
	{
	  Rte_Call_rpHeightMotor_Opr_MoveOperation(step);	
	}
	
}

/**
 *
 * Runnable RE_AutoSetIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_AutoSetIncline_200ms
 *
 */

void RE_AutoSetIncline (void)
{
	Std_ReturnType status;
	uint8 Arg_MotorRead;
	uint8 Arg_position;
	uint8 Arg_weight;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustRead=IsAdjustReadNeeded(Arg_position,Arg_weight,&Arg_MotorRead);
	if(AdjustRead==TRUE)
	{
	  Rte_Call_rpInclineMotor_Opr_MoveOperation(Arg_MotorRead);
	}
}


/**
 *
 * Runnable RE_AutoSetSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_AutoSetSlide_200ms
 *
 */

void RE_AutoSetSlide (void)
{
	Std_ReturnType status;
	uint8 Arg_MotorRead;
	uint8 Arg_position;
	uint8 Arg_weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_Opr_GetPosition(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_weight);
	AdjustRead=IsAdjustReadNeeded(Arg_position,Arg_weight,&Arg_MotorRead);
	if(AdjustRead==TRUE)
	{
	  Rte_Call_rpSlideMotor_Opr_MoveOperation(Arg_MotorRead);
	}
	
}

