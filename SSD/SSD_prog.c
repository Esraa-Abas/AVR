/*
 * SSD_prog.c
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */



#include "../MCAL/DIO/errorstate.h"
#include "../MCAL/DIO/stdTypes.h"

#include "../MCAL/DIO/DIO_Init.h"

#include "SSD_int.h"
#include "SSD_priv.h"
#include "SSD_config.h"


ES_t seg_enuinit(void){
	ES_t local_enustate=ES_OK;
	local_enustate=DIO_enuSetPinDIR(seg_portA,seg_pinA,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portB,seg_pinB,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portC,seg_pinC,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portD,seg_pinD,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portE,seg_pinE,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portF,seg_pinF,DIO_PINOUTPUT);
	local_enustate=DIO_enuSetPinDIR(seg_portG,seg_pinG,DIO_PINOUTPUT);


	#if cmnpin<=DIO_PIN7&&cmnport<=DIO_u8PORTD
	DIO_enuSetPinDIR(cmnport,cmnpin,DIO_PINOUTPUT);
	#elif cmnpin==not_connected||cmnport==not_connected
	#else
	#error "wrong selection"
	#endif

	#if dotpin<=DIO_PIN7&&dotport<=DIO_u8PORTD
	DIO_enuSetPinDIR(dotport,dotpin,DIO_PINOUTPUT);
	#elif dotpin==not_connected&&dotport==not_connected
	#else
	#error "wrong selection"
	#endif

	return local_enustate;
}
ES_t seg_enudisplaynumber(u8 copy_number){
	ES_t local_enustate;
	#if connection_type == cmn_cathode
	local_enustate=DIO_enuSetPinVAL(seg_portA,seg_pinA,(seg[copy_number]>>0)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portB,seg_pinB,(seg[copy_number]>>1)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portC,seg_pinC,(seg[copy_number]>>2)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portD,seg_pinD,(seg[copy_number]>>3)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portE,seg_pinE,(seg[copy_number]>>4)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portF,seg_pinF,(seg[copy_number]>>5)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portG,seg_pinG,(seg[copy_number]>>6)&1);
	#elif connection_type==cmn_anode
	local_enustate=DIO_enuSetPinVAL(seg_portA,seg_pinA,!(seg[copy_number]>>0)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portB,seg_pinB,!(seg[copy_number]>>1)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portC,seg_pinC,!(seg[copy_number]>>2)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portD,seg_pinD,!(seg[copy_number]>>3)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portE,seg_pinE,!(seg[copy_number]>>4)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portF,seg_pinF,!(seg[copy_number]>>5)&1);
	local_enustate=DIO_enuSetPinVAL(seg_portG,seg_pinG,!(seg[copy_number]>>6)&1);

	#error "SEG type has a wrong selection"
	#endif

	return local_enustate;
}
ES_t seg_enuclear(void){
	#if connection_type==cmn_cathode
	DIO_enuSetPinVAL(seg_portA,seg_pinA,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portB,seg_pinB,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portC,seg_pinC,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portD,seg_pinD,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portE,seg_pinE,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portF,seg_pinF,DIO_PIN_HIGH);
	DIO_enuSetPinVAL(seg_portG,seg_pinG,DIO_PIN_HIGH);

#elif connection_type==cmn_anode
		DIO_enuSetPinVAL(seg_portA,seg_pinA,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portB,seg_pinB,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portC,seg_pinC,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portD,seg_pinD,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portE,seg_pinE,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portF,seg_pinF,DIO_PIN_LOW);
		DIO_enuSetPinVAL(seg_portG,seg_pinG,DIO_PIN_LOW);
#endif
	return ES_OK;
}
ES_t seg_enumenablecommon(void){

	#if cmnport<=DIO_u8PORTD &&cmnpin<=DIO_PIN7
	#if connection_type==cmn_anode
	DIO_enuSetPinVAL(cmnport,cmnpin,DIO_PIN_HIGH);
	#elif connection_type==cmn_cathode
	DIO_enuSetPinVAL(cmnport,cmnpin,DIO_PIN_LOW);
	#else
	#error "segment type wrong selection"
	#endif
	#elif connection_type==not_connected
	#else
	//#error "common PIN has wrong selection"
	#endif
	return ES_OK;
}
ES_t seg_enumdisablecommon(void){
	#if cmnport<=DIO_u8PORTD &&cmnpin<=DIO_PIN7
	#if connection_type==cmn_anode
	DIO_enuSetPinVAL(cmnport,cmnpin,DIO_PIN_LOW);
	#elif connection_type==cmn_cathode
	DIO_enuSetPinVAL(cmnport,cmnpin,DIO_PIN_HIGH);
	#else
	//#error "segment type wrong selection"
	#endif
	#elif connection_type==not_connected
	#else
	//#error "Common Pin has a wrong selection"
	#endif
	return ES_OK;

}
ES_t seg_enumenabledot(void){
	#if dotport<=DIO_u8PORTD &&dotpin<=DIO_PIN7
	#if connection_type==cmn_cathode
	DIO_enuSetPinVAL(dotport,dotpin,DIO_PIN_HIGH);
	#elif connection_type==cmn_anode
	DIO_enuSetPinVAL(dotport,dotpin,DIO_PIN_LOW);
	#else
	//#error "segment type wrong selection"
	#endif
	#elif connection_type==not_connected
	#else
	//#error "Common Pin has a wrong selection"
	#endif

	return ES_OK;
}
ES_t seg_enumdisabledot(void){
	#if dotport<=DIO_u8PORTD &&dotpin<=DIO_PIN7
	#if connection_type==cmn_anode
	DIO_enuSetPinVAL(dotport,dotpin,DIO_PIN_HIGH);
	#elif connection_type==cmn_cathode
	DIO_enuSetPinVAL(dotport,dotpin,DIO_PIN_LOW);
	#else
	//#error "segment type wrong selection"
	#endif
	#elif connection_type==not_connected
	#else
	//#error "Common Pin has a wrong selection"
	#endif

	return ES_OK;

}

