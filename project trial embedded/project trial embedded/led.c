#include"GPIO.h"
#include "Macro.h"
#include "led.h"


void LED_init(unsigned char portName , unsigned char pinNumber )
{	
	void Port_Init( unsigned char portName );
	GPIO_SetPinDir(portName , pinNumber , 1 );
}
void LED_On(unsigned char portName , unsigned char pinNumber )
{
	GPIO_WritePin(portName,pinNumber,1);
}
void LED_Off(unsigned char portName , unsigned char pinNumber )
{
	GPIO_WritePin(portName,pinNumber,0);
}
void LED_toggle(unsigned char portName , unsigned char pinNumber )
{
	GPIO_Toggle(portName,pinNumber);
}