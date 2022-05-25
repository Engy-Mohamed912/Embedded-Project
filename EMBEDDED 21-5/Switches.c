#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "Switches.h"


unsigned char SW1_input(void){
	return GPIO_ReadPin('f',4);
}

unsigned char SW2_input(void){
	return GPIO_ReadPin('f',0);
}

unsigned char SW3_input(void){
	return GPIO_ReadPin('a',0);
}

