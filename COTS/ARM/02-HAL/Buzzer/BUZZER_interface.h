/***************************************************************************/
/* File Name: BUZZER_interface.h                                           */
/* File Info: This file contains buzzer functions prototypes, macros, and  */
/*            user-defined data types.                                     */
/* Version  : V1.0                                                         */
/* Author   : Mohamed Serag                                                */
/* Date     : 25 Dec 2020                                                  */
/***************************************************************************/

/******************************************************************/
/* File guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

/**********************************************************************/
/************************ Definition Section **************************/
/**********************************************************************/
/* Buzzer hardware connection status macros */
#define ACTIVE_LOW    0
#define ACTIVE_HIGH   1

/**********************************************************************/
/* Description   : This structure is used to choose a buzzer specific */
/*                  configurations.                                   */
/* Struct Name   : BUZZER_t                                           */
/* Struct Members: Port --> the port to which the buzzer is connected.*/
/*                          Available choices: - GPIO_U8_PORTA        */
/*                                             - GPIO_U8_PORTB        */
/*                                             - GPIO_U8_PORTC        */
/*                                                                    */
/*                 Pin  --> the pin to which the buzzer is connected. */
/*                          Available choices: - GPIO_U8_PIN0         */
/*                                             - GPIO_U8_PIN1         */
/*                                             - GPIO_U8_PIN2         */
/*                                                     .              */
/*                                                     .              */
/*                                                     .              */
/*                                                     .              */
/*                                             - GPIO_U8_PIN15        */
/*                                                                    */
/*                 Active_State --> the buzzer activation status based*/
/*                                  on its hardware connection.       */
/*                                  Available choices: - ACTIVE_LOW   */
/*                                                     - ACTIVE_HIGH  */
/**********************************************************************/
typedef struct{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}BUZZER_t;


/**********************************************************************/
/* Function Name   : BUZZER_voidOn()                                  */
/* Function Info   : This function turns the buzzer ON.               */
/* Function Input  : BUZZER --> Pointer to structure of type BUZZER_t */
/*                              to pass the address of the buzzer     */
/*                              struct through it.                    */
/* Function Ret_Val: None.                                            */
/**********************************************************************/
void BUZZER_voidOn(BUZZER_t *BUZZER);


/**********************************************************************/
/* Function Name   : BUZZER_voidOff()                                 */
/* Function Info   : This function turns the buzzer OFF.              */
/* Function Input  : BUZZER --> Pointer to structure of type BUZZER_t */
/*                              to pass the address of the buzzer     */
/*                              struct through it.                    */
/* Function Ret_Val: None.                                            */
/**********************************************************************/
void BUZZER_voidOff(BUZZER_t *BUZZER);


#endif /** the end of BUZZER_INTERFACE_H */