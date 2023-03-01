/*
 * SSD_config.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#include "../MCAL/DIO/DIO_Init.h"

#define seg_pinA  DIO_PIN0
#define seg_portA DIO_u8PORTA

#define seg_pinB  DIO_PIN1
#define seg_portB DIO_u8PORTB

#define seg_pinC DIO_PIN2
#define seg_portC DIO_u8PORTC

#define seg_pinD DIO_PIN3
#define seg_portD DIO_u8PORTD

#define seg_pinE DIO_PIN4
#define seg_portE DIO_u8PORTD

#define seg_pinF DIO_PIN5
#define seg_portF DIO_u8PORTD

#define seg_pinG DIO_PIN6
#define seg_portG DIO_u8PORTD

#define cmnpin not_connected
#define cmnport not_connected

#define dotpin not_connected
#define dotport not_connected

#define connection_type cmn_cathode

#define cmn_cathode 8
#define cmn_anode 9
#define not_connected 10

#endif /* SSD_CONFIG_H_ */
