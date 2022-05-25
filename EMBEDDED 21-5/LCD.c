#include <stdint.h>
#include "Keypad.h"
#include "tm4c123gh6pm.h"
#include "Systick.h"
#include "LCD.h"


void LCD_Cmd(unsigned char command)
{
    GPIO_PORTA_DATA_R = 0x00; //RS=0, E=0, RW=0
    GPIO_PORTB_DATA_R =command;
    GPIO_PORTA_DATA_R = 0x80; //E=1 to secure command
    delay_milli(1);
    GPIO_PORTA_DATA_R =0x00;
    if(command <4)
    {
        delay_milli(2);
    }
    else
    {
        delay_milli(1);
    }
}

void LCD_Data(unsigned char data)
    {
        GPIO_PORTA_DATA_R =0x20; //RS=1, E=0,RW=0
        GPIO_PORTB_DATA_R =data;
        GPIO_PORTA_DATA_R |= 0x80;
        GPIO_PORTA_DATA_R =0x00;
        delay_milli(1);
    }
		

void LCD_WriteString(unsigned char *_Str)
{
	while( *_Str)
	{
		LCD_Data(*_Str);
		_Str++;
	}
}

