/*
 * Buzzer.c
 *
 *  Created on: Jan 26, 2019
 *      Author: ahmed
 */

#include "../MCAL/DIO.h"
#include "Buzzer.h"

void Buzzer_init(void)
{
	SET_BIT(BUZZER_DIR,BUZZER_PIN);
}
