/*
 * RTC.c
 *
 *  Created on: Dec 8, 2016
 *      Author: ahmed
 */


#include "RTC.h"

static unsigned char DecToBcdConvert(unsigned char val)
{
	return val + 6 * (val / 10);
}

/*
 * transform bcd value to decimal
 */
static unsigned char BcdToDecConvert(unsigned char val)
{
	return val - 6 * (val >> 4);
}


void RTC_init(void)
{
	TWI_init();
}

void RTC_set_parameters(RTC * RTC_Settings)
{
	/*initializing the DS1307 (RealTimeClock)*/
	TWI_start();
	_delay_ms(1);
	TWI_send_DeviceAddress_Write(RTC_Address);
	_delay_ms(1);
	/*initialize address pointer*/
	TWI_send_data(0x00);
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->sec));
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->min));
	_delay_ms(1);
	/*12 hours format  bit 6 (12/24)formats*/
	TWI_send_data((DecToBcdConvert(RTC_Settings->hour))|(1<<6));
	_delay_ms(1);
	TWI_send_data((DecToBcdConvert(RTC_Settings->day)));
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->date));
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->month));
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->year));
	_delay_ms(1);
	TWI_send_data(DecToBcdConvert(RTC_Settings->control));
	_delay_ms(1);
	TWI_stop();

}

RTC  RTC_get_parameters(void)
{
	RTC  S1;
	unsigned char PM_AM=0;

	TWI_start();
	_delay_ms(1);
	TWI_send_DeviceAddress_Write(RTC_Address);
	_delay_ms(1);
	TWI_send_data(0x00);
	_delay_ms(1);
	TWI_stop();
	_delay_ms(1);
	TWI_start();
	_delay_ms(1);
	TWI_send_DeviceAddress_Read(RTC_Address);
	_delay_ms(1);
	S1.sec=TWI_recieve_data_ACK();
	_delay_ms(1);
	S1.min=TWI_recieve_data_ACK();
	_delay_ms(1);
	S1.hour=TWI_recieve_data_NACK();
	_delay_ms(1);
	TWI_stop();
	PM_AM=(S1.hour &(1<<5));// 1 --> pm / 0-->am
	S1.hour=((S1.hour)&(0x1F));

	S1.sec=BcdToDecConvert(S1.sec);
	S1.min=BcdToDecConvert(S1.min);
	S1.hour=BcdToDecConvert(S1.hour);
	/*if(PM is true---> Night Mode)*/
	if(PM_AM){S1.hour=(S1.hour)-12;}
	return S1;

}
