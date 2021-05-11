/************************************************************************/
/* File Name: DIO_interface.h                                           */
/* File Info: This file contains DIO driver functions prototypes.       */
/* Version  : V1.0                                                      */
/* Date     : 18 Oct. 2020                                              */
/* Author   : Mohamed Serag.                                            */
/************************************************************************/
/********************************************************************/
/** Header file Guard to prevent this file from muliple inclusions **/
/********************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* DIO Ports Macros */
#define  DIO_U8_PORTA   0
#define  DIO_U8_PORTB   1
#define  DIO_U8_PORTC   2
#define  DIO_U8_PORTD   3
/* DIO Pins Macros  */
#define  DIO_U8_PIN0    0
#define  DIO_U8_PIN1    1
#define  DIO_U8_PIN2    2
#define  DIO_U8_PIN3    3
#define  DIO_U8_PIN4    4
#define  DIO_U8_PIN5    5
#define  DIO_U8_PIN6    6
#define  DIO_U8_PIN7    7
/* DIO Pins Values Macros */
#define  DIO_U8_LOW     0
#define  DIO_U8_HIGH    1

/********************************************************************/
/* Function Name   : MDIO_voidInit()                                */
/* Function info   : This function initializes the DIO Pins through */
/*                   Pre-build configurations.                      */
/* Function Input  : None.                                          */
/* Function Returns: None.                                          */
/********************************************************************/
void MDIO_voidInit(void);

/********************************************************************/
/* Function Name   : MDIO_enuSetPinValue()                          */
/* Function info   : This Function sets a pin value High or Low.    */
/* Function Input  :- Copy_u8PORT -> the targeted port.             */
/*                    Options: DIO_U8_PORTx where x (A, B, C, or D) */
/*                                                                  */
/*                  - Copy_u8PIN -> the targeted pin.               */
/*                    Options: DIO_U8_PINx where x (0, 1, ...., 7)  */
/*                                                                  */
/*                  - Copy_u8Value -> the value of the pin.         */
/*                    Options:  DIO_U8_LOW                          */
/*                              DIO_U8_HIGH                         */
/* Function Returns:  L_RetVal -> variable of enum Error_State_t    */
/*                                type that returns function        */
/*                                execution status.                 */
/********************************************************************/
Error_State_t MDIO_enuSetPinValue(uint8_t Copy_u8PORT, uint8_t Copy_u8PIN, uint8_t Copy_u8Value);

/********************************************************************/
/* Function Name   : MDIO_enuGetPinValue()                          */
/* Function info   : This Function reads a pin value.               */
/* Function Input  :- Copy_u8PORT -> the targeted port.             */
/*                    Options: DIO_U8_PORTx where x (A, B, C, or D) */
/*                                                                  */
/*                  - Copy_u8PIN -> the targeted pin.               */
/*                    Options: DIO_U8_PINx where x (0, 1, ...., 7)  */
/*                                                                  */
/*                  - Pu8PinValue -> a pointer to return the value  */
/*                                   through it.                    */
/* Function Returns:  L_RetVal -> variable of enum Error_State_t    */
/*                                type that returns function        */
/*                                execution status.                 */
/********************************************************************/
Error_State_t MDIO_enuGetPinValue(uint8_t Copy_u8PORT, uint8_t Copy_u8PIN, uint8_t *Pu8PinValue);

#endif /** The end of DIO_INTERFACE_H */
