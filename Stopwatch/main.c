#include "LIB/STD_TYPES.h"
#include "MCAL/PORT Driver/PORT_interface.h"
#include "MCAL/DIO Driver/DIO_interface.h"
#include "HAL/CLCD Driver/CLCD_interface.h"
#include "HAL/KEYPAD Driver/KPD_interface.h"
#include "HAL/LED Driver/LED_interface.h"
#include <util/delay.h>

void choosingNum(s8* Copy_s8Num, u8* Copy_u8KeyState , u8 Copy_u8NumType, u8 Copy_u8Digit);
void Setup(s8 *Copy_u8Tens , s8* Copy_u8Units ,u8 Copy_u8Type);
void decreasingDigits();

u8 Global_u8ColumnIdx = 0;
//Keypad
u8 Global_u8PressedKey;
void main(void)
{
	//Port Initialization
	PORT_voidInit();
	//CLCD Initialization
	CLCD_voidInit();
	u8 Local_u8BodyGreeting[] = {0b00010100,0b00011110,0b00000101,0b00000100,0b00000100,0b00000100,0b00001010,0b00001010};
	//Led Initialization
	LED_t Local_ledRedLight = {DIO_u8PORTA,DIO_u8PIN3,LED_u8SOURCE};


	//Stop watch Initialization
	s8 Local_s8HoursTens=0,Local_s8HoursUnits=0, Local_s8MinutesTens=0,Local_s8MinutesUnits=0, Local_s8SecondsTens=0,Local_s8SecondsUnits=0;
	u32 Local_u32TotalHours , Local_u32TotalMinutes , Local_u32TotalSeconds;
	u32 Local_u32Time;
	CLCD_voidSendString("To Setup Stop");
	CLCD_u8GoToXY(1,0);
	CLCD_voidSendString("Watch Press GO");

	do
	{
		Global_u8PressedKey = KPD_u8GetPressedKey();
	}while(Global_u8PressedKey != KPD_PRESSED_GO);
	CLCD_voidClearDisplay();
	CLCD_u8GoToXY(0,0);
	CLCD_voidSendString("00:00:00");
	CLCD_u8GoToXY(1,Global_u8ColumnIdx);
	CLCD_voidSendData('^');

	//Hours
	Setup(&Local_s8HoursTens,&Local_s8HoursUnits,0);
	Local_u32TotalHours = Local_s8HoursTens*10 + Local_s8HoursUnits;

	//Minutes
	Setup(&Local_s8MinutesTens,&Local_s8MinutesUnits,1);
	Local_u32TotalMinutes = Local_s8MinutesTens*10 + Local_s8MinutesUnits;

	//Seconds
	Setup(&Local_s8SecondsTens,&Local_s8SecondsUnits,2);
	Local_u32TotalSeconds = Local_s8SecondsTens*10 + Local_s8SecondsUnits;

	Local_u32Time = Local_u32TotalSeconds + (Local_u32TotalMinutes*60) + (Local_u32TotalHours*60*60);

	do
	{
		Global_u8PressedKey = KPD_u8GetPressedKey();
	}while(Global_u8PressedKey != KPD_PRESSED_GO);

	while(1)
	{
		if (Local_u32Time != 0)
		{
			if (Local_u32TotalSeconds == 0)
			{
				Local_u32TotalSeconds = 59;
				if (Local_u32TotalMinutes == 0 && Local_u32TotalHours !=0 )
				{
					Local_u32TotalMinutes = 59;
					Local_u32TotalHours--;
				}
				else if (Local_u32TotalMinutes == 0 && Local_u32TotalHours ==0)
				{
					Local_u32TotalHours=0;
					Local_u32TotalMinutes=0;
				}
				else
				{
					Local_u32TotalMinutes--;
				}
			}
			else
			{
				Local_u32TotalSeconds--;
			}

			Local_u32Time--;
			CLCD_voidWriteNumber(0,0,6,READ_FROM_RIGHT);
			CLCD_voidWriteNumber(Local_u32TotalSeconds,0,7,READ_FROM_RIGHT);

			CLCD_voidWriteNumber(0,0,3,READ_FROM_RIGHT);
			CLCD_voidWriteNumber(Local_u32TotalMinutes,0,4,READ_FROM_RIGHT);

			CLCD_voidWriteNumber(0,0,0,READ_FROM_RIGHT);
			CLCD_voidWriteNumber(Local_u32TotalHours,0,1,READ_FROM_RIGHT);

			_delay_ms(1000);
		}
		else
		{
			CLCD_u8GoToXY(1,0);
			CLCD_voidSendString("Its time !!");
//			CLCD_u8GoToXY(0,14);
//			CLCD_voidSendData('o');
//			CLCD_voidWriteSpecialCharacter(Local_u8BodyGreeting,0,1,14);

			LED_u8TurnOn(&Local_ledRedLight);
			_delay_ms(500);
			LED_u8TurnOff(&Local_ledRedLight);
			_delay_ms(500);
		}
	}
}

void choosingNum(s8* Copy_s8Num, u8* Copy_u8KeyState , u8 Copy_u8NumType, u8 Copy_u8Digit)
{
	// Copy_u8NumType ---->  0 for Hours , 1 for Minutes , 2 for Seconds
	// Copy_u8Digit ----> 0 for Tens , 1 for Units

	do
	{
		*Copy_u8KeyState = KPD_u8GetPressedKey();
	}while(*Copy_u8KeyState == 0xff);

	if (*Copy_u8KeyState == KPD_PRESSED_UP)
	{
		if ((Copy_u8NumType == 1 && Copy_u8Digit==0) || (Copy_u8NumType == 2 && Copy_u8Digit==0))
		{
			(*Copy_s8Num)++;
			if (*Copy_s8Num > 6)
			{
				*Copy_s8Num = 0;
			}
		}
		else
		{
			(*Copy_s8Num)++;
			if (*Copy_s8Num > 9)
			{
				*Copy_s8Num = 0;
			}
		}
	}


	else if (*Copy_u8KeyState == KPD_PRESSED_DOWN)
	{
		if ((Copy_u8NumType == 1 && Copy_u8Digit==0) || (Copy_u8NumType == 2 && Copy_u8Digit==0))
		{
			(*Copy_s8Num)--;
			if (*Copy_s8Num < 0)
			{
				*Copy_s8Num = 6;
			}
		}
		else
		{
			(*Copy_s8Num)--;
			if (*Copy_s8Num < 0)
			{
				*Copy_s8Num = 9;
			}
		}
	}
}

void Setup(s8 *Copy_u8Tens , s8* Copy_u8Units ,u8 Copy_u8Type)
{
	while (Global_u8PressedKey != KPD_PRESSED_ENTER)
	{
		choosingNum(Copy_u8Tens,&Global_u8PressedKey,Copy_u8Type,0);
		CLCD_voidWriteNumber(*Copy_u8Tens,0,Global_u8ColumnIdx,READ_FROM_LEFT);
	}
	CLCD_u8GoToXY(1,Global_u8ColumnIdx);
	CLCD_voidSendData(' ');
	Global_u8ColumnIdx++;
	CLCD_u8GoToXY(1,Global_u8ColumnIdx);
	CLCD_voidSendData('^');
	Global_u8PressedKey = 0xff;
	while (Global_u8PressedKey != KPD_PRESSED_ENTER)
	{
		choosingNum(Copy_u8Units,&Global_u8PressedKey,Copy_u8Type,1);
		CLCD_voidWriteNumber(*Copy_u8Units,0,Global_u8ColumnIdx,READ_FROM_LEFT);
	}
	CLCD_u8GoToXY(1,Global_u8ColumnIdx);
	CLCD_voidSendData(' ');
	Global_u8ColumnIdx+=2;
	if (Copy_u8Type != 2)
	{
		CLCD_u8GoToXY(1,Global_u8ColumnIdx);
		CLCD_voidSendData('^');
	}

	Global_u8PressedKey = 0xff;
}


