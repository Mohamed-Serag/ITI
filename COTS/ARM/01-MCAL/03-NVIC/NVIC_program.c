/*******************************************************************************************************/
/* File Name : NVIC_program.c                                                                          */
/* File info : This file contains all functions implementations concerning nested vector interrupt     */
/*             controller module.                                                                      */
/* Date      : 30 Nov 2020                                                                             */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/
/**************************************************************************/
/************************* Linking Section ********************************/
/**************************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/**************************************************************************/
/************************ Definition Section ******************************/
/**************************************************************************/
#ifndef		NULL
#define		NULL		(void *)0
#endif

#define		SCB_AIRCR		*((volatile u32 *)(0xE000ED00 + 0x0C))


/********************************************************************************************/
/* Function Name   : MNVIC_voidInit()                                                       */
/* Function Info   : This function initializes the number of groups and                     */
/*                   sub-groups.                                                            */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MNVIC_voidInit(void)
{
	SCB_AIRCR = NUM_GROUPS_NUM_SUB;
}


/********************************************************************************************/
/* Function Name   : MNVIC_voidSetPriority()                                                */
/* Function Info   : This function is used to set the group and the sub-group priority of   */
/*                   an interrupt.                                                          */
/* Function Input  : Copy_s8InterruptID   --> Interrupt number from vector table.           */
/*                   Copy_u8GroupPriority --> the group priority required by the user.      */
/*                   Copy_u8SubPriority   --> the sub group priority required by the user.  */
/*                   Copy_u32Group        --> the group number from table 45 (priority      */
/*                                            grouping in data sheet [Programing Manual]    */
/*                                            in SCB_AIRCR in System Control Block Section  */
/*                                            in the data sheet).                           */
/*                                            Ex: 0x05FA0500  --> 4 Group Priority and 4 Sub*/
/*                                                                 Priority.                */
/* Function Ret_Val: None.                                                                  */ 
/********************************************************************************************/
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group)
{
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32Group - 0x05FA0300) / 0x100)); /* 0x100 is the steps (e.g. from 0x05FA0300 and 0x05FA0400)*/
	
	
	if(Copy_s8InterruptID >= 0)
	{
		NVIC_IPR[Copy_s8InterruptID] = Local_u8Priority << 4;
	}
	else if (Copy_s8InterruptID < 0)
	{
		/**!comment: internal interrupts (fixed not settable)*/
	}
	SCB_AIRCR = Copy_u32Group;
}


/********************************************************************************************/
/* Function Name   : MNVIC_enuEnableInterrupt()                                             */
/* Function Info   : This function is used to enable an interrupt.                          */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuEnableInterrupt(u8 Copy_u8Interrupt_Number)
{
	Error_State_t LOC_u8Ret_state = RET_OK;
	if(Copy_u8Interrupt_Number < 32)
	{
		SET_BIT(NVIC_ISER0, Copy_u8Interrupt_Number);
	}
	else if(Copy_u8Interrupt_Number < 60){
		Copy_u8Interrupt_Number -= 32;
		SET_BIT(NVIC_ISER1, Copy_u8Interrupt_Number);
	}
	else
	{
		LOC_u8Ret_state = RET_NOK;
	}
	return LOC_u8Ret_state;
}


/********************************************************************************************/
/* Function Name   : MNVIC_enuDisableInterrupt()                                            */
/* Function Info   : This function is used to disable an interrupt.                         */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/	
Error_State_t MNVIC_enuDisableInterrupt(u8 Copy_u8Interrupt_Number)
{
	Error_State_t LOC_u8Ret_state = RET_OK;
	if(Copy_u8Interrupt_Number < 32)
	{
		SET_BIT(NVIC_ICER0, Copy_u8Interrupt_Number);
	}
	else if(Copy_u8Interrupt_Number < 60){
		Copy_u8Interrupt_Number -= 32;
		SET_BIT(NVIC_ICER1, Copy_u8Interrupt_Number);
	}
	else
	{
		LOC_u8Ret_state = RET_NOK;
	}
	return LOC_u8Ret_state;
}


/********************************************************************************************/
/* Function Name   : MNVIC_enuEnablePendingInterrupt()                                      */
/* Function Info   : This function is used to enable a pending interrupt.                   */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuEnablePendingInterrupt(u8 Copy_u8Interrupt_Number)
{
	Error_State_t LOC_u8Ret_state = RET_OK;
	if(Copy_u8Interrupt_Number < 32)
	{
		SET_BIT(NVIC_ISPR0, Copy_u8Interrupt_Number);
	}
	else if(Copy_u8Interrupt_Number < 60){
		Copy_u8Interrupt_Number -= 32;
		SET_BIT(NVIC_ISPR1, Copy_u8Interrupt_Number);
	}
	else
	{
		LOC_u8Ret_state = RET_NOK;
	}
	return LOC_u8Ret_state;
}


/********************************************************************************************/
/* Function Name   : MNVIC_enuClearPendingInterrupt()                                       */
/* Function Info   : This function is used to disable (clear) a pending interrupt.          */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuClearPendingInterrupt(u8 Copy_u8Interrupt_Number)
{
	Error_State_t LOC_u8Ret_state = RET_OK;
	if(Copy_u8Interrupt_Number < 32)
	{
		SET_BIT(NVIC_ICPR0, Copy_u8Interrupt_Number);
	}
	else if(Copy_u8Interrupt_Number < 60){
		Copy_u8Interrupt_Number -= 32;
		SET_BIT(NVIC_ICPR1, Copy_u8Interrupt_Number);
	}
	else
	{
		LOC_u8Ret_state = RET_NOK;
	}
	return LOC_u8Ret_state;
}


/********************************************************************************************/
/* Function Name   : MNVIC_u8GetActiveInterruptFlag()                                       */
/* Function Info   : This function is used to get the status of an interrupt (active or Not)*/
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/*                   Copy_Pu8Result --> pointer to return the flag status through it.       */
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_u8GetActiveInterruptFlag(u8 Copy_u8InterruptNumber, u8 *Copy_Pu8Result)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	if(Copy_u8InterruptNumber < 32 && Copy_Pu8Result != NULL){
		*Copy_Pu8Result = GET_BIT(NVIC_IABR0, Copy_u8InterruptNumber);
		
	}
	else if(Copy_u8InterruptNumber < 60 && Copy_Pu8Result != NULL){
		Copy_u8InterruptNumber -= 32;
		*Copy_Pu8Result = GET_BIT(NVIC_IABR1, Copy_u8InterruptNumber);
	}
	else{
		if(Copy_Pu8Result == NULL){
			Local_u8Ret_State = RET_NULL_POINTER;
		}
		else{
			Local_u8Ret_State = RET_OUT_OF_RANGE;
		}
		
	}
	return Local_u8Ret_State;
}







