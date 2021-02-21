/***********************************************************************************/
/*  File Name: RCC_cfg.h                                                           */
/*  File Info: This File Contains macros used for all RCC module configurations.   */
/*  Version  : V1.0                                                                */
/*  Author   : Mohamed Serag                                                       */
/*  Date     : 29 Nov 2020                                                         */
/***********************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/******************************************************************/
/* This configuration section selects the System Clock Source:    */
/* options:                                                       */
/*  1-  RCC_HSE_CRYSTAL                                           */
/*  2-  RCC_HSE_RC                                                */
/*  3-  RCC_HSI                                                   */
/*  4-  RCC_PLL                                                   */
/******************************************************************/
#define    RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


#if RCC_CLOCK_TYPE == RCC_PLL
    /*************************************************************/
    /* This configuration section selects the PLL Input Source:  */
    /* options:                                                  */
    /*  1-  RCC_PLL_HSE                                          */
    /*  2-  RCC_PLL_HSE_DIV_BY_2                                 */
    /*  3-  RCC_PLL_HSI_DIV_BY_2                                 */
	/*************************************************************/
    #define    RCC_PLL_INPUT    RCC_PLL_HSE

    #if RCC_PLL_INPUT == RCC_PLL_HSE
        /************************************************************/
        /* This configuration section selects the HSE Type:         */ 
        /* options:                                                 */
        /*  1- PLL_HSE_RC                                           */
        /*  2- PLL_HSE_CRYSTAL                                      */
        /************************************************************/
        #define    PLL_HSE_TYPE    PLL_HSE_RC		
			
    #elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_BY_2
        /************************************************************/
        /* This configuration section selects the HSE/2 Type:       */ 
        /* options:                                                 */
        /*  1- PLL_HSE_DIV_2_RC                                     */
        /*  2- PLL_HSE_DIV_2_CRYSTAL                                */
        /************************************************************/
        #define    PLL_HSE_DIV_BY_2_TYPE    PLL_HSE_DIV_2_RC
    #endif

    /****************************************************************/
    /* This configuration section selects the Multiplication value  */
    /* of PLL :                                                     */
    /* Note that :	it can only be from 4 to 16 MHZ, so your choice */
    /*	            must not exceed PLL_IN_CLK_MUL_9 in STM32F10x   */
    /* options :                                                    */
    /*            PLL_IN_CLK_MUL_2                                  */
    /*            PLL_IN_CLK_MUL_3                                  */
    /*            PLL_IN_CLK_MUL_4                                  */
    /*            PLL_IN_CLK_MUL_5                                  */
    /*            PLL_IN_CLK_MUL_6                                  */
    /*            PLL_IN_CLK_MUL_7                                  */
    /*            PLL_IN_CLK_MUL_8                                  */
    /*            PLL_IN_CLK_MUL_9                                  */
    /*            PLL_IN_CLK_MUL_10                                 */
    /*            PLL_IN_CLK_MUL_11                                 */
    /*            PLL_IN_CLK_MUL_12                                 */
    /*            PLL_IN_CLK_MUL_13                                 */
    /*            PLL_IN_CLK_MUL_14                                 */
    /*            PLL_IN_CLK_MUL_15                                 */
    /*            PLL_IN_CLK_MUL_16                                 */
    /*            PLL_IN_CLK_MUL_16_2                               */
    /****************************************************************/
    #define    RCC_PLL_MUL_VAL    PLL_IN_CLK_MUL_2	
#endif


/******************************************************************/
/* This configuration section selects the AHB Bus Clock :         */
/* options:                                                       */
/*  1-  SYSCLK_NOT_DIVIDED                                        */
/*  2-  SYSCLK_DIV_BY_2                                           */
/*  3-  SYSCLK_DIV_BY_4                                           */
/*  4-  SYSCLK_DIV_BY_8                                           */
/*  5-  SYSCLK_DIV_BY_16                                          */
/*  6-  SYSCLK_DIV_BY_64                                          */
/*  7-  SYSCLK_DIV_BY_128                                         */
/*  8-  SYSCLK_DIV_BY_256                                         */
/*  9-  SYSCLK_DIV_BY_512                                         */
/******************************************************************/
#define    AHB_CLOCK_SPEED    SYSCLK_NOT_DIVIDED			


/******************************************************************/
/* This configuration section selects the APB1 Bus Clock :        */
/* Note that: the clock speed can't exceed 36 MHZ.                */
/* options:                                                       */
/*  1-  HCLK_NOT_DIVIDED                                          */
/*  2-  HCLK_DIV_BY_2                                             */
/*  3-  HCLK_DIV_BY_4                                             */
/*  4-  HCLK_DIV_BY_8                                             */
/*  5-  HCLK_DIV_BY_16                                            */
/******************************************************************/
#define    APB1_CLOCK_SPEED    HCLK_NOT_DIVIDED


/******************************************************************/
/* This configuration section selects the APB2 Bus Clock :        */
/* options:                                                       */
/*  1-  HCLK_NOT_DIVIDED                                          */
/*  2-  HCLK_DIV_BY_2                                             */
/*  3-  HCLK_DIV_BY_4                                             */
/*  4-  HCLK_DIV_BY_8                                             */
/*  5-  HCLK_DIV_BY_16                                            */
/******************************************************************/
#define    APB2_CLOCK_SPEED    HCLK_NOT_DIVIDED

	
#endif /** the end of RCC_CONFIG_H*/