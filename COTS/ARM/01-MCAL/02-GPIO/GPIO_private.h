/*************************************************************************/
/* File Name : GPIO_private.h                                            */
/* File info : This file contains all macro needed to create the GPIO    */
/*             module.                                                   */
/* Date      : 30 Nov 2020                                               */
/* Version   : V1.0                                                      */
/* Author    : Mohamed Serag.                                            */
/*************************************************************************/
/******************************************************************/
/* File Guard to prevent this header file from multiple inclusion */
/******************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/*            Ports and Pins Maximum Numbers            */
#define        PORT_MAX                         (3)		
#define        PIN_MAX                          (16)



/*            GPIO Registers Offset Values              */
#define        GPIOX_CRL                        (0x00)
#define        GPIOX_CRH                        (0x04)
#define        GPIOX_IDR                        (0x08)
#define        GPIOX_ODR                        (0x0C)
#define        GPIOX_BSRR                       (0x10)
#define        GPIOX_BRR                        (0x14)
#define        GPIOX_LCKR                       (0x18)


/*            GPIO Port A  Base Address                 */
#define        GPIOA_BASE_ADDRESS               (0x40010800)
/*       GPIO Port A  Registers definitions             */
#define        GPIOA_CRL                        *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_CRL ))
#define        GPIOA_CRH                        *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_CRH ))
#define        GPIOA_IDR                        *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_IDR ))
#define        GPIOA_ODR                        *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_ODR ))
#define        GPIOA_BSRR                       *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_BSRR))
#define        GPIOA_BRR                        *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_BRR ))
#define        GPIOA_LCKR                       *((volatile u32*)(GPIOA_BASE_ADDRESS + GPIOX_LCKR))


/*            GPIO Port B  Base Address                 */
#define        GPIOB_BASE_ADDRESS              (0x40010C00)
/*       GPIO Port B  Registers definitions             */
#define        GPIOB_CRL                       *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_CRL ))
#define        GPIOB_CRH                       *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_CRH ))
#define        GPIOB_IDR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_IDR ))
#define        GPIOB_ODR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_ODR ))
#define        GPIOB_BSRR                      *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_BSRR))
#define        GPIOB_BRR                       *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_BRR ))
#define        GPIOB_LCKR                      *((volatile u32*)(GPIOB_BASE_ADDRESS + GPIOX_LCKR))


/*            GPIO Port C  Base Address                 */
#define        GPIOC_BASE_ADDRESS               (0x40011000)
/*       GPIO Port C  Registers definitions             */
#define        GPIOC_CRL                        *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_CRL ))
#define        GPIOC_CRH                        *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_CRH ))
#define        GPIOC_IDR                        *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_IDR ))
#define        GPIOC_ODR                        *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_ODR ))
#define        GPIOC_BSRR                       *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_BSRR))
#define        GPIOC_BRR                        *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_BRR ))
#define        GPIOC_LCKR                       *((volatile u32*)(GPIOC_BASE_ADDRESS + GPIOX_LCKR))

#endif /** the end of GPIO_PRIVATE_H_*/