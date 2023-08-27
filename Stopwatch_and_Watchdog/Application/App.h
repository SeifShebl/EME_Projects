
#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_


#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "avr/interrupt.h"
#include "../MCAL/Timers/Timers.h"

#define TIMER_INITIAL_VALUE 		247
#define OVERFLOWS_PER_SECOND 		62
#define TIME_OUT_SECONDS			30

volatile uint8 overflows=0;
volatile sint8 counter=0;
volatile uint8 watchdog=0;


#endif /* APPLICATION_APP_H_ */
