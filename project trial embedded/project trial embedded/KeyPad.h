#ifndef KEYPAD_H_
#define KEYPAD_H_
#define  RowsSize  4
#define  ColsSize  4
void KEYPAD_VInit (unsigned char portName);
unsigned  char keypad_u8_READ ( unsigned char portName);
unsigned  char keypadArr[RowsSize][ColsSize];
unsigned  char keypadArr [RowsSize][ColsSize] = {{ '1', '2',  '3', 'A'},      
                                                { '4', '5',  '6', 'B'},      
                                                { '7', '8',  '9', 'C'},      
                                                { '*', '0',  '#', 'D'}}; 
#endif