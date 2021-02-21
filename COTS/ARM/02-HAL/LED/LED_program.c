/*******************************************************************************************************/
/* File Name : LED_program.c                                                                           */
/* File info : This file contains all functions implementations of LED SW module.                      */
/* Date      : 1 Oct 2020                                                                              */
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
#include "LED_interface.h"


/**************************************************************************/
/***************** Functions Implementation Section ***********************/
/**************************************************************************/
/**************************************************************************/
/* Function Name   : LED_voidOn()                                         */
/* Function Info   : This function is used for turning a LED ON.          */
/* Function Input  : LED --> Pointer to stucture of LED_t type to pass the*/
/*                         the value or the address of the LED structure  */
/*                         through it.                                    */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void LED_voidOn(LED_t *LED){
	if(LED->Active_State == ACTIVE_HIGH){
		MGPIO_enuSetPinValue(LED->Port, LED->Pin, GPIO_U8_HIGH);
	}else if(LED->Active_State == ACTIVE_LOW){
		MGPIO_enuSetPinValue(LED->Port, LED->Pin, GPIO_U8_LOW);
	}
}

/**************************************************************************/
/* Function Name   : LED_voidOff()                                        */
/* Function Info   : This function is used for turning a LED OFF.         */
/* Function Input  : LED --> Pointer to stucture of LED_t type to pass the*/
/*                         the value or the address of the LED structure  */
/*                         through it.                                    */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void LED_voidOff(LED_t *LED){
	if(LED->Active_State == ACTIVE_LOW){
		MGPIO_enuSetPinValue(LED->Port, LED->Pin, GPIO_U8_HIGH);
	}else if(LED->Active_State == ACTIVE_HIGH){
		MGPIO_enuSetPinValue(LED->Port, LED->Pin, GPIO_U8_LOW);
	}
	
}

