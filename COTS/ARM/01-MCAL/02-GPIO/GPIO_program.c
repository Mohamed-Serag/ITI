/***********************************************************************************/
/* File Name : GPIO_Program.c                                                      */
/* File info : This file contains all functions implementations concerning         */
/*             GPIO module.                                                        */
/* Date      : 30 Nov 2020                                                         */
/* Version   : V1.0                                                                */
/* Author    : Mohamed Serag.                                                      */
/***********************************************************************************/
#include "Std_Types.h"
#include "Error_State.h"
#include "Bit_Math.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"




/********************************************************************************/
/* Function Name : MGPIO_voidSetPinDirection()                                  */
/* Function Info : This function sets the direction of the pin including        */
/*                 pin mode.                                                    */
/* Function Input: This function takes the following Parameters:                */
/*                 - Copy_u8PortID     : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                 - Copy_u8PinID      : The available choices are:             */
/*                                       -> GPIO_U8_PIN0     -> GPIO_U8_PIN1    */
/*                                       -> GPIO_U8_PIN2     -> GPIO_U8_PIN3    */
/*                                       -> GPIO_U8_PIN4     -> GPIO_U8_PIN5    */
/*                                       -> GPIO_U8_PIN6     -> GPIO_U8_PIN7    */
/*                                       -> GPIO_U8_PIN8     -> GPIO_U8_PIN9    */
/*                                       -> GPIO_U8_PIN10    -> GPIO_U8_PIN11   */
/*                                       -> GPIO_U8_PIN12    -> GPIO_U8_PIN13   */
/*                                       -> GPIO_U8_PIN14    -> GPIO_U8_PIN15   */
/*                          >> Note That: if your choice is GPIO_U8_PORTC, then */
/*                                        The available choices are (ONLY):     */
/*                                       -> GPIO_U8_PIN13                       */
/*                                       -> GPIO_U8_PIN14                       */
/*                                       -> GPIO_U8_PIN15                       */
/*                                                                              */
/*                 - Copy_u8DirectionID : The available choices are:            */
/*                                       -> GPIO_U8_INPUT_ANALOG                */
/*                                       -> GPIO_U8_INPUT_FLOATING              */
/*                                       -> GPIO_U8_INPUT_PULL_UP_DOWN          */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_PUSH_PULL      */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_OPEN_DRAIN     */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_AF_PUSH_PULL   */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_AF_OPEN_DRAIN  */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_PUSH_PULL       */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_OPEN_DRAIN      */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_AF_PUSH_PULL    */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_AF_OPEN_DRAIN   */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_PUSH_PULL      */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_OPEN_DRAIN     */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_AF_PUSH_PULL   */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_AF_OPEN_DRAIN  */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8DirectionID)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	/*			Range Check				*/
	if(Copy_u8PortID < PORT_MAX && Copy_u8PinID <PIN_MAX){
		switch(Copy_u8PortID)
		{
		case GPIO_U8_PORTA:
			if(Copy_u8PinID<8)
			{
				/* Clear the 4 bits position */
				GPIOA_CRL &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOA_CRL |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			else if(Copy_u8PinID<16)
			{
				Copy_u8PinID -= 8;
				/* Clear the 4 bits position */
				GPIOA_CRH &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOA_CRH |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			break;

		case GPIO_U8_PORTB:
			if(Copy_u8PinID<8)
			{
				/* Clear the 4 bits position */
				GPIOB_CRL &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOB_CRL |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			else if(Copy_u8PinID<16)
			{
				Copy_u8PinID -= 8;
				/* Clear the 4 bits position */
				GPIOB_CRH &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOB_CRH |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			break;

		case GPIO_U8_PORTC:
			if(Copy_u8PinID<8)
			{
				/* Clear the 4 bits position */
				GPIOC_CRL &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOC_CRL |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			else if(Copy_u8PinID<16)
			{
				Copy_u8PinID -= 8;
				/* Clear the 4 bits position */
				GPIOC_CRH &= ~(((u32)0b1111) << (Copy_u8PinID*4));
				/* Set the 4 bits with the required direction */
				GPIOC_CRH |= (((u32)Copy_u8DirectionID) << (Copy_u8PinID*4));
			}
			break;
		}
	}
	else
	{
		Local_u8Ret_State = RET_NOK;
	}
	return Local_u8Ret_State;
}



/********************************************************************************/
/* Function Name : MGPIO_voidSetPinValue()                                      */
/* Function Info : This function sets the Value of the pin.                     */
/* Function Input: This function takes the following Parameters:                */
/*                     - Copy_u8PortID : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                     - Copy_u8PinID  : The available choices are:             */
/*                                       -> GPIO_U8_PIN0     -> GPIO_U8_PIN1    */
/*                                       -> GPIO_U8_PIN2     -> GPIO_U8_PIN3    */
/*                                       -> GPIO_U8_PIN4     -> GPIO_U8_PIN5    */
/*                                       -> GPIO_U8_PIN6     -> GPIO_U8_PIN7    */
/*                                       -> GPIO_U8_PIN8     -> GPIO_U8_PIN9    */
/*                                       -> GPIO_U8_PIN10    -> GPIO_U8_PIN11   */
/*                                       -> GPIO_U8_PIN12    -> GPIO_U8_PIN13   */
/*                                       -> GPIO_U8_PIN14    -> GPIO_U8_PIN15   */
/*                          >> Note That: if your choice is GPIO_U8_PORTC, then */
/*                                        The available choices are (ONLY):     */
/*                                       -> GPIO_U8_PIN13                       */
/*                                       -> GPIO_U8_PIN14                       */
/*                                       -> GPIO_U8_PIN15                       */
/*                                                                              */
/*                     - Copy_u8Value   : The available choices are:            */
/*                                       -> GPIO_U8_HIGH                        */
/*                                       -> GPIO_U8_LOW                         */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	/*			Range Check				*/
	if(Copy_u8PortID < PORT_MAX && Copy_u8PinID <PIN_MAX){
		switch(Copy_u8PortID)
		{
		case GPIO_U8_PORTA:
			if(Copy_u8Value == GPIO_U8_HIGH)
			{
				SET_BIT(GPIOA_BSRR, Copy_u8PinID);
			}
			else if (Copy_u8Value == GPIO_U8_LOW)
			{
				SET_BIT(GPIOA_BRR, Copy_u8PinID);
			}
			else
			{
				Local_u8Ret_State = RET_NOK;
			}
			break;

		case GPIO_U8_PORTB:
			if(Copy_u8Value == GPIO_U8_HIGH)
			{
				SET_BIT(GPIOB_BSRR, Copy_u8PinID);
			}
			else if (Copy_u8Value == GPIO_U8_LOW)
			{
				SET_BIT(GPIOB_BRR, Copy_u8PinID);
			}
			else
			{
				Local_u8Ret_State = RET_NOK;
			}
			break;

		case GPIO_U8_PORTC:
			if(Copy_u8Value == GPIO_U8_HIGH)
			{
				SET_BIT(GPIOC_BSRR, Copy_u8PinID);
			}
			else if (Copy_u8Value == GPIO_U8_LOW)
			{
				SET_BIT(GPIOC_BRR, Copy_u8PinID);
			}
			else
			{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		}
	}
	else
	{
		Local_u8Ret_State = RET_NOK;
	}
	return Local_u8Ret_State ;
}



/********************************************************************************/
/* Function Name : MGPIO_voidGetPinValue()                                      */
/* Function Info : This function Gets the value of the pin.                     */
/* Function Input: This function takes the following Parameters:                */
/*                     - Copy_u8PortID : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                     - Copy_u8PinID  : The available choices are:             */
/*                                       -> GPIO_U8_PIN0     -> GPIO_U8_PIN1    */
/*                                       -> GPIO_U8_PIN2     -> GPIO_U8_PIN3    */
/*                                       -> GPIO_U8_PIN4     -> GPIO_U8_PIN5    */
/*                                       -> GPIO_U8_PIN6     -> GPIO_U8_PIN7    */
/*                                       -> GPIO_U8_PIN8     -> GPIO_U8_PIN9    */
/*                                       -> GPIO_U8_PIN10    -> GPIO_U8_PIN11   */
/*                                       -> GPIO_U8_PIN12    -> GPIO_U8_PIN13   */
/*                                       -> GPIO_U8_PIN14    -> GPIO_U8_PIN15   */
/*                          >> Note That: if your choice is GPIO_U8_PORTC, then */
/*                                        The available choices are (ONLY):     */
/*                                       -> GPIO_U8_PIN13                       */
/*                                       -> GPIO_U8_PIN14                       */
/*                                       -> GPIO_U8_PIN15                       */
/*                                                                              */
/*                     -*Copy_u8Ret_val : this is a pointer to return the value */
/*                                        of the pin through it.                */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_u8Ret_val)
{
	Error_State_t Local_u8Ret_State = RET_OK;

	/*			Range Check				*/
	if(Copy_u8PortID < PORT_MAX && Copy_u8PinID <PIN_MAX){
		switch(Copy_u8PortID)
		{
		case GPIO_U8_PORTA:  *Copy_u8Ret_val = GET_BIT(GPIOA_IDR, Copy_u8PinID); break;
		case GPIO_U8_PORTB:  *Copy_u8Ret_val = GET_BIT(GPIOB_IDR, Copy_u8PinID); break;
		case GPIO_U8_PORTC:  *Copy_u8Ret_val = GET_BIT(GPIOC_IDR, Copy_u8PinID); break;
		}
	}       
	else
	{
		Local_u8Ret_State = RET_NOK;
	}
	return Local_u8Ret_State;
}



/********************************************************************************/
/* Function Name : MGPIO_enuSetPortDirection()                                  */
/* Function Info : This function sets the direction of the port.                */
/* Function Input: This function takes the following Parameters:                */
/*                     - Copy_u8PortID : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                     - Copy_u8PortSide : The available choices are:           */
/*                                       -> GPIO_U8_PORT_LOW                    */
/*                                       -> GPIO_U8_PORT_HIGH                   */
/*                                       -> GPIO_U8_ALL_PORT                    */
/*                          >> Note That: if your choice is GPIO_U8_PORTC, then */
/*                                        The available choices are (ONLY):     */
/*                                       -> GPIO_U8_PORT_HIGH                   */
/*                                       -> GPIO_U8_ALL_PORT                    */
/*                                                                              */
/*                 - Copy_u8DirectionID : The available choices are:            */
/*                                       -> GPIO_U8_INPUT_ANALOG                */
/*                                       -> GPIO_U8_INPUT_FLOATING              */
/*                                       -> GPIO_U8_INPUT_PULL_UP_DOWN          */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_PUSH_PULL      */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_OPEN_DRAIN     */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_AF_PUSH_PULL   */
/*                                       -> GPIO_U8_OUTPUT_10MHZ_AF_OPEN_DRAIN  */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_PUSH_PULL       */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_OPEN_DRAIN      */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_AF_PUSH_PULL    */
/*                                       -> GPIO_U8_OUTPUT_2MHZ_AF_OPEN_DRAIN   */
/*                                                                              */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_PUSH_PULL      */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_OPEN_DRAIN     */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_AF_PUSH_PULL   */
/*                                       -> GPIO_U8_OUTPUT_50MHZ_AF_OPEN_DRAIN  */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortSide, u8 Copy_u8DirectionID)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	/*            Port Range Check            */
	if(Copy_u8PortID < PORT_MAX)
	{
		switch(Copy_u8PortID)
		{
		case GPIO_U8_PORTA:
			if(Copy_u8PortSide == GPIO_U8_PORT_LOW){
				GPIOA_CRL = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_PORT_HIGH){
				GPIOA_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_ALL_PORT){
				GPIOA_CRL = (0x11111111 * Copy_u8DirectionID);
				GPIOA_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		case GPIO_U8_PORTB:
			if(Copy_u8PortSide == GPIO_U8_PORT_LOW){
				GPIOB_CRL = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_PORT_HIGH){
				GPIOB_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_ALL_PORT){
				GPIOB_CRL = (0x11111111 * Copy_u8DirectionID);
				GPIOB_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		case GPIO_U8_PORTC:
			if(Copy_u8PortSide == GPIO_U8_PORT_LOW){
				GPIOC_CRL = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_PORT_HIGH){
				GPIOC_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else if(Copy_u8PortSide == GPIO_U8_ALL_PORT){
				GPIOC_CRL = (0x11111111 * Copy_u8DirectionID);
				GPIOC_CRH = (0x11111111 * Copy_u8DirectionID);
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		}
	}
	else{
		Local_u8Ret_State =RET_NOK;
	}
	return Local_u8Ret_State;
}



/********************************************************************************/
/* Function Name : MGPIO_enuSetPortValue()                                      */
/* Function Info : This function sets all values of the port.                   */
/* Function Input: This function takes the following Parameters:                */
/*                     - Copy_u8PortID : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                    - Copy_u8Value : The available choices are:               */
/*                                     -> GPIO_U8_HIGH                          */
/*                                     -> GPIO_U8_LOW                           */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	/*            Range Check            */
	if(Copy_u8PortID < PORT_MAX){
		switch(Copy_u8PortID)
		{
		case GPIO_U8_PORTA:
			if(Copy_u8Value == GPIO_U8_HIGH){
				GPIOA_BSRR = 0x0000FFFF;
			}
			else if(Copy_u8Value == GPIO_U8_LOW){
				GPIOA_BRR = 0x0000FFFF;
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		case GPIO_U8_PORTB:
			if(Copy_u8Value == GPIO_U8_HIGH){
				GPIOB_BSRR = 0x0000FFFF;
			}
			else if(Copy_u8Value == GPIO_U8_LOW){
				GPIOB_BRR = 0x0000FFFF;
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		case GPIO_U8_PORTC:
			if(Copy_u8Value == GPIO_U8_HIGH){
				GPIOC_BSRR = 0x0000FFFF;
			}
			else if(Copy_u8Value == GPIO_U8_LOW){
				GPIOC_BRR = 0x0000FFFF;
			}
			else{
				Local_u8Ret_State = RET_NOK;
			}
			break;
		}
	}
	else{
		Local_u8Ret_State = RET_NOK;
	}
	return Local_u8Ret_State;
}


/********************************************************************************/
/* Function Name : MGPIO_enuSetPortValues()                                     */
/* Function Info : This function sets the values of the port (High word - Low   */
/*                 word - All port).                                            */
/* Function Input: This function takes the following Parameters:                */
/*                     - Copy_u8PortID : The available choices are:             */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                     - Copy_u8WordSide : The available choices are:           */
/*                                       -> GPIO_U8_PORT_LOW                    */
/*                                       -> GPIO_U8_PORT_HIGH                   */
/*                                       -> GPIO_U8_ALL_PORT                    */
/*                                                                              */
/*                    - Copy_u8Value : The available choices are:               */
/*                                     -> GPIO_U8_HIGH                          */
/*                                     -> GPIO_U8_LOW                           */
/* Function Ret_val : Local_u8Ret_State                                         */
/********************************************************************************/
Error_State_t MGPIO_enuSetPortValues(u8 Copy_u8PortID, u8 Copy_u8WordSide, u16 Copy_u8Value)
{
	Error_State_t Local_u8Ret_State = RET_OK;
	if(Copy_u8PortID < 3){
		switch(Copy_u8PortID){
		case GPIO_U8_PORTA:
			if(Copy_u8WordSide == GPIO_U8_PORT_LOW){
				GPIOA_ODR &= 0x00000000;
				GPIOA_BSRR = Copy_u8Value;
			}
			else if(Copy_u8WordSide == GPIO_U8_PORT_HIGH){
				GPIOA_ODR &= 0x00000000;
				GPIOA_BSRR = (Copy_u8Value << 8);
			}
			else if (Copy_u8WordSide == GPIO_U8_ALL_PORT){
				GPIOA_ODR &= 0x00000000;
				GPIOA_BSRR = Copy_u8Value;
			}
			else{}
			break;
		case GPIO_U8_PORTB:
			if(Copy_u8WordSide == GPIO_U8_PORT_LOW){
				GPIOB_ODR &= 0x00000000;
				GPIOB_BSRR = Copy_u8Value;
			}
			else if(Copy_u8WordSide == GPIO_U8_PORT_HIGH){
				GPIOB_ODR &= 0x00000000;
				GPIOB_BSRR = (Copy_u8Value << 8);
			}
			else if (Copy_u8WordSide == GPIO_U8_ALL_PORT){
				GPIOB_ODR &= 0x00000000;
				GPIOB_BSRR = Copy_u8Value;
			}
			else{}
			break;
		case GPIO_U8_PORTC:
			if(Copy_u8WordSide == GPIO_U8_PORT_LOW){
				GPIOC_ODR &= 0x00000000;
				GPIOC_BSRR = Copy_u8Value;
			}
			else if(Copy_u8WordSide == GPIO_U8_PORT_HIGH){
				GPIOC_ODR &= 0x00000000;
				GPIOC_BSRR = (Copy_u8Value << 8);
			}
			else if (Copy_u8WordSide == GPIO_U8_ALL_PORT){
				GPIOC_ODR &= 0x00000000;
				GPIOC_BSRR = Copy_u8Value;
			}
			else{};
			break;
		}
	}
	else{
		Local_u8Ret_State = RET_NOK;
	}
	return Local_u8Ret_State;
}
