/***************************************************************************/
/* File Name: BUZZER_program.c                                             */
/* File Info: This file contains buzzer functions (APIs) implementations.  */
/* Version  : V1.0                                                         */
/* Author   : Mohamed Serag                                                */
/* Date     : 25 Dec 2020                                                  */
/***************************************************************************/

/**********************************************************************/
/*************************** Linking Section **************************/
/**********************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"
#include "GPIO_interface.h"
#include "BUZZER_interface.h"


/**********************************************************************/
/**************** Functions Inplementations Section *******************/
/**********************************************************************/

/**********************************************************************/
/* Function Name   : BUZZER_voidOn()                                  */
/* Function Info   : This function turns the buzzer ON.               */
/* Function Input  : BUZZER --> Pointer to structure of type BUZZER_t */
/*                              to pass the address of the buzzer     */
/*                              struct through it.                    */
/* Function Ret_Val: None.                                            */
/**********************************************************************/
void BUZZER_voidOn(BUZZER_t *BUZZER)
{
	if(BUZZER->Active_State == ACTIVE_HIGH){
		MGPIO_enuSetPinValue(BUZZER->Port, BUZZER->Pin, GPIO_U8_HIGH);
	}
	else if(BUZZER->Active_State == ACTIVE_LOW){
		MGPIO_enuSetPinValue(BUZZER->Port, BUZZER->Pin, GPIO_U8_LOW);
	}
}


/**********************************************************************/
/* Function Name   : BUZZER_voidOff()                                 */
/* Function Info   : This function turns the buzzer OFF.              */
/* Function Input  : BUZZER --> Pointer to structure of type BUZZER_t */
/*                              to pass the address of the buzzer     */
/*                              struct through it.                    */
/* Function Ret_Val: None.                                            */
/**********************************************************************/
void BUZZER_voidOff(BUZZER_t *BUZZER)
{
	if(BUZZER->Active_State == ACTIVE_LOW){
		MGPIO_enuSetPinValue(BUZZER->Port, BUZZER->Pin, GPIO_U8_HIGH);
	}
	else if(BUZZER->Active_State == ACTIVE_HIGH){
		MGPIO_enuSetPinValue(BUZZER->Port, BUZZER->Pin, GPIO_U8_LOW);
	}
}

