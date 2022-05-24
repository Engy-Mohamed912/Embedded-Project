#ifndef GPIO_h_
#define NUM_OF_PORTS 			6
#define NUM_OF_PINS_PER_PORT 	8

#define PORTA_ID         0
#define PORTB_ID         1
#define PORTC_ID         2
#define PORTD_ID         3
#define PORTE_ID         4
#define PORTF_ID         5

#define PIN0_ID          0
#define PIN1_ID          1
#define PIN2_ID          2
#define PIN3_ID          3
#define PIN4_ID          4
#define PIN5_ID          5
#define PIN6_ID          6
#define PIN7_ID          7

#define PA0		0
#define PA1		1
#define PA2		2
#define PA3		3
#define PA4		4
#define PA5		5
#define PA6		6
#define PA7		7

#define PB0		0
#define PB1		1
#define PB2		2
#define PB3		3
#define PB4		4
#define PB5		5
#define PB6		6
#define PB7		7


#define PC0		0
#define PC1		1
#define PC2		2
#define PC3		3
#define PC4		4
#define PC5		5
#define PC6		6
#define PC7		7


#define PD0		0
#define PD1		1
#define PD2		2
#define PD3		3
#define PD4		4
#define PD5		5
#define PD6		6
#define PD7		7


#define PE0		0
#define PE1		1
#define PE2		2
#define PE3		3
#define PE4		4
#define PE5		5
#define PE6		6
#define PE7		7

#define PF0		0
#define PF1		1
#define PF2		2
#define PF3		3
#define PF4		4
#define PF5		5
#define PF6		6
#define PF7		7

void Port_Init( unsigned char portName );
void GPIO_SetPinDir ( unsigned char portName , unsigned char pinNumber, unsigned char Dir);
void GPIO_WritePin ( unsigned char portName , unsigned char pinNumber, unsigned char Data);
void GPIO_Toggle ( unsigned char portName , unsigned char pinNumber);
void GPIO_SetPortDir ( unsigned char portName , unsigned char Dir);
void GPIO_WritePort ( unsigned char portName , unsigned char Data);
unsigned char GPIO_ReadPin ( unsigned char portName , unsigned char pinNumber);
void GPIO_EnablePullUp ( unsigned char portName , unsigned char pinNumber);
unsigned char GPIO_ReadPort ( unsigned char portName);
void GPIO_WriteHighNibble ( unsigned char portName , unsigned char Data);
void GPIO_WriteLowNibble ( unsigned char portName , unsigned char Data);
#endif
	
