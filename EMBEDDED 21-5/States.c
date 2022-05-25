#include "Counter.h"
#include "Switches.h"
#include "LCD.h"
#include "States.h"



void Start(int cookingtimeinsec){
	
	while(SW2_input() != 0){
		Countdown_Integertocharacter(cookingtimeinsec);
		count();
		
		if(SW2_input() == 0 || SW3_input()==0 ) goto Pause;
		
		Pause:
		Pause();
		
	}
	
}

void Pause (void){
	
	while(SW2_input() != 0)
	{
		displayTimer();
		
		if (SW2_input()==0) goto STOP;
		
		
		STOP:
		Shut();
	}
	
	
}

void Shut (void){
	
	LCD_Cmd(0x01);
	timerArray[0] = '0';
	timerArray[1] = '0';
	timerArray[2] = '0';
	timerArray[3] = '0';
	
}
