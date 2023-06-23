/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */

#include"stdtypes.h"

#include"MCAL/DIO/DIO_Init.h"

#include"UART_init.h"

#define F_CPU 8000000UL
int main()
{
	//Rx pin->D0 --->input
	//TX pin->D1 --->output
	DIO_enuSetPinDIR(DIO_u8PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_enuSetPinDIR(DIO_u8PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

	DIO_enuSetPinDIR(DIO_u8PORTA,DIO_PIN0,DIO_PIN_OUTPUT);

	u8 local_u8Data=0;
	UART_enuInit();
	USART_enuSendString("to turn led press A, to turn it off press B\r\n");

	while(1)
	{
		USART_SyncBlockingReceive(&local_u8Data);
		if(local_u8Data=='A'||local_u8Data=='a')
		{
			DIO_enuSetPinVAL(DIO_u8PORTA,DIO_PIN0,DIO_PIN_HIGH);
		}
		else
		{
			DIO_enuSetPinVAL(DIO_u8PORTA,DIO_PIN0,DIO_PIN_LOW);
		}
	}


}
