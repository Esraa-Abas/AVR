/*
 * lm35_prog.c
 *
 *  Created on: Dec 7, 2022
 *      Author: esraa
 */

#include "../errorstate.h"
#include "../stdtypes.h"

#include "../MCAL/DIO/DIO_Init.h"

#include"../MCAL/ADC/ADC_init.h"

//#include "LCD_priv.h"
#include "lm35_config.h"
//#include "LM35_init.h"


ES_t enuLM35_init(){
	//ADC init;
	ADC_enuInit();
	ADC_enuSelectChannel(0);
	ADC_enuEnableTriggeringMode();
	ADC_enuTriggeringSource(FREE_RUNNING);

	//ADC pin init
	DIO_enuSetPinDIR(LM53_PORT,LM35_PIN,DIO_u8INPUT);
	ADC_enuStartConversion();
}

ES_t LM35_enuRead(u16 *COPY_u16TEMP){

	ADC_enuPollingSys();

	u8 Local_u16AnalogValue = 0;
	//u16 Local_u16Temperature = 0;
	ADC_enuReadHigh(&Local_u16AnalogValue);
	*COPY_u16TEMP = ((u8)Local_u16AnalogValue*150*5)/(1023*1.5);
	//return Local_u16Temperature;
}
