#include "Macros.h"
#include "keypad.h" 
#include "tm4c123gh6pm.h"
#include "Systick.h"


 

unsigned char keypad_u8_READ( void ){
int i ,j;
unsigned  char keypadArr [4][4]= {{ '1', '2',  '3', 'A'},
																	{ '4', '5',  '6', 'B'},
																	{ '7', '8',  '9', 'C'},
																	{ '*', '0',  '#', 'D'}};
  while(1)
  {
    for( i = 0; i < 4; i++)    //Scan columns loop
    {
      GPIO_PORTE_DATA_R = (1U << i);
    delay_milli(500);
      for(j = 0; j < 4; j++)  //Scan rows
      {
        if((GPIO_PORTC_DATA_R & 0xF0) & (1U << j+4))
				return keypadArr[j][i];
      }
    }
	}
}