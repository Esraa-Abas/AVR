/*
 * SSD_int.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef SSD_INT_H_
#define SSD_INT_H_

#include "../MCAL/DIO/errorstate.h"
#include "../MCAL/DIO/stdTypes.h"


ES_t seg_enuinit(void);
ES_t seg_enudisplaynumber(u8 copy_number);
ES_t seg_enuclear(void);
ES_t seg_enumenablecommon(void);
ES_t seg_enumdisablecommon(void);
ES_t seg_enumenabledot(void);
ES_t seg_enumdisabledot(void);

#endif /* SSD_INT_H_ */
