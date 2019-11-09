/*
 * RTC.h
 *
 *  Created on: Dec 8, 2016
 *      Author: ahmed
 */

#ifndef RTC_H_
#define RTC_H_

#include "../MCAL/TWI.h"
#include <util/delay.h>

typedef struct rtc
{
	unsigned char sec;
	unsigned char min;
	unsigned char hour;
	unsigned char day;
	unsigned char date;
	unsigned char month;
	unsigned char year;
	unsigned char control;
}RTC;

#define RTC_Address (0b01101000)


void RTC_init(void);

void RTC_set_parameters(RTC * RTC_Settings);

RTC  RTC_get_parameters(void);


#endif /* RTC_H_ */
