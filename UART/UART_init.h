/*
 * UART_init.h
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_

#include"stdtypes.h"
#include"errorstate.h"

ES_t UART_enuInit();
ES_t UART_enuSend(u8 copy_u8Data);
ES_t USART_Receive( u8 *copy_u8Dtata);
#endif /* UART_INIT_H_ */
