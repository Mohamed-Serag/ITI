/*****************************************************************************************************
 * File Name                       : compiler.h                                                      *
 * File info                       :this file contains the functions prototypes of syntax error      *
 *                                   compiler .                                                      *
 * Version                         : 1.0 V (Trial).                                                  *
 * File creation and documentation : - Mohamed Serag.                                                *
 * Participant developers          : - Yassen Kamal. - Mohannad El-Tabbakh. - Mohamed Serag.         *
 * Date                            : 17 Oct. 2020                                                    *
 *****************************************************************************************************/
#ifndef _COMPILER_H
#define _COMPILER_H

#include "main.h"
extern int ifflag ;

#define LINE_MAX_LEN 100

/**************** Functions Prototypes ****************/
void main_call_function(char *str_arr);
void int_check(char *str_arr);
void Float_Check(char* pstr);
void do_while_check(char *str_arr);
void forcheck(char* pstr);
int MainCheck(char *str);
void If_Check(char *str);
void ElseIfCheck(char *str);
void ElseCheck(char *str);
void WhileCheck(char *str);
void CharCheck(char *str);
void switchcheck(char* pstr);

#endif // _COMPILER_H
