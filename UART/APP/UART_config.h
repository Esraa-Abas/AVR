/*
 * UART_config.h
 *
 *  Created on: Jan 26, 2023
 *      Author: esraa
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_




#define MODE               ASYNC
#define PARITY             Disabled
#define STOP_BIT           one_bit
#define DATA_SIZE          eight_bits
#define CLOCK_PARITY       rising_falling


#define SPEED              single_speed
#define F_SYS              freq_8m
#define BUAD_RATE          rate_9600_pbs


#define TIME_OUT           10000

#endif /* UART_CONFIG_H_ */
