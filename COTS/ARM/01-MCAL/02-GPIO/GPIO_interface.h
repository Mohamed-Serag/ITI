/*************************************************************************/
/* File Name : GPIO_interface.h                                          */
/* File info : This file contains all functions concerning GPIO that     */
/*             will be used by the user.                                 */
/* Date      : 30 Nov 2020                                               */
/* Version   : V1.0                                                      */
/* Author    : Mohamed Serag.                                            */
/*************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*        GPIO Ports Sides        */
#define    GPIO_U8_PORT_LOW     0
#define    GPIO_U8_PORT_HIGH    1
#define    GPIO_U8_ALL_PORT     2

/*        GPIO Pins values        */
#define    GPIO_U8_LOW          0
#define    GPIO_U8_HIGH         1

/*        GPIO Ports              */
#define    GPIO_U8_PORTA        0
#define    GPIO_U8_PORTB        1
#define    GPIO_U8_PORTC        2

/*        GPIO Pins               */
#define    GPIO_U8_PIN0         0
#define    GPIO_U8_PIN1         1
#define    GPIO_U8_PIN2         2
#define    GPIO_U8_PIN3         3                              
#define    GPIO_U8_PIN4         4
#define    GPIO_U8_PIN5         5
#define    GPIO_U8_PIN6         6
#define    GPIO_U8_PIN7         7                               
#define    GPIO_U8_PIN8         8
#define    GPIO_U8_PIN9         9
#define    GPIO_U8_PIN10        10
#define    GPIO_U8_PIN11        11                              
#define    GPIO_U8_PIN12        12
#define    GPIO_U8_PIN13        13
#define    GPIO_U8_PIN14        14
#define    GPIO_U8_PIN15        15

/*      GPIO Input Modes           */
#define    GPIO_U8_INPUT_ANALOG                         (0b0000)
#define    GPIO_U8_INPUT_FLOATING                       (0b0100)
#define    GPIO_U8_INPUT_PULL_UP_DOWN                   (0b1000)

/*    GPIO Output 10MHZ Modes      */
#define    GPIO_U8_OUTPUT_10MHZ_PUSH_PULL               (0b0001)
#define    GPIO_U8_OUTPUT_10MHZ_OPEN_DRAIN              (0b0101)
#define    GPIO_U8_OUTPUT_10MHZ_AF_PUSH_PULL            (0b1001)
#define    GPIO_U8_OUTPUT_10MHZ_AF_OPEN_DRAIN           (0b1101)

/*    GPIO Output 2MHZ Modes       */
#define    GPIO_U8_OUTPUT_2MHZ_PUSH_PULL                (0b0010)
#define    GPIO_U8_OUTPUT_2MHZ_OPEN_DRAIN               (0b0110)
#define    GPIO_U8_OUTPUT_2MHZ_AF_PUSH_PULL             (0b1010)
#define    GPIO_U8_OUTPUT_2MHZ_AF_OPEN_DRAIN            (0b1110)

/*    GPIO Outout 50MHZ Modes      */
#define    GPIO_U8_OUTPUT_50MHZ_PUSH_PULL               (0b0011)
#define    GPIO_U8_OUTPUT_50MHZ_OPEN_DRAIN              (0b0111)
#define    GPIO_U8_OUTPUT_50MHZ_AF_PUSH_PULL            (0b1011)
#define    GPIO_U8_OUTPUT_50MHZ_AF_OPEN_DRAIN           (0b1111)


/******************************************************************/
/********************* Functions Prototypes ***********************/
/******************************************************************/

/********************************************************************************/
/* Function Name : MGPIO_voidSetPinDirection()                                  */
/* Function Info : This function sets the direction of the pin including        */
/*                 pin mode.                                                    */
/* Function Input: This function takes the following Parameters:                */
/*                 - Copy_u8PortID     : The targeted port, and the available   */
/*                                       choices are:                           */
/*                                       -> GPIO_U8_PORTA                       */
/*                                       -> GPIO_U8_PORTB                       */
/*                                       -> GPIO_U8_PORTC                       */
/*                                                                              */
/*                 - Copy_u8PinID      : The targeted pin, and the available    */
/*                                       choices are:                           */
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
/*                 - Copy_u8DirectionID : The required direction, and available */
/*                                        choices are:                          */
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
Error_State_t MGPIO_enuSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8DirectionID);


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
Error_State_t MGPIO_enuSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);


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
Error_State_t MGPIO_enuGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Copy_u8Ret_val);


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
Error_State_t MGPIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortSide, u8 Copy_u8DirectionID);


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
Error_State_t MGPIO_enuSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value);


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
Error_State_t MGPIO_enuSetPortValues(u8 Copy_u8PortID, u8 Copy_u8WordSide, u16 Copy_u8Value);



#endif /** the end of GPIO_INTERFACE_H_*/
