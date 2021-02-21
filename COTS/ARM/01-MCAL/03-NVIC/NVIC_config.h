/*******************************************************************************************************/
/* File Name : NVIC_config.h                                                                           */
/* File info : This file contains all user configuration of the NVIC module.                           */
/* Date      : 30 Nov 2020                                                                             */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/
/**************************************************************************/
/******* File guard to prevent this file from multiple inclusions *********/
/**************************************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/* The number of bits for groups and sub-groups */
#define    NVIC_4BITS_GROUP_0BITS_SUB    (0x05FA0300)
#define    NVIC_3BITS_GROUP_1BITS_SUB    (0x05FA0400)
#define    NVIC_2BITS_GROUP_2BITS_SUB    (0x05FA0500)
#define    NVIC_1BITS_GROUP_3BITS_SUB    (0x05FA0600)
#define    NVIC_0BITS_GROUP_4BITS_SUB    (0x05FA0700)


/**************************************************************************/
/* Macro Name  : NUM_GROUPS_NUM_SUB                                       */
/* Macro Info  : This macro is used to choose the number of groups and    */
/*                sub-groups.                                             */
/* Macro Values: 1- NVIC_4BITS_GROUP_0BITS_SUB                            */
/*               2- NVIC_3BITS_GROUP_1BITS_SUB                            */
/*               3- NVIC_2BITS_GROUP_2BITS_SUB                            */
/*               4- NVIC_1BITS_GROUP_3BITS_SUB                            */
/*               5- NVIC_0BITS_GROUP_4BITS_SUB                            */
/**************************************************************************/
#define    NUM_GROUPS_NUM_SUB            NVIC_2BITS_GROUP_2BITS_SUB

#endif/** the end of NVIC_CONFIG_H*/