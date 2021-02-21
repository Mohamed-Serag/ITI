/*******************************************************************************************************/
/* File Name : LED_interface.h                                                                         */
/* File info : This file contains all functions prototypes, user-defined data types, and macros of LED */
/*             SW module.                                                                              */
/* Date      : 1 Oct 2020                                                                              */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/***** File Guard to prevent this header file from multiple inclusions ****/
/**************************************************************************/
#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

/**************************************************************************/
/*********************** Definition Section *******************************/
/**************************************************************************/
#define    ACTIVE_LOW     0
#define    ACTIVE_HIGH    1

/**************************************************************************/
/* Structure Name   : LED_t                                               */
/* Structure Info   : This structure is used to define a LED.             */
/* Structure members: Port --> defines the PORT to which the LED is       */
/*                             connected. Choices: - GPIO_U8_PORTA        */
/*                                                 - GPIO_U8_PORTB        */
/*                                                 - GPIO_U8_PORTC        */
/*                                                                        */
/*                    Pin  --> defines the PIN to which the LED is        */
/*                             connected. Choices: - GPIO_U8_PIN0         */
/*                                                 - GPIO_U8_PIN1         */
/*                                                 - GPIO_U8_PIN2         */
/*                                                 - GPIO_U8_PIN3         */
/*                                                 - GPIO_U8_PIN4         */
/*                                                 - GPIO_U8_PIN5         */
/*                                                        .               */
/*                                                        .               */
/*                                                        .               */
/*                                                 - GPIO_U8_PIN15        */
/*                                                                        */
/*                    Active_State --> defines the active status of the   */
/*                                     LED based on its HW connection.    */
/*                                     Choices:    - ACTIVE_HIGH          */
/*                                                 - ACTIVE_LOW           */
/**************************************************************************/
typedef struct{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_t;

/**************************************************************************/
/*********************** Functions Prototypes  ****************************/
/**************************************************************************/
/**************************************************************************/
/* Function Name   : LED_voidOn()                                         */
/* Function Info   : This function is used for turning a LED ON.          */
/* Function Input  : LED --> Pointer to stucture of LED_t type to pass the*/
/*                         the value or the address of the LED structure  */
/*                         through it.                                    */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void LED_voidOn(LED_t *LED);


/**************************************************************************/
/* Function Name   : LED_voidOff()                                        */
/* Function Info   : This function is used for turning a LED OFF.         */
/* Function Input  : LED --> Pointer to stucture of LED_t type to pass the*/
/*                         the value or the address of the LED structure  */
/*                         through it.                                    */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void LED_voidOff(LED_t *LED);


#endif /** the end of _LED_INTERFACE_H*/