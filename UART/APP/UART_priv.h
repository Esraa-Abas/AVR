/*
 * UART_priv.h
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_



typedef enum
{
	UART_RX_INT,
	UART_UDR_INT,
	UART_TX_INT
}UART_INT;


/******************************************************************************
* !comment : UART Registers Addresses Definition.  			         	      *
******************************************************************************/
#define UDR       *((volatile u8 *) 0x2C)
#define UCSRA     *((volatile u8 *) 0x2B)
#define UCSRB     *((volatile u8 *) 0x2A)
#define UBRRL     *((volatile u8 *) 0x29)
#define UCSRC     *((volatile u8 *) 0x40)
#define UBRRH     *((volatile u8 *) 0x40)



/******************************************************************************
* !comment : UART Registers Addresses Definition.  			         	      *
******************************************************************************/
#define UDR       *((volatile u8 *) 0x2C)
#define UCSRA     *((volatile u8 *) 0x2B)
#define UCSRB     *((volatile u8 *) 0x2A)
#define UBRRL     *((volatile u8 *) 0x29)
#define UCSRC     *((volatile u8 *) 0x40)
#define UBRRH     *((volatile u8 *) 0x40)


/******************************************************************************
* !comment : Control and Status Register-A (UCSRA) PINS Definition.           *
******************************************************************************/
#define MPCM     (u8)0
#define U2X      (u8)1
#define PE       (u8)2
#define DOR      (u8)3
#define FE       (u8)4
#define UDRE     (u8)5
#define TXC      (u8)6
#define RXC      (u8)7

/******************************************************************************
* !comment : Control and Status Register-B (UCSRB) PINS Definition.       	  *
******************************************************************************/
#define TXB8     (u8)0
#define RXB8     (u8)1
#define UCSZ2    (u8)2
#define TXEN     (u8)3
#define RXEN     (u8)4
#define UDRIE    (u8)5
#define TXCIE    (u8)6
#define RXCIE    (u8)7

/******************************************************************************
* !comment : Control and Status Register-C (UCSRC) PINS Definition.       	  *
******************************************************************************/
#define UCPOL    (u8)0
#define UCSZ0    (u8)1
#define UCSZ1    (u8)2
#define USBS     (u8)3
#define UPM0     (u8)4
#define UPM1     (u8)5
#define UMSEL    (u8)6
#define URSEL    (u8)7

/******************************************************************************
* !comment : Baud Rate Registers (UBRRL) and (UBRRH) PINS Definition.         *
******************************************************************************/
#define URSEL2   (u8)15


/******************************************************************************
* !comment : UART UCSRC Register options.  			                	      *
******************************************************************************/
/* synchronization options */
#define SYNC           1
#define ASYNC          0

/* parity options */
#define Disabled       0
#define Even_Parity    2
#define ODD_Parity     3

/* stop bit options */
#define one_bit        0
#define two_bit        1

/*data size*/
#define five_bits      0
#define six_bits       1
#define seven_bits     2
#define eight_bits     3
#define nine_bits      7

/* clock parity */
#define rising_falling 0
#define falling_rising 1


/******************************************************************************
* !comment : buad rate options.                 			         	      *
******************************************************************************/
/*speed*/
#define single_speed        0
#define double_speed        1

/*f_os */
#define freq_8m             0
#define freq_1m             1

/* buadreat*/
#define rate_9600_pbs       0
#define rate_250k_pbs       1


//#define SENDDATA(char copy_u8Data)          while ( !( UCSRA & (1<<UDRE)));\
//	                        UDR = copy_u8Data

#define LOGICAL_ONE         1
#define LOGICAL_ZERO        0

#define NULL                ((void *)0)

#endif /* UART_PRIV_H_ */
