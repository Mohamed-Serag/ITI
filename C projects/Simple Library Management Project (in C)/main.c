/**************************************************************************************/
/* File Name: main.c                                                                  */
/* File Info: This is the main file of the library management application project.    */
/* Version  : V1.0                                                                    */
/* Date     : 1 Aug 2021.                                                             */
/* Author   : Mohamed Serag.                                                          */
/**************************************************************************************/
/*********************************************************************/
/************************* Linking Section ***************************/
/*********************************************************************/
#include "main.h"

int main(void)
{
	u8 Choice = 0;    /* This is the variable that will hold the user choice */
	u8 EntryCheck = 0; /* This variable is used to check the validitiy of users input */
	u8 ExitVariable = 0; /* This variable is used for App automatic shutdown */
	E_State ReturnCheck = 0; /* This variable is used for APIs return check */
	
	printf("--------------- WELCOME TO THE LIBRARY APP ---------------\n");
	
	while(1)
	{
		if(NO_ERRORS == ExitVariable)
		{
			printf("---------------------------------------------\n");
			printf("Choose one of the following options:\n");
			printf("To view all books               Enter \'1\'\n");
			printf("To add a New book               Enter \'2\'\n");
			printf("To Delete a book                Enter \'3\'\n");
			printf("To view No. of available books  Enter \'4\'\n");
			printf("To Exist the Library App        Enter \'5\'\n");
			printf("---------------------------------------------\n");
			printf("---> You Choice is : ");
			scanf("%d",&Choice);    /* Taking the user choice and placing it in Choice variable*/
			fflush(stdin);
			switch(Choice)
			{
				case 1 :ReturnCheck = ViewAllBooks();
						switch(ReturnCheck)
						{
							case E_NOK : printf("Something went wrong with ViewAllBooks function\n"); break;
							case E_OK  : EntryCheck = NO_ERRORS; break;
							default    : printf("Invalid return from ViewAllBooks in case 1\n"); 
										EntryCheck = NO_ERRORS; break;
						}
						Choice = 0;
						break;

				case 2 :ReturnCheck = AddNewBook();
						switch(ReturnCheck)
						{
							case E_NOK : printf("Something went wrong with AddNewBook function\n"); break;
							case E_OK  : EntryCheck = NO_ERRORS; break;
							default    : printf("Invalid return from AddNewBook in case 2\n"); 
										 EntryCheck = NO_ERRORS; break;
						}
						Choice = 0;
						break;

				case 3 :ReturnCheck = DeleteBook();
						switch(ReturnCheck)
						{
							case E_NOK : printf("Something went wrong with DeleteBook function\n"); break;
							case E_OK  : EntryCheck = NO_ERRORS; break;
							default    : printf("Invalid return from DeleteBook in case 2\n"); 
										 EntryCheck = NO_ERRORS; break;
						}
						Choice = 0;
						break;

				case 4 :ReturnCheck = PrintNumberOfBooks();
						switch(ReturnCheck)
						{
							case E_NOK : printf("Something went wrong with PrintNumberOfBooks function\n"); break;
							case E_OK  : EntryCheck = NO_ERRORS; break;
							default    : printf("Invalid return from PrintNumberOfBooks in case 2\n"); 
										 EntryCheck = NO_ERRORS; break;
						}
						Choice = 0;
						break;

				case 5 :printf("GOODBYE, Till We Meet Again :) \n");
				        exit(0);
						break;

				default:printf("You entered a wrong input, please try again !\n");
						EntryCheck++;
						if(MAXIMUM_WRONG_ENTRIES == EntryCheck)
						{
							printf("SORRY!, You've exceeded the maximum number of trials.\n The App is shutingdown GOODBYE...\n");
							ExitVariable = 1;
							break;
						}
						else{}
						break;
			}
		}
		else
		{
			break; /* To break the super loop (while(1)) and exit the application */
		}
	}
	return 0;
}