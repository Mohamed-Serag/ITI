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

#endif /** the end of BIT_MATH_H */