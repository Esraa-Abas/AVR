/*
 * UART_prog.c
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */
#include "stdtypes.h"
#include "errorstate.h"

//#include "UART_init.h"
#include "UART_priv.h"
#include "UART_config.h"


static void (*FuncPtr[3]) (void)={NULL,NULL,NULL};

ES_t UART_enuInit()
{
	/*
	 * UCSRB REG configuration
	 */
	//enable sending/receiving
	UCSRB|=(LOGICAL_ONE<<RXEN) | (LOGICAL_ONE<<TXEN);
/*
 * UCSRC REG configuration
 */
	u8 local_Help=0;
	/*mode*/
#if MODE==SYNC
	local_Help|=(LOGICAL_ONE<<UMSEL);
#endif

	/*parity*/
#if PARITY==DISABLED
	local_Help&=~(LOGICAL_ONE<<UPM0);
	local_Help&=~(LOGICAL_ONE<<UPM1);
#elif PARITY==Even_Parity
	local_Help&=~(LOGICAL_ONE<<UPM0);
	local_Help|=(LOGICAL_ONE<<UPM1);
#elif PARITY==DISABLED
	local_Help|=(LOGICAL_ONE<<UPM0);
	local_Help|=(LOGICAL_ONE<<UPM1);
#endif

	/*stop bit*/
#if STOP_BIT==one_bit
	local_Help&=~(LOGICAL_ONE<<USBS);
#elif STOP_BIT==two_bit
	local_Help|=(LOGICAL_ONE<<UPM0);
#endif

	/*data size*/
#if DATA_SIZE==eight_bits
	local_Help|=(LOGICAL_ONE<<UCSZ0);
	local_Help|=(LOGICAL_ONE<<UCSZ1);
	UCSRB&=~(LOGICAL_ONE<<UCSZ2);
#endif

	/*sunc clk polarity */
#if MODE==SYNC&&CLOCK_PARITY==rising_falling
	local_Help&=~(LOGICAL_ONE<<UCPOL);
#elif MODE==SYNC&&CLOCK_PARITY==falling_rising
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

ES_t UART_enuSyncSendBlocking(u8 copy_u8Data)
{
	while ( !( 1 & (UCSRA>>UDRE)));
	UDR = copy_u8Data;
}

ES_t UART_enuAsyncSend(u8 copy_u8Data)
{
	if(((UCSRA>>5)& 1)==1)
	{
	UDR = copy_u8Data;
	}

}

ES_t USART_SyncBlockingReceive( u8 *copy_u8Dtata) //sync
{
	while ( !( 1 & (UCSRA>>RXC)));
*copy_u8Dtata=UDR;
}


ES_t USART_AsyncReceive( u8 *copy_u8Dtata)
{
	if(((UCSRA>>7)& 1)==1) //??
	{
		*copy_u8Dtata=UDR;
	}

}

ES_t UART_enuSendByteSyncBlocking(u8 copy_u8Data)
{
	//making sure that buffer empty
	while ( !( 1 & (UCSRA>>UDRE)));
	//send data
	UDR = copy_u8Data;
	//making sure that data was sent
	//while ( !( 1 & (UCSRA>>UDRE)));
	//UCSRA|=(LOGICAL_ONE<<TXC);
}


ES_t UART_enuSendByteSyncNonBlocking(u8 copy_u8Data)
{
	u32 Local_u8Counter=0;
	while ( !( 1 & (UCSRA>>UDRE)))
	{
		Local_u8Counter++;
		if(Local_u8Counter==TIME_OUT)
		{
			break;
		}
	}
	//if the flag was cleared before the time out--> it is ok, send data
	//else, this func will do nothing
	if(Local_u8Counter!=TIME_OUT)
	{
		//send data
		UDR = copy_u8Data;

//		Local_u8Counter=0;
//		//wait until data send, or time out
//		while ( !( 1 & (UCSRA>>UDRE)))
//		{
//			Local_u8Counter++;
//			if(Local_u8Counter==TIME_OUT)
//			{
//				break;
//			}
//		}
//		UCSRA|=(LOGICAL_ONE<<TXC);

	}
}

//string is passed using address of its array, so receive it in pointer
//sync
ES_t USART_enuSendString(u8 *copy_u8StringData)
{
	//accessing each character and check if it is null( end of string )
	while(*copy_u8StringData > 0)
	{
		UART_enuSendByteSyncBlocking(*copy_u8StringData++);
	}
}

void USRAT_voidRX_InterruptEnable()
{
	UCSRB|=(LOGICAL_ONE<<RXCIE);
}
void USRAT_voidRX_InterruptDisable()
{
	UCSRB&=~(LOGICAL_ONE<<RXCIE);
}
void USRAT_voidTX_InterruptEnable()
{
	UCSRB|=(LOGICAL_ONE<<TXCIE);
}
void USRAT_voidTX_InterruptDisable()
{
	UCSRB&=~(LOGICAL_ONE<<TXCIE);
}
void USRAT_voidUDRIE_InterruptEnable()
{
	UCSRB|=(LOGICAL_ONE<<UDRIE);
}
void USRAT_voidUDRIE_InterruptDisable()
{
	UCSRB&=~(LOGICAL_ONE<<UDRIE);
}

//three interrupt sources
ES_t UART_enuCallBack(u8 INT_Source,void(*Copy_FuncPtr)(void))
{

	if(Copy_FuncPtr!=NULL&&INT_Source<=UART_TX_INT)
	{
		FuncPtr[INT_Source]= Copy_FuncPtr;
	}
}


void __vector__13(void) __attribute__((signal));
void __vector13__(void)
{
	if(FuncPtr[UART_RX_INT]!=NULL)
	{
		FuncPtr[UART_RX_INT]();
	}
}


void __vector__14(void) __attribute__((signal));
void __vector14__(void)
{
	if(FuncPtr[UART_UDR_INT]!=NULL)
	{
		FuncPtr[UART_UDR_INT]();
	}
}

void __vector__15(void) __attribute__((signal));
void __vector15__(void)
{
	if(FuncPtr[UART_TX_INT]!=NULL)
	{
		FuncPtr[UART_TX_INT]();
	}
}
