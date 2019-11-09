/*
 * Temperature.h
 *
 *  Created on: Nov 30, 2018
 *      Author: ahmed
 */

#ifndef HAL_TEMPERATURE_H_
#define HAL_TEMPERATURE_H_

#include "../ServiceLayer/PLATFORM_TYPES.h"

#define TEMPERATURE_PIN		(5)

void 	Temperature_init(void);
uint8	Temperature_Get_Value(void);

#endif /* HAL_TEMPERATURE_H_ */
