#include "tm4c123gh6pm.h"
#include "Switches.h"



unsigned char SW1_input(void){
	return (GPIO_PORTA_DATA_R&0x10);
}

unsigned char SW2_input(void){
	return (GPIO_PORTA_DATA_R&0x01);
}

unsigned char SW3_input(void){
	return (GPIO_PORTA_DATA_R &0x04);
}