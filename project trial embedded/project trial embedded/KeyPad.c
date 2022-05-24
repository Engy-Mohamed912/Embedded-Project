#include "GPIO.h"
#include "Button.h"
#include "tm4c123gh6pm.h"
#include "keyPad.h" 
void keypad_VInit (unsigned char portName)
{

Port_Init ( portName);
GPIO_SetPortDir( portName , 0x0F);
GPIO_EnablePullUp ( portName , 4);
GPIO_EnablePullUp  ( portName , 5);
GPIO_EnablePullUp  ( portName , 6);
GPIO_EnablePullUp  (portName , 7);
 }
unsigned  char keypad_u8_READ( unsigned char portName ) 
{ 
	unsigned  char keypadArr [4][4] = {{ '1', '2',  '3', 'A'},      
                                                { '4', '5',  '6', 'B'},      
                                                { '7', '8',  '9', 'C'},      
                                                { '*', '0',  '#', 'D'}}; 
unsigned char i, j ,z; /* i = row , j= columns , z is a variable */
unsigned char return_value = 0xFF;
	for (i =0 ; i<4 ; i++)
{											GPIO_WriteLowNibble ( portName , 0xFF);
											GPIO_WritePin( portName ,i , 0);
													for(j=0;j<4;j++)
														{	z = GPIO_ReadPin ( portName , j+4);
															if(z==0) { return_value = keypadArr[i][j]; break 
															;}
																		
																		} if (z==0)
																							break;
																		
																						}
															return return_value;
																					}
