/*
 * EXTI_prog.c
 *
 *  Created on: Nov 25, 2022
 *      Author: esraa
 */

/******************************************************************************
*                              Libraries  directives                 	      *
******************************************************************************/

#include"errorstate.h"
#include"stdtypes.h"


#include"EXTI_config.h"
#include"EXTI_priv.h"
//#include"EXTI_init.h"    ????

/******************************************************************************
*                    functions implementation                                 *
******************************************************************************/


ES_t EXTI0_enuminit(u8 copy_u8sate){
#if copy_u8sate==enable ||copy_u8sate==disable
	switch(copy_u8sate){
	case enable:
		GICR|=(masking_bit<<INT0);
		break;
	case disable:
		GICR&=~(clearing_bit<<INT0);
		break;

	}
#else
	return ES_OUT_OF_RANGE;
#endif
	return ES_OK;
}



ES_t EXTI1_enuminit(u8 copy_u8sate){
#if copy_u8sate==enable ||copy_u8sate==disable
	switch(copy_u8sate){
	case enable:
		GICR|=(masking_bit<<INT1);
		break;
	case disable:
		GICR&=~(clearing_bit<<INT1);
		break;

	}
#else
	return ES_OUT_OF_RANGE;
#endif
	return ES_OK;
}


ES_t EXTI2_enuminit(u8 copy_u8sate){
#if copy_u8sate==enable ||copy_u8sate==disable
	switch(copy_u8sate){
	case enable:
		GICR|=(masking_bit<<INT2);
		break;
	case disable:
		GICR&=~(clearing_bit<<INT2);
		break;

	}
#else
	return ES_OUT_OF_RANGE;
#endif
	return ES_OK;
}


ES_t EXTI0_enumSenceContrl(u8 copy_u8edge){
#if copy_u8edge==any_change ||copy_u8edge==rising_edge||copy_u8edge==falling_edge||copy_u8edge==low
	switch(copy_u8edge){
	case rising_edge:
		MCUCR|=(masking_bit<<ISC00);
		MCUCR|=(masking_bit<<ISC01);
		break;
	case falling_edge:
		MCUCR|=(masking_bit<<ISC01);
		break;
	case low:
		MCUCR=0;
		break;
	case any_change:
		MCUCR|=(masking_bit<<ISC00);
		break;
	}
#else
	return ES_OUT_OF_RANGE;
	#endif
		return ES_OK;
}


ES_t EXTI1_enumSenceContrl(u8 copy_u8edge){
#if copy_u8edge==any_change ||copy_u8edge==rising_edge||copy_u8edge==falling_edge||copy_u8edge==low
	switch(copy_u8edge){
	case rising_edge:
		MCUCR|=(masking_bit<<ISC11);
		MCUCR|=(masking_bit<<ISC10);
		break;
	case falling_edge:
		MCUCR|=(masking_bit<<ISC11);
		break;
	case low:
		MCUCR=0;
		break;
	case any_change:
		MCUCR|=(masking_bit<<ISC10);
		break;
	}
#else
	return ES_OUT_OF_RANGE;
	#endif
		return ES_OK;
}



ES_t EXTI2_enumSenceContrl(u8 copy_u8edge){
#if copy_u8edge==rising_edge||copy_u8edge==falling_edge
	switch(copy_u8edge){
	case rising_edge:
		MCUCSR|=(masking_bit<<ISC2);
		break;
	case falling_edge:
			MCUCSR&=~(masking_bit<<ISC2);
			break;
	}
#else
	return ES_OUT_OF_RANGE;
	#endif
		return ES_OK;
}

EXTI_enumGlobalINT(u8 copy_u8sate){
#if copy_u8sate==enable ||copy_u8sate==disable
	switch(copy_u8sate){
	case enable:
		SREG|=(masking_bit<<I);
		break;
	case disable:
		SREG|=(clearing_bit<<I);
		break;

	}
#else
	return ES_OUT_OF_RANGE;
#endif
	return ES_OK;
}
static volatile void (*globalpfunc) (void)=NULL;

ES_t EXTI0_callBack(void (* copy_pfunAppfun)(void)){
	if(copy_pfunAppfun!=NULL)
	globalpfunc=copy_pfunAppfun;
}


ISR(INT0_VECTOR){
	if(globalpfunc!=NULL)
	globalpfunc();
}

