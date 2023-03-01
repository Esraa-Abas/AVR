/*
 * LED.c
 */

#include"../../MCAL/DIO/stdtypes.h"
#include"../../MCAL/DIO/errorstate.h"


#include"../../MCAL/DIO/DIO_Init.h"

#include"LED_priv.h"
#include"LED_config.h"
#include"LED_int.h"

ES_t LED_init(void){
	DIO_enuSetPinDIR(LED_PORT,LED_PIN,DIO_PINOUTPUT);
//#if LED_STATE==LED_ON
//	DIO_enuSetPinVAL(LED_PORT,LED_PIN,DIO_PIN_HIGH);
//#elif LED_STATE==LED_Off
//	DIO_enuSetPinVAL(LED_PORT,LED_PIN,DIO_PIN_LOW);
//#endif
}

ES_t LED_enuON(u8 copy_port,u8 copy_pin){
	DIO_enuSetPinVAL(copy_port,copy_pin,DIO_PIN_HIGH);
}

ES_t LED_enuOFF(u8 copy_port,u8 copy_pin){
	DIO_enuSetPinVAL(copy_port,copy_pin,DIO_PIN_LOW);
}

ES_t LED_enuTOG(u8 copy_port,u8 copy_pin){
	DIO_enuTogPin(copy_port,copy_pin);
}
