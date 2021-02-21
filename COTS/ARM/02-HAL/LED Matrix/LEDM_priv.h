/*******************************************************************************************************/
/* File Name : LedMatrix_private.h                                                                     */
/* File info : This file contains all helper functions prototypes of the Led Matrix.                   */
/* Date      : 14 Dec 2020                                                                             */
/* Version   : V1.1                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/***** File Guard to prevent this header file from multiple inclusions ****/
/**************************************************************************/
#ifndef LEDM_PRIVATE_H_
#define LEDM_PRIVATE_H_

/**************************************************************************/
/* Function Name   : ActivateColumn()                                     */
/* Function Info   : This function activates a column.                    */
/* Function Input  : Copy_u8Column --> the required column number.        */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void ActivateColumn(u8 Copy_u8Column);

/**************************************************************************/
/* Function Name   : DisplayNextColumn()                                  */
/* Function Info   : This function displays the next frame by activating  */
/*                   the next column and updates the next rows values.    */
/* Function Input  : None.                                                */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void DisplayNextColumn(void);

/**************************************************************************/
/* Function Name   : SetRowsValue()                                       */
/* Function Info   : This function sets Led Matrix rows values.           */
/* Function Input  : Copy_u8Value --> the upcoming frame value.           */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void SetRowsValue(u8 Copy_u8Value);

#endif /**the end of LEDM_PRIVATE_H_*/