/**************************************************************************************/
/* File Name: Lib_Mng.c                                                               */
/* File Info: This is the source file of the library management application project   */
/*            that contains the APIs implemetations for the project.                  */
/* Version  : V1.0                                                                    */
/* Date     : 1 Aug 2021.                                                             */
/* Author   : Mohamed Serag.                                                          */
/**************************************************************************************/
/*********************************************************************/
/************************* Linking Section ***************************/
/*********************************************************************/
#include "Lib_Mng.h"


/*********************************************************************/
/******************* Global Declaration Section **********************/
/*********************************************************************/

u8 NumberOfBooks;
BookInfo_t Books[100];



/*********************************************************************/
/* Function Name   : ViewAllBooks()                                  */
/* Function Info   : This function prints available books in the     */
/*                   library on the CMD.                             */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
E_State ViewAllBooks(void)
{
	E_State L_ReturnValue = E_OK;
	u8 Local_Iterator = 0;
	if(NO_BOOKS == NumberOfBooks)
	{
		printf("The library is empty. No books to view !\n");
		return L_ReturnValue; 
	}
	else if(((MAXIMUM_BOOKS_NUMBER > NumberOfBooks) && (NO_BOOKS != NumberOfBooks)) || ((MAXIMUM_BOOKS_NUMBER == NumberOfBooks)))
	{
		printf("-------------------- The Available Books --------------------\n");
		for(Local_Iterator = 0; Local_Iterator < NumberOfBooks; Local_Iterator++)
		{
			printf("Book NO.%d is:\n", Local_Iterator+1);
			printf("The Book Name   : %s\n", Books[Local_Iterator].BookName);
			printf("The Book Author : %s\n", Books[Local_Iterator].Author);
			printf("The Book Price  : %d\n", Books[Local_Iterator].Price);
			printf("------------------------------------------\n");
		}
		return L_ReturnValue;
	}
}

/*********************************************************************/
/* Function Name   : AddNewBook()                                    */
/* Function Info   : This function adds a new book to the library    */
/*                   the CMD.                                        */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
E_State AddNewBook(void)
{
	E_State L_ReturnValue = E_OK;
	if(MAXIMUM_BOOKS_NUMBER == NumberOfBooks)
	{
		printf("SORRY!, The Library seems to be full :( \n");
	}
	else if(MAXIMUM_BOOKS_NUMBER > NumberOfBooks)
	{
		/* Adding the Book Name */
		printf("Enter the name of the book : ");
		gets(&(Books[NumberOfBooks].BookName));
		/* Adding the Author Name */
		printf("Enter the name of the author : ");
		gets(&(Books[NumberOfBooks].Author));
		/* Adding the Book Price */
		printf("Enter the book price : ");
		scanf("%d", &Books[NumberOfBooks].Price);
		/* Increasing the NumberOfBooks variable */
		NumberOfBooks++;
		printf("The Book has been added succefully :) \n");
	}
	else{
		L_ReturnValue = E_NOK;
	}
	return L_ReturnValue;
}

/*********************************************************************/
/* Function Name   : DeleteBook()                                    */
/* Function Info   : This function deletes a book from the library.  */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
E_State DeleteBook(void)
{
	E_State L_ReturnValue = E_OK;
	if(NO_BOOKS == NumberOfBooks)
	{
		printf("Sorry the library is empty and there is no books to be deleted. \n");
	}
	else if(NO_BOOKS < NumberOfBooks)
	{
		s8 BookNumber = 0; /* This variable will hold the number of the book to be deleted */
		printf("Enter the Number of the book you want to delete (from 1 to %d):", NumberOfBooks);
		scanf("%d", &BookNumber);
		if((BookNumber <= NumberOfBooks) && (BookNumber > ZERO_WITH_SIGNED))
		{
			u8 L_Iterator = 0, L_Iterator1 = 0, L_Iterator2 = 0;
			for(L_Iterator = (BookNumber-1); L_Iterator < (NumberOfBooks-1); L_Iterator++)
			{
				for(L_Iterator1 = 0; L_Iterator1 < 30; L_Iterator1++)
				{
					Books[L_Iterator].BookName[L_Iterator1] = Books[L_Iterator+1].BookName[L_Iterator1];
				}
				for(L_Iterator2 = 0; L_Iterator2 < 20; L_Iterator2++)
				{
					Books[L_Iterator].Author[L_Iterator2] = Books[L_Iterator+1].Author[L_Iterator2];
				}
				Books[L_Iterator].Price = Books[L_Iterator+1].Price;
			}
			NumberOfBooks--;
		}
		else if(BookNumber == NO_BOOKS)
		{
			printf("SORRY!, Invalid input. Please try again.\n");
		}
		else if(BookNumber > NumberOfBooks)
		{
			printf("This Book NO. is unavailable !!!\n");
		}
		else if (BookNumber < ZERO_WITH_SIGNED)
		{
			printf("Woops !!!, You Entered a negative number.\n");
		}
		else
		{
			L_ReturnValue = E_NOK;
		}
	}
	else
	{
		L_ReturnValue = E_NOK;
	}
	return L_ReturnValue;
}

/*********************************************************************/
/* Function Name   : PrintNumberOfBooks()                            */
/* Function Info   : This function prints the number of the available*/
/*                   books in the library.                           */
/* Function Input  : None.                                           */
/* Function Ret_val: Function execution status (E_OK or E_NOK).      */
/*********************************************************************/
E_State PrintNumberOfBooks(void)
{
	E_State L_ReturnValue = E_OK;
	if(NO_BOOKS == NumberOfBooks)
	{
		printf("The Library is empty. No available books to view !\n");
	}
	else if(NO_BOOKS < NumberOfBooks)
	{
		printf("The Number of available Books is %d\n", NumberOfBooks);
	}
	else
	{
		L_ReturnValue = E_NOK;
	}
	return L_ReturnValue;
}