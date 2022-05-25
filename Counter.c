#include "GPIO.h"
#include "LCD.h"
#include "Switches.h"
#include "Counter.h"

unsigned char timerArray[4];

void displayTimer(){
	LCD_Cmd(0x01);
	LCD_Data(timerArray[0]);
	LCD_Data(timerArray[1]);
	LCD_Data(':');
	LCD_Data(timerArray[2]);
	LCD_Data(timerArray[3]);
}



void count(void){

while(1){
	displayTimer();
	if(timerArray[3] != '0' ){timerArray[3]--;}//decrement seconds
	else if((timerArray[3] == '0')&&(timerArray[2] != '0')) {timerArray[3]='9';timerArray[2]--;} //decrement seconds tens
	else if((timerArray[3] == '0')&&(timerArray[2] == '0')&&(timerArray[1] != '0')) {timerArray[3]='9';timerArray[2]='5';timerArray[1]--;}//decrement min
	else if((timerArray[3] == '0')&&(timerArray[2] == '0')&&(timerArray[1] == '0')&&(timerArray[0] != '0')) {timerArray[3]='9';timerArray[2]='5';timerArray[1]='9';timerArray[0]--;;}
	else if((timerArray[3] == '0')&&(timerArray[2] == '0')&&(timerArray[1] == '0')&&(timerArray[0] == '0')) break;
}}


void Countdown_Integertocharacter(int time){

unsigned char minutes_tens;
unsigned char minutes_units;
unsigned char seconds_tens;
unsigned char seconds_units;
int seconds;
int minutes;	
	
minutes = time / 60;
	
minutes_tens = minutes / 10;
minutes_units = minutes % 10;

seconds = time - (minutes_tens * 600) - (minutes_units * 60);

seconds_tens = seconds / 10;
seconds_units = seconds % 10;	

timerArray[0] = minutes_tens + '0';
timerArray[1] = minutes_units + '0';
timerArray[2] = seconds_tens + '0';
timerArray[3] = seconds_units + '0';
}
