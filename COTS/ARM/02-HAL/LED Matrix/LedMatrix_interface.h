/*******************************************************************************************************/
/* File Name : LedMatrix_interface.h                                                                   */
/* File info : This file contains all functions prototypes of the Led Matrix.                          */
/* Date      : 14 Dec 2020                                                                             */
/* Version   : V1.1                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/***** File Guard to prevent this header file from multiple inclusions ****/
/**************************************************************************/
#ifndef LEDM_INTERFACE_H_
#define LEDM_INTERFACE_H_


/**************************************************************************/
/******************** Functions Definitions Section ***********************/
/**************************************************************************/

/**************************************************************************/
/* Function Name   : HLEDMAT_voidInit()                                   */
/* Function Info   : This function initializes the Led Matrix Pins to     */
/*                   which it is connected.                               */
/* Function Input  : None.                                                */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void HLEDMAT_voidInit(void);


/**************************************************************************/
/* Function Name   : HLEDMAT_voidDisplayFrame()                           */
/* Function Info   : This function starts displaying the required frame by*/
/*                   activating the first column and rows values and the  */
/*                   periodic interrupt continues the repetition.         */
/* Function Input  : Copy_u8Frame --> a pointer that receives the address */
/*                                    of the array containing the frame   */
/*                                    data.                               */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame);


/**************************************************************************/
/* Function Name   : HLEDMAT_voidDisplayMovingFrame()                     */
/* Function Info   : This function starts displaying the required moving  */
/*                   frame by activating the first column and rows values */
/*                   and the periodic interrupt continues the repetition. */
/* Function Input  : Copy_u8Frame --> a pointer that receives the address */
/*                                    of the array containing the frame   */
/*                                    data.                               */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void HLEDMAT_voidDisplayMovingFrame(u8 *Copy_u8Frame);


/**************************************************************************/
/* Function Name   : DisplayNextMovingColumn()                            */
/* Function Info   : This function activates the next column to display   */
/*                   the required moving frame.                           */
/* Function Input  : Copy_u8Column --> the required column number.        */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void DisplayNextMovingColumn(void);


#endif /** the end of LEDM_INTERFACE_H_ */