/*******************************************************************************************************/
/* File Name : LedMatrix_config.h                                                                      */
/* File info : This file contains all configurable macros of the Led Matrix.                           */
/* Date      : 14 Dec 2020                                                                             */
/* Version   : V1.1                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/***** File Guard to prevent this header file from multiple inclusions ****/
/**************************************************************************/
#ifndef LEDM_CONFIG_H_
#define LEDM_CONFIG_H_

/**************************************************************************/
/************************** Macros Definition *****************************/
/**************************************************************************/

/**************************************************************************/
/* Macro Description: This macro defines the Port side to which the Led   */
/*                    matrix rows will be connected to.                   */
/* Choices          : - GPIO_U8_PORT_LOW       (from Pin 0 to Pin 7)      */
/*                    - GPIO_U8_PORT_HIGH      (from Pin 8 to Pin 15)     */
/*                    - GPIO_U8_ALL_PORT       (from Pin 0 to Pin 15)     */
/**************************************************************************/
#define		HLEDMAT_ROWS_PORT		GPIO_U8_PORT_LOW


/**************************************************************************/
/* Macros Description: This macros define the Port pins to which the Led  */
/*                     matrix rows will be connected.                     */
/* Choices           : - GPIO_U8_PORTx , GPIO_U8_PINy                     */
/*                      where: x can be (A, B, C, or D) and y can be      */
/*                             (from 0 to 15).                            */
/**************************************************************************/
#define		HLEDMAT_ROW_0			GPIO_U8_PORTA , GPIO_U8_PIN0
#define		HLEDMAT_ROW_1			GPIO_U8_PORTA , GPIO_U8_PIN1
#define		HLEDMAT_ROW_2			GPIO_U8_PORTA , GPIO_U8_PIN2
#define		HLEDMAT_ROW_3			GPIO_U8_PORTA , GPIO_U8_PIN3
#define		HLEDMAT_ROW_4			GPIO_U8_PORTA , GPIO_U8_PIN4
#define		HLEDMAT_ROW_5			GPIO_U8_PORTA , GPIO_U8_PIN5
#define		HLEDMAT_ROW_6			GPIO_U8_PORTA , GPIO_U8_PIN6
#define		HLEDMAT_ROW_7			GPIO_U8_PORTA , GPIO_U8_PIN7


/**************************************************************************/
/* Macro Description: This macro defines the Port side to which the Led   */
/*                    matrix columns will be connected.                   */
/* Choices          : - GPIO_U8_PORT_LOW       (from Pin 0 to Pin 7)      */
/*                    - GPIO_U8_PORT_HIGH      (from Pin 8 to Pin 15)     */
/*                    - GPIO_U8_ALL_PORT       (from Pin 0 to Pin 15)     */
/**************************************************************************/
#define		HLEDMAT_COLUMNS_PORT	GPIO_U8_PORT_HIGH


/**************************************************************************/
/* Macros Description: This macros define the pins to which the Led matrix*/
/*                     columns will be connected.                         */
/* Choices           : - GPIO_U8_PORTx , GPIO_U8_PINy                     */
/*                      where: x can be (A, B, C, or D) and y can be      */
/*                             (from 0 to 15).                            */
/**************************************************************************/
#define		HLEDMAT_COLUMN_0		GPIO_U8_PORTB , GPIO_U8_PIN8
#define		HLEDMAT_COLUMN_1		GPIO_U8_PORTB , GPIO_U8_PIN9
#define		HLEDMAT_COLUMN_2		GPIO_U8_PORTB , GPIO_U8_PIN10
#define		HLEDMAT_COLUMN_3		GPIO_U8_PORTB , GPIO_U8_PIN11
#define		HLEDMAT_COLUMN_4		GPIO_U8_PORTB , GPIO_U8_PIN12
#define		HLEDMAT_COLUMN_5		GPIO_U8_PORTB , GPIO_U8_PIN13
#define		HLEDMAT_COLUMN_6		GPIO_U8_PORTB , GPIO_U8_PIN14
#define		HLEDMAT_COLUMN_7		GPIO_U8_PORTB , GPIO_U8_PIN15


#endif /**the end of LEDM_CONFIG_H_*/