/*******************************************************************/
/* File Name: DIO_private.h                                        */
/* File Info: This file contains DIO driver registers definitions  */
/*            and macros.                                          */
/* Version  : V1.0                                                 */
/* Date     : 18 Oct. 2020                                         */
/* Author   : Mohamed Serag.                                       */
/*******************************************************************/
/******************************************************************/
/* Header file Guard to prevent this file from muliple inclusions */
/******************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Disabling or Enabling Ports Macros */
#define  DISABLE_PORT   0
#define  ENABLE_PORT    1

/* Input or Output Pins Config Macros */
#define  INPUT_PIN      0
#define  OUTPUT_PIN     1

/* Disabling or Enabling Internal Pull-up Resistors Macros */
#define  PULL_UP_DISABLED  0
#define  PULL_UP_ENABLED   1



/* Port A Registers Definition */
#define DDRA_REG  *((uint8_t volatile *)0x3A)
#define PORTA_REG *((uint8_t volatile *)0x3B)
#define PINA_REG  *((uint8_t volatile *)0x39)

/* Port B Registers Definitions */
#define DDRB_REG  *((uint8_t volatile *)0x37)
#define PORTB_REG *((uint8_t volatile *)0x38)
#define PINB_REG  *((uint8_t volatile *)0x36)

/* Port C Registers Definitions */
#define DDRC_REG  *((uint8_t volatile *)0x34)
#define PORTC_REG *((uint8_t volatile *)0x35)
#define PINC_REG  *((uint8_t volatile *)0x33)

/* Port D Registers Definitions */
#define DDRD_REG  *((uint8_t volatile *)0x31)
#define PORTD_REG *((uint8_t volatile *)0x32)
#define PIND_REG  *((uint8_t volatile *)0x30)


#endif /** The end of DIO_PRIVATE_H */
