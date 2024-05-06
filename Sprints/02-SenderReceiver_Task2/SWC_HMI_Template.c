/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/6/2024 09:34 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


#define MULTI_STATE_BTN_INIT 0
#define MULTI_STATE_BTN_MINUS  1
#define MULTI_STATE_BTN_PLUS 2
MultiStateBtnType Get_BtnState(uint8_t value)
{
	MultiButtonStateType btnstate;
	
	if(value == 1)
	{
		btnstate = MULTI_STATE_BTN_MINUS;	
	}
	else if(value == 2)
	{
		btnstate = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		btnstate = MULTI_STATE_BTN_INIT;
	}
	
	return btnstate;
}
		
/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;
	MultiStateBtnType DE_InclineBtnState;
	MultiStateBtnType DE_SlideBtnState;
	SeatCtrlData_Height DE_Height;
	SeatCtrlData_Incline DE_Incline;
	SeatCtrlData_Slide DE_Slide;
	
	/* Data Receive Points */
	status = Rte_Read_rp_SeatCtrlData_DE_Height(&DE_Height);
	if(status == E_OK)
	{
		DE_HeightBtnState = Get_BtnState(DE_Height)
		status = Rte_Write_pp_SeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	}
	
	status = Rte_Read_rp_SeatCtrlData_DE_Slide(&DE_Slide);
	if(status == E_OK)
	{
		DE_SlideBtnState = Get_BtnState(DE_Slide)
		status = Rte_Write_pp_SeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	}
	
	status = Rte_Read_rp_SeatCtrlData_DE_Incline(&DE_Incline);
	if(status == E_OK)
	{
		DE_SlideBtnState = Get_BtnState(DE_Incline)
		status = Rte_Write_pp_SeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	}
}

