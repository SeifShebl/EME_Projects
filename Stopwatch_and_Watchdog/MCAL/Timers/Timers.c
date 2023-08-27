#include "Timers.h"


void Timer0_Init(){
	SREG  |= (1<<7);
	TCCR0=0x85;
	TIMSK=(TIMSK&0xFE)|1;
	TCNT0=247;
}

void Timer0_Set_Start(uint8 start){
	TCNT0=start;
}
