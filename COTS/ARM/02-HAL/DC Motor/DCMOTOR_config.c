/***************************************************************************/
/*  File Name: DCMOTOR_Config.c                                            */
/*  File Info: This file contains configurable array used by the user to   */
/*             configure the MCU GPIO ports andpins connected to project   */
/*             DC motors.                                                  */
/*  Version  : 1.0V                                                        */
/*  Author   : Mohamed Serag                                               */
/*  Date     : 7 Dec 2020                                                  */
/***************************************************************************/


/***********************************************************************/
/************************** Linking Section ****************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_private.h"


/***********************************************************************/
/* Description : This array configures DC motor(s) GPIO Ports and pins */
/*               to which they are connectd.                           */
/***********************************************************************/
DcMotor ArrayOfMotors[NUMBER_OF_MOTORS] = {{GPIO_U8_PIN0, GPIO_U8_PORTA, GPIO_U8_PIN1, GPIO_U8_PORTA},
										   {GPIO_U8_PIN2, GPIO_U8_PORTA, GPIO_U8_PIN3, GPIO_U8_PORTA},
										   {GPIO_U8_PIN4, GPIO_U8_PORTA, GPIO_U8_PIN5, GPIO_U8_PORTA},
										   {GPIO_U8_PIN6, GPIO_U8_PORTA, GPIO_U8_PIN7, GPIO_U8_PORTA}};