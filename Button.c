#include "GPIO.h"
#include "macro.h"

void Btn_Init(unsigned char Port_Name ,unsigned char Pin_Number){
	Port_Init(Port_Name );
	GPIO_SetPinDir (Port_Name , Pin_Number,0);
}


unsigned char Btn_Read(unsigned char port_Name,unsigned char Pin_Number){
	return GPIO_ReadPin ( port_Name ,Pin_Number );
}

void Btn_InitPullUp(unsigned char Port_Name,unsigned char Pin_Number){
	Port_Init(Port_Name );
	GPIO_SetPinDir (Port_Name , Pin_Number,0);
	GPIO_EnablePullUp (Port_Name ,Pin_Number );
}