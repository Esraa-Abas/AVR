/*
 * ADC_prog.c
 *
 *  Created on: Dec 24, 2022
 *      Author: esraa
 */


#include <avr/interrupt.h>
#include "../../LIB/EXTI_stdtypes.h"
#include "../../LIB/errorstate.h"

#include"ADC_priv.h"
#include"ADC_config.h"


ES_t ADC_enuInit(void){

		#if ADC_VoltageSource == AREF

			/* Select Verf = AREF */
	        ADMUX &=!(masking_bit<<REFS0); ADMUX &=!(masking_bit<<REFS1);

		#elif ADC_VoltageSource == AVCC

			/* Select Verf = AVCC */
	        ADMUX|=(masking_bit<<REFS0);	ADMUX&=!(masking_bit<<REFS1);

		#elif VOLTAGE_REF == INTERNAL

			/* Select Verf = INTERNAL */
	        ADMUX|=(masking_bit<<REFS0);	ADMUX|=(masking_bit<<REFS1);

		#else
			#error("You Chose Wrong Voltage Reference Selections for ADC!")
		#endif

		#if ADC_ReadingMode == RIGHT_ADJUST

			/* select right adjust result */
	        ADMUX&=!(masking_bit<<ADLAR);

		#elif ADC_ReadingMode == LEFT_ADJUST

			/* select left adjust result */
	        ADMUX|=(masking_bit<<ADLAR);

		#else
			#error("You Chose Wrong ADC Adjust Result!")
		#endif

		#if ADC_AUTO_TRIGGERING == AUTO_TRIGGER_ENABLE

			/* Enable of trigger */
	        ADCSRA|=(masking_bit<<ADATE);

	        if(AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR){
	        			SFIOR|=(masking_bit<<ADTS0);
	        		}
	        	else if(AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQUEST0){
	        		SFIOR|=(masking_bit<<ADTS1);
	        	}
	        	else if(AUTO_TRIGGER_SOURCE == TIMER0_COMPARE_MATCH){
	        		SFIOR|=(masking_bit<<ADTS0);
	        		SFIOR|=(masking_bit<<ADTS1);
	        		}
	        	else if(AUTO_TRIGGER_SOURCE == TIMER0_OVERFLOW){
	        		SFIOR|=(masking_bit<<ADTS2);
	        		}
	        	else if(AUTO_TRIGGER_SOURCE == TIMER_COMPARE_MATCH_B){
	        		SFIOR|=(masking_bit<<ADTS0);
	        		SFIOR|=(masking_bit<<ADTS2);
	        		}
	        	else if(AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW){
	        		SFIOR|=(masking_bit<<ADTS1);
	        		SFIOR|=(masking_bit<<ADTS2);
	        		}
	        	else if(AUTO_TRIGGER_SOURCE == TIMER1_CAPTURE_EVENT){
	        		SFIOR|=(masking_bit<<ADTS0);
	        		SFIOR|=(masking_bit<<ADTS1);
	        		SFIOR|=(masking_bit<<ADTS2);
	        		}
		#elif ADC_AUTO_TRIGGERING == AUTO_TRIGGER_DISABLE

			/* disable of trigger & Select single conversion */
	        ADCSRA&=!(masking_bit<<ADATE);

		#else
		//	#error("You Chose Wrong ADC Auto Trigger!")    ///error? why?!
		#endif

		/* ADC interrupt disable */
		//ADC_voidInterruptDisable();

		/* ADC Prescaller */
		ADCSRA &= ADC_PRESCALER_MASK;
		ADCSRA |= ADC_PRESCALER;

#if ADC_CONVERSION==ADC_ENABLE_CONVERSION
		/* Enable ADC */
		ADCSRA|=(masking_bit<<ADEN);
#endif

}


ES_t ADC_enuRead(u16 *copy_u16read){
#if ADC_ReadingMode==LEFT_ADJUST
	*copy_u16read= (ADCL<<6);
	*copy_u16read|=(ADCH<<2);


#elif	ADC_ReadingMode==RIGHT_ADJUST
	*copy_u16read=ADCL;     //you always must read right first
	*copy_u16read|=((u16)ADCH<<8);

#endif
}

/*
 *
 * pre:
 * post: call Read function to get conversion result.
 */

ES_t ADC_enuPollingSys(){
	while(((ADCSRA>>ADIF)&1)==0);
	ADCSRA|=(masking_bit<<ADIF);
}

ES_t ADC_enuEnableADC(void){
	ADCSRA|=(masking_bit<<ADEN);
}
ES_t ADC_enuDisableADC(void){
	ADCSRA&=~(masking_bit<<ADEN);
}

ES_t ADC_enuSelectChannel(u8 copy_u8channel){

#if	ADC_channelType==SINGLE_CHANNEL_ASYNC
#if ADC_chaneelNumber==CHANNEL_0

#elif ADC_chaneelNumber==CHANNEL_1
	ADMUX|=(masking_bit<<MUX0);

#elif ADC_chaneelNumber==CHANNEL_2
	ADMUX|=(masking_bit<<MUX1);

#elif ADC_chaneelNumber==CHANNEL_3
	ADMUX|=(masking_bit<<MUX0);
	ADMUX|=(masking_bit<<MUX1);

#elif ADC_chaneelNumber==CHANNEL_4
	ADMUX|=(masking_bit<<MUX2);

#elif ADC_chaneelNumber==CHANNEL_5
	ADMUX|=(masking_bit<<MUX0);
	ADMUX|=(masking_bit<<MUX2);

#elif ADC_chaneelNumber==CHANNEL_6
	ADMUX|=(masking_bit<<MUX1);
	ADMUX|=(masking_bit<<MUX2);

#elif ADC_chaneelNumber==CHANNEL_1
	ADMUX|=(masking_bit<<MUX0);
	ADMUX|=(masking_bit<<MUX1);
	ADMUX|=(masking_bit<<MUX2);
#endif

#elif ADC_channelType==CHAIN_CHANNELS_ASYNC ////study chain!

#endif


}


ES_t ADC_enuEnableTriggeringMode(void){
	ADCSRA|=(masking_bit<<ADATE);
	//SFIOR|=(masking_bit<<ADTS1);



}

ES_t ADC_enuTriggeringSource(u8 copy_u8triggering_source){
	if(copy_u8triggering_source == ANALOG_COMPARATOR){
			SFIOR|=(masking_bit<<ADTS0);
		}
	else if(copy_u8triggering_source == EXTERNAL_INTERRUPT_REQUEST0){
		SFIOR|=(masking_bit<<ADTS1);
	}
	else if(copy_u8triggering_source == TIMER0_COMPARE_MATCH){
		SFIOR|=(masking_bit<<ADTS0);
		SFIOR|=(masking_bit<<ADTS1);
		}
	else if(copy_u8triggering_source == TIMER0_OVERFLOW){
		SFIOR|=(masking_bit<<ADTS2);
		}
	else if(copy_u8triggering_source == TIMER_COMPARE_MATCH_B){
		SFIOR|=(masking_bit<<ADTS0);
		SFIOR|=(masking_bit<<ADTS2);
		}
	else if(copy_u8triggering_source == TIMER1_OVERFLOW){
		SFIOR|=(masking_bit<<ADTS1);
		SFIOR|=(masking_bit<<ADTS2);
		}
	else if(copy_u8triggering_source == TIMER1_CAPTURE_EVENT){
		SFIOR|=(masking_bit<<ADTS0);
		SFIOR|=(masking_bit<<ADTS1);
		SFIOR|=(masking_bit<<ADTS2);
		}

}


ES_t ADC_enuDisableTriggeringMode(void){
	/* disable of trigger & Select single conversion */
    ADCSRA&=!(masking_bit<<ADATE);

}

ES_t ADC_enuEnableINT(void){
	ADCSRA|=(masking_bit<<ADIE);
}

ES_t ADC_enuDisableINT(void){
	ADCSRA&=~(masking_bit<<ADIE);
}

ES_t ADC_enuReadHigh(u8 *copy_u8read){
	*copy_u8read=ADCH;
}

ES_t ADC_enuStartConversion(void){
	ADCSRA|=(masking_bit<<ADSC);
}


/*
 *
 *
 * pre: enable ADC INiT
 *
 */
static void (*ADC_PFuncAppFunc)(void *)=NULL;
static void * ADC_Pvoid_AppPara=NULL;
ES_t ADC_CallBack(void (*copy_PFuncAppFunc)(void *), void * copy_Pvoid_AppPara){
	ADC_PFuncAppFunc=copy_PFuncAppFunc;
	ADC_Pvoid_AppPara=copy_Pvoid_AppPara;

}



ISR(ADC_VECTOR){
	if(ADC_Pvoid_AppPara!=NULL&&ADC_PFuncAppFunc!=NULL)
	ADC_PFuncAppFunc(ADC_Pvoid_AppPara);
}
