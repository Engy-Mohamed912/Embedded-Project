#ifndef led_h_
#define led_h_
void LED_init(unsigned char portName , unsigned char pinNumber );
void LED_On(unsigned char portName , unsigned char pinNumber );
void LED_Off(unsigned char portName , unsigned char pinNumber );
void LED_toggle(unsigned char portName , unsigned char pinNumber );

#endif
