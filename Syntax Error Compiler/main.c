/*************************************************************************************************
 * File Name                       : main.c                                                      *
 * File info                       : Prototype of a syntax error compiler that check for special *
 *                                   and little cases (not all cases)in C-Programming language . *
 * Version                         : 1.0 V (Trial).                                              *
 * File creation and documentation : - Mohamed Serag.                                            *
 * Participant developers          : - Yassen Kamal. - Mohannad El-Tabbakh. - Mohamed Serag.     *
 * Date                            : 17 Oct. 2020                                                *
 *************************************************************************************************/
#include "main.h"

/**************** Global Variables ****************/
char char_arr[LINE_MAX_LEN] = {0};
FILE *ptr = NULL;


int main()
{
    ptr = fopen("data.txt", "r");
    if(ptr == NULL)
    {
        printf("File does not exist !!!\n");
    }
    else
    {
       while(fgets(char_arr, LINE_MAX_LEN, ptr) != NULL)
       {
           main_call_function(char_arr);

        }
    }

    return 0;
}




