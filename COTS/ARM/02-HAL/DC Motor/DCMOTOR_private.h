/***************************************************************************/
/*  File Name: DCMOTOR_private.h                                           */
/*  File Info: This file contains macros and user-defined data types used  */
/*             to develop the DC motor driver.                             */
/*  Version  : V1.0                                                        */
/*  Author   : Mohamed Serag                                               */
/*  Date     : 7 Dec 2020                                                  */
/***************************************************************************/
/***********************************************************************/
/*** File Guard to Prevent this Header File from Multiple inclusions ***/
/***********************************************************************/
#ifndef DCMOTOR_PRIVATE_H
#define DCMOTOR_PRIVATE_H

/***********************************************************************/
/********** DC Motor Movement Directions Macros Definitions ************/
/***********************************************************************/
#define    LEFT_MOVEMENT     1
#define    RIGHT_MOVEMENT    2
#define    STOP_MOVEMENT     0


/***********************************************************************/
/********************** User-Defined Data Types ************************/
/***********************************************************************/
typedef struct{
	u8 DCMOTOR_u8RightMotorPin;
	u8 DCMOTOR_u8RightMotorPort;
	
	u8 DCMOTOR_u8LeftMotorPin ;
	u8 DCMOTOR_u8LeftMotorPort ;
}DcMotor;


/***********************************************************************/
/************************ Declaration Section **************************/
/***********************************************************************/
extern DcMotor ArrayOfMotors[NUMBER_OF_MOTORS];


#endif /*the end of DCMOTOR_PRIVATE_H*/