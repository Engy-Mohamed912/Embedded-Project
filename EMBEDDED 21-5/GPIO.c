#include "tm4c123gh6pm.h"
#include "Macros.h"
#include "LCD.h"
#include "GPIO.h"

void init(){
	
	SYSCTL_RCGCGPIO_R |= 0x3F;						//Clock Activation
	while((SYSCTL_PRGPIO_R & 0x3f)==0){}
	
//********PORT A INITIALLIZATION***********

GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port A
GPIO_PORTA_CR_R = 0xFF;									//Allow Changes of Port A
GPIO_PORTA_AMSEL_R = 0x00;							//Disable Analog on Port A
GPIO_PORTA_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTA_DIR_R |=0xE0; 								
GPIO_PORTA_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTA_DEN_R |=0xFF;								
GPIO_PORTA_PUR_R = 0x00;								//No pullup resistances
	
//********PORT B INITIALLIZATION***********

GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port B
GPIO_PORTB_CR_R = 0xFF;									//Allow Changes of Port B
GPIO_PORTB_AMSEL_R = 0x00;							//Disable Analog on Port B
GPIO_PORTB_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTB_DIR_R |=0xFF; 								//PORTB D0-D7 								
GPIO_PORTB_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTB_DEN_R |=0xFF;								//All pins are digital
GPIO_PORTB_PUR_R = 0x00;								//No pullup resistances

//********PORT C INITIALLIZATION***********

GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port C
GPIO_PORTC_CR_R  |= 0xF0;								//Allow Changes of Port C
GPIO_PORTC_AMSEL_R = 0x00;							//Disable Analog on Port C
GPIO_PORTC_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTC_DIR_R |= 0x00; 							//ALL PINS ARE INPUT
GPIO_PORTC_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTC_DEN_R |= 0xFF;								//All pins are digital
GPIO_PORTC_PDR_R |= 0xF0;							

//********PORT D INITIALLIZATION***********

GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port D
GPIO_PORTD_CR_R = 0xFF;									//Allow Changes of Port D
GPIO_PORTD_AMSEL_R = 0x00;							//Disable Analog on Port D
GPIO_PORTD_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTD_DIR_R = 0x00; 								//ALL PINS ARE INPUT 
GPIO_PORTD_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTD_DEN_R = 0xFF;								//All pins are digital
GPIO_PORTD_PUR_R = 0xFF;								//No pullup resistances

//********PORT E INITIALLIZATION***********

GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port
GPIO_PORTE_CR_R = 0x3F;									//Allow Changes of Port
GPIO_PORTE_AMSEL_R = 0x00;							//Disable Analog on Port
GPIO_PORTE_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTE_DIR_R |= 0x0F; 							
GPIO_PORTE_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTE_DEN_R |= 0xFF;								//All pins are digital
GPIO_PORTE_PUR_R = 0x00;								//No pullup resistances

//********PORT F INITIALLIZATION***********

GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; 			//Unlock Port
GPIO_PORTE_CR_R = 0x1F;									//Allow Changes of Port
GPIO_PORTE_AMSEL_R = 0x00;							//Disable Analog on Port
GPIO_PORTE_PCTL_R = 0x00000000;					//I/O Pins
GPIO_PORTE_DIR_R = 0x0E; 								
GPIO_PORTE_AFSEL_R = 0x00;							//Disable Alternate function
GPIO_PORTE_DEN_R = 0x1F;								//All pins are digital
GPIO_PORTE_PUR_R = 0x11;								//No pullup resistances


//*********LCD INITAILLIZATION***************

LCD_Cmd(0x38); //8-bits,2 display lines, 5x7 font
LCD_Cmd(0x06); //increments automatically
LCD_Cmd(0x0F); //Turn on display
LCD_Cmd(0x01); //clear display

}
unsigned char GPIO_ReadPin ( unsigned char portName , unsigned char pinNumber)
{ unsigned char y ; 
	switch ( portName)
	{
		case 'A' :
		case 'a':
		{ 
			y = READ_BIT( GPIO_PORTA_DATA_R, pinNumber);
				
		} break;
		
		case 'B' :
		case 'b':
		{ 
			y= READ_BIT( GPIO_PORTB_DATA_R, pinNumber);
				
		} break;
		
		case 'C' :
		case 'c':
		{ 
			y =READ_BIT( GPIO_PORTC_DATA_R, pinNumber);
				
		} break;
		
		case 'D' :
		case 'd':
		{ 
		y= READ_BIT( GPIO_PORTD_DATA_R, pinNumber);
				
		} break;
		
		case 'E' :
		case 'e':
		{ 
			y= READ_BIT( GPIO_PORTE_DATA_R, pinNumber);
				
		} break;
		
		case 'F' :
		case 'f':
		{ 
			y= READ_BIT( GPIO_PORTF_DATA_R, pinNumber);
				
		} break;
	}
	return y;
}
