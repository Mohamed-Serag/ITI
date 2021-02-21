/***********************************************************************************/
/*  File Name: RCC_inter.h                                                         */
/*  File Info: This File Contains functions prototypes of RCC module that          */
/*              will be used in the application.                                   */
/*  Version  : V1.0                                                                */
/*  Author   : Mohamed Serag                                                       */
/*  Date     : 29 Nov 2020                                                         */
/***********************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/******************************************************************/
/******************  Available BusID Choices **********************/
/******************************************************************/
#define     RCC_AHB                    1
#define     RCC_APB1                   3
#define     RCC_APB2                   5

/******************************************************************/
/**************  Available PeripheralID Choices *******************/
/******************************************************************/
/*    RCC_AHBENR Register bits              */
#define    DMA1_EN                     0
#define    DMA2_EN                     1
#define    SRAM_EN                     2
#define    FLITF_EN                    4
#define    CRCEN                       5
#define    OTGFS_EN                    12
#define    ETHMAC_EN                   14
#define    ETHMACTX_EN                 15
#define    ETHMACRX_EN                 16


/*    RCC_APB2ENR Register bits              */
#define    AFIO_EN                     0
#define    IOPA_EN                     2
#define    IOPB_EN                     3
#define    IOPC_EN                     4
#define    IOPD_EN                     5
#define    IOPE_EN                     6
#define    ADC1_EN                     9
#define    ADC2_EN                     10
#define    TIM1_EN                     11
#define    SPI1_EN                     12
#define    USART1_EN                   14


/*    RCC_APB1ENR Register bits              */
#define    TIM2_EN                     0
#define    TIM3_EN                     1
#define    TIM4_EN                     2
#define    TIM5_EN                     3
#define    TIM6_EN                     4
#define    TIM7_EN                     5
#define    WWDG_EN                     11
#define    SPI2_EN                     14
#define    SPI3_EN                     15
#define    USART2_EN                   17
#define    USART3_EN                   18
#define    USART4_EN                   19
#define    USART5_EN                   20
#define    I2C1_EN                     21
#define    I2C2_EN                     22
#define    CAN1_EN                     25
#define    CAN2_EN                     26
#define    BKP_EN                      27
#define    PWR_EN                      28
#define    DAC_EN                      29



/******************************************************************/
/******************** Functions Prototypes ************************/
/******************************************************************/

/****************************************************************************/
/*  Function Name   : MRCC_voidInit()                                       */
/*  Function Info   : This function initializes the system clock            */
/*  Function Inputs : None.                                                 */
/*  Function Ret_Val: None.                                                 */
/****************************************************************************/
extern void MRCC_voidInit(void);

/*************************************************************************/
/* Function Name    : RCC_voidEnablePeripheralClock()                    */
/* Function Info    : This function Enables the Peripheral Clock.        */
/* Fuction Input    : - u8 Copy_u8BusID : the Peripheral Bus.            */
/*                                        - RCC_AHB.                     */
/*                                        - RCC_APB1.                    */
/*                                        - RCC_APB2.                    */
/*                    - u8 Copy_u8PeripheralID : The Peripheral Bit in   */
/*                                               the following registers:*/
/*                                               - RCC_AHBENR.           */
/*                                               - RCC_APB2ENR.          */
/*                                               - RCC_APB1ENR.          */
/*                                                                       */
/* Function Ret_val : Local_u8Ret_Val.                                   */
/*************************************************************************/
extern Error_State_t MRCC_voidEnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/*************************************************************************/
/* Function Name    : RCC_voidDisablePeripheralClock()                   */
/* Function Info    : This function Disables the Peripheral Clock.       */
/* Fuction Input    : - u8 Copy_u8BusID : the Peripheral Bus.            */
/*                                        - RCC_AHB.                     */
/*                                        - RCC_APB1.                    */
/*                                        - RCC_APB2.                    */
/*                    - u8 Copy_u8PeripheralID : The Peripheral (Bit) in */
/*                                       one of the following registers: */
/*                                               - RCC_AHBENR.           */
/*                                               - RCC_APB2ENR.          */
/*                                               - RCC_APB1ENR.          */
/*                                                                       */
/* Function Ret_val : Local_u8Ret_Val.                                   */
/*************************************************************************/
extern Error_State_t MRCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

#endif /** the end of RCC_INTERFACE_H*/