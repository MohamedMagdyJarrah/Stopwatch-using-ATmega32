/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:   CLCD				******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

/*File guard for Preproccesor*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*Configuration of Data pins*/
#define CLCD_DATA_PORT		DIO_u8PORTC

/*Configuration of Control pins*/
#define CLCD_CTRL_PORT		DIO_u8PORTA
#define CLCD_RS_PIN			DIO_u8PIN0
#define CLCD_RW_PIN			DIO_u8PIN1
#define CLCD_E_PIN			DIO_u8PIN2

/*Mode of CLCD (4-bit or 8-bit)*/
#define CLCD_Mode			EIGHT_BIT_MODE

#endif
