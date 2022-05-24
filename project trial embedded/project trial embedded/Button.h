#ifndef button_h_
#define button_h_

void Btn_Init(unsigned char Port_Name ,unsigned char Pin_Number);
unsigned char Btn_Read(unsigned char port_Name,unsigned char Pin_Number);
void Btn_InitPullUp(unsigned char Port_Name,unsigned char Pin_Number);
#endif
