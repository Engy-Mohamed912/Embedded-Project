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
				

					Start:
					
					LCD_Cmd(0x01);
					LCD_WriteString(BeefWeightText);
					BeefWeightInput = keypad_u8_READ();
					
					
					for (i=0;i<10;i++){ if(BeefWeightInput == BeefWeight[i]){True = 1;}}  //Checking of Value
					
					if (True == 1){
						
						LCD_Cmd(0x01);
						Cookingtimeinsec = (BeefWeightInput - '0') * 30;
						LCD_WriteString(BeefWeightText2);
						LCD_Data(BeefWeightInput);
						delay_milli(2000);
						LCD_Cmd(0x01);
						for(int i =Cookingtimeinsec ;i>=1;i--)
						{
						 Countdown_Integertocharacter(i);
			       delay_milli(1000);
			       LCD_Cmd(0x01);
		        }
					}
				
					else{
						
						LCD_Cmd(0x01);
						LCD_WriteString("Err");
						delay_milli(2000);
						goto Start;
						
						
					}
						
						HoldB:
					Start(Cookingtimeinsec);
 //       	if (SW2_input()==0){Start(Cookingtimeinsec);}
//					else {goto HoldB;}
//					
//					}
//				}
			}
					
		}}