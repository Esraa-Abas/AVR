/*
 * EXTI_init.h
 *
 *  Created on: Nov 25, 2022
 *      Author: esraa
 */

#ifndef EXTI_INIT_H_
#define EXTI_INIT_H_

#include"errorstate.h"
#include"stdtypes.h"



#define EXTI_U8FALLINGEDGE 0
#define EXTI_U8RISINGEDGE  1
#define EXTI_U8LOW          2
#define EXTI_U8ANY_CHANGE   3

/********************************************************************************
 * Description:function to Enable/Disable interrupt 0                           *
 * Parameters: state {enable, disable}                                          *
 * Return type: {OK, NOK,   }                                                   *
 * Pre_condition:this function is called before enabling global interrupt       *
 ********************************************************************************/

ES_t EXTI0_enuminit(u8 copy_u8sate);

/********************************************************************************
 * Description:function to Enable/Disable interrupt 1                           *
 * Parameters: state {enable, disable}                                          *
 * Return type: {OK, NOK,   }                                                   *
 * Pre_condition:this function is called before enabling global interrupt        *
 ********************************************************************************/

ES_t EXTI1_enuminit(u8 copy_u8sate);


/********************************************************************************
 * Description:function to Enable/Disable interrupt 2                           *
 * Parameters: state {enable, disable}                                          *
 * Return type: {OK, NOK,   }                                                   *
 * Pre_condition:this function is called before enabling global interrupt        *
 ********************************************************************************/

ES_t EXTI2_enuminit(u8 copy_u8sate);


/********************************************************************************
 * Description:function for triggering edge                                    *
 * Parameters: triggering edge  {falling, rising, low, any_logic}              *
 * Return type: enum {OK, NOK,   }                                             *
 * Pre_condition:this function is called before enabling interrupt 0            *
 ********************************************************************************/

ES_t EXTI0_enumSenceContrl(u8 copy_u8edge);


/********************************************************************************
 * Description:function for triggering edge                                     *
 * Parameters: triggering edge  {falling, rising, low, any_logic}               *
 * Return type: enum {OK, NOK,   }                                              *
 * Pre_condition:this function is called before enabling interrupt 1            *
 ********************************************************************************/

ES_t EXTI1_enumSenceContrl(u8 copy_u8edge);


/********************************************************************************
 * Description:function for triggering edge                                    *
 * Parameters: triggering edge  {falling, rising, low, any_logic}              *
 * Return type: enum {OK, NOK,   }                                             *
 * Pre_condition:this function is called before enabling interrupt 2           *
 ********************************************************************************/

ES_t EXTI2_enumSenceContrl(u8 copy_u8edge);


/********************************************************************************
 * Description:function to enable/disable global interrupt                      *
 * Parameters: none                                                             *
 * Return type: enum {OK, NOK,   }                                              *
 * Pre_condition:this function is called after setting interrupt                *
 ********************************************************************************/
ES_t EXTI_enumGlobalINT(u8 copy_u8sate);


ES_t EXTI0_callBack(void (* copy_pfunAppfun)(void*));




#endif /* EXTI_INIT_H_ */
