define NVIC_ST_CTRL_R (((volatile unsigned long)0xE000E010))
#define NVIC_ST_RELOAD_R (((volatile unsigned long)0xE000E014))
#define NVIC_ST_CURRENT_R (((volatile unsigned long)0xE000E018))
#include "Io.h"

void SystemInit() {
SYSCTL_RCGCGPIO_R |= 0x20;
while ((SYSCTL_PRGPIO_R &0x20)==0);
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x0E;
GPIO_PORTF_AMSEL_R &= ~0x0E;
GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
GPIO_PORTF_AFSEL_R &= ~0x0E;
GPIO_PORTF_DIR_R |= 0x0E;
GPIO_PORTF_DEN_R |=0x0E;
GPIO_PORTF_DATA_R |= 0x0E;
}
void SysTick_wait(unsigned long delay){
NVIC_ST_CTRL_R=0x00;
NVIC_ST_RELOAD_R= delay-1;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0x05;
while((NVIC_ST_CTRL_R& 0x00010000)==0) //wait for COUNT Flag
{ }
}
void genericDelay(unsigned long time)
{ int i;
for(i=0;i< time ;i++){
SysTick_wait(16000);//wait 1ms
}
}