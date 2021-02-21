/***************************************************************************/
/*  File Name: DCMOTOR_program.c                                           */
/*  File Info: This file contains functions implementations that will be   */
/*             used by the user to control one or more DC motors.          */
/*  Version  : V1.0                                                        */
/*  Author   : Mohamed Serag                                               */
/*  Date     : 7 Dec 2020                                                  */
/***************************************************************************/

/***********************************************************************/
/************************** Linking Section ****************************/
/***********************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"
#include "GPIO_interface.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_private.h"



/***********************************************************************/
/********************** Functions Implementations **********************/
/***********************************************************************/

/***********************************************************************/
/* Function Name   : DCMOTOR_voidInit()                                */
/* Function Info   : This function initializes MCU GPIO pins connect to*/
/*                   the DC motors used and configured by the user.   */
/* Function Input  : None.                                             */
/* Function Ret_val: None.                                             */
/***********************************************************************/
void DCMOTOR_voidInit(void)
{
	u8 Local_u8itr
	for(Local_u8itr = 0; Local_u8itr < NUMBER_OF_MOTORS ;Local_u8itr++)
	{
		GPIO_enuSetPinValue(ArrayOfMotors[Local_u8itr].DCMOTOR_u8RightMotorPort, ArrayOfMotors[Local_u8itr].DCMOTOR_u8RightMotorPin, GPIO_U8_LOW);
		GPIO_enuSetPinValue(ArrayOfMotors[Local_u8itr].DCMOTOR_u8LeftMotorPort, ArrayOfMotors[Local_u8itr].DCMOTOR_u8LeftMotorPin, GPIO_U8_LOW);
	}
}

/***********************************************************************/
/* Function Name   : DCMOTOR_voidMove()                                */
/* Function Info   : This function initializes MCU GPIO pins connect to*/
/*                   the DC motors used and configured by the user.    */
/* Function Input  :- Copy_u8MotorNumber (The targeted motor Number)   */
/*                  - Copy_u8MotorDirection (The targeted motor Number)*/
/* Function Ret_val: LOC_u8Ret_Status [of type Error_State_t (enum)]   */
/*                   that returns function Status.                     */
/***********************************************************************/
Error_State_t DCMOTOR_voidMove(u8 Copy_u8MotorNumber, u8 Copy_u8MotorDirection)
{
	Error_State_t LOC_u8Ret_Status = RET_OK;
	if(Copy_u8MotorNumber > NUMBER_OF_MOTORS){
		LOC_u8Ret_Status = RET_NOK;
	}
	else{
		switch(Copy_u8MotorDirection)
		{
			case LEFT_MOVEMENT: 
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPin, GPIO_U8_LOW);
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPin, GPIO_U8_HIGH);
				break;
			case RIGHT_MOVEMENT: 
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPin, GPIO_U8_HIGH);
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPin, GPIO_U8_LOW);
				break;
			case STOP_MOVEMENT: 
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPin, GPIO_U8_LOW);
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPin, GPIO_U8_LOW);
				break;
			default :
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8RightMotorPin, GPIO_U8_LOW);
				GPIO_enuSetPinValue(ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPort, ArrayOfMotors[Copy_u8MotorNumber].DCMOTOR_u8LeftMotorPin, GPIO_U8_LOW);
		}
	}
	return LOC_u8Ret_Status;
}