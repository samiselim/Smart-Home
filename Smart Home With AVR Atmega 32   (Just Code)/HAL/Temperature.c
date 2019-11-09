/*
 * Temperature.c
 *
 *  Created on: Nov 30, 2018
 *      Author: ahmed
 */
#include "../MCAL/ADC.h"
#include "Temperature.h"

void 	Temperature_init(void)
	{
		ADC_init();
	}

uint8	Temperature_Get_Value(void)
	{
		long Tempsensor = 0;

		Tempsensor = ADC_read(TEMPERATURE_PIN);
		Tempsensor *=500;
		Tempsensor /=1023;

		return (uint8)Tempsensor;
	}
