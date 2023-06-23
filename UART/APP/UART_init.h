/*
 * UART_init.h
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_
/*
 * version:1.0
 * in this version, there are issues when clearing the TCX flag after sending complete
 * it works well when you do not clear, otherwise it does not.
 * so i commented this issue in all send functions until i figure out why
 */
#include"stdtypes.h"
#include"errorstate.h"


typedef enum
{
	UART_RX_INTERRUPT=0,
	UART_UDR_INTERRUPT=1,
	UART_TX_INTERRUPT=2
}UART_INTERRUPT;

ES_t UART_enuInit();
ES_t UART_enuSyncSendBlocking(u8 copy_u8Data);
ES_t UART_enuAsyncSend(u8 copy_u8Data);
ES_t USART_SyncBlockingReceive( u8 *copy_u8Dtata);
ES_t USART_AsyncReceive( u8 *copy_u8Dtata);
ES_t UART_enuSendByteSyncBlocking(u8 copy_u8Data);
ES_t UART_enuSendByteSyncNonBlocking(u8 copy_u8Data);
ES_t USART_enuSendString(u8 *copy_u8StringData);
void USRAT_voidRX_InterruptEnable();
void USRAT_voidRX_InterruptDisable();
void USRAT_voidTX_InterruptEnable();
void USRAT_voidTX_InterruptDisable();
void USRAT_voidUDRIE_InterruptEnable();
void USRAT_voidUDRIE_InterruptDisable();
ES_t UART_enuCallBack(u8 INT_Source,void(*Copy_FuncPtr)(void));
#endif /* UART_INIT_H_ */
