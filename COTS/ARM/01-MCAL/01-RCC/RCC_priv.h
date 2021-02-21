/********************************************************************************/
/* File Name: RCC_priv.h                                                        */
/* File Info: This File Contains RCC memory registers address and other macros  */
/*            used for building the RCC module.                                 */
/* Version  : V1.0                                                              */
/* Author   : Mohamed Serag                                                     */
/* Date     : 29 Nov 2020                                                       */
/********************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*    RCC Memory Registers Addresses          */
#define    RCC_BASE_ADDRESS            (0x40021000)

#define    RCC_CR                      *((volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
#define    RCC_CFGR                    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x04))
#define    RCC_CIR                     *((volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
#define    RCC_APB2RSTR                *((volatile u32 *)(RCC_BASE_ADDRESS + 0x0C))
#define    RCC_APB1RSTR                *((volatile u32 *)(RCC_BASE_ADDRESS + 0x10))
#define    RCC_AHBENR                  *((volatile u32 *)(RCC_BASE_ADDRESS + 0x14))
#define    RCC_APB2ENR                 *((volatile u32 *)(RCC_BASE_ADDRESS + 0x18))
#define    RCC_APB1ENR                 *((volatile u32 *)(RCC_BASE_ADDRESS + 0x1C))
#define    RCC_BDCR                    *((volatile u32 *)(RCC_BASE_ADDRESS + 0x20))
#define    RCC_CSR                     *((volatile u32 *)(RCC_BASE_ADDRESS + 0x24))


/*    Clock Selections                        */
#define    RCC_HSE_CRYSTAL             1
#define    RCC_HSE_RC                  3
#define    RCC_HSI                     5
#define    RCC_PLL                     7


/*    PLL Options                             */
#define    RCC_PLL_HSE                 1
#define    RCC_PLL_HSE_DIV_BY_2        3
#define    RCC_PLL_HSI_DIV_BY_2        5



/*    PLL Multiplication Options              */
#define    PLL_IN_CLK_MUL_2            0
#define    PLL_IN_CLK_MUL_3            2
#define    PLL_IN_CLK_MUL_4            4
#define    PLL_IN_CLK_MUL_5            6
#define    PLL_IN_CLK_MUL_6            8
#define    PLL_IN_CLK_MUL_7            10
#define    PLL_IN_CLK_MUL_8            12
#define    PLL_IN_CLK_MUL_9            14
/**********************************************/
/**!Comment: The following values from       **/
/** PLL_IN_CLK_MUL_10 to PLL_IN_CLK_MUL_16_2 **/
/** are not used in STM32F10x family of MCUs **/
/**********************************************/
#define    PLL_IN_CLK_MUL_10           16
#define    PLL_IN_CLK_MUL_11           18
#define    PLL_IN_CLK_MUL_12           20
#define    PLL_IN_CLK_MUL_13           22
#define    PLL_IN_CLK_MUL_14           24
#define    PLL_IN_CLK_MUL_15           26
#define    PLL_IN_CLK_MUL_16           28
#define    PLL_IN_CLK_MUL_16_2         30

 
/*    AHB Bus Clock Options                   */ 
#define    SYSCLK_NOT_DIVIDED          0
#define    SYSCLK_DIV_BY_2             2
#define    SYSCLK_DIV_BY_4             4
#define    SYSCLK_DIV_BY_8             6
#define    SYSCLK_DIV_BY_16            8
#define    SYSCLK_DIV_BY_64            10
#define    SYSCLK_DIV_BY_128           12
#define    SYSCLK_DIV_BY_256           14
#define    SYSCLK_DIV_BY_512           16


/*    APB1 and APB2 Buses Clock Options       */ 
#define    HCLK_NOT_DIVIDED            0
#define    HCLK_DIV_BY_2               2
#define    HCLK_DIV_BY_4               4
#define    HCLK_DIV_BY_8               6
#define    HCLK_DIV_BY_16              8

/*    RCC_CR Register Bits                    */
#define    HSION                       0
#define    HSIRDY                      1
#define    HSITRIM0                    3
#define    HSITRIM1                    4
#define    HSITRIM2                    5
#define    HSITRIM3                    6
#define    HSITRIM4                    7
#define    HSICAL0                     8
#define    HSICAL1                     9
#define    HSICAL2                     10
#define    HSICAL3                     11
#define    HSICAL4                     12
#define    HSICAL5                     13
#define    HSICAL6                     14
#define    HSICAL7                     15
#define    HSEON                       16
#define    HSERDY                      17
#define    HSEBYP                      18
#define    CSSON                       19
#define    PLLON                       24
#define    PLLRDY                      25
#define    PLL2ON                      26
#define    PLL2RDY                     27
#define    PLL3ON                      28
#define    PLL3RDY                     29


/*    RCC_CFGR Register Bits                  */
#define    SW0                         0
#define    SW1                         1
#define    SWS0                        2
#define    SWS1                        3
#define    HPRE0                       4
#define    HPRE1                       5
#define    HPRE2                       6
#define    HPRE3                       7
#define    PPRE1_0                     8
#define    PPRE1_1                     9
#define    PPRE1_2                     10
#define    PPRE2_0                     11
#define    PPRE2_1                     12
#define    PPRE2_2                     13
#define    ADC_PRE0                    14
#define    ADC_PRE1                    15
#define    PLL_SRC                     16
#define    PLL_XTPRE                   17
#define    PLLMUL0                     18
#define    PLLMUL1                     19
#define    PLLMUL2                     20
#define    PLLMUL3                     21
#define    OTGFS_PRE                   22
#define    MCO0                        24
#define    MCO1                        25
#define    MCO2                        26
#define    MCO3                        27


/*    RCC_CIR Register bits                   */
#define    LSI_RDYIF                   0
#define    LSE_RDYF                    1
#define    HSI_RDYF                    2
#define    HSE_RDYF                    3
#define    PLL_RDYF                    4
#define    PLL2_RDYF                   5
#define    PLL3_RDYF                   6
#define    CSSF                        7
#define    LSI_RDYIE                   8
#define    LSE_RDYIE                   9
#define    HSI_RDYIE                   10
#define    HSE_RDYIE                   11
#define    PLL_RDYIE                   12
#define    PLL2_RDYIE                  13
#define    PLL3_RDYIE                  14
#define    LSI_RDYC                    16
#define    LSE_RDYC                    17
#define    HSI_RDYC                    18
#define    HSE_RDYC                    19
#define    PLL_RDYC                    20
#define    PLL2_RDYC                   21
#define    PLL3_RDYC                   22
#define    CSSC                        23


/*    RCC_APB2RSTR Register bits              */
#define    AFIO_RST                    0
#define    IOPA_RST                    2
#define    IOPB_RST                    3
#define    IOPC_RST                    4
#define    IOPD_RST                    5
#define    IOPE_RST                    6
#define    ADC1_RST                    9
#define    ADC2_RST                    10
#define    TIM1_RST                    11
#define    SPI1_RST                    12
#define    USART1_RST                  14


/*    RCC_APB1RSTR Register bits              */
#define    TIM2_RST                    0
#define    TIM3_RST                    1
#define    TIM4_RST                    2
#define    TIM5_RST                    3
#define    TIM6_RST                    4
#define    TIM7_RST                    5
#define    WWDG_RST                    11
#define    SPI2_RST                    14
#define    SPI3_RST                    15
#define    USART2_RST                  17
#define    USART3_RST                  18
#define    USART4_RST                  19
#define    USART5_RST                  20
#define    I2C1_RST                    21
#define    I2C2_RST                    22
#define    CAN1_RST                    25
#define    CAN2_RST                    26
#define    BKP_RST                     27
#define    PWR_RST                     28
#define    DAC_RST                     29


/*    RCC_BDCR Register bits                 */
#define    LSEON                       0
#define    RDY_LSE                     1
#define    LSE_BYP                     2
#define    RTCSEL0                     8
#define    RTCSEL1                     9
#define    RTC_EN                      15
#define    BD_RST                      16


/*    RCC_CSR Register bits                  */
#define    LSION                       0
#define    LSI_RDY                     1
#define    RMVF                        24
#define    PIN_RSTF                    26
#define    POR_RSTF                    27
#define    SFT_RSTF                    28
#define    IWDG_RSTF                   29
#define    WWDG_RSTF                   30
#define    LPWR_RSTF                   31


/*    RCC_AHBRSTR Register bits              */
#define    OTGFS_RST                   12
#define    ETHMAC_RST                  14


/*    RCC_CFGR2 Register bits                */
#define    PREDIV1_0                   0
#define    PREDIV1_1                   1
#define    PREDIV1_2                   2
#define    PREDIV1_3                   3
#define    PREDIV2_0                   4
#define    PREDIV2_1                   5
#define    PREDIV2_2                   6
#define    PREDIV2_3                   7
#define    PLL2MUL_0                   8
#define    PLL2MUL_1                   9
#define    PLL2MUL_2                   10
#define    PLL2MUL_3                   11
#define    PLL3MUL_0                   12
#define    PLL3MUL_1                   13
#define    PLL3MUL_2                   14
#define    PLL3MUL_3                   15
#define    PREDIV1_SRC                 16
#define    I2S2_SRC                    17
#define    I2S3_SRC                    18

#endif /** the end of RCC_PRIVATE_H*/