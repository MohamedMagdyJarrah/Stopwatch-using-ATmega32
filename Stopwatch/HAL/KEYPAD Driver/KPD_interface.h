/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  HAL				******************/
/*****************		SWC:    KEYPAD			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

//For Stop Watch APP
#define KPD_PRESSED_UP				0
#define KPD_PRESSED_DOWN			1
#define KPD_PRESSED_ENTER			2
#define KPD_PRESSED_GO				3

u8 KPD_u8GetPressedKey(void);

#endif
