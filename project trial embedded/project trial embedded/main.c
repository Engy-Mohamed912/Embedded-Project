

int main()
{
	  //initialization of cases
    char Choice = {'A','B','C','D','a','b','c','d'};
		int cookingtimeinsec;
		
    //Variables of case B
    int Beef_Weight[] = {1,2,3,4,5,6,7,8,9};
    int Beef_Weight_Input;
		
		//Variables of case C
    int Chicken_Weight[] = {1,2,3,4,5,6,7,8,9};
    int Chicken_Weight_Input;
    


    while (sw3 = 1){
            while (sw1 =! 1){
                
                if (sw2 = 1){
                    
                    switch (Choice)
                    {
                        case A
                        case 'a'
                        {
         
         
            
            
                        }

                        case 'B'
                        case 'b'
                        {
                        LCD_Display("Beef Weight?");
                        LCD_Receive("%d", &Beef_Weight_Input);
                        LCD_Display("%d", &Beef_Weight_Input);

                        if (Beef_Weight_Input == Beef_Weight[Beef_Weight_Input-1]){

                            cookingtimeinsec = Beef_Weight_Input * 30;
                            // TO BE EDITED
                            LCD_Display(cookingtimeinsec);
                            LCD_Display(Countdown);
                            LCD_Clear;
                        }
                        else
                            LCD_Display_Delay("Err");

                        }

                        case 'C';
                        case 'c';
                        {   
                            LCD_Display("Chicken Weight?");
                            LCD_Receive("%d", &Chicken_Weight_Input);
                            LCD_Display("%d", &Chicken_Weight_Input);

                            if (Chicken_Weight_Input == Chicken_Weight[Chicken_Weight_Input-1]){

                            cookingtimeinsec = Chicken_Weight_Input * 12;
                            // TO BE EDITED
                            LCD_Display(cookingtimeinsec);
                            LCD_Display(Countdown);
                            LCD_Clear;
                            }
                            else
                            LCD_Display_Delay("Err");

                        }

                        case 'D';
                        case 'd';

                        {
                            LCD_Display("Cooking time ?");

                        }
                
                
                    }
                }
            
            
                else if (sw1 = pressed) {
                
                //display remaining countdown
                
                if (sw1 = pressed)
                    //stop & clear
            }
    }





    
        }









    }

    }




}