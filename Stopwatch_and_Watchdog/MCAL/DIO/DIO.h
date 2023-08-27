/*
 * DIO.h
 *
 *  Created on: Aug 17, 2023
 *      Author: SeifS
 */

#ifndef DIO_H_
#define DIO_H_

#include "../../Commons/std_types.h"
#include "../../Commons/Bit_math.h"
#include "avr/io.h"
typedef enum{
	LOW,HIGH
}Value;

typedef enum {
	INPUT,OUTPUT
}DirectionType;


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0x00

#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF


void DIO_SetPortDir(uint8 Port,DirectionType Dir);
void DIO_SetPinDir(uint8 Port,uint8 Pin,DirectionType Dir);

void DIO_SetPortVal(uint8 Port,Value Val);
void DIO_SetPinVal(uint8 Port,uint8 Pin,Value Val);

void DIO_ReadPort (uint8 Port, uint8* Val);
uint8 DIO_ReadPin(uint8 Port,uint8 Pin);

void DIO_TogglePin(uint8 Port,uint8 Pin);

#endif /* DIO_H_ */
