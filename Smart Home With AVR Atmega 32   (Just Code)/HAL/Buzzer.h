/*
 * Buzzer.h
 *
 *  Created on: Jan 26, 2019
 *      Author: ahmed
 */

#ifndef HAL_BUZZER_H_
#define HAL_BUZZER_H_

#include <avr/io.h>

#define BUZZER_DIR 	DDRD
#define BUZZER_PORT PORTD
#define BUZZER_PIN 	PD7

#define BUZZER_ON	(BUZZER_PORT|=(1<<BUZZER_PIN))
#define BUZZER_OFF	(BUZZER_PORT&=~(1<<BUZZER_PIN))


void Buzzer_init(void);


#endif /* HAL_BUZZER_H_ */
