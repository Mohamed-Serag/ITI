/*******************************************************************************************************/
/* File Name : SSD_interface.c                                                                         */
/* File info : This file contains all seven segment display sw module functions prototypes and user    */
/*             defined data types.                                                                     */
/* Date      : 19 Oct 2020                                                                             */
/* Version   : V1.0                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/
/***************************************************************************/
/***** File guard to prevent this header file from multiple inclusions *****/
/***************************************************************************/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define    COMMON_CATHOD    0
#define    COMMON_ANODE     1

typedef struct{
	u8 Type;                 /* Common Cathod or Anode*/
	u8 Data_Port;			 /* Data Port             */
	u8 Enable_Pin;           /* common pin in 7 seg. is connected to which PIN in the MCU */
	u8 Enable_Port;          /* common pin in 7 seg. is connected to which PORT in the MCU*/
}SSD_t;

/**************************************************************************/
/********************** Functions Prototypes ******************************/
/**************************************************************************/

/********************************************************************************************/
/* Function Name   : SSD_voidSendNumber()                                                   */
/* Function Info   : This function is used to display a number on the seven segment display.*/
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure to it.                                 */
/*                   Copy_u8Number --> the number to be displayed.                          */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
extern Error_State_t SSD_voidSendNumber(SSD_t *SSD, u8 Copy_u8Number);

/********************************************************************************************/
/* Function Name   : SSD_voidEnable()                                                       */
/* Function Info   : This function is used to enable a seven segment display.               */
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure to it.                                 */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
extern Error_State_t SSD_voidEnable(SSD_t *SSD);

/********************************************************************************************/
/* Function Name   : SSD_voidDisable()                                                      */
/* Function Info   : This function is used to disable a seven segment display.              */
/* Function Input  : SSD --> pointer to struct of type SSD_t to pass the address of the     */
/*                           seven segment structure to it.                                 */
/* Function Ret_Val: Local_u8Ret_Status --> the status of the function operation.           */
/********************************************************************************************/
extern Error_State_t SSD_voidDisable(SSD_t *SSD);

#endif /** the end of _SSD_INTERFACE_H*/
