/*******************************************************************************************************/
/* File Name : STK_config.h                                                                            */
/* File info : This file contains Systick core peripheral (STK) configuration macros.                  */
/* Date      : 8 Dec 2020                                                                              */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/******* File guard to prevent this file from multiple inclusions *********/
/**************************************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/**************************************************************************/
/* Macro Discription: This macro is used to choose the STK clock source.  */
/* Available Choices: 1- MSTK_SRC_AHB_8  (AHB / 8)                        */
/*                    2- MSTK_SRC_AHB    (AHB)                            */
/**************************************************************************/
#define    MSTK_CLK_SRC    MSTK_SRC_AHB_8

#endif /** the end of STK_CONFIG_H */