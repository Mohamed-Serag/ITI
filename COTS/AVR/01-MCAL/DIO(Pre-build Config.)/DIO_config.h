/*******************************************************************/
/* File Name: DIO_config.h                                         */
/* File Info: This file contains DIO driver configurations.        */
/* Version  : V1.0                                                 */
/* Date     : 18 Oct. 2020                                         */
/* Author   : Mohamed Serag.                                       */
/*******************************************************************/
/******************************************************************/
/* Header file Guard to prevent this file from muliple inclusions */
/******************************************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/******************************************************************/
/* Macro Name: PORTA                                              */
/* Macro Info: This macro is used to enable or disable Port A     */
/* Options   : To enable Port A  : ENABLE_PORT                    */
/*             To disable Port A : DISABLE_PORT                   */
/******************************************************************/
#define  PORTA  ENABLE_PORT

/******************************************************************/
/* Macro Name: PORTA_PINx                                         */
/* Macro Info: These macros are used to configure Port A pins as  */
/*             input or output.                                   */
/* Options   : for an output pin : OUTPUT_PIN                     */
/*             for an input pin  : INPUT_PIN                      */
/******************************************************************/
/* Macro Name: PINAx_IN_PUllUP                                    */
/* Macro Info: These macros are used to enable or disable the in- */
/*             ternal pull up resistors.                          */
/* Note That : The internal pull up resistors can be enabled ONLY */
/*             if the pin is configured as input (INPUT_PIN)      */
/* Options   : To enable the pull-up  : PULL_UP_ENABLED           */
/*             To disable the pull-up : PULL_UP_DISABLED          */
/******************************************************************/
#define  PORTA_PIN0       OUTPUT_PIN
#define  PINA0_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN1       INPUT_PIN
#define  PINA1_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN2       OUTPUT_PIN
#define  PINA2_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN3       INPUT_PIN
#define  PINA3_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN4       OUTPUT_PIN
#define  PINA4_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN5       INPUT_PIN
#define  PINA5_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN6       OUTPUT_PIN
#define  PINA6_IN_PUllUP  PULL_UP_DISABLED

#define  PORTA_PIN7       INPUT_PIN
#define  PINA7_IN_PUllUP  PULL_UP_DISABLED



/******************************************************************/
/* Macro Name: PORTB                                              */
/* Macro Info: This macro is used to enable or disable Port B     */
/* Options   : To enable Port B  : ENABLE_PORT                    */
/*             To disable Port B : DISABLE_PORT                   */
/******************************************************************/
#define  PORTB  ENABLE_PORT

/******************************************************************/
/* Macro Name: PORTB_PINx                                         */
/* Macro Info: These macros are used to configure Port B pins as  */
/*             input or output.                                   */
/* Options   : for an output pin : OUTPUT_PIN                     */
/*             for an input pin  : INPUT_PIN                      */
/******************************************************************/
/* Macro Name: PINBx_IN_PUllUP                                    */
/* Macro Info: These macros are used to enable or disable the in- */
/*             ternal pull up resistors.                          */
/* Note That : The internal pull up resistors can be enabled ONLY */
/*             if the pin is configured as input (INPUT_PIN)      */
/* Options   : To enable the pull-up  : PULL_UP_ENABLED           */
/*             To disable the pull-up : PULL_UP_DISABLED          */
/******************************************************************/
#define  PORTB_PIN0       OUTPUT_PIN
#define  PINB0_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN1       INPUT_PIN
#define  PINB1_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN2       OUTPUT_PIN
#define  PINB2_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN3       INPUT_PIN
#define  PINB3_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN4       OUTPUT_PIN
#define  PINB4_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN5       INPUT_PIN
#define  PINB5_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN6       OUTPUT_PIN
#define  PINB6_IN_PUllUP  PULL_UP_DISABLED

#define  PORTB_PIN7       INPUT_PIN
#define  PINB7_IN_PUllUP  PULL_UP_DISABLED



/******************************************************************/
/* Macro Name: PORTC                                              */
/* Macro Info: This macro is used to enable or disable Port C     */
/* Options   : To enable Port C  : ENABLE_PORT                    */
/*             To disable Port C : DISABLE_PORT                   */
/******************************************************************/
#define  PORTC  ENABLE_PORT

/******************************************************************/
/* Macro Name: PORTC_PINx                                         */
/* Macro Info: These macros are used to configure Port C pins as  */
/*             input or output.                                   */
/* Options   : for an output pin : OUTPUT_PIN                     */
/*             for an input pin  : INPUT_PIN                      */
/******************************************************************/
/* Macro Name: PINCx_IN_PUllUP                                    */
/* Macro Info: These macros are used to enable or disable the in- */
/*             ternal pull up resistors.                          */
/* Note That : The internal pull up resistors can be enabled ONLY */
/*             if the pin is configured as input (INPUT_PIN)      */
/* Options   : To enable the pull-up  : PULL_UP_ENABLED           */
/*             To disable the pull-up : PULL_UP_DISABLED          */
/******************************************************************/
#define  PORTC_PIN0       OUTPUT_PIN
#define  PINC0_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN1       INPUT_PIN
#define  PINC1_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN2       OUTPUT_PIN
#define  PINC2_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN3       INPUT_PIN
#define  PINC3_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN4       OUTPUT_PIN
#define  PINC4_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN5       INPUT_PIN
#define  PINC5_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN6       OUTPUT_PIN
#define  PINC6_IN_PUllUP  PULL_UP_DISABLED

#define  PORTC_PIN7       INPUT_PIN
#define  PINC7_IN_PUllUP  PULL_UP_DISABLED



/******************************************************************/
/* Macro Name: PORTD                                              */
/* Macro Info: This macro is used to enable or disable Port D     */
/* Options   : To enable Port D  : ENABLE_PORT                    */
/*             To disable Port D : DISABLE_PORT                   */
/******************************************************************/
#define  PORTD  ENABLE_PORT

/******************************************************************/
/* Macro Name: PORTD_PINx                                         */
/* Macro Info: These macros are used to configure Port D pins as  */
/*             input or output.                                   */
/* Options   : for an output pin : OUTPUT_PIN                     */
/*             for an input pin  : INPUT_PIN                      */
/******************************************************************/
/* Macro Name: PINDx_IN_PUllUP                                    */
/* Macro Info: These macros are used to enable or disable the in- */
/*             ternal pull up resistors.                          */
/* Note That : The internal pull up resistors can be enabled ONLY */
/*             if the pin is configured as input (INPUT_PIN)      */
/* Options   : To enable the pull-up  : PULL_UP_ENABLED           */
/*             To disable the pull-up : PULL_UP_DISABLED          */
/******************************************************************/
#define  PORTD_PIN0       OUTPUT_PIN
#define  PIND0_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN1       INPUT_PIN
#define  PIND1_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN2       OUTPUT_PIN
#define  PIND2_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN3       INPUT_PIN
#define  PIND3_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN4       OUTPUT_PIN
#define  PIND4_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN5       INPUT_PIN
#define  PIND5_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN6       OUTPUT_PIN
#define  PIND6_IN_PUllUP  PULL_UP_DISABLED

#define  PORTD_PIN7       INPUT_PIN
#define  PIND7_IN_PUllUP  PULL_UP_DISABLED

#endif /** The end of DIO_CONFIG_H */