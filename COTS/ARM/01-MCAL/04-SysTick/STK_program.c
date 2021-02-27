/*******************************************************************************************************/
/* File Name : STK_program.c                                                                           */
/* File info : This file contains all functions implementations of Systick core peripheral (STK).      */
/* Date      : 8 Dec 2020                                                                              */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/************************* Linking Section ********************************/
/**************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/**************************************************************************/
/************************ Definition Section ******************************/
/**************************************************************************/
static void ( *MSTK_CallBack)(void);
static u8 MSTK_u8ModeOfInterval = 0;


/********************************************************************************************/
/* Function Name   : MSTK_voidInit()                                                        */
/* Function Info   : This function initializes the Systick core peripheral.                 */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidInit(void)
{
	/* Select the STK clock source & Disable it and its Interrupt */
	#if MSTK_CLK_SRC == MSTK_SRC_AHB_8
		MSTK -> CTRL = 0x00000000;
	#elif MSTK_CLK_SRC == MSTK_SRC_AHB
		MSTK -> CTRL = 0x00000004;
	#else
		#error"Wrong Choice of Prescaller!"
	#endif
}



/********************************************************************************************/
/* Function Name   : MSTK_voidSetBusyWait()                                                 */
/* Function Info   : This function performs a delay for a given period in milliseconds.     */
/* Function Input  : Copy_u32Ticks --> The delay period in milliseconds.                    */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load ticks to LOAD Register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the STK to start counting */
	SET_BIT(MSTK -> CTRL, 0);
	/* Wait (Polling) till the count flag is raised */
	while(GET_BIT(MSTK -> CTRL, 16) == 0);
	/* Disable the STK */
	CLR_BIT(MSTK -> CTRL, 0);
	/* Clear STK LOAD register */
	MSTK -> LOAD = 0;
	/* Clear STK VAL register */
	MSTK -> VAL = 0;
}


/********************************************************************************************/
/* Function Name   : MSTK_voidSetIntervalSingle()                                           */
/* Function Info   : This function performs an interrupt for only one time after a given    */
/*                   period of time (in milliseconds).                                      */
/* Function Input  : Copy_u32Ticks --> The time period in milliseconds.                     */
/*                   Copy_pf --> Pointer to function to pass the address of the function to */
/*                               be called in the interrupt through it.                     */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pf)(void))
{
	/* Disable the STK at the beginning */
	CLR_BIT(MSTK -> CTRL, 0);
	/* Clear the STK VAL register */
	MSTK -> VAL = 0;
	/* Load ticks to STK LOAD Register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the STK to start counting */
	SET_BIT(MSTK -> CTRL, 0);
	/* CallBack */
	MSTK_CallBack = Copy_pf;
	/* Set the mode to single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}


/********************************************************************************************/
/* Function Name   : MSTK_voidSetIntervalPeriodic()                                         */
/* Function Info   : This function performs an interrupt periodically after a given period  */
/*                   of time (in milliseconds).                                             */
/* Function Input  : Copy_u32Ticks --> The time period in milliseconds.                     */
/*                   Copy_pf --> Pointer to function to pass the address of the function to */
/*                               be called in the interrupt through it.                     */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_pf)(void))
{
	/* Load ticks to LOAD Register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the STK to start counting */
	SET_BIT(MSTK -> CTRL, 0);
	/* CallBack */
	MSTK_CallBack = Copy_pf;
	/* Set the mode to periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}


/********************************************************************************************/
/* Function Name   : MSTK_voidStopInterval()                                                */
/* Function Info   : This function stops the STK and clears both STK_VAL and STK_LOAD       */
/*                   registers.                                                             */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidStopInterval(void)
{
	/* Stop (disable) the STK */
	CLR_BIT(MSTK -> CTRL, 0);
	/* Clear the STK LOAD register */
	MSTK -> LOAD = 0;
	/* Clear the STK VAL register */
	MSTK -> VAL = 0;
}


/********************************************************************************************/
/* Function Name   : MSTK_u32GetElapsedTicks()                                              */
/* Function Info   : This function returns the elapsed time (STK counted time).             */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: Local_u32Ticks --> The elapsed or counted time (STK ticks).            */
/********************************************************************************************/
u32 MSTK_u32GetElapsedTicks(void)
{
	u32 Local_u32Ticks = 0;
	Local_u32Ticks = ((MSTK -> LOAD) - (MSTK -> VAL));
	return Local_u32Ticks;
}


/********************************************************************************************/
/* Function Name   : MSTK_u32GetRemainingTicks()                                            */
/* Function Info   : This function returns the remaining time (the remaining ticks or value */
/*                   in the STK VAL register).                                              */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: Local_u32RemainingTicks --> The remaining time that will be counted.   */
/********************************************************************************************/
u32 MSTK_u32GetRemainingTicks(void)
{
	u32 Local_u32RemainingTicks = 0;
	Local_u32RemainingTicks = MSTK -> VAL;
	return Local_u32RemainingTicks;
}


/********************************************************************************************/
/* Function Name   : SysTick_Handler()                                                      */
/* Function Info   : This function handles the Systick core peripheral interrupt in both    */
/*                   single and periodic mode.                                              */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void SysTick_Handler(void)
{
	u8 Local_u8Temp = 0;
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK interrupt */
		CLR_BIT(MSTK -> CTRL, 1);
		/* Stop (disable) the STK */
		CLR_BIT(MSTK -> CTRL, 0);
		/* Clear the STK LOAD register */
		MSTK -> LOAD = 0;
		/* Clear the STK VAL register */
		MSTK -> VAL = 0;
	}
	else{}
	
	/* CallBack function */
	MSTK_CallBack();
	/* Clear interrupt flag */
	Local_u8Temp = GET_BIT(MSTK -> CTRL, 16);
}


/*******************************************************************************************************/
/****************************************** History Log ************************************************/
/*******************************************************************************************************/
/*   .DD/MM/YYYY              .Name                        .Modification                               */
/*   ------------             ----------------             ------------------------                    */
/*   8 Dec 2020               Mohamed Serag                - File first Creation.                      */
/*                                                                                                     */
/*******************************************************************************************************/







