/*
 * main.c
 *
 *  Created on: Dec 18, 2022
 *      Author: esraa
 */

#include"errorstate.h"
#include"stdtypes.h"

//#include"MCAL/ADC_/ADC_init.h"
#include"MCAL/DIO/DIO_Init.h"
#include"HAL/lm35_init.h"
int main(){
	enuLM35_init();
	u16 temp;

//	if(temp)
	while(1){
		LM35_enuRead(&temp);

		DIO_enuSetPortDIR(DIO_u8PORTD,temp);
		DIO_enuSetPortDIR(DIO_u8PORTC,(temp>>8)&0xFF);
	}
}
