/*
 * main.c
 *
 *  Created on: Dec 2, 2022
 *      Author: esraa
 */
#include"util/delay.h"
//#include <avr/io.h>
#include <avr/interrupt.h>

#include"errorstate.h"
#include "stdtypes.h"

#include"timer_init.h"
#include"MCAL/DIO/DIO_Init.h"

int main(){

	Timer0_enuInit();
	DIO_enuSetPinDIR(DIO_u8PORTB,DIO_PIN3,DIO_PINOUTPUT);

	while(1){
		for(int i=0;i<=255;){
				i+=30;
				TIMER0_enuGeneratePWM(i);
				//delay to notice the change in speed on proteus,or use timer2
				_delay_ms(3000);
			}
	}


return 0;
}

