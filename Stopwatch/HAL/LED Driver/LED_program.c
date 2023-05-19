/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    LED				******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


u8 LED_u8TurnOn(LED_t* Copy_u8LED)
{
	u8 Local_u8ErrorState = 0;

	switch(Copy_u8LED->ConnectionType)
	{
	case LED_u8SINK:
		DIO_u8SetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,DIO_u8PIN_LOW);
		break;
	case LED_u8SOURCE:
		DIO_u8SetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,DIO_u8PIN_HIGH);
		break;
	default: Local_u8ErrorState =1;break;
	}

	return Local_u8ErrorState;
}

u8 LED_u8TurnOff(LED_t* Copy_u8LED)
{
	u8 Local_u8ErrorState = 0;

	switch(Copy_u8LED->ConnectionType)
	{
	case LED_u8SINK:
		DIO_u8SetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,DIO_u8PIN_HIGH);
		break;
	case LED_u8SOURCE:
		DIO_u8SetPinValue(Copy_u8LED->Port,Copy_u8LED->Pin,DIO_u8PIN_LOW);
		break;
	default: Local_u8ErrorState =1;break;
	}

	return Local_u8ErrorState;
}
