#include "tm4c123gh6pm.h"
#include "Systick.h"

void LEDBlink(void)
{
	GPIO_PORTF_DATA_R |= 0x02; // turn on the red led
	delay_milli(500);
	GPIO_PORTF_DATA_R &=~0x02; // turn on the red led
	delay_milli(500);
}