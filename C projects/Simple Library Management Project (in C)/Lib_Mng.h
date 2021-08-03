/**************************************************************************************/
/* File Name: Lib_Mng.h                                                               */
/* File Info: This is the header file of the library management application project.  */
/* Version  : V1.0                                                                    */
/* Date     : 1 Aug 2021.                                                             */
/* Author   : Mohamed Serag.                                                          */
/**************************************************************************************/
/*********************************************************************/
/*** Header file guard to prevent muliple inclusions of this file ****/
/*********************************************************************/
#ifndef LIBRARY_MANAGMENT_H
#define LIBRARY_MANAGMENT_H

/*********************************************************************/
/********************** Files Inclusions *****************************/
/*********************************************************************/
#include <stdio.h>
#include "STD_TYPES.h"


/*********************************************************************/
/*********************** Macros Definitions **************************/
/*********************************************************************/
#define MAXIMUM_WRONG_ENTRIES (3U)
#define MAXIMUM_BOOKS_NUMBER  (100U)
#define NO_BOOKS              (0U)
#define NO_ERRORS             (0U)
#define ZERO_WITH_SIGNED      (0)

/*********************************************************************/
/********************* User-Defined data types ***********************/
/*********************************************************************/
typedef enum Error_State{
	E_NOK,
	E_OK
}E_State;


typedef struct{
	u8 BookName[30];
	u8 Author[20];
	u16 Price;
}BookInfo_t;


/*********************************************************************/
/********************** Functions Prototypes *************************/
/*********************************************************************/

/*********************************************************************/
/* Function Name   : ViewAllBooks()                                  */
/* Function Info   : This function prints available books in the     */
/*                   library on the CMD.                             */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
extern E_State ViewAllBooks(void);


/*********************************************************************/
/* Function Name   : AddNewBook()                                    */
/* Function Info   : This function adds a new book to the library    */
/*                   the CMD.                                        */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
extern E_State AddNewBook(void);


/*********************************************************************/
/* Function Name   : DeleteBook()                                    */
/* Function Info   : This function deletes a book from the library.  */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
extern E_State DeleteBook(void);


/*********************************************************************/
/* Function Name   : PrintNumberOfBooks()                            */
/* Function Info   : This function prints the number of the available*/
/*                   books in the library.                           */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
extern E_State PrintNumberOfBooks(void);



#endif /** The end of LIBRARY_MANAGMENT_H */