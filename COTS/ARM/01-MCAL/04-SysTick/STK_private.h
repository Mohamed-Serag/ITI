/*******************************************************************************************************/
/* File Name : STK_private.h                                                                           */
/* File info : This file contains macros and user-defined data types used to build (STK) Systick core  */
/*             peripheral module.                                                                      */
/* Date      : 8 Dec 2020                                                                              */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/******* File guard to prevent this file from multiple inclusions *********/
/**************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/**************************************************************************/
/************************ Definition Section ******************************/
/**************************************************************************/
typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	
}MSTK_Type;

/* Systick base address definition */
#define    MSTK    ((volatile MSTK_Type *)(0xE000E010))

/* Systick clock source options (AHB or AHB/8)*/
#define    MSTK_SRC_AHB          1
#define    MSTK_SRC_AHB_8        0

/* Systick interrput mode (single or periodic) */
#define    MSTK_SINGLE_INTERVAL  0
#define    MSTK_PERIOD_INTERVAL  1

#endif /** the end of STK_PRIVATE_H */