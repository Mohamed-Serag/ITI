/*******************************************************************************************************/
/* File Name : LedMatrix_program.c                                                                     */
/* File info : This file contains all functions implementations of LED Matrix SW module.               */
/* Date      : 14 Dec 2020                                                                             */
/* Version   : V1.1                                                                                    */
/* Author    : Mohamed Serag.                                                                          */
/*******************************************************************************************************/

/**************************************************************************/
/************************* Linking Section ********************************/
/**************************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"
#include "GPIO_interface.h"
#include "STK_interface.h"        /* ARM Systick core peripheral interface file */
#include "LedMatrix_interface.h"
#include "LedMatrix_config.h"
#include "LedMatrix_private.h"


/**************************************************************************/
/************************ Definition Section ******************************/
/**************************************************************************/
u8 HLEDMAT_u8Index;
u8 HLEDMAT_u8Frame[8];
u8 *HLEDMAT_Ptru8Frame = NULL;
u8 HLEDMAT_u8NewCount1;
u8 HLEDMAT_u8NewCount2;

/**************************************************************************/
/***************** Functions Implementations Section **********************/
/**************************************************************************/
/**************************************************************************/
/* Function Name   : HLEDMAT_voidInit()                                   */
/* Function Info   : This function initializes the Led Matrix Pins to     */
/*                   which it is connected.                               */
/* Function Input  : None.                                                */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void HLEDMAT_voidInit(void)
{
	/**!comment: Row Port Direction*/
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_0, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_1, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_2, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_3, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_4, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_5, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_6, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_ROW_7, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);

	/**!comment: Columns Port Direction*/
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_0, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_1, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_2, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_3, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_4, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_5, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_6, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_enuSetPinDirection(HLEDMAT_COLUMN_7, GPIO_U8_OUTPUT_2MHZ_PUSH_PULL);

}



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
void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	HLEDMAT_u8Frame = Copy_u8Frame;
	/* Activate the column */
	ActivateColumn(HLEDMAT_u8Index);
	SetRowsValue(HLEDMAT_u8Frame[HLEDMAT_u8Index]);
	/* 2.5 msec periodic interrupt due to persistence of vision (50 FPS) */
	MSTK_voidSetIntervalPeriodic(2500, DisplayNextColumn);
}



/**************************************************************************/
/* Function Name   : DisplayNextColumn()                                  */
/* Function Info   : This function displays the next frame by activating  */
/*                   the next column and updates the next rows values.    */
/* Function Input  : None.                                                */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void DisplayNextColumn(void)
{
	/**!comment: Clearing all rows and columns at first to avoid ghosting */
	MGPIO_enuSetPortValues(GPIO_U8_PORTA, GPIO_U8_LOW);
	MGPIO_enuSetPortValues(GPIO_U8_PORTB, GPIO_U8_HIGH);
	/**!comment:incrementing the index to get the next column and array element */
	HLEDMAT_u8Index++ ;
	if (HLEDMAT_u8Index == 8)
	{
		HLEDMAT_u8Index = 0;
	}
	else{
		ActivateColumn(HLEDMAT_u8Index);
		SetRowsValue(HLEDMAT_u8Frame[HLEDMAT_u8Index]);
	}
}



/**************************************************************************/
/* Function Name   : SetRowsValue()                                       */
/* Function Info   : This function sets Led Matrix rows values.           */
/* Function Input  : Copy_u8Value --> the upcoming frame value.           */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void SetRowsValue(u8 Copy_u8Value)
{
	u8 Local_u8Iteration = 0;
	u8 Local_u8Temp[8];
	for(Local_u8Iteration = 0; Local_u8Iteration < 8; Local_u8Iteration++)
	{
		Local_u8Temp[Local_u8Iteration] = GET_BIT(Copy_u8Value, Local_u8Iteration);
	}
	/*		Set All Rows Values		*/
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_0, Local_u8Temp[0]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_1, Local_u8Temp[1]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_2, Local_u8Temp[2]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_3, Local_u8Temp[3]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_4, Local_u8Temp[4]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_5, Local_u8Temp[5]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_6, Local_u8Temp[6]);
	MGPIO_enuSetPinValue(HLEDMAT_ROWS_7, Local_u8Temp[7]);
}



/**************************************************************************/
/* Function Name   : ActivateColumn()                                     */
/* Function Info   : This function activates a column.                    */
/* Function Input  : Copy_u8Column --> the required column number.        */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void ActivateColumn(u8 Copy_u8Column)
{
	/*	Enable One Columns						*/
	switch(Copy_u8Column)
	{
		case 0: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_0, GPIO_U8_LOW); break;
		case 1: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_1, GPIO_U8_LOW); break;
		case 2: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_2, GPIO_U8_LOW); break;
		case 3: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_3, GPIO_U8_LOW); break;
		case 4: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_4, GPIO_U8_LOW); break;
		case 5: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_5, GPIO_U8_LOW); break;
		case 6: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_6, GPIO_U8_LOW); break;
		case 7: MGPIO_enuSetPinValue(HLEDMAT_COLUMN_7, GPIO_U8_LOW); break;
	}
}



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
void HLEDMAT_voidDisplayMovingFrame(u8 *Copy_u8Frame)
{

	HLEDMAT_Ptru8Frame = Copy_u8Frame;
	/* Activate the column */
	ActivateColumn(HLEDMAT_u8Index);
	SetRowsValue(HLEDMAT_Ptru8Frame[HLEDMAT_u8Index]);
	/* 2.5 msec periodic interrupt due to persistence of vision (50 FPS) */
	MSTK_voidSetIntervalPeriodic(2500, DisplayNextMovingColumn);
}



/**************************************************************************/
/* Function Name   : DisplayNextMovingColumn()                            */
/* Function Info   : This function activates the next column to display   */
/*                   the required moving frame.                           */
/* Function Input  : Copy_u8Column --> the required column number.        */
/* Function Ret_Val: None.                                                */
/**************************************************************************/
void DisplayNextMovingColumn(void)
{
	/**!Comment: Clearing all rows and columns at first to avoid ghosting */
	MGPIO_enuSetPortValues(GPIO_U8_PORTA, GPIO_U8_ALL_PORT, 0x0000);
	MGPIO_enuSetPortValues(GPIO_U8_PORTB, GPIO_U8_ALL_PORT, 0xFFFF);
	/**!Comment: incrementing the index to get the next column and array element */
	HLEDMAT_u8Index++ ;
	if (HLEDMAT_u8Index == 8)
	{
		HLEDMAT_u8Index = 0;
		HLEDMAT_u8NewCount1++;
		if(HLEDMAT_u8NewCount1 == 6)
		{
			HLEDMAT_u8NewCount2++;
			HLEDMAT_u8NewCount1 = 0;
		}

	}
	else{
		SetRowsValue(HLEDMAT_Ptru8Frame[HLEDMAT_u8Index + HLEDMAT_u8NewCount2]);
		ActivateColumn(HLEDMAT_u8Index);
		if (HLEDMAT_u8NewCount2 == 28)
		{
			HLEDMAT_u8NewCount2 = 0;
		}
	}
}

/*******************************************************************************************************/
/********************************************* History Log *********************************************/
/*******************************************************************************************************/
/*   .DD/MM/YYYY              .Name                        .Modification                               */
/*   ------------             ----------------             ------------------------                    */
/*   14 Dec 2020              Mohamed Serag                - File first Creation.                      */
/*                                                                                                     */
/*   18 Dec 2020              Mohamed Serag                - Adding two functions:                     */
/*                                                          1- HLEDMAT_voidDisplayMovingFrame()        */
/*                                                          2- DisplayNextMovingColumn()               */
/*                                                                                                     */
/*******************************************************************************************************/