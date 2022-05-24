#include "GPIO.h"
#include "Macro.h"
#include "tm4c123gh6pm.h"

void Port_Init (unsigned char portName) 
{
	
	switch (portName)
	{
		// Initialization of port A
		case 'A':
		case 'a':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTA_LOCK_R = 0x4C4F434B ;
			GPIO_PORTA_DEN_R = 0xFF ;
			GPIO_PORTA_CR_R = 0xFF ;
		}
			// Initialization of port B
		case 'B':
		case 'b':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTB_LOCK_R = 0x4C4F434B ;
			GPIO_PORTB_DEN_R = 0xFF ;
			GPIO_PORTB_CR_R = 0xFF ;
		}
		
		
		// Initialization of port C
		case 'C':
		case 'c':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTC_LOCK_R = 0x4C4F434B ;
			GPIO_PORTC_DEN_R = 0xFF ;
			GPIO_PORTC_CR_R = 0xFF ;
		}
		
		
		// Initialization of port D
		case 'D':
		case 'd':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTD_LOCK_R = 0x4C4F434B ;
			GPIO_PORTD_DEN_R = 0xFF ;
			GPIO_PORTD_CR_R = 0xFF ;
		}
		
		
		// Initialization of port E
		case 'E':
		case 'e':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTE_LOCK_R = 0x4C4F434B ;
			GPIO_PORTE_DEN_R = 0xFF ;
			GPIO_PORTE_CR_R = 0xFF ;
		}
		
		// Initialization of port F
		case 'F':
		case 'f':
		{ 
			
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_PRGPIO_R , 0) == 0);
			
			GPIO_PORTF_LOCK_R = 0x4C4F434B ;
			GPIO_PORTF_DEN_R = 0xFF ;
			GPIO_PORTF_CR_R = 0xFF ;
		}
		
	}
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

void GPIO_EnablePullUp ( unsigned char portName , unsigned char pinNumber)
	{
		switch ( portName)
		{ case 'A' :
			case 'a':
		{ 
			SET_BIT(GPIO_PORTA_PUR_R,pinNumber);
				
		} break;
		
			case 'B' :
			case 'b':
		{ 
			SET_BIT(GPIO_PORTB_PUR_R,pinNumber);
				
		} break;
		
			case 'C' :
			case 'c':
		{ 
			SET_BIT(GPIO_PORTC_PUR_R,pinNumber);
				
		} break;
		
			case 'D' :
			case 'd':
		{ 
			SET_BIT(GPIO_PORTD_PUR_R,pinNumber);
				
		} break;
		
			case 'E' :
			case 'e':
		{ 
			SET_BIT(GPIO_PORTE_PUR_R,pinNumber);
				
		} break;
		
			case 'F' :
			case 'f':
		{ 
			SET_BIT(GPIO_PORTF_PUR_R,pinNumber);
				
		} break;
	}
}
unsigned char GPIO_ReadPort ( unsigned char portName)
{
	unsigned char x;
	
			switch ( portName)
		{ case 'A' :
			case 'a':
		{ 
		x = GPIO_PORTA_DATA_R;
				
		} break;
		
			case 'B' :
			case 'b':
		{ 
			x=  GPIO_PORTB_DATA_R;
		} break;
		
			case 'C' :
			case 'c':
		{ 
			x = GPIO_PORTC_DATA_R;
				
		} break;
		
			case 'D' :
			case 'd':
		{ 
			x=  GPIO_PORTD_DATA_R;
				
		} break;
		
			case 'E' :
			case 'e':
		{ 
			x=  GPIO_PORTE_DATA_R;
				
		} break;
		
			case 'F' :
			case 'f':
		{ 
			x=    GPIO_PORTF_DATA_R;
				
		} break;
	}  return x ;
		 }

	
void GPIO_SetPinDir ( unsigned char portName , unsigned char pinNumber, unsigned char Dir)
{
	switch ( portName)
	{
		case 'A' :
		case 'a':
		{ 
			if( Dir==1) SET_BIT ( GPIO_PORTA_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTA_DIR_R , pinNumber) ;
			
		} break;
		
		case 'B' :
		case 'b':
		{ 
			if( Dir==1) SET_BIT (GPIO_PORTB_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTB_DIR_R , pinNumber) ;
			
		} break;
		
		case 'C' :
		case 'c':
		{ 
			if( Dir==1) SET_BIT ( GPIO_PORTC_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTC_DIR_R , pinNumber) ;
			
		} break;
		
		case 'D' :
		case 'd':
		{ 
			if( Dir==1) SET_BIT ( GPIO_PORTD_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTD_DIR_R , pinNumber) ;
			
		} break;
		
		case 'E' :
		case 'e':
		{ 
			if( Dir==1) SET_BIT ( GPIO_PORTE_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTE_DIR_R , pinNumber) ;
			
		} break;
		
		case 'F' :
		case 'f':
		{ 
			if( Dir==1) SET_BIT ( GPIO_PORTF_DIR_R , pinNumber) ;
				else CLEAR_BIT (GPIO_PORTF_DIR_R , pinNumber) ;
			
		} break;
	}
}
void GPIO_WritePin ( unsigned char portName , unsigned char pinNumber, unsigned char Data)
{
	switch(portName)
	{ 
		case 'A':
		case 'a':
		{
			if ( Data==1) SET_BIT(GPIO_PORTA_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTA_DIR_R , pinNumber) ;
		}break;
		
		case 'B':
		case 'b':
		{
			if ( Data==1) SET_BIT(GPIO_PORTB_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTB_DIR_R , pinNumber) ;
		}break;
		
		case 'C':
		case 'c':
		{
			if ( Data==1) SET_BIT(GPIO_PORTC_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTC_DIR_R , pinNumber) ;
		}break;
		
		case 'D':
		case 'd':
		{
			if ( Data==1) SET_BIT(GPIO_PORTD_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTD_DIR_R , pinNumber) ;
		}break;
		
		case 'E':
		case 'e':
		{
			if ( Data==1) SET_BIT(GPIO_PORTE_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTE_DIR_R , pinNumber) ;
		}break;
		
		case 'F':
		case 'f':
		{
			if ( Data==1) SET_BIT(GPIO_PORTF_DIR_R, pinNumber);
			else CLEAR_BIT (GPIO_PORTF_DIR_R , pinNumber) ;
		}break;
	}
}

void GPIO_Toggle ( unsigned char portName , unsigned char pinNumber){
switch(portName)
{
	case 'A':
	case 'a':
	{
		TOGGLE_BIT(GPIO_PORTA_DATA_R , pinNumber) ;
	}break;
	case 'B':
	case 'b':
	{
		TOGGLE_BIT(GPIO_PORTB_DATA_R , pinNumber) ;
	}break;
	case 'C':
	case 'c':
	{
		TOGGLE_BIT(GPIO_PORTC_DATA_R , pinNumber) ;
	}break;
	case 'D':
	case 'd':
	{
		TOGGLE_BIT(GPIO_PORTD_DATA_R , pinNumber) ;
	}break;
	case 'E':
	case 'e':
	{
		TOGGLE_BIT(GPIO_PORTE_DATA_R , pinNumber) ;
	}break;
	case 'F':
	case 'f':
	{
		TOGGLE_BIT(GPIO_PORTF_DATA_R , pinNumber) ;
	}break;
}
}


void GPIO_SetPortDir ( unsigned char portName , unsigned char Dir)
{ 
	switch( portName )
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DIR_R=Dir;
		}break;
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DIR_R=Dir;
		}break;
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DIR_R=Dir;
		}break;
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DIR_R=Dir;
		}break;
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DIR_R=Dir;
		}break;
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DIR_R=Dir;
		}break;
	}
}


void GPIO_WritePort ( unsigned char portName , unsigned char Data)
{
	switch( portName )
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R=Data;
		}break;
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R=Data;
		}break;
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R=Data;
		}break;
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R=Data;
		}break;
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R=Data;
		}break;
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R=Data;
		}break;
	}
}
	
	
	void GPIO_WriteHighNibble ( unsigned char portName , unsigned char Data){
		Data<<=4;
			switch( portName )
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R&=0x0F;
			GPIO_PORTA_DATA_R|=Data;
    }break;
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R&=0x0F;
			GPIO_PORTB_DATA_R|=Data;
		}break;
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R&=0x0F;
			GPIO_PORTC_DATA_R|=Data;
		}break;
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R&=0x0F;
			GPIO_PORTD_DATA_R|=Data;
		}break;
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R&=0x0F;
			GPIO_PORTE_DATA_R|=Data;
		}break;
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R&=0x0F;
			GPIO_PORTF_DATA_R|=Data;
		}break;
	}
}	

	void GPIO_WriteLowNibble ( unsigned char portName , unsigned char Data){
			switch( portName )
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R&=0xF0;
			GPIO_PORTA_DATA_R|=Data;
    }break;
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R&=0xF0;
			GPIO_PORTB_DATA_R|=Data;
		}break;
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R&=0xF0;
			GPIO_PORTC_DATA_R|=Data;
		}break;
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R&=0xF0;
			GPIO_PORTD_DATA_R|=Data;
		}break;
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R&=0xF0;
			GPIO_PORTE_DATA_R|=Data;
		}break;
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R&=0xF0;
			GPIO_PORTF_DATA_R|=Data;
		}break;
	}
}
	