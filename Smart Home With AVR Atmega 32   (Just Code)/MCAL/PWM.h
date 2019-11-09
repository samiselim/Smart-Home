/*
 * PWM.h
 *
 *  Created on: Oct 5, 2016
 *      Author: ahmed
 */

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

void PWM_init(void);
void PWM_Duty_Cycle(unsigned char Duty_Cycle);

#endif /* PWM_H_ */
