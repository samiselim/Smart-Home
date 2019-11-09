/*
 * Main.c
 *
 *  Created on: May 4, 2019
 *      Author: ahmed
 */

/* Scheduler */
#include "../ServiceLayer/Scheduler.h"
#include "../ServiceLayer/PLATFORM_TYPES.h"

/* HAL */
#include "../HAL/LCD.h"
#include "../HAL/Keypad.h"
#include "../HAL/Buzzer.h"
#include "../HAL/ULTRASONIC.h"
#include "../HAL/RTC.h"
#include "../HAL/Temperature.h"

/* Shall be removed after integrating BT or WIFI HAL peripheral */
#include "../MCAL/UART.h"

/* Tasks  */

void Task_2ms(void)
{

}

void Task_5ms(void)
{

}

void Task_10ms(void)
{

}

void Task_100ms(void)
{
	char Key =0;

	static int cnt =0;

	Key = Keypad_get_pressed_key();

	if(Key != 0)
	{
		cnt++;

		if(cnt > 16)
		{
			cnt = 0;
			LCD_Clear_Display();
			LCD_Send_String_Row_Column(0,0,"PIN:");
		}
		else
		{
			LCD_GoTO_Row_Colunmn(1,cnt);
			LCD_Send_character(Key);
		}

	}
	else
	{
		/* Do Nothing */
	}
}
void Task_500ms(void)
{


}

void Task_1000ms(void)
{
	long Tempsensor =0;
	char arr1[10];
	Tempsensor = Temperature_Get_Value();
	UART_send_string("\n\r Temperature is : ");
	LCD_IntToString(Tempsensor,arr1);
	UART_send_string(arr1);
	UART_send_string(" Degree\n\r");

}

int  main(void)
{
	/* Initialization HAL */

	/* LCD */
	LCD_Init();
	LCD_Clear_Display();
	LCD_Send_String_Row_Column(0,0,"PIN:");

	/* Buzzer */
	Buzzer_init();

	/* keypad */
	Keypad_init();

	/* Ultrasonic */
	UltraSonic_init();

	/* Temperature */
	Temperature_init();


	/* shall be removed */
	Uart_init(9600);


	/* Initialization Scheduler */
	Scheduler_init();
	Scheduler_2ms_Task_Create(Task_2ms);
	Scheduler_5ms_Task_Create(Task_5ms);
	Scheduler_10ms_Task_Create(Task_10ms);
	Scheduler_100ms_Task_Create(Task_100ms);
	Scheduler_500ms_Task_Create(Task_500ms);
	Scheduler_1000ms_Task_Create(Task_1000ms);

	Scheduler_Run();


	while(1)
	{
		/* Do Nothing */
	}

}

