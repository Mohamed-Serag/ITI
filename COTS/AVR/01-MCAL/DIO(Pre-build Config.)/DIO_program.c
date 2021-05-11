/*****************************************************************************/
/* File Name: DIO_program.c                                                  */
/* File Info: This file contains DIO driver functions definitions.           */
/*            (and it's a pre-build configuration driver).                   */
/* Version  : V1.0                                                           */
/* Date     : 18 Oct. 2020                                                   */
/* Author   : Mohamed Serag.                                                 */
/*****************************************************************************/
/********************************************************************/
/*********************** Linking Section ****************************/
/********************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Error_State.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/********************************************************************/
/* Function Name   : MDIO_voidInit()                                */
/* Function info   : This function initializes the DIO Pins through */
/*                   Pre-build configurations.                      */
/* Function Input  : None.                                          */
/* Function Returns: None.                                          */
/********************************************************************/
void MDIO_voidInit(void){
	/*** PORT A Configurations ***/
	#if PORTA == ENABLE_PORT
	
	/* Port A Pin 0 Configurations */
		#if PORTA_PIN0 == OUTPUT_PIN
			#define  A0  1
			#define  A0_PU  0
		#elif PORTA_PIN0 == INPUT_PIN
			#define  A0  0
			#if PINA0_IN_PUllUP == PULL_UP_DISABLED
				#define  A0_PU  0
			#elif PINA0_IN_PUllUP == PULL_UP_ENABLED
				#define  A0_PU  1
			#endif 
		#endif
	
	/* Port A Pin 1 Configurations */
		#if PORTA_PIN1 == OUTPUT_PIN
			#define  A1  1
			#define  A1_PU  0
		#elif PORTA_PIN1 == INPUT_PIN
			#define  A1  0
			#if PINA1_IN_PUllUP == PULL_UP_DISABLED
				#define  A1_PU  0
			#elif PINA1_IN_PUllUP == PULL_UP_ENABLED
				#define  A1_PU  1
			#endif 
		#endif
	
	/* Port A Pin 2 Configurations */
		#if PORTA_PIN2 == OUTPUT_PIN
			#define  A2  1
			#define  A2_PU  0
		#elif PORTA_PIN2 == INPUT_PIN
			#define  A2  0
			#if PINA2_IN_PUllUP == PULL_UP_DISABLED
				#define  A2_PU  0
			#elif PINA2_IN_PUllUP == PULL_UP_ENABLED
				#define  A2_PU  1
			#endif 
		#endif
	
	/* Port A Pin 3 Configurations */
		#if PORTA_PIN3 == OUTPUT_PIN
			#define  A3  1
			#define  A3_PU  0
		#elif PORTA_PIN3 == INPUT_PIN
			#define  A3  0
			#if PINA3_IN_PUllUP == PULL_UP_DISABLED
				#define  A3_PU  0
			#elif PINA3_IN_PUllUP == PULL_UP_ENABLED
				#define  A3_PU  1
			#endif 
		#endif
	
	/* Port A Pin 4 Configurations */
		#if PORTA_PIN4 == OUTPUT_PIN
			#define  A4  1
			#define  A4_PU  0
		#elif PORTA_PIN4 == INPUT_PIN
			#define  A4  0
			#if PINA4_IN_PUllUP == PULL_UP_DISABLED
				#define  A4_PU  0
			#elif PINA4_IN_PUllUP == PULL_UP_ENABLED
				#define  A4_PU  1
			#endif 
		#endif
	
	/* Port A Pin 5 Configurations */
		#if PORTA_PIN5 == OUTPUT_PIN
			#define  A5  1
			#define  A5_PU  0
		#elif PORTA_PIN5 == INPUT_PIN
			#define  A5  0
			#if PINA5_IN_PUllUP == PULL_UP_DISABLED
				#define  A5_PU  0
			#elif PINA5_IN_PUllUP == PULL_UP_ENABLED
				#define  A5_PU  1
			#endif 
		#endif
	
	/* Port A Pin 6 Configurations */
		#if PORTA_PIN6 == OUTPUT_PIN
			#define  A6  1
			#define  A6_PU  0
		#elif PORTA_PIN6 == INPUT_PIN
			#define  A6  0
			#if PINA6_IN_PUllUP == PULL_UP_DISABLED
				#define  A6_PU  0
			#elif PINA6_IN_PUllUP == PULL_UP_ENABLED
				#define  A6_PU  1
			#endif 
		#endif
	
	/* Port A Pin 7 Configurations */
		#if PORTA_PIN7 == OUTPUT_PIN
			#define  A7  1
			#define  A7_PU  0
		#elif PORTA_PIN7 == INPUT_PIN
			#define  A7  0
			#if PINA7_IN_PUllUP == PULL_UP_DISABLED
				#define  A7_PU  0
			#elif PINA7_IN_PUllUP == PULL_UP_ENABLED
				#define  A7_PU  1
			#endif 
		#endif
		/* Assigning Port A values into DDRA and PORTA Registers */
	    DDRA_REG = CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0);
	    PORTA_REG = CONC_BIT(A7_PU,A6_PU,A5_PU,A4_PU,A3_PU,A2_PU,A1_PU,A0_PU);
	#endif

	
	/*** PORT B Configurations ***/
	#if PORTB == ENABLE_PORT
		/* Port B Pin 0 Configurations */
		#if PORTB_PIN0 == OUTPUT_PIN
			#define  B0  1
			#define  B0_PU  0
		#elif PORTB_PIN0 == INPUT_PIN
			#define  B0  0
			#if PINB0_IN_PUllUP == PULL_UP_DISABLED
				#define  B0_PU  0
			#elif PINB0_IN_PUllUP == PULL_UP_ENABLED
				#define  B0_PU  1
			#endif 
		#endif
	
	/* Port B Pin 1 Configurations */
		#if PORTB_PIN1 == OUTPUT_PIN
			#define  B1  1
			#define  B1_PU  0
		#elif PORTB_PIN1 == INPUT_PIN
			#define  B1  0
			#if PINB1_IN_PUllUP == PULL_UP_DISABLED
				#define  B1_PU  0
			#elif PINB1_IN_PUllUP == PULL_UP_ENABLED
				#define  B1_PU  1
			#endif 
		#endif
	
	/* Port B Pin 2 Configurations */
		#if PORTB_PIN2 == OUTPUT_PIN
			#define  B2  1
			#define  B2_PU  0
		#elif PORTB_PIN2 == INPUT_PIN
			#define  B2  0
			#if PINB2_IN_PUllUP == PULL_UP_DISABLED
				#define  B2_PU  0
			#elif PINB2_IN_PUllUP == PULL_UP_ENABLED
				#define  B2_PU  1
			#endif 
		#endif
	
	/* Port B Pin 3 Configurations */
		#if PORTB_PIN3 == OUTPUT_PIN
			#define  B3  1
			#define  B3_PU  0
		#elif PORTB_PIN3 == INPUT_PIN
			#define  B3  0
			#if PINB3_IN_PUllUP == PULL_UP_DISABLED
				#define  B3_PU  0
			#elif PINB3_IN_PUllUP == PULL_UP_ENABLED
				#define  B3_PU  1
			#endif 
		#endif
	
	/* Port B Pin 4 Configurations */
		#if PORTB_PIN4 == OUTPUT_PIN
			#define  B4  1
			#define  B4_PU  0
		#elif PORTB_PIN4 == INPUT_PIN
			#define  B4  0
			#if PINB4_IN_PUllUP == PULL_UP_DISABLED
				#define  B4_PU  0
			#elif PINB4_IN_PUllUP == PULL_UP_ENABLED
				#define  B4_PU  1
			#endif 
		#endif
	
	/* Port B Pin 5 Configurations */
		#if PORTB_PIN5 == OUTPUT_PIN
			#define  B5  1
			#define  B5_PU  0
		#elif PORTB_PIN5 == INPUT_PIN
			#define  B5  0
			#if PINB5_IN_PUllUP == PULL_UP_DISABLED
				#define  B5_PU  0
			#elif PINB5_IN_PUllUP == PULL_UP_ENABLED
				#define  B5_PU  1
			#endif 
		#endif
	
	/* Port B Pin 6 Configurations */
		#if PORTB_PIN6 == OUTPUT_PIN
			#define  B6  1
			#define  B6_PU  0
		#elif PORTB_PIN6 == INPUT_PIN
			#define  B6  0
			#if PINB6_IN_PUllUP == PULL_UP_DISABLED
				#define  B6_PU  0
			#elif PINB6_IN_PUllUP == PULL_UP_ENABLED
				#define  B6_PU  1
			#endif 
		#endif
	
	/* Port B Pin 7 Configurations */
		#if PORTB_PIN7 == OUTPUT_PIN
			#define  B7  1
			#define  B7_PU  0
		#elif PORTB_PIN7 == INPUT_PIN
			#define  B7  0
			#if PINB7_IN_PUllUP == PULL_UP_DISABLED
				#define  B7_PU  0
			#elif PINB7_IN_PUllUP == PULL_UP_ENABLED
				#define  B7_PU  1
			#endif 
		#endif
		/* Assigning Port B values into DDRB and PORTB Registers */
	    DDRB_REG = CONC_BIT(B7,B6,B5,B4,B3,B2,B1,B0);
	    PORTB_REG = CONC_BIT(B7_PU,B6_PU,B5_PU,B4_PU,B3_PU,B2_PU,B1_PU,B0_PU);
	#endif
	

	/*** PORT C Configurations ***/
	#if PORTC == ENABLE_PORT
		/* Port B Pin 0 Configurations */
		#if PORTC_PIN0 == OUTPUT_PIN
			#define  C0  1
			#define  C0_PU  0
		#elif PORTC_PIN0 == INPUT_PIN
			#define  C0  0
			#if PINC0_IN_PUllUP == PULL_UP_DISABLED
				#define  C0_PU  0
			#elif PINC0_IN_PUllUP == PULL_UP_ENABLED
				#define  C0_PU  1
			#endif 
		#endif
	
	/* Port C Pin 1 Configurations */
		#if PORTC_PIN1 == OUTPUT_PIN
			#define  C1  1
			#define  C1_PU  0
		#elif PORTC_PIN1 == INPUT_PIN
			#define  C1  0
			#if PINC1_IN_PUllUP == PULL_UP_DISABLED
				#define  C1_PU  0
			#elif PINC1_IN_PUllUP == PULL_UP_ENABLED
				#define  C1_PU  1
			#endif 
		#endif
	
	/* Port C Pin 2 Configurations */
		#if PORTC_PIN2 == OUTPUT_PIN
			#define  C2  1
			#define  C2_PU  0
		#elif PORTC_PIN2 == INPUT_PIN
			#define  C2  0
			#if PINC2_IN_PUllUP == PULL_UP_DISABLED
				#define  C2_PU  0
			#elif PINC2_IN_PUllUP == PULL_UP_ENABLED
				#define  C2_PU  1
			#endif 
		#endif
	
	/* Port C Pin 3 Configurations */
		#if PORTC_PIN3 == OUTPUT_PIN
			#define  C3  1
			#define  C3_PU  0
		#elif PORTC_PIN3 == INPUT_PIN
			#define  C3  0
			#if PINC3_IN_PUllUP == PULL_UP_DISABLED
				#define  C3_PU  0
			#elif PINC3_IN_PUllUP == PULL_UP_ENABLED
				#define  C3_PU  1
			#endif 
		#endif
	
	/* Port C Pin 4 Configurations */
		#if PORTC_PIN4 == OUTPUT_PIN
			#define  C4  1
			#define  C4_PU  0
		#elif PORTC_PIN4 == INPUT_PIN
			#define  C4  0
			#if PINC4_IN_PUllUP == PULL_UP_DISABLED
				#define  C4_PU  0
			#elif PINC4_IN_PUllUP == PULL_UP_ENABLED
				#define  C4_PU  1
			#endif 
		#endif
	
	/* Port C Pin 5 Configurations */
		#if PORTC_PIN5 == OUTPUT_PIN
			#define  C5  1
			#define  C5_PU  0
		#elif PORTC_PIN5 == INPUT_PIN
			#define  C5  0
			#if PINC5_IN_PUllUP == PULL_UP_DISABLED
				#define  C5_PU  0
			#elif PINC5_IN_PUllUP == PULL_UP_ENABLED
				#define  C5_PU  1
			#endif 
		#endif
	
	/* Port C Pin 6 Configurations */
		#if PORTC_PIN6 == OUTPUT_PIN
			#define  C6  1
			#define  C6_PU  0
		#elif PORTC_PIN6 == INPUT_PIN
			#define  C6  0
			#if PINC6_IN_PUllUP == PULL_UP_DISABLED
				#define  C6_PU  0
			#elif PINC6_IN_PUllUP == PULL_UP_ENABLED
				#define  C6_PU  1
			#endif 
		#endif
	
	/* Port C Pin 7 Configurations */
		#if PORTC_PIN7 == OUTPUT_PIN
			#define  C7  1
			#define  C7_PU  0
		#elif PORTC_PIN7 == INPUT_PIN
			#define  C7  0
			#if PINC7_IN_PUllUP == PULL_UP_DISABLED
				#define  C7_PU  0
			#elif PINC7_IN_PUllUP == PULL_UP_ENABLED
				#define  C7_PU  1
			#endif 
		#endif
	    /* Assigning Port C values into DDRC and PORTC Registers */
	    DDRC_REG = CONC_BIT(C7,C6,C5,C4,C3,C2,C1,C0);
	    PORTC_REG = CONC_BIT(C7_PU,C6_PU,C5_PU,C4_PU,C3_PU,C2_PU,C1_PU,C0_PU);
	#endif
	

	/** Port D Configuration **/
	#if PORTD == ENABLE_PORT
		/* Port B Pin 0 Configurations */
		#if PORTD_PIN0 == OUTPUT_PIN
			#define  D0  1
			#define  D0_PU  0
		#elif PORTD_PIN0 == INPUT_PIN
			#define  D0  0
			#if PIND0_IN_PUllUP == PULL_UP_DISABLED
				#define  D0_PU  0
			#elif PIND0_IN_PUllUP == PULL_UP_ENABLED
				#define  D0_PU  1
			#endif 
		#endif
	
	/* Port D Pin 1 Configurations */
		#if PORTD_PIN1 == OUTPUT_PIN
			#define  D1  1
			#define  D1_PU  0
		#elif PORTD_PIN1 == INPUT_PIN
			#define  D1  0
			#if PIND1_IN_PUllUP == PULL_UP_DISABLED
				#define  D1_PU  0
			#elif PIND1_IN_PUllUP == PULL_UP_ENABLED
				#define  D1_PU  1
			#endif 
		#endif
	
	/* Port D Pin 2 Configurations */
		#if PORTD_PIN2 == OUTPUT_PIN
			#define  D2  1
			#define  D2_PU  0
		#elif PORTD_PIN2 == INPUT_PIN
			#define  D2  0
			#if PIND2_IN_PUllUP == PULL_UP_DISABLED
				#define  D2_PU  0
			#elif PIND2_IN_PUllUP == PULL_UP_ENABLED
				#define  D2_PU  1
			#endif 
		#endif
	
	/* Port D Pin 3 Configurations */
		#if PORTD_PIN3 == OUTPUT_PIN
			#define  D3  1
			#define  D3_PU  0
		#elif PORTD_PIN3 == INPUT_PIN
			#define  D3  0
			#if PIND3_IN_PUllUP == PULL_UP_DISABLED
				#define  D3_PU  0
			#elif PIND3_IN_PUllUP == PULL_UP_ENABLED
				#define  D3_PU  1
			#endif 
		#endif
	
	/* Port D Pin 4 Configurations */
		#if PORTD_PIN4 == OUTPUT_PIN
			#define  D4  1
			#define  D4_PU  0
		#elif PORTD_PIN4 == INPUT_PIN
			#define  D4  0
			#if PIND4_IN_PUllUP == PULL_UP_DISABLED
				#define  D4_PU  0
			#elif PIND4_IN_PUllUP == PULL_UP_ENABLED
				#define  D4_PU  1
			#endif 
		#endif
	
	/* Port D Pin 5 Configurations */
		#if PORTD_PIN5 == OUTPUT_PIN
			#define  D5  1
			#define  D5_PU  0
		#elif PORTD_PIN5 == INPUT_PIN
			#define  D5  0
			#if PIND5_IN_PUllUP == PULL_UP_DISABLED
				#define  D5_PU  0
			#elif PIND5_IN_PUllUP == PULL_UP_ENABLED
				#define  D5_PU  1
			#endif 
		#endif
	
	/* Port D Pin 6 Configurations */
		#if PORTD_PIN6 == OUTPUT_PIN
			#define  D6  1
			#define  D6_PU  0
		#elif PORTD_PIN6 == INPUT_PIN
			#define  D6  0
			#if PIND6_IN_PUllUP == PULL_UP_DISABLED
				#define  D6_PU  0
			#elif PIND6_IN_PUllUP == PULL_UP_ENABLED
				#define  D6_PU  1
			#endif 
		#endif
	
	/* Port D Pin 7 Configurations */
		#if PORTD_PIN7 == OUTPUT_PIN
			#define  D7  1
			#define  D7_PU  0
		#elif PORTD_PIN7 == INPUT_PIN
			#define  D7  0
			#if PIND7_IN_PUllUP == PULL_UP_DISABLED
				#define  D7_PU  0
			#elif PIND7_IN_PUllUP == PULL_UP_ENABLED
				#define  D7_PU  1
			#endif 
		#endif
		/* Assigning Port D values into DDRD and PORTD Registers */
		DDRD_REG = CONC_BIT(D7,D6,D5,D4,D3,D2,D1,D0);
		PORTD_REG = CONC_BIT(D7_PU,D6_PU,D5_PU,D4_PU,D3_PU,D2_PU,D1_PU,D0_PU)
	#endif
;
}

/********************************************************************/
/* Function Name   : MDIO_enuSetPinValue()                          */
/* Function info   : This Function sets a pin value High or Low.    */
/* Function Input  :- Copy_u8PORT -> the targeted port.             */
/*                    Options: DIO_U8_PORTx where x (A, B, C, or D) */
/*                                                                  */
/*                  - Copy_u8PIN -> the targeted pin.               */
/*                    Options: DIO_U8_PINx where x (0, 1, ...., 7)  */
/*                                                                  */
/*                  - Copy_u8Value -> the value of the pin.         */
/*                    Options:  DIO_U8_LOW                          */
/*                              DIO_U8_HIGH                         */
/* Function Returns:  L_RetVal -> variable of enum Error_State_t    */
/*                                type that returns function        */
/*                                execution status.                 */
/********************************************************************/
Error_State_t MDIO_enuSetPinValue(uint8_t Copy_u8PORT, uint8_t Copy_u8PIN, uint8_t Copy_u8Value){
	Error_State_t L_RetVal = ERR_ST_OK;
	if((Copy_u8PORT < 4) && (Copy_u8PIN < 8)){
		switch(Copy_u8Value){
			case DIO_U8_LOW:
				switch(Copy_u8PORT){
					case DIO_U8_PORTA: CLR_BIT(PORTA_REG, Copy_u8PIN); break;
					case DIO_U8_PORTB: CLR_BIT(PORTB_REG, Copy_u8PIN); break;
					case DIO_U8_PORTC: CLR_BIT(PORTC_REG, Copy_u8PIN); break;
					case DIO_U8_PORTD: CLR_BIT(PORTD_REG, Copy_u8PIN); break;
				}
			break;
			case DIO_U8_HIGH:
				switch(Copy_u8PORT){
					case DIO_U8_PORTA: SET_BIT(PORTA_REG, Copy_u8PIN); break;
					case DIO_U8_PORTB: SET_BIT(PORTB_REG, Copy_u8PIN); break;
					case DIO_U8_PORTC: SET_BIT(PORTC_REG, Copy_u8PIN); break;
					case DIO_U8_PORTD: SET_BIT(PORTD_REG, Copy_u8PIN); break;
				}
			break;
			default: L_RetVal = ERR_ST_OUT_OF_RANGE;
		}
	}
	else{
		L_RetVal = ERR_ST_NOK;
	}
	return L_RetVal;
}

/********************************************************************/
/* Function Name   : MDIO_enuGetPinValue()                          */
/* Function info   : This Function reads a pin value.               */
/* Function Input  :- Copy_u8PORT -> the targeted port.             */
/*                    Options: DIO_U8_PORTx where x (A, B, C, or D) */
/*                                                                  */
/*                  - Copy_u8PIN -> the targeted pin.               */
/*                    Options: DIO_U8_PINx where x (0, 1, ...., 7)  */
/*                                                                  */
/*                  - Pu8PinValue -> a pointer to return the value  */
/*                                   through it.                    */
/* Function Returns:  L_RetVal -> variable of enum Error_State_t    */
/*                                type that returns function        */
/*                                execution status.                 */
/********************************************************************/
Error_State_t MDIO_enuGetPinValue(uint8_t Copy_u8PORT, uint8_t Copy_u8PIN, uint8_t *Pu8PinValue){
	Error_State_t L_RetVal = ERR_ST_OK;
	/* In case of an error, 0xFF will be returned */
	*Pu8PinValue = 0xFF; 
	if((Copy_u8PORT < 4) && (Copy_u8PIN < 8)){
		switch(Copy_u8PORT){
			case DIO_U8_PORTA: *Pu8PinValue = GET_BIT(PORTA_REG, Copy_u8PIN); break;
			case DIO_U8_PORTB: *Pu8PinValue = GET_BIT(PORTB_REG, Copy_u8PIN); break;
            case DIO_U8_PORTC: *Pu8PinValue = GET_BIT(PORTC_REG, Copy_u8PIN); break;
			case DIO_U8_PORTD: *Pu8PinValue = GET_BIT(PORTD_REG, Copy_u8PIN); break;
		}
	}
	else{
		L_RetVal = ERR_ST_NOK;
	}
	return L_RetVal;
}

