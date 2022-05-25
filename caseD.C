#include "test.h"
#include <stdint.h>
#include "keypadF.h"

void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_WriteString(char *_Str);
void delay_milli(int n);
unsigned char timerArray[4];




//countdown in sec:
void Countdown_Integertocharacter(int time){


char toTime [4] = {'0','1'};
sprintf(toTime,"%d",time);
LCD_WriteString(toTime);


}


	

void LCD_init(void)
{
	//SW3 initialization
	GPIO_PORTA_CR_R |=0x04;
	GPIO_PORTA_PUR_R |=0x04;
    SYSCTL_RCGCGPIO_R |= 0x03; // Enable clock for ports
    while((SYSCTL_PRGPIO_R & 0x03)==0){};  //wait til ports are activated
    GPIO_PORTA_DIR_R |=0xE1; //PORTA controls RS,E and R/W
    GPIO_PORTA_DEN_R |=0xE1;
    //portB
    GPIO_PORTB_DIR_R |=0xFF; //PORTB D0-D7
    GPIO_PORTB_DEN_R |=0xFF; //PORTB D0-D7
    //LCD
    LCD_Cmd(0x38); //8-bits,2 display lines, 5x7 font
    LCD_Cmd(0x06); //increments automatically
    LCD_Cmd(0x0F); //Turn on display
    LCD_Cmd(0x01); //clear display
}



void LCD_GotoXY(uint8_t _x, uint8_t _y)
{
	if(_y)
		_x |= 0x40;
	_x |= 0x80;

	LCD_Cmd(_x);
}

int main() {
SystemInit();
		unsigned char Choice ='0';
    keypad_Init();

	  LCD_init();
LCD_Cmd(0x01);	
LCD_Cmd(0x80);

delay_milli(500);
		while(1){
		Choice = keypad_u8_READ();
	int8_t CookingTime [] = {"0000"};
	int16_t CookingTimeInSecs =0;
	char CookingTimeSecs [11] = {'0','1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':'};

				
					 if (Choice == 'D')	{
			LCD_WriteString("Cooking Time?");
			delay_milli(1000);
			       LCD_Cmd(0x01);	
				
						LCD_GotoXY(11,1);
					LCD_WriteString("00:00");
						
				
						CookingTime[0] = keypad_u8_READ();
					
						LCD_GotoXY(15,1);
					LCD_WriteString(&CookingTime[0]);
						
						CookingTime[1] = keypad_u8_READ();
						
						LCD_GotoXY(14,1);
					LCD_WriteString(&CookingTime[0]);
						LCD_GotoXY(15,1);
					LCD_WriteString(&CookingTime[1]);
						
						CookingTime[2] = keypad_u8_READ();
						
							LCD_GotoXY(12,1);
					LCD_WriteString(&CookingTime[0]);
					LCD_GotoXY(13,1);
				 LCD_WriteString(":");
						LCD_GotoXY(14,1);
					LCD_WriteString(&CookingTime[1]); 
						LCD_GotoXY(15,1);
					LCD_WriteString(&CookingTime[2]);
					
						CookingTime[3] = keypad_u8_READ();
						
							LCD_GotoXY(11,1);
					LCD_WriteString(&CookingTime[0]);
						LCD_GotoXY(12,1);
					LCD_WriteString(&CookingTime[1]);
         LCD_GotoXY(13,1);
				 LCD_WriteString(":");					
						LCD_GotoXY(14,1);
					LCD_WriteString(&CookingTime[2]);
						LCD_GotoXY(15,1);
					LCD_WriteString(&CookingTime[3]);
					
			
						delay_milli(2000);
			LCD_Cmd(0x01);
			
			    CookingTimeInSecs = ((CookingTime[0] - '0') * 600) + ((CookingTime[1] - '0') * 60) + ((CookingTime[2] - '0') * 10) + ((CookingTime[3] - '0'));
	     if((CookingTimeInSecs <= 1800) && CookingTime[2] <='6') {   
				 sprintf(CookingTimeSecs,"%d",CookingTimeInSecs);
					LCD_WriteString(CookingTimeSecs);
				 
//				 if (SW1_input()==0){LCD_Cmd(0x01);}
//			if (SW2_input()==0){Start(Cookingtimeinsec);
//				for(int i =Cookingtimeinsec ;i>=1;i--)
//						{
//						 Countdown_Integertocharacter(i);
//			       delay_milli(1000);
//			       LCD_Cmd(0x01);
//		        }
//					}
//				
//				else {goto HoldD;}
			 }
		 }
		}
	}