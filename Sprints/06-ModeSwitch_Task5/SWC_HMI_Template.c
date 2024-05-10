/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/18/2024 10:13 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


/**
 *
 * Runnable HMI_Main_Function
 *
 * Triggered By:
 *
 */
#define INIT 0
#define FALSE 0
#define RTE_E_MAX_AGE_EXCEDDED 0
uint8_t counter=0;

 static MultiButtonStateType btnValueToState(uint8 value)
 {
	 MultiButtonStateType btnstate;
	 if(value==1)
	 {
		 btnstate=MULTI_STATE_BTN_MINUS 
	 }
	 else if(value==2)
	 {
		 btnstate=MULTI_STATE_BTN_PLUS; 
	 }
	 else
	 {
		 btnstate=MULTI_STATE_BTN_INIT;
	 }
	 return btnstate;
 }
void HMI_Main_Function (void)
{
	Std_ReturnType status;
	MultiButtonStateType DE_Height;
	MultiButtonStateType DE_Incline;
	MultiButtonStateType DE_Slide;
	uint8 Height;
	uint8 Slide;
	uint8 Incline;
    boolean IsUpdated;
		/* Server Call Points */
	IsUpdated = Rte_Call_rpHeightIsUpdated_Opr_IsUpdated();
	status = Rte_Read_rpSeatCtrlDataHeight_Height(&Height);
	if(statues == E_OK && IsUpdated==TRUE)
	{
		DE_Height=btnValueToState(Height);
		(void)Rte_Write_ppHeightBtnState_DE_Height(DE_Height);
	}
	
	IsUpdated = Rte_Call_rpInclineIsUpdated_Opr_InclineIsUpdated();
	status = Rte_Read_rpSeatCtrlDataIncline_Incline(&Incline);
	if(statues == E_OK && IsUpdated==TRUE)
	{
		DE_Incline=btnValueToState(Incline);
		(void)Rte_Write_ppInclineBtnState_DE_Incline(DE_Incline);
	}
	
	IsUpdated = Rte_Call_rpSlideIsUpdated_Opr_SlideIsUpdated();
	status = Rte_Read_rpSeatCtrlDataSlide_Slide(&Slide);
	if(statues == E_OK && IsUpdated==TRUE)
	{
		 DE_Height=btnValueToState(Slide);
		 (void)Rte_Write_ppSlideBtnState_DE_Slide(DE_Slide);
	}
	
}


/**
 *
 * Runnable RE_HMI_SeatModeManager
 *
 * Triggered By:
 *
 */

void RE_HMI_SeatModeManager (void)
{
	SeatModeButtonType Arg_SeatModeButton;
	uint8 HMI_SeatManager = RTE_MODE_HMI_SeatManager_INIT;

	/* Server Call Points */
	 Rte_Call_rpSeatModeButton_Opr_SeatMode(&Arg_SeatModeButton);
	 if(SeatModeButton == SEAT_MODE_BTN_MANUAL)
	 {
		 HMI_SeatManager=RTE_MODE_HMI_SeatManager_MANUAL;
	 }
	 else if(SeatModeButton == SEAT_MODE_BTN_AUTO)
	 {
		  HMI_SeatManager=RTE_MODE_HMI_SeatManager_AUTO;
	 }
	
	/* Mode Switch Points */
	(void)Rte_Switch_ppSeatControlMode_HMI_SeatManager(HMI_SeatManager);
	
}
