/*
 * LED_int.h
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "../../MCAL/DIO/errorstate.h"
#include"../../MCAL/DIO/stdtypes.h"

ES_t LED_init(void);
ES_t LED_enuON(u8 copy_port,u8 copy_pin);
ES_t LED_enuOFF(u8 copy_port,u8 copy_pin);
ES_t LED_enuTOG(u8 copy_port,u8 copy_pin);


#endif /* LED_INT_H_ */
