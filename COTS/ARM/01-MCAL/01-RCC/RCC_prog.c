/***********************************************************************************/
/*  File Name: RCC_prog.c                                                          */
/*  File Info: This File Contains functions (APIs) implementations of RCC module.  */
/*  Version  : V1.0                                                                */
/*  Author   : Mohamed Serag                                                       */
/*  Date     : 29 Nov 2020                                                         */
/***********************************************************************************/
/***************************************************************************/
/***************************  Linking Section ******************************/
/***************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Error_State.h"

#include "RCC_inter.h"
#include "RCC_priv.h"
#include "RCC_cfg.h"


/****************************************************************************/
/************************ Functions Implementations *************************/
/****************************************************************************/

/****************************************************************************/
/*  Function Name   : MRCC_voidInit()                                       */
/*  Function Info   : This function initializes the system clock            */
/*  Function Inputs : None.                                                 */
/*  Function Ret_Val: None.                                                 */
/****************************************************************************/
void MRCC_voidInit(void)
{
	/*        HSE Crystal Configuration        */
	#if	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CFGR, SW0);
		CLR_BIT(RCC_CFGR, SW1);
		SET_BIT(RCC_CR, HSEON);
		CLR_BIT(RCC_CR, HSEBYP);
		SET_BIT(RCC_CR, HSITRIM4);
	/*        HSE RC Configuration             */		
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		SET_BIT(RCC_CFGR, SW0);
		CLR_BIT(RCC_CFGR, SW1);
		SET_BIT(RCC_CR, HSEON);
		SET_BIT(RCC_CR, HSEBYP);
		SET_BIT(RCC_CR, HSITRIM4);
	/*        HSI Configuration                */		
	#elif RCC_CLOCK_TYPE == RCC_HSI
		SET_BIT(RCC_CR, HSIRDY);
		SET_BIT(RCC_CR, HSITRIM4);
		CLR_BIT(RCC_CFGR, SW0);
		CLR_BIT(RCC_CFGR, SW1);
	/*        PLL Configuration                */	
	#elif RCC_CLOCK_TYPE == RCC_PLL
		SET_BIT(RCC_CR, PLLON);
		CLR_BIT(RCC_CFGR, SW0);
		SET_BIT(RCC_CFGR, SW1);
		/* Checks if PLL source = High Speed External Oscillator                  */
		#if RCC_PLL_INPUT == RCC_PLL_HSE
			SET_BIT(RCC_CR, HSEON);
			SET_BIT(RCC_CR, HSITRIM4);
			SET_BIT(RCC_CFGR, PLL_SRC);
			CLR_BIT(RCC_CFGR, PLL_XTPRE);
			/* Checks if the PLL High Speed External Oscillator is RC             */
			#if PLL_HSE_TYPE == PLL_HSE_RC	
				SET_BIT(RCC_CR, HSEBYP);
			/* Checks if the PLL High Speed External Oscillator is Crystal        */	
			#elif PLL_HSE_TYPE == PLL_HSE_CRYSTAL
				CLR_BIT(RCC_CR, HSEBYP);
			#endif	
		
		/* Checks if PLL source = High Speed External Oscillator / 2              */		
		#elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_BY_2
			SET_BIT(RCC_CR, HSEON);
			SET_BIT(RCC_CR, HSITRIM4);
			SET_BIT(RCC_CFGR, PLL_SRC);
			SET_BIT(RCC_CFGR, PLL_XTPRE);
			/* Checks if the PLL High Speed External Oscillator / 2	is RC         */	
			#if PLL_HSE_DIV_BY_2_TYPE == PLL_HSE_DIV_2_RC
				SET_BIT(RCC_CR, HSEBYP);
			/* Checks if the PLL High Speed External Oscillator / 2	is Crystal    */
			#elif PLL_HSE_DIV_BY_2_TYPE == PLL_HSE_DIV_2_CRYSTAL
				CLR_BIT(RCC_CR, HSEBYP);
			#endif
		/* Checks if PLL source = High Speed Internal Oscillator / 2              */	
		#elif RCC_PLL_INPUT == 	RCC_PLL_HSI_DIV_BY_2
			SET_BIT(RCC_CR, HSIRDY);
			SET_BIT(RCC_CR, HSITRIM4);
			CLR_BIT(RCC_CFGR, PLL_SRC);
		#endif
		
		/* PLL Multiplication Value Check                                         */
		#if RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_2
			CLR_BIT(RCC_CFGR, PLLMUL0);
			CLR_BIT(RCC_CFGR, PLLMUL1);
			CLR_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_3
			SET_BIT(RCC_CFGR, PLLMUL0);
			CLR_BIT(RCC_CFGR, PLLMUL1);
			CLR_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);	
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_4
			CLR_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			CLR_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);	
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_5
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			CLR_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_6
			CLR_BIT(RCC_CFGR, PLLMUL0);
			CLR_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_7
			SET_BIT(RCC_CFGR, PLLMUL0);
			CLR_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_8
			CLR_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#elif RCC_PLL_MUL_VAL == PLL_IN_CLK_MUL_9
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			CLR_BIT(RCC_CFGR, PLLMUL3);
		#else
			#error "you must not exceed PLL_IN_CLK_MUL_9 "
		#endif

	
	/*		AHB Bus Speed Configuration			*/	
	#if AHB_CLOCK_SPEED == SYSCLK_NOT_DIVIDED
		CLR_BIT(RCC_CFGR, HPRE0);
		CLR_BIT(RCC_CFGR, HPRE1);
		CLR_BIT(RCC_CFGR, HPRE2);
		CLR_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_2
		CLR_BIT(RCC_CFGR, HPRE0);
		CLR_BIT(RCC_CFGR, HPRE1);
		CLR_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_4
		SET_BIT(RCC_CFGR, HPRE0);
		CLR_BIT(RCC_CFGR, HPRE1);
		CLR_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_8
		CLR_BIT(RCC_CFGR, HPRE0);
		SET_BIT(RCC_CFGR, HPRE1);
		CLR_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_16
		SET_BIT(RCC_CFGR, HPRE0);
		SET_BIT(RCC_CFGR, HPRE1);
		CLR_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_64
		CLR_BIT(RCC_CFGR, HPRE0);
		CLR_BIT(RCC_CFGR, HPRE1);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_128
		SET_BIT(RCC_CFGR, HPRE0);
		CLR_BIT(RCC_CFGR, HPRE1);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_256
		CLR_BIT(RCC_CFGR, HPRE0);
		SET_BIT(RCC_CFGR, HPRE1);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#elif AHB_CLOCK_SPEED == SYSCLK_DIV_BY_512
		SET_BIT(RCC_CFGR, HPRE0);
		SET_BIT(RCC_CFGR, HPRE1);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE3);
	#endif

	/*        APB1 Bus Speed Configuration        */	
	#if APB1_CLOCK_SPEED == HCLK_NOT_DIVIDED
		CLR_BIT(RCC_CFGR, PPRE1_0);
		CLR_BIT(RCC_CFGR, PPRE1_1);
		CLR_BIT(RCC_CFGR, PPRE1_2);
	#elif APB1_CLOCK_SPEED == HCLK_DIV_BY_2
		CLR_BIT(RCC_CFGR, PPRE1_0);
		CLR_BIT(RCC_CFGR, PPRE1_1);
		SET_BIT(RCC_CFGR, PPRE1_2);
	#elif APB1_CLOCK_SPEED == HCLK_DIV_BY_4
		SET_BIT(RCC_CFGR, PPRE1_0);
		CLR_BIT(RCC_CFGR, PPRE1_1);
		SET_BIT(RCC_CFGR, PPRE1_2);
	#elif APB1_CLOCK_SPEED == HCLK_DIV_BY_8
		CLR_BIT(RCC_CFGR, PPRE1_0);
		SET_BIT(RCC_CFGR, PPRE1_1);
		SET_BIT(RCC_CFGR, PPRE1_2);
	#elif APB1_CLOCK_SPEED == HCLK_DIV_BY_16
		SET_BIT(RCC_CFGR, PPRE1_0);
		SET_BIT(RCC_CFGR, PPRE1_1);
		SET_BIT(RCC_CFGR, PPRE1_2);
	#endif


	/*        APB2 Bus Speed Configuration        */
	#if APB2_CLOCK_SPEED == HCLK_NOT_DIVIDED
		CLR_BIT(RCC_CFGR, PPRE2_0);
		CLR_BIT(RCC_CFGR, PPRE2_1);
		CLR_BIT(RCC_CFGR, PPRE2_2);
	#elif APB2_CLOCK_SPEED == HCLK_DIV_BY_2
		CLR_BIT(RCC_CFGR, PPRE2_0);
		CLR_BIT(RCC_CFGR, PPRE2_1);
		SET_BIT(RCC_CFGR, PPRE2_2);
	#elif APB2_CLOCK_SPEED == HCLK_DIV_BY_4
		SET_BIT(RCC_CFGR, PPRE2_0);
		CLR_BIT(RCC_CFGR, PPRE2_1);
		SET_BIT(RCC_CFGR, PPRE2_2);
	#elif APB2_CLOCK_SPEED == HCLK_DIV_BY_8
		CLR_BIT(RCC_CFGR, PPRE2_0);
		SET_BIT(RCC_CFGR, PPRE2_1);
		SET_BIT(RCC_CFGR, PPRE2_2);
	#elif APB2_CLOCK_SPEED == HCLK_DIV_BY_16
		SET_BIT(RCC_CFGR, PPRE2_0);
		SET_BIT(RCC_CFGR, PPRE2_1);
		SET_BIT(RCC_CFGR, PPRE2_2);
	#endif
		
}


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
Error_State_t MRCC_voidEnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	u8 Local_u8Ret_Val = RET_OK;
	/*        Range Check        */
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	SET_BIT(RCC_AHBENR, Copy_u8PeripheralID); break;
			case RCC_APB1:	SET_BIT(RCC_APB1ENR, Copy_u8PeripheralID);break;
			case RCC_APB2:	SET_BIT(RCC_APB2ENR, Copy_u8PeripheralID);break;
		}
	}
	else{
		Local_u8Ret_Val = RET_OUT_OF_RANGE;
	}
	return Local_u8Ret_Val;
}



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
Error_State_t MRCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	u8 Local_u8Ret_Val = RET_OK;
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	CLR_BIT(RCC_AHBENR, Copy_u8PeripheralID); break;
			case RCC_APB1:	CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralID);break;
			case RCC_APB2:	CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralID);break;
		}
	}
	else{
		Local_u8Ret_Val = RET_OUT_OF_RANGE;
	}
	return Local_u8Ret_Val;
}
