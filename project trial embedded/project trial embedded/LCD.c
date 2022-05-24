#include "GPIO.h"
#include "LCD.h"
#include "stdio.h"
#include "string.h"






void LCD_Init (void){
	GPIO_SetPortDir (DATAPORT,0xFF);
	GPIO_SetPinDir  (CTRLPORT,EN,1);
	GPIO_SetPinDir  (CTRLPORT,RS,1);
	GPIO_SetPinDir  (CTRLPORT,RW,1);
	GPIO_WritePin   (CTRLPORT,RW,0);
	LCD_Send_Cmd   (Function_set_8bit);
	//delay_ms (1);  //in milli seconds
	
	LCD_Send_Cmd (0x0C);   //cursor off 
	//delay_ms (1);
	
	LCD_Send_Cmd (clear_display);
	//delay_ms (10);
	
  LCD_Send_Cmd (Entry_mode);
	//delay_ms (10);
}



static void Send_Pulse (void){
	GPIO_WritePin (CTRLPORT,EN,1);
  //delay_ms (2);
	GPIO_WritePin (CTRLPORT,EN,0);
 // delay_ms (2);
}

void LCD_Send_Cmd (unsigned char Cmd){
	GPIO_WritePort(DATAPORT,Cmd);
	GPIO_WritePin (CTRLPORT,RS,0);
	Send_Pulse();
	//delay_ms (1);
}

void LCD_Send_Char (unsigned char Char){
	GPIO_WritePort(DATAPORT,Char);
	GPIO_WritePin (CTRLPORT,RS,1);
	Send_Pulse();
	//delay_ms (1);
}

void LCD_Send_String(unsigned char*data){
	while ((*data)!='0')
	{ 
		LCD_Send_Char((*data));
		data++;
	}
}

void LCD_clear_display (void ){
	LCD_Send_Cmd (0x01);
	//delay_ms (10);
}
	
void LCD_movecursor (unsigned char row ,unsigned char col)
{
	char position=0;
	if (row == 0)
	{
		position = col;
	}
	else if (row == 1)
	{
		position = (0x40)+col;
	}

	
	LCD_Send_Cmd ( position | 0x80);
	//delay_ms(1);
}

void LCD_Print_Int(int x) {
	char toPrint [4] ;
	sprintf(toPrint[], %d,x );
	
	
	
	
	
	
	