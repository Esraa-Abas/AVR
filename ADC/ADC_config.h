/*
 * ADC_config.h
 *
 *  Created on: Dec 24, 2022
 *      Author: esraa
 */

#ifndef MCAL_ADC__ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_



#define ADC_PRESCALER               DIV_FACTOR_16
#define ADC_channelType             SINGLE_CHANNEL_ASYNC
#define ADC_chaneelNumber           CHANNEL_0
#define ADC_VoltageSource           AREF
#define ADC_ReadingMode             LEFT_ADJUST
#define ADC_AUTO_TRIGGERING         AUTO_TRIGGER_ENABLE
#define AUTO_TRIGGER_SOURCE         FREE_RUNNING
#define ADC_CONVERSION              ADC_ENABLE_CONVERSION


#endif /* MCAL_ADC__ADC_CONFIG_H_ */
