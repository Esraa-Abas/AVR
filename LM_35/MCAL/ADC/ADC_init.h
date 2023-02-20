/*
 * ADC_init.h
 *
 *  Created on: Dec 24, 2022
 *      Author: esraa
 */

#ifndef MCAL_ADC__ADC_INIT_H_
#define MCAL_ADC__ADC_INIT_H_

#include"../../errorstate.h"
#include"../../stdtypes.h"

#define SREG       *((volatile u8  *) 0x5F)

/******************************************************************************
* !comment : ADC Channels options Definition.  			         	          *
******************************************************************************/
#define CH_A0     0
#define CH_A1     1
#define CH_A2     2
#define CH_A3     3
#define CH_A4     4
#define CH_A5     5
#define CH_A6     6
#define CH_A7     7

/******************************************************************************
* !comment : ADC Trigerring Sources options.  	         		   	          *
******************************************************************************/
#define FREE_RUNNING 					0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRUPT_REQUEST0		2
#define TIMER0_COMPARE_MATCH			3
#define TIMER0_OVERFLOW					4
#define TIMER_COMPARE_MATCH_B			5
#define TIMER1_OVERFLOW					6
#define TIMER1_CAPTURE_EVENT			7


/******************************************************************************
* Description 	: ADC Initialization Function, it uses the configurations in  *
*                 config.h, to set ADC										  *
* Parameters  	: none   		                                    	 	  *
* Return type 	:                                            		       	  *
******************************************************************************/
ES_t ADC_enuInit(void);

/******************************************************************************
* Description 	: ADC Read Value Function .									  *
* Parameters  	: pass by reference u16 variable     	        	    	  *
* Return type 	:                                                         	  *
*******************************************************************************
* Pre_condition : This function must be used after ADC_enuInit func &
*                 ADC_enuSelectChannel func  & ADC_enuStartConversion.
*                 (ADC_enuPollingSys | ADC_enuEnableINT)      *
*                                                                    *
******************************************************************************/
ES_t ADC_enuRead(u16 *copy_u16read);

/******************************************************************************
* Description 	: ADC polling on ADC flag until conversion is finished.		  *
* Parameters  	: none								          				  *
* Return type 	:		                                                      *
*******************************************************************************
* Pre_condition : This function must be used after ADC Initialization         *
*				  Function & ADC_enuSelectChannel func &ADC_enuStartConversion*                                                   *
******************************************************************************/
ES_t ADC_enuPollingSys(void);

ES_t ADC_enuSelectChannel(u8 copy_u8channel);

ES_t ADC_enuEnableTriggeringMode(void);

ES_t ADC_enuDisableTriggeringMode(void);

ES_t ADC_enuTriggeringSource(u8 copy_u8triggering_source);

ES_t ADC_enuEnableINT(void);

ES_t ADC_enuDisableINT(void);

ES_t ADC_enuEnableADC(void);
ES_t ADC_enuDisableADC(void);

ES_t ADC_CallBack(void (*PFuncAppFunc)(void *), void * Pvoid_AppPara);

ES_t ADC_enuReadHigh(u8 *copy_u8read);

ES_t ADC_enuStartConversion(void);

#endif /* MCAL_ADC__ADC_INIT_H_ */
