/********************************************************************************/
/*  File Name: Bit_Math.h                                                       */
/*  File Info: This File Contains the Macro Like Functions used for bits        */
/*             configuration.                                                   */
/*  Version  : V1.1                                                             */
/*  Author   : Mohamed Serag                                                    */
/*  Date     : 25 Oct 2020                                                      */
/********************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT)    (VAR |= (1<<BIT))
#define CLR_BIT(VAR, BIT)    (VAR &=~(1<<BIT))
#define TGL_BIT(VAR, BIT)    (VAR ^= (1<<BIT))
#define GET_BIT(VAR, BIT)    ((VAR >> BIT) &1)

#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)          CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)   (0b##B7##B6##B5##B4##B3##B2##B1##B0)

#define BYTE_IN_BINARY_FORMATE "%c%c%c%c%c%c%c%c"
#define BYTE_IN_BINARY(Byte) (Byte & 0x80 ? '1' : '0'), \
                             (Byte & 0x40 ? '1' : '0'), \
							 (Byte & 0x20 ? '1' : '0'), \
							 (Byte & 0x10 ? '1' : '0'), \
							 (Byte & 0x08 ? '1' : '0'), \
							 (Byte & 0x04 ? '1' : '0'), \
							 (Byte & 0x02 ? '1' : '0'), \
							 (Byte & 0x01 ? '1' : '0') 
#endif /** the end of BIT_MATH_H */
/*******************************************************************************************************/
/********************************************* History Log *********************************************/
/*******************************************************************************************************/
/*   .DD/MM/YYYY              .Name                        .Modification                               */
/*   ------------             ----------------             ------------------------                    */
/*   25 Oct 2020              Mohamed Serag                - File first Creation.                      */
/*                                                                                                     */
/*   25 Feb 2021              Mohamed Serag                - Adding:                                   */
/*                                                          1- BYTE_IN_BINARY_FORMATE                  */
/*                                                          2- BYTE_IN_BINARY(Byte)                    */
/*                                                                                                     */
/*******************************************************************************************************/