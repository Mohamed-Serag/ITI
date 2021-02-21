/***************************************************************************/
/*  File Name: DCMOTOR_interface.h                                         */
/*  File Info: This file contains functions prototypes that can be used by */
/*             the user to control one or more DC motors.                  */
/*  Version  : V1.0                                                        */
/*  Author   : Mohamed Serag                                               */
/*  Date     : 7 Dec 2020                                                  */
/***************************************************************************/
/***********************************************************************/
/*** File Guard to Prevent this Header File from Multiple inclusion ****/
/***********************************************************************/
#ifndef DCMOTOR_INTERFCAE_H
#define DCMOTOR_INTERFCAE_H


/***********************************************************************/
/************************ Functions Prototypes *************************/
/***********************************************************************/

/***********************************************************************/
/* Function Name   : DCMOTOR_voidInit()                                */
/* Function Info   : This function initializes MCU GPIO pins connect to*/
/*                   the DC motors used and configured by the user.    */
/* Function Input  : None.                                             */
/* Function Ret_val: None.                                             */
/***********************************************************************/
void DCMOTOR_voidInit(void);



/***********************************************************************/
/* Function Name   : DCMOTOR_voidMove()                                */
/* Function Info   : This function initializes MCU GPIO pins connect to*/
/*                   the DC motors used and configured by the user.    */
/* Function Input  :- Copy_u8MotorNumber (The targeted motor Number)   */
/*                    >> Note That: mustn't exceed the selected number */
/*                                  of motors (NUMBER_OF_MOTORS).      */
/*                                                                     */
/*                  - Copy_u8MotorDirection (The targeted motor Number)*/
/*                    Available Options are:    1- LEFT_MOVEMENT       */
/*                                              2- RIGHT_MOVEMENT      */
/*                                              3- STOP_MOVEMENT       */
/*                                                                     */
/* Function Ret_val: LOC_u8Ret_Status [of type Error_State_t (enum)]   */
/*                   that returns function Status.                     */
/***********************************************************************/
Error_State_t DCMOTOR_voidMove(u8 Copy_u8MotorNumber, u8 Copy_u8MotorDirection)

#endif /*the end of DCMOTOR_INTERFCAE_H*/