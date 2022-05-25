#include "Macro.h"
#include "test.h"
#include "keypadF.h" 
void keypad_Init(void)
{
SYSCTL_RCGCGPIO_R |= 0x04;// Enable clock to PORTC
	 SYSCTL_RCGCGPIO_R |= 0x10; // Enable clock to PORTE
	 GPIO_PORTC_CR_R  |= 0xF0;  // Allow settings for all pins of PORTC
	 GPIO_PORTC_DEN_R |= 0xF0;  // Set PORTC as digital pins
	 GPIO_PORTE_DEN_R |= 0x0F;  // Set PORTE as digital pins
	 GPIO_PORTC_DIR_R |= 0x00;  // Set pins of PORTC as digital output
	 GPIO_PORTE_DIR_R |= 0x0F;  // Set pins of PORTE as digital input
   GPIO_PORTC_PDR_R |= 0xF0;
}
 void delay_ms(int r)
	{
int k,l;
for(k=0;k<r;k++)
for(l=0;l<700;l++)
{}
}

 unsigned char keypad_u8_READ( void ){
int i ,j;
  unsigned char keypadArr [4][4]= {{ '1', '2',  '3', 'A'},
	{ '4', '5',  '6', 'B'},
	{ '7', '8',  '9', 'C'},
	{ '*', '0',  '#', 'D'}};
  while(1)
  {
    for( i = 0; i < 4; i++)    //Scan columns loop
    {
      GPIO_PORTE_DATA_R = (1U << i);
     delay_ms(500);
      for(j = 0; j < 4; j++)  //Scan rows
      {
        if((GPIO_PORTC_DATA_R & 0xF0) & (1U << j+4))
				return keypadArr[j][i];
      }
    }
	}
}