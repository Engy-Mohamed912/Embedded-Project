else if (Choice == 'C'){
					
					
  				while (SW3_input()!=0){//door is closed
					while(SW1_input()!=0){//check the pause switch
					
					unsigned char ChickenWeightText[] = "Chicken Weight?";
					unsigned char ChickenWeightText2[] = "Chicken Weight is ";
					unsigned char ChickenWeight[] = {'1','2','3','4','5','6','7','8','9'};
					unsigned char ChickenWeightInput;
					int i;
					int True;
					int Cookingtimeinsec;
					
					Start:
					
					LCD_Cmd(0x01);
					LCD_WriteString(ChickenWeightText);
					ChickenWeightInput = keypad_u8_READ();
					
					
					for (i=0;i<10;i++){ if(ChickenWeightInput == ChickenWeight[i]){True = 1;}}  //Checking of Value
					
					if (True == 1){
						
						LCD_Cmd(0x01);
						Cookingtimeinsec = (ChickenWeightInput - '0') * 12;
						LCD_WriteString(ChickenWeightText2);
						LCD_Data(ChickenWeightInput);
						delay_milli(2000);
						LCD_Cmd(0x01);
						for(int i =Cookingtimeinsec ;i>=1;i--)
						{
						 Countdown_Integertocharacter(i);
			       delay_milli(1000);
			       LCD_Cmd(0x01);
		        }
					}
				
						else {
						
						LCD_Cmd(0x01);
						LCD_WriteString("Err");
						delay_milli(2000);
						goto Start;
						
						
					}
						
						HoldC:
					  Start(Cookingtimeinsec);
//					if (SW2_input()==0){Start(Cookingtimeinsec);}
//					else {goto HoldC;}
//					
//					}
//				}
			}
					
					
					
					
		}	
				}