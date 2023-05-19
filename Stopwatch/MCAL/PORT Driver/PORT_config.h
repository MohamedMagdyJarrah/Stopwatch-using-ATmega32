/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    PORT			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*
Choose:
  0 ---> For INPUT PIN
  1 ---> For OUTPUT PIN
*/
  
#define PORTA_PIN0_DIR				1
#define PORTA_PIN1_DIR				1
#define PORTA_PIN2_DIR				1
#define PORTA_PIN3_DIR				0
#define PORTA_PIN4_DIR				0
#define PORTA_PIN5_DIR				0
#define PORTA_PIN6_DIR				0
#define PORTA_PIN7_DIR				0
		
#define PORTB_PIN0_DIR				0
#define PORTB_PIN1_DIR				0
#define PORTB_PIN2_DIR				0
#define PORTB_PIN3_DIR				0
#define PORTB_PIN4_DIR				0
#define PORTB_PIN5_DIR				0
#define PORTB_PIN6_DIR				0
#define PORTB_PIN7_DIR				0
		
#define PORTC_PIN0_DIR				1
#define PORTC_PIN1_DIR				1
#define PORTC_PIN2_DIR				1
#define PORTC_PIN3_DIR				1
#define PORTC_PIN4_DIR				1
#define PORTC_PIN5_DIR				1
#define PORTC_PIN6_DIR				1
#define PORTC_PIN7_DIR				1
		
#define PORTD_PIN0_DIR				1
#define PORTD_PIN1_DIR				1
#define PORTD_PIN2_DIR				1
#define PORTD_PIN3_DIR				1
#define PORTD_PIN4_DIR				0
#define PORTD_PIN5_DIR				0
#define PORTD_PIN6_DIR				0
#define PORTD_PIN7_DIR				0

/*
Put initial value for pin:
	In INPUT:	0-->FLOATING PIN	1-->PULL UP PIN
	In OUTPUT:	0-->LOW	VALUE		1-->HIGH VALUE
*/
	
#define PORTA_PIN0_INIT_VALUE		0
#define PORTA_PIN1_INIT_VALUE		0
#define PORTA_PIN2_INIT_VALUE		0
#define PORTA_PIN3_INIT_VALUE		0
#define PORTA_PIN4_INIT_VALUE		0
#define PORTA_PIN5_INIT_VALUE		0
#define PORTA_PIN6_INIT_VALUE		0
#define PORTA_PIN7_INIT_VALUE		0
				   
#define PORTB_PIN0_INIT_VALUE		0
#define PORTB_PIN1_INIT_VALUE		0
#define PORTB_PIN2_INIT_VALUE		0
#define PORTB_PIN3_INIT_VALUE		0
#define PORTB_PIN4_INIT_VALUE		0
#define PORTB_PIN5_INIT_VALUE		0
#define PORTB_PIN6_INIT_VALUE		0
#define PORTB_PIN7_INIT_VALUE		0
				   
#define PORTC_PIN0_INIT_VALUE		0
#define PORTC_PIN1_INIT_VALUE		0
#define PORTC_PIN2_INIT_VALUE		0
#define PORTC_PIN3_INIT_VALUE		0
#define PORTC_PIN4_INIT_VALUE		0
#define PORTC_PIN5_INIT_VALUE		0
#define PORTC_PIN6_INIT_VALUE		0
#define PORTC_PIN7_INIT_VALUE		0
				   
#define PORTD_PIN0_INIT_VALUE		1
#define PORTD_PIN1_INIT_VALUE		1
#define PORTD_PIN2_INIT_VALUE		1
#define PORTD_PIN3_INIT_VALUE		1
#define PORTD_PIN4_INIT_VALUE		1
#define PORTD_PIN5_INIT_VALUE		1
#define PORTD_PIN6_INIT_VALUE		1
#define PORTD_PIN7_INIT_VALUE		1



#endif
