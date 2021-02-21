/********************************************************************************/
/*  File Name: Error_State.h                                                    */
/*  File Info: This File Contains the Error Status Enumeration used as a return */
/*             type of modules APIs.                                            */
/*  Version  : V1.0                                                             */
/*  Author   : Mohamed Serag                                                    */
/*  Date     : 5 Oct 2019                                                       */
/********************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef ERROR_STATE_H
#define ERROR_STATE_H

typedef enum{
    RET_NOK          ,
    RET_OK           ,
    RET_OUT_OF_RANGE ,
    RET_NULL_POINTER
}Error_State_t;


#endif /** the end of ERROR_STATE_H*/
