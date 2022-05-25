#include "Macros.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "Switches.h"
#include "LCD.h"
#include "Counter.h"
#include "Keypad.h"
#include "Systick.h"
#include "LED.h"
#include "States.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <stdint.h>




void SystemInit (){}

int main (){
	
	
	unsigned char Choice;
	init();
	
	keypad_u8_READ();
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	delay_milli(500);
			
	
	Choice = keypad_u8_READ();
	
	if (Choice == 'A'){
					
			while (SW3_input()!=0){
				while(SW2_input()!=0){
					
					unsigned char popcorn[] = "POPCORN";
					int Cookingtime = 60;
					
					LCD_Cmd(0x01);
					LCD_WriteString (popcorn);
					delay_milli(2000);
					LCD_Cmd(0x01);
					Countdown_Integertocharacter(Cookingtime);
					displayTimer();
					
					HoldA:
					if (SW1_input()==0){Start(Cookingtime);}
					else {goto HoldA;}
					
				}
			}
		}
				
				
				else if (Choice == 'B'){
					
			while (SW3_input()!=0){	
				while(SW2_input()!=0){
					unsigned char BeefWeightText[] = "Beef Weight?";
					unsigned char BeefWeightText2[] = "Beef Weight is ";
					unsigned char BeefWeight[] = {'1','2','3','4','5','6','7','8','9'};
					unsigned char BeefWeightInput;
					int i;
					int True;
					int Cookingtimeinsec;
					unsigned char Error [] = "Err";
				

					Start:
					
					LCD_Cmd(0x01);
					LCD_WriteString(BeefWeightText);
					BeefWeightInput = keypad_u8_READ();
					
					
					for (i=0;i<10;i++){ if(BeefWeightInput == BeefWeight[i]){True = 1;}}  //Checking of Value
					
					if (True == 1){
						
						LCD_Cmd(0x01);
						Cookingtimeinsec = (BeefWeightInput - '0') * 30;
						Countdown_Integertocharacter(Cookingtimeinsec);
						LCD_WriteString(BeefWeightText2);
						LCD_Data(BeefWeightInput);
						delay_milli(2000);
						displayTimer();
					}
					else{
						
						LCD_Cmd(0x01);
						LCD_WriteString(Error);
						delay_milli(2000);
						goto Start;
						
						
					}
						
						HoldB:
					if (SW1_input()==0){Start(Cookingtimeinsec);}
					else {goto HoldB;}
					
					}
				}
			}
					
					
					
					
					

			
				else if (Choice == 'C'){
					
					
				while (SW3_input()!=0){
					while(SW2_input()!=0){
					
					unsigned char ChickenWeightText[] = "Chicken Weight?";
					unsigned char ChickenWeightText2[] = "Chicken Weight is ";
					unsigned char ChickenWeight[] = {'1','2','3','4','5','6','7','8','9'};
					unsigned char ChickenWeightInput;
					int i;
					int True;
					int Cookingtimeinsec;
					unsigned char Error [] = "Err";
					
					LCD_Cmd(0x01);
					LCD_WriteString(ChickenWeightText);
					ChickenWeightInput = keypad_u8_READ();
					
					
					for (i=0;i<10;i++){ if(ChickenWeightInput == ChickenWeight[i]){True = 1;}}  //Checking of Value
					
					if (True == 1){
						
						LCD_Cmd(0x01);
						Cookingtimeinsec = (ChickenWeightInput - '0') * 12;
						Countdown_Integertocharacter(Cookingtimeinsec);
						LCD_WriteString(ChickenWeightText2);
						LCD_Data(ChickenWeightInput);
						delay_milli(2000);
						displayTimer();
						
					}
						else{
						
						LCD_Cmd(0x01);
						LCD_WriteString(Error);
						delay_milli(2000);
						goto Start;
						
						
					}
						
						HoldC:
					if (SW1_input()==0){Start(Cookingtimeinsec);}
					else {goto HoldC;}
					
					}
				}
			}
					
					
					
					
					
}