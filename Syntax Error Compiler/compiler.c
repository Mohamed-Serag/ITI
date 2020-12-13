/***********************************************************************************************
 * File Name                       : compiler.c                                                *
 * File info                       :this file contains the functions implementations of syntax *
 *                                   error compiler .                                          *
 * Version                         : 1.0 V (Trial).                                            *
 * File creation and documentation : - Mohamed Serag.                                          *
 * Participant developers          : - Yassen Kamal. - Mohannad El-Tabbakh. - Mohamed Serag.   *
 * Date                            : 17 Oct. 2020                                              *
 ***********************************************************************************************/
#include "compiler.h"
/**************** Global Variables ****************/
int ifflag = 0;

/************************ Functions Implementations ************************/
/************************************************************
 * Function Name    : main_call_function                    *
 * AUTHOR           : Mohamed Serag.                        *
 * Function info    : it chooses which function to call to  *
 *                    for the required line.                *
 * Function Input   : pointer to char (str_arr)             *
 * Function Ret_val : None.                                 *
 ************************************************************/
void main_call_function(char *str_arr)
{
	char i = 0;
    while(str_arr[i] == ' ')
    {
        i++;
    }
    switch(str_arr[i])
    {
		case 'c' :
			if(str_arr[i+1] == 'h' && str_arr[i+2] == 'a' && str_arr[i+3] == 'r' && str_arr[i+4] == ' ')
			{
				CharCheck(str_arr);
			}
			else
			{
				printf("Syntax Error : in %s\n", str_arr);
			}
			break;
		case 'd' :
			if(str_arr[i+1] == 'o')
			{
				do_while_check(str_arr);
			}
			else
			{
				printf("Syntax Error : in %s\n", str_arr);
			}
			break;
		case 'f' :
			if(str_arr[i+1] == 'l' && str_arr[i+2] == 'o' && str_arr[i+3] == 'a' && str_arr[i+4] == 't' && str_arr[i+5] == ' ')
			{
				Float_Check(str_arr);
			}
			else if(str_arr[i+1] == 'o' && str_arr[i+2] == 'r' )
            {
                forcheck(str_arr);
            }
			else
			{
				printf("Syntax Error : in %s\n", str_arr);
			}
			break;
		case 's' :
			if(str_arr[i+1] == 'w' && str_arr[i+2] == 'i' && str_arr[i+3] == 't' && str_arr[i+4] == 'c' && str_arr[i+5] == 'h' )
			{
				switchcheck(str_arr);
			}
			else
			{
				printf("Syntax Error : in %s\n", str_arr);
			}
			break;
		case 'i':
			if(str_arr[i+1] == 'n' && str_arr[i+2] == 't' && str_arr[i+3] == ' ')
			{
				int_check(str_arr);

			}
			else if(str_arr[i+1] == 'f')
			{
				If_Check(str_arr);
			}
			else
			{
				printf("Syntax Error 15 : in %s\n", str_arr);
			}
			break;
		case 'w':
			if(str_arr[i+1] == 'h' && str_arr[i+2] == 'i' && str_arr[i+3] == 'l' && str_arr[i+4] == 'e')
			{
				WhileCheck(str_arr);
			}
			else
			{
				printf("Syntax Error : in %s\n", str_arr);
			}
			break;
		case 'e' :
            if(str_arr[i+1] == 'l' && str_arr[i+5] == 'i' && str_arr[i+6] == 'f')
            {
                ElseIfCheck(str_arr);
            }
            else if(str_arr[i+1] == 'l' && str_arr[i+2] == 's' && str_arr[i+3] == 'e' && str_arr[i+5] != 'i')
            {
                ElseCheck(str_arr);
            }
            else
            {
                printf("Syntax Error : in %s\n", str_arr);
            }
            break;
        case 'v':
            if(str_arr[i+1] == 'o' && str_arr[i+2] == 'i' && str_arr[i+3] == 'd' && str_arr[i+4] == ' ')
            {
                MainCheck(str_arr);
            }
		default :
            break;



    }
}

/************************************************************
 * Function Name    : CharCheck                             *
 * AUTHOR           : Mohanned ElTabbakh.                   *
 * Function info    : it checks for char variable definition*
 *                    and initialization both in one line.  *
 * Function Input   : pointer to char (str)                 *
 * Function Ret_val : None.                                 *
 ************************************************************/
void CharCheck(char *str)
{
	int semicolon = 0, i = 0, equal = 0, charflag = 0, nameflag = 0, decflag = 0;

	for(i = 0; i <= strlen(str); i++)
    {
        if(str[i]==' ')
        {
            continue;
        }
        else if (str [i] == 'c' && str [i + 1] == 'h' && str [i + 2] == 'a' && str [i + 3] == 'r' && str [i+4] == ' ')
        {
            i += 4;
            charflag = 1;
        }
        else if ((charflag == 1 && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) == 1 )
        {
            nameflag = 1;
        }
        else if (charflag == 1 && str [i] == '=')
        {
            equal = 1;
        }
        else if (charflag == 1 && str [i] == '\'' && str [i+2] == '\'' && ((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'A' && str[i+1] <= 'Z')) == 1)
        {
            decflag = 1;
        }
        else if (charflag == 1 && str [i] == ';')
        {
            semicolon = 1;
        }
    }

    if (charflag == 0)
    {
        printf("Error in char keyword usage in --> %s\n", str);
    }
    if (nameflag == 0)
    {
        printf ("Error in variable naming in --> %s\n", str);
    }
    if (equal == 0)
    {
        printf ("Equal sign missing in --> %s\n", str);
    }
    if (decflag == 0)
    {
        printf ("Error in variable initialization in --> %s\n", str);
    }
    if (semicolon == 0)
    {
        printf ("Semicolon missing in --> %s\n", str);
    }
}


/************************************************************
 * Function Name    : int_check                             *
 * AUTHOR           : Mohamed Serag.                        *
 * Function info    : it checks for int variable definition *
 *                    and initialization both in one line   *
 * Function Input   : pointer to char (str_arr)             *
 * Function Ret_val : None.                                 *
 ************************************************************/
void int_check(char *str_arr)
{
	char i=0, int_itr=0, j=0;
	char arr[10] = {0};
	while(str_arr[i] == ' ')
    {
        i++;
    }

	for(int_itr = 0; int_itr < 3 ; int_itr++)
	{
	    j = i + int_itr;
		arr[int_itr]= str_arr[j];
	}
	if(strcmp(arr,"int") != 0)
	{
		printf("Syntax Error, undefined data type !  in \" %s \" \n",str_arr);
		return;
	}
    i+=3;



    if(str_arr[i] != ' ')
    {
        printf("Syntax Error, indentation problem int%c..   in \" %s \"\n",str_arr[i], str_arr);
    }


    while(str_arr[i]== ' ')
    {
        i++;
    }
    if(isalpha(str_arr[i++]) == 0)
    {
        printf("Syntax Error : Invaild variable Name %c%c%c... in \"%s\"\n",str_arr[i-1],str_arr[i],str_arr[i+1], str_arr);
    }


    while(isalpha(str_arr[i]) != 0 || isdigit(str_arr[i]) != 0 || str_arr[i] == '_' || str_arr[i] == ' '){
        i++;
    }

    if(str_arr[i] != '_' && str_arr[i] != '=')
    {
        printf("Syntax Error : Invaild symbol(%c) in variable name   in \" %s \" \n", str_arr[i], str_arr);
        return;
    }

    if(str_arr[i++] == '=')
    {
        while(isdigit(str_arr[i])!= 0 || str_arr[i] == '-' || str_arr[i] == ' ' && str_arr[i] != ';' && i<strlen(str_arr)-1)
        {
            i++;
        }
        if(str_arr[i] == ';'){
            return;
        }else if(i >= strlen(str_arr)-1){
            printf("Syntax Error : missing ';' in \"%s\"\n", str_arr);
            return;
        }else{
            printf("Syntax Error : implicit casting in \"%s\"\n", str_arr);
            return;
        }
    }
}

/*************************************************************
 * Function Name    : Float_Check                            *
 * AUTHOR           : Yassen Kamal.                          *
 * Function info    : it checks for float variable definition*
 *                    and initialization both in one line    *
 * Function Input   : pointer to char (pstr)                 *
 * Function Ret_val : None.                                  *
 *************************************************************/
void Float_Check(char* pstr)
{
	char flag=0;
    int i=0;
	//Check syntax
	for(i=0;i<=strlen(pstr);i++){
		if(pstr[i]==' '){
			continue;
		}
		else if(pstr[i] == 'f' && pstr[i+1]=='l' && pstr[i+2]=='o' && pstr[i+3]=='a' && pstr[i+4]=='t' && pstr[i+5]==' '){
			flag+=1;
			i+=5;
		}
		else if(flag==1 && !((pstr[i]>='A' && pstr[i]<='Z') | (pstr[i]>='a' && pstr[i]<='z')) ){
			break;
		}
		else if(flag==1 && ((pstr[i]>='A' && pstr[i]<='Z') | (pstr[i]>='a' && pstr[i]<='z')) ){
			flag+=1;
		}
		else if(flag==2 && pstr[i]==';'){
			//float syntax test passed
			flag+=1;
			break;
		}
		else if(flag==2 && pstr[i]=='=' ){
			flag+=2;
		}
		else if(flag == 4 && (pstr[i]<'0' | pstr[i]>'9' | pstr[i]==';')){
			break;
		}
		else if(flag==4 && pstr[i]>='0' && pstr[i]<='9'){
			flag+=1;
		}
        else if(flag == 5 && (pstr[i]!=';' && pstr[i] != '.') && (pstr[i]<'0' | pstr[i]>'9' )){
            break;
		}
		else if(flag == 5 && pstr[i] == '.'){
		    flag+=1;
		}
		else if(flag == 6 && (pstr[i]<'0' | pstr[i]>'9')){
            break;
		}
		else if(flag==6  && (pstr[i]>='0' && pstr[i]<='9')){
            flag+=1;
		}
		else if(flag==7  && (pstr[i]<'0' | pstr[i]>'9') && pstr[i]!=';'){
            break;
		}
		else if((flag==5 | flag ==7)  && pstr[i]==';'){
            //float syntax test passed
            flag=3;
		}
	}

	if(flag != 3){
		printf("Syntax Error: in float statement\n");
	}
}


/*************************************************************
 * Function Name    : do_while_check                         *
 * AUTHOR           : Mohamed Serag.                         *
 * Function info    : it checks for do while-loop syntax     *
 *                    errors.                                *
 * Function Input   : pointer to char (str_arr)              *
 * Function Ret_val : None.                                  *
 *************************************************************/
void do_while_check(char *str_arr)
{
    char i = 0, int_itr = 0, j = 0, arr[60] = {0};
    static char  first_bracket_flag = 0 ;

	/**********************************************************************
	 * checking for spaces before "do" and neglecting them                *
	 **********************************************************************/
	while(str_arr[i] == ' ')
    {
        i++;
    }

     /*********************************************************************
      *  Filling the first 2 elements of the array "arr" with "do"        *
      *  word to check in the next step if it has been written correctly  *
      *********************************************************************/

	for(int_itr = 0; int_itr < 2 ; int_itr++)
	{
	    j = i + int_itr;
		arr[int_itr]= str_arr[j];
	}


    /**********************************************************************
     * checking for "do" keyword itself                                   *
     **********************************************************************/
	if(strcmp(arr,"do") != 0)
	{
	    printf("arr = %s\n", arr);
		printf("Syntax Error in do...  in  \" %s \"\n", str_arr);
		return;
	}
	i+=2;


	/**********************************************************************
	 * checking for spaces after "do" and neglecting them                 *
	 **********************************************************************/

	while(str_arr[i] == ' ')
    {
        i++;
    }


     /********************************************************************
      * checking if the first character after spaces is '{' or '{' does  *
      * not exist in the same line with "do" at all (and reaches the end *
      * of line without finding '{' ).                                   *
      ********************************************************************/

	if(str_arr[i] != '{' && i<strlen(str_arr)-1)
    {
        printf("Syntax Error : Unknown object in  \" %s \"\n", str_arr);
        i++;
            /**************************************************************
             *   Another while loop to check if the '{' exists after      *
             *   an unknown object, number, or character.                 *
             **************************************************************/
            while(str_arr[i] != '{')
            {
                if(str_arr[i] == '{')
                {
                    first_bracket_flag = 1;
                }
                i++;
            }
    }
    else if (str_arr[i] != '{' && i>=strlen(str_arr)-1)
    {
        first_bracket_flag = 0; /** didn't find the '{' in the first line after "do"*/
    }
    if(str_arr[i++] == '{')
    {
        first_bracket_flag = 1;
    }

    /*********************************************************************
     *The end of "do" + the first '{' checking                           *
     *********************************************************************/

/******************** The beginning of the second line ********************/

    /*********************************************************************
     * Checking for the first '{' because if the first_bracket_flag = 0  *
     * this means it was not found in in the first line                  *
     *********************************************************************/
    if(first_bracket_flag == 0)
    {
        i=0;
        fgets(char_arr, LINE_MAX_LEN, ptr);
    /**********************************************************************
     * checking for spaces before '{' (if exist) and neglecting them      *
     **********************************************************************/
        while(str_arr[i] == ' ')
        {
            i++;
        }

    /**********************************************************************
     * checking for the existence of the first '{' in the second line     *
     **********************************************************************/
        if(str_arr[i] != '{')
        {
            printf("Syntax Error : missing \'{\' after \"do\" in  \" %s \"\n", str_arr);
        }
        else{
            first_bracket_flag = 1;
        }
    }
            i=0;
            fgets(char_arr, LINE_MAX_LEN, ptr);
            /**********************************************************************
             * checking for spaces at the beginning of line and neglecting them   *
             **********************************************************************/
            while(str_arr[i] == ' ')
            {
                i++;
            }

            while(str_arr[i++] != '}')
            {
              /*************************************************************************************
               ( CHECKING AND CALLING main_call_function() TO CHOOSE OTHER FUNCTIONS TO CHAECK FOR
                THE CODE INSIDE THE {} OF DO..WHILE ).
               **************************************************************************************/
                main_call_function(char_arr);
                i=0;
                fgets(char_arr, LINE_MAX_LEN, ptr);
               // printf("The line : %s\n", char_arr);
                while(str_arr[i] == ' ')
                {
                    i++;
                }
            }

            /**********************************************************************
             * checking for spaces between '}' and while and neglecting them      *
             **********************************************************************/
             while(str_arr[i] == ' ')
            {
                i++;
            }
            /**********************************************************************
             * checking if the while( )  is not in the same line with                               *
             **********************************************************************/
            if(str_arr[i] != 'w'){
                i=0;
                fgets(char_arr, LINE_MAX_LEN, ptr);
                 while(str_arr[i] == ' ')
                {
                    i++;
                }
            }
            /**********************************************************************
             * checking for "while" keyword itself                                *
             **********************************************************************/
            if(str_arr[i++]=='w' && str_arr[i++]=='h' && str_arr[i++]=='i' && str_arr[i++]=='l' && str_arr[i++]=='e')
            {
            /**********************************************************************
             * checking for spaces between "while" and '(' and neglecting them    *
             **********************************************************************/
                while(str_arr[i] == ' ')
                {
                    i++;
                }

            /**********************************************************************
             * checking for '(' after "while" keyword                             *
             **********************************************************************/
                if(str_arr[i++] != '(')
                {
                    printf("Syntax Error : missing '(' before \"while\" in  \" %s \"\n", str_arr);
                }
                else{

            /**********************************************************************
             * if '(' is found the while loop will keep iterating until ')' is    *
             * found.                                                             *
             **********************************************************************/
                    while(str_arr[i] != ')')
                    {
                        i++;
                    }
                    i++;

           /**********************************************************************
            * checking for spaces between ')' and ';' and neglecting them      *
            **********************************************************************/
                     while(str_arr[i] == ' ')
                     {
                         i++;
                     }

            /**********************************************************************
             * checking for ';' at the end of line      *
             **********************************************************************/
                    if(str_arr[i] != ';')
                    {
                        printf("Syntax Error : expected ; after while() in  \" %s \"\n", str_arr);
                    }
                    else{

                    }
                }
            }else{
                printf("Syntax Error : \"while\" keyword is incorrect in  \" %s \"\n", str_arr);
            }


}


/************************************************************
 * Function Name    : while_check                           *
 * AUTHOR           : Mohanned El Tabbakh.                  *
 * Function info    : it checks for while-loop syntax error.*
 * Function Input   : pointer to char (str)                 *
 * Function Ret_val : None.                                 *
 ************************************************************/
void WhileCheck(char *str)
{
	int openbracket = 0, closebracket = 0, whileflag = 0, ocbracket = 0, i = 0;

	for(i = 0; i <= strlen(str); i++)
    {
        if(str[i]==' ')
        {
            continue;
        }
        else if (str [i] == 'w' && str [i + 1] == 'h' && str [i + 2] == 'i' && str [i + 3] == 'l' && str [i + 4] == 'e')
        {
            i += 4;
            whileflag = 1;
        }
        else if (whileflag == 1 && str [i] == '(')
        {
            openbracket = 1;
        }
        else if (whileflag == 1 && str [i] == ')')
        {
            closebracket = 1;
        }
        else if (whileflag == 1 && closebracket == 1 && str [i] == '{')
        {
            ocbracket = 1;
        }
    }

    if (whileflag == 0)
    {
        printf("Error in while keyword usage in --> %s\n", str);
    }
    if (openbracket == 0 && whileflag != 0)
    {
        printf("Opening parenthesis absent after while keyword in --> %s\n", str);
    }
    if (closebracket == 0 && whileflag != 0)
    {
        printf("Closing parenthesis absent in --> %s\n", str);
    }
    else if (closebracket == 1 && ocbracket == 0)
    {
        printf("Opening Curl Bracket absent in --> %s\n", str);
    }

    if (ocbracket == 1)
	{
		while(str[i++] != '}')
            {
                i=0;
                fgets (char_arr, LINE_MAX_LEN, ptr);
                while(str[i] == ' ')
                {
                    i++;
                }
                main_call_function(char_arr);
            }
    }
}


 /************************************************************
 * Function Name    : forcheck                               *
 * AUTHOR           : Yassen Kamal.                          *
 * Function info    : it checks for for-loop syntax errors.  *
 * Function Input   : pointer to char (pstr)                 *
 * Function Ret_val : None.                                  *
 *************************************************************/
void forcheck(char* pstr)
{
	char flag=0 , curly = 0 , semicolon = 0, newline = 0 , statement=0, i = 0;

	update_line:
		if(flag!=0){
			fgets(pstr, LINE_MAX_LEN, ptr);
			newline+=1;
		}

	//Check syntax
	for(i=0;i<=strlen(pstr);i++){
		if(pstr[i]==' '){
			continue;
		}
		else if(pstr[i] == 'f' && pstr[i+1]=='o' && pstr[i+2]=='r'){
			flag+=1;
			i+=2;

		}
		else if(flag==1 && pstr[i]=='('){
			flag+=1;

		}
		else if(flag==2 && pstr[i]!=')' ){
			// Call other functions to check condition syntax//

			if(pstr[i]==';'){
                semicolon+=1;
			}
		}
		else if(flag==2 && pstr[i]==')' && semicolon == 2 ){
			flag+=1;

		}
		else if(flag==3 && pstr[i]=='{' ){
			flag+=1;
			curly+=1;
			statement+=1;


		}
		else if(flag == 4 && statement ==1 && pstr[i]!='{' && pstr[i]!='}'){
            fgets(pstr, LINE_MAX_LEN, ptr);
            i=0;
            if(pstr[i]=='}'){
                goto closedcurly;
            }
            main_call_function(pstr);
            statement-=1;
            goto update_line;
		}

        else if(flag == 4 && pstr[i]=='}' && curly!=0 ){
            closedcurly:
            curly+=1;

                if(curly==2 && semicolon == 2){
                    //for syntax test passed
					flag+=1;
					return ;
                }
		}
	}

	if(curly!=2){
        if(newline==25){
            goto Error;
        }
		goto update_line;

	}

    Error:
	if(flag != 5){
		printf("Syntax Error: in for statement \n");
	}
}
/*************************************************************
 * Function Name    : If_Check                               *
 * AUTHOR           : Mohannad El Tabbakh.                   *
 * Function info    : it checks for if statement syntax error*
 * Function Input   : pointer to char (str)                  *
 * Function Ret_val : None.                                  *
 *************************************************************/
void If_Check(char *str)
{
	int openbracket = 0, closebracket = 0, ocbracket = 0, i = 0;

	for(i = 0; i <= strlen(str); i++)
    {
        if(str[i]==' ')
        {
            continue;
        }
        else if (str [i] == 'i' && str [i + 1] == 'f')
        {
            i += 1;
            ifflag = 1;
        }
        else if (ifflag == 1 && str [i] == '(')
        {
            openbracket = 1;
        }
        else if (ifflag == 1 && str [i] == ')')
        {
            closebracket = 1;
        }
		else if (ifflag == 1 && closebracket == 1 && str [i] == '{')
        {
            ocbracket = 1;
        }
    }

    if (ifflag == 0)
    {
        printf("Error in if keyword usage in --> %s\n", str);
    }
    if (openbracket == 0 && ifflag != 0)
    {
        printf("Opening parenthesis absent after if keyword in --> %s\n", str);
    }
    if (closebracket == 0 && ifflag != 0)
    {
        printf("Closing parenthesis absent in --> %s\n", str);
    }
    else if (closebracket == 1 && ocbracket == 0)
    {
        printf("Opening Curl Bracket absent in --> %s\n", str);
    }

    if (ocbracket == 1)
	{
		while(char_arr[i++] != '}')
            {
                i=0;
                fgets (char_arr, LINE_MAX_LEN, ptr);
                while(char_arr[i] == ' ')
                {
                    i++;
                }
                main_call_function(char_arr);
            }
            //printf("if out \n");
    }
}

/*************************************************************
 * Function Name    : ElseIfCheck                            *
 * AUTHOR           : Mohannad El Tabbakh.                   *
 * Function info    : it checks for if statement syntax error*
 * Function Input   : pointer to char (str_arr)              *
 * Function Ret_val : None.                                  *
 *************************************************************/
void ElseIfCheck(char *str)
{
	int openbracket = 0, closebracket = 0, elseifflag = 0, ocbracket = 0, i = 0;

	if (ifflag == 0)
    {
        printf("Else If Without If in --> %s\n", str);
    }

    else if (ifflag == 1)
    {
        for(i = 0; i <= strlen(str); i++)
        {
            if(str[i]==' ')
            {
                continue;
            }
            else if (str [i] == 'e' && str [i + 1] == 'l' && str [i + 2] == 's' && str [i + 3] == 'e' && str [i + 4] == ' ' && str [i + 5] == 'i' && str [i + 6] == 'f')
            {
                i += 6;
                elseifflag = 1;
            }
            else if (elseifflag == 1 && str [i] == '(')
            {
                openbracket = 1;
            }
            else if (elseifflag == 1 && str [i] == ')')
            {
                closebracket = 1;
            }
            else if (elseifflag == 1 && closebracket == 1 && str [i] == '{')
            {
                ocbracket = 1;
            }
        }

        if (elseifflag == 0)
        {
            printf("Error in else if keyword usage in --> %s\n", str);
        }
        if (openbracket == 0 && elseifflag != 0)
        {
            printf("Opening parenthesis absent after else if keyword in --> %s\n", str);
        }
        if (closebracket == 0 && elseifflag != 0)
        {
            printf("Closing parenthesis absent in --> %s\n", str);
        }
        else if (closebracket == 1 && ocbracket == 0)
        {
            printf("Opening Curl Bracket absent in --> %s\n", str);
        }

        if (ocbracket == 1)
        {
            while(str[i++] != '}')
            {
                i=0;
                fgets (char_arr, LINE_MAX_LEN, ptr);
                while(char_arr[i] == ' ')
                {
                    i++;
                }
                main_call_function(char_arr);
            }
           printf("else if out \n");
        }

    }
}
/*************************************************************
 * Function Name    : ElseCheck                              *
 * AUTHOR           : Mohannad El Tabbakh.                   *
 * Function info    : it checks for if statement syntax error*
 * Function Input   : pointer to char (str_arr)              *
 * Function Ret_val : None.                                  *
 *************************************************************/
void ElseCheck(char *str)
{
	int elseflag = 0, ocbracket = 0, i = 0;

	if (ifflag == 0)
	{
		printf ("Else function without If in --> %s\n", str);
	}

	else if (ifflag == 1)
    {
        for(i = 0; i <= strlen(str); i++)
        {
            if(str[i]==' ')
            {
                continue;
            }
            else if (str [i] == 'e' && str [i + 1] == 'l' && str [i + 2] == 's' && str [i + 3] == 'e')
            {
                i += 3;
                elseflag = 1;
            }
            else if (elseflag == 1 && str [i] == '{')
            {
                ocbracket = 1;
            }
        }
    }

    if (elseflag == 0)
    {
        printf("Error in else keyword usage in --> %s\n", str);
    }

	ifflag = 0;

	if (ocbracket == 1)
	{
		while(str[i++] != '}')
            {
                i=0;
                fgets (char_arr, LINE_MAX_LEN, ptr);
                while(str[i] == ' ')
                {
                    i++;
                }
                main_call_function(char_arr);
            }
    }
}


/*************************************************************
 * Function Name    : switch_check                           *
 * AUTHOR           : Yassen Kamal.                          *
 * Function info    : it checks for switch-case syntax error *
 * Function Input   : pointer to char (str_arr)              *
 * Function Ret_val : None.                                  *
 *************************************************************/
void switchcheck(char* pstr){
	char flag=0 , curly = 0 , dotscheck = 0 , statement=0,value=0 , def=0, newline = 0, i = 0;

	update_line:
		if(flag!=0){
			fgets(pstr, LINE_MAX_LEN, ptr);
			newline+=1;
		}
	//Check syntax
	for(i=0;i<=strlen(pstr);i++){
		if(pstr[i]==' '){
			continue;
		}
		else if(pstr[i] == 's' && pstr[i+1]=='w' && pstr[i+2]=='i' && pstr[i+3]=='t' && pstr[i+4]=='c' && pstr[i+5]=='h'){
			flag+=1;
			i+=5;
		}
		else if(flag==1 && pstr[i]=='('){
			flag+=1;
		}
		else if(flag==2 && pstr[i]!=')' ){
			// Call a function to check availability of variable

		}
		else if(flag==2 && pstr[i]==')'){
			flag+=1;

		}
		else if(flag==3 && pstr[i]=='{' ){

			flag+=1;
			curly+=1;

		}
		else if(flag == 4 && pstr[i]=='c' && pstr[i+1]=='a' && pstr[i+2]=='s' && pstr[i+3]=='e' && pstr[i+4]==' '){
			value +=1;
			i+=4;

		}
		else if(flag == 4 && pstr[i]=='d' && pstr[i+1]=='e' && pstr[i+2]=='f' && pstr[i+3]=='a' && pstr[i+4]=='u' && pstr[i+5]=='l' && pstr[i+6]=='t'){
			if(def==1){
                goto Error;
			}
			dotscheck +=1;
			i+=6;
			def=1;
		}
		else if(flag == 4 && value == 1 && (pstr[i]>='0' && pstr[i]<='9')|(pstr[i]== 39 && pstr[i+2]== 39)){
			value -=1;
			dotscheck +=1;
		}
		else if(flag == 4 && dotscheck == 1 && pstr[i]==':'){
			dotscheck -=1;
			statement +=1;
		}
		else if(flag == 4 && statement == 1 && pstr[i]!='}'){
			////// Call other functions to check statements////
            fgets(pstr, LINE_MAX_LEN, ptr);
			main_call_function(pstr);
			statement -=1;
			goto update_line;
		}

        else if(flag == 4  && pstr[i]=='}' && curly==1 ){
            curly+=1;
                if(curly==2 && dotscheck==0 && value == 0 && statement == 0 ){
                    //switch syntax test passed
					flag+=1;
					return ;
                }
		}
	}

	if(curly!=2){
        if(newline==50){
            goto Error;
        }
		goto update_line;
	}

    Error:
	if(flag != 5){
		printf("Syntax Error: in switch statement\n");
	}
}

 /*************************************************************
 * Function Name    : main_check                              *
 * AUTHOR           : Mohannad El Tabbakh.                    *
 * Function info    : it checks for void main() function      *
 *                    syntax errors                           *
 * Function Input   : pointer to char (text)                  *
 * Function Ret_val : int mainflag                            *
 **************************************************************/
int MainCheck(char *text)
{
    int mainflag = 0, voidflag = 0, openbracket = 0, closingbracket = 0, ocbracket = 0;
    int i = 0;
    for(i = 0; i <= 50; i++)
    {
        if (text [i] == 'v' && text [i+1] == 'o' && text [i+2] == 'i' && text [i+3] == 'd')
        {
            i += 3;
            voidflag = 1;
        }
        else if (voidflag == 1 && text [i] == 'm' && text [i+1] == 'a' && text [i+2] == 'i' && text [i+3] == 'n')
        {
            i += 3;
            mainflag = 1;
        }
        else if (mainflag == 1 && text [i] == '(')
        {
            openbracket = 1;
        }
        else if (mainflag == 1 && text [i] == ')')
        {
            closingbracket = 1;
        }
        else if (closingbracket == 1 && text [i] == '{')
        {
            ocbracket = 1;
        }
    }

    if (voidflag == 0)
    {
        printf("Error in Void Keyword in --> %s\n", text);
    }
    else if (voidflag == 1 && mainflag == 0)
    {
        printf("Error in Main Keyword in --> %s\n", text);
    }
    else if (mainflag == 1 && openbracket == 0)
    {
        printf("Opening parenthesis absent after Main Keyword in --> %s\n", text);
    }
    else if (mainflag == 1 && closingbracket == 0)
    {
        printf("Closing parenthesis absent in --> %s\n", text);
    }
    else if (closingbracket == 1 && ocbracket == 0)
    {
        printf("Opening Curl Bracket absent in --> %s\n", text);
    }
    else if (ocbracket == 1)
    {
        while(char_arr[i++] != '}')
            {
                i=0;
                fgets (char_arr, LINE_MAX_LEN, ptr);
                while(char_arr[i] == ' ')
                {
                    i++;
                }
                main_call_function(char_arr);
            }
            //printf("main out \n");
    }

    return 0;
}
