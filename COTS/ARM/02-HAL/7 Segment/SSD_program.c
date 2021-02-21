/*******************************************************************************************************/
/* File Name : SSD_Program.c                                                                           */
/* File info : This file contains all functions implementations of the seven segment display sw module.*/
/* Date      : 19 Oct 2020                                                                             */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/
/**************************************************************************/
/************************* Linking Section ********************************/
/**************************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"
#include "GPIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


/********************************************************************************************/
/* Function Name   : SSD_voidSendNumber()                                                   */
/* Function Info   : This function is used to display a number on the seven segment display.*/
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure.                                       */
/*                   Copy_u8Number --> the number to be displayed.                          */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
Error_State_t SSD_voidSendNumber(SSD_t *SSD, u8 Copy_u8Number)
{
	Error_State_t Local_u8Ret_Status = RET_OK;
	u8 Local_u8Arr[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	if (SSD->Type == COMMON_CATHOD)
	{
		MGPIO_enuSetPortValues(SSD->Data_Port, Local_u8Arr[Copy_u8Number]);
	}
	else if(SSD->Type == COMMON_ANODE)
	{
		MGPIO_enuSetPortValue(SSD->Data_Port, ~Local_u8Arr[Copy_u8Number]);
	}
	else
	{
		Local_u8Ret_Status = RET_NOK;
	}
	return Local_u8Ret_Status;
}


/********************************************************************************************/
/* Function Name   : SSD_voidEnable()                                                       */
/* Function Info   : This function is used to enable a seven segment display.               */
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure.                                       */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
Error_State_t SSD_voidEnable(SSD_t *SSD)
{
	Error_State_t Local_u8Ret_Status = RET_OK;
	if (SSD->Type == COMMON_CATHOD)
	{
		MGPIO_enuSetPinValue(SSD->Enable_Port, SSD ->Enable_Pin, GPIO_U8_LOW);
	}
	else if(SSD->Type == COMMON_ANODE)
	{
		MGPIO_enuSetPinValue(SSD->Enable_Port, SSD ->Enable_Pin, GPIO_U8_HIGH);
	}
	else
	{
		Local_u8Ret_Status = RET_NOK;
	}
	return Local_u8Ret_Status;
}

/********************************************************************************************/
/* Function Name   : SSD_voidDisable()                                                      */
/* Function Info   : This function is used to disable a seven segment display.              */
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure.                                       */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
Error_State_t SSD_voidDisable(SSD_t *SSD)
{
	Error_State_t Local_u8Ret_Status = RET_OK;
	if (SSD->Type == COMMON_CATHOD)
	{
		MGPIO_enuSetPinValue(SSD->Enable_Port, SSD ->Enable_Pin, GPIO_U8_HIGH);
	}
	else if(SSD->Type == COMMON_ANODE)
	{
		MGPIO_enuSetPinValue(SSD->Enable_Port, SSD ->Enable_Pin, GPIO_U8_LOW);
	}
	else
	{
		Local_u8Ret_Status = RET_NOK;
	}
	return Local_u8Ret_Status;
}
