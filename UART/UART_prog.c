/*
 * UART_prog.c
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */
#include "stdtypes.h"

#include "UART_init.h"
#include "UART_priv.h"
#include "UART_config.h"




ES_t UART_enuInit(){
	UCSRB|=(LOGICAL_ONE<<RXEN) | (LOGICAL_ONE<<TXEN);

	u8 local_Help=0;
	/*mode*/
#if MODE==ASYNC
	local_Help|=(LOGICAL_ZERO<<UMSEL);
#endif

	/*parity*/
#if PARITY==DISABLED
	local_Help|=(LOGICAL_ZERO<<UPM0);
	local_Help|=(LOGICAL_ZERO<<UPM1);
#elif PARITY==Even_Parity
	local_Help|=(LOGICAL_ZERO<<UPM0);
	local_Help|=(LOGICAL_ONE<<UPM1);
#elif PARITY==DISABLED
	local_Help|=(LOGICAL_ONE<<UPM0);
	local_Help|=(LOGICAL_ONE<<UPM1);
#endif

	/*stop bit*/
#if STOP_BIT==one_bit
	local_Help|=(LOGICAL_ZERO<<USBS);
#elif STOP_BIT==two_bit
	local_Help|=(LOGICAL_ONE<<UPM0);
#endif

	/*data size*/
#if DATA_SIZE==eight_bits
	local_Help|=(LOGICAL_ONE<<UCSZ0);
	local_Help|=(LOGICAL_ONE<<UCSZ1);
	UCSRB|=(LOGICAL_ZERO<<UCSZ2);
#endif

	/*sunc clk polarity */
#if MODE==SYNC&&CLOCK_PARITY==rising_falling
	local_Help|=(LOGICAL_ZERO<<UCPOL);
#elif CLOCK_PARITY==falling_rising
	local_Help|=(LOGICAL_ONE<<UCPOL);
#endif

#if F_SYS==freq_8m
#if BUAD_RATE==rate_9600_pbs
	UBRRL=51;
#elif BUAD_RATE==rate_250k_pbs
	UBRRL=1;
#endif
#elif F_SYS==freq_1m
#if BUAD_RATE==rate_9600_pbs
	UBRRL=6;

#endif
#endif
	UCSRC=local_Help;

}

ES_t UART_enuSend(u8 copy_u8Data){
	while ( !( UCSRA & (1<<UDRE))); //( 1 & (1>>UDRE))==0
	UDR = copy_u8Data;
}

ES_t USART_Receive( u8 *copy_u8Dtata)
{
while ( !(UCSRA & (1<<RXC)));
*copy_u8Dtata=UDR;
}

ES_t USART_enuSendString(u8 *copy_u8StringData){
	while(*copy_u8StringData != NULL){
		UART_enuSend(*copy_u8StringData);
			*copy_u8StringData++;
		}
}



