/*******************************************************************************************************/
/* File Name : NVIC_interface.h                                                                        */
/* File info : This file contains all functions prototypes used in the nested vector interrupt         */
/*             controller (NVIC) module.                                                               */
/* Date      : 30 Nov 2020                                                                             */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/
/**************************************************************************/
/******* File guard to prevent this file from multiple inclusions *********/
/**************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/********************************************************************************************/
/* Function Name   : MNVIC_voidInit()                                                       */
/* Function Info   : This function initializes the number of groups and                     */
/*                   sub-groups.                                                            */
/* Function Input  : None.                                                                  */
/* Function Ret_Val: None.                                                                  */
/********************************************************************************************/
void MNVIC_voidInit(void);

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
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group);

/********************************************************************************************/
/* Function Name   : MNVIC_enuEnableInterrupt()                                             */
/* Function Info   : This function is used to enable an interrupt.                          */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuEnableInterrupt(u8 Copy_u8Interrupt_Number);

/********************************************************************************************/
/* Function Name   : MNVIC_enuDisableInterrupt()                                            */
/* Function Info   : This function is used to disable an interrupt.                         */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/	
Error_State_t MNVIC_enuDisableInterrupt(u8 Copy_u8Interrupt_Number);

/********************************************************************************************/
/* Function Name   : MNVIC_enuEnablePendingInterrupt()                                      */
/* Function Info   : This function is used to enable a pending interrupt.                   */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuEnablePendingInterrupt(u8 Copy_u8Interrupt_Number);

/********************************************************************************************/
/* Function Name   : MNVIC_enuClearPendingInterrupt()                                       */
/* Function Info   : This function is used to disable (clear) a pending interrupt.          */
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_enuClearPendingInterrupt(u8 Copy_u8Interrupt_Number);

/********************************************************************************************/
/* Function Name   : MNVIC_u8GetActiveInterruptFlag()                                       */
/* Function Info   : This function is used to get the status of an interrupt (active or Not)*/
/* Function Input  : Copy_u8Interrupt_Number --> the interrupt number from the vector table.*/
/*                   Copy_Pu8Result --> pointer to return the flag status through it.       */
/* Function Ret_Val: LOC_u8Ret_state --> the status of the function.                        */
/********************************************************************************************/
Error_State_t MNVIC_u8GetActiveInterruptFlag(u8 Copy_u8InterruptNumber, u8 *Copy_Pu8Result);

#endif/** the end of NVIC_INTERFACE_H*/