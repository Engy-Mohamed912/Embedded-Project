#ifndef KEYPAD_H_
#define KEYPAD_H_
//#define  RowsSize  4
//#define  ColsSize  4
void keypad_Init (void);
void delay_ms(int r);
  unsigned  char keypad_u8_READ ( void);
//unsigned  char keypadArr[RowsSize][ColsSize];

#endif