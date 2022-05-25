#include "tm4c123gh6pm.h"
#include "Systick.h"


void SysTick_Wait( unsigned long delay   ){
	
	NVIC_ST_CTRL_R  = 0x00 ; //disable systick or clear enable to stop counter 
	NVIC_ST_RELOAD_R = delay -1 ;
	NVIC_ST_CURRENT_R =0;  // clean counter value 
	NVIC_ST_CTRL_R = 0x05 ; // enable systick again & clock
	while((NVIC_ST_CTRL_R&0x00010000)==0){// wait for flag
	}
}
//this function wait 10ms for minimum counter =1
void Systick_Wait10ms( unsigned long  mul ){
	long i=0 ;
for (i=0; i<mul ;i++){
		SysTick_Wait(16000);//wait 10 ms 
	// as frequency of the systick is 16 MHz

}	
}


void delay_milli(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}

