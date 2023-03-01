/*
 * EXTI_priv.h
 *
 *  Created on: Nov 25, 2022
 *      Author: esraa
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/******************************************************************************
*                   External interrupt Registers.      	      	     	      *
******************************************************************************/

#define MCUCR     *((volatile u8 *) 0x55)
#define MCUCSR    *((volatile u8 *) 0x54)
#define GICR      *((volatile u8 *) 0x5B)
#define GIFR      *((volatile u8 *) 0x5A)
#define SREG 	  *((volatile u8 *) 0x5F)
/******************************************************************************
*                    MCUCR Register Pin Definition.      	      		      *
******************************************************************************/

#define ISC00     0
#define ISC01     1
#define ISC10     2
#define ISC11     3


/******************************************************************************
*                      MCUCSR Register Pin Definition.      	      	      *
******************************************************************************/

#define ISC2      6


/******************************************************************************
*                   	GICR Register Pin Definition.       	      		  *
******************************************************************************/

#define INT2      5
#define INT0      6
#define INT1      7

/******************************************************************************
*      	                GIFR Register Pin Definition.       				  *
******************************************************************************/

#define INTF2     5
#define INTF0     6
#define INTF1     7

/******************************************************************************
*                      SREG Register Pin Definition.        	      	      *
******************************************************************************/

#define  I       7

#define clearing_bit 0
#define masking_bit  1

/******************************************************************************
*      	      	           ISR attribute.       	      					  *
******************************************************************************/

#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/******************************************************************************
*                      EXIT Interrupt Vectors Numbers.      	      		  *
******************************************************************************/

#define INT0_VECTOR     __vector_1
#define INT1_VECTOR     __vector_2
#define INT2_VECTOR     __vector_3

#endif /* EXTI_PRIV_H_ */
