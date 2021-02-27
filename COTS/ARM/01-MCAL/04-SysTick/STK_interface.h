/*******************************************************************************************************/
/* File Name : STK_interface.h                                                                         */
/* File info : This file contains all functions prototypes used in Systick core peripheral module.     */
/* Date      : 8 Dec 2020                                                                              */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/******* File guard to prevent this file from multiple inclusions *********/
/**************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/**************************************************************************/
/*********************** Functions Prototypes *****************************/
/**************************************************************************/

/********************************************************************************************/
/* Function Name   : MSTK_voidInit()                                                        */
/* Function Info   : This function initializes the Systick core peripheral.                 */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidInit(void);


/********************************************************************************************/
/* Function Name   : MSTK_voidSetBusyWait()                                                 */
/* Function Info   : This function performs a delay for a given period in milliseconds.     */
/* Function Input  : Copy_u32Ticks --> The delay period in milliseconds.                    */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);


/********************************************************************************************/
/* Function Name   : MSTK_voidSetIntervalSingle()                                           */
/* Function Info   : This function performs an interrupt for only one time after a given    */
/*                   period of time (in milliseconds).                                      */
/* Function Input  : Copy_u32Ticks --> The time period in milliseconds.                     */
/*                   Copy_pf --> Pointer to function to pass the address of the function to */
/*                               be called in the interrupt through it.                     */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pf)(void));


/********************************************************************************************/
/* Function Name   : MSTK_voidSetIntervalPeriodic()                                         */
/* Function Info   : This function performs an interrupt periodically after a given period  */
/*                   of time (in milliseconds).                                             */
/* Function Input  : Copy_u32Ticks --> The time period in milliseconds.                     */
/*                   Copy_pf --> Pointer to function to pass the address of the function to */
/*                               be called in the interrupt through it.                     */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_pf)(void));


/********************************************************************************************/
/* Function Name   : MSTK_voidStopInterval()                                                */
/* Function Info   : This function stops the STK and clears both STK_VAL and STK_LOAD       */
/*                   registers.                                                             */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MSTK_voidStopInterval(void);


/********************************************************************************************/
/* Function Name   : MSTK_u32GetElapsedTicks()                                              */
/* Function Info   : This function returns the elapsed time (STK counted time).             */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: Local_u32Ticks --> The elapsed or counted time (STK ticks).            */
/********************************************************************************************/
u32 MSTK_u32GetElapsedTicks(void);


/********************************************************************************************/
/* Function Name   : MSTK_u32GetRemainingTicks()                                            */
/* Function Info   : This function returns the remaining time (the remaining ticks or value */
/*                   in the STK VAL register).                                              */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: Local_u32RemainingTicks --> The remaining time that will be counted.   */
/********************************************************************************************/
u32 MSTK_u32GetRemainingTicks(void);


#endif /** the end of STK_INTERFACE_H */