

#include "DIO.h"


void DIO_SetPortDir(uint8 Port, DirectionType Dir) {
	switch (Port) {
	case DIO_PORTA:
		DDRA = Dir;
		break;
	case DIO_PORTB:
		DDRB = Dir;
		break;
	case DIO_PORTC:
		DDRC = Dir;
		break;
	case DIO_PORTD:
		DDRD = Dir;
		break;

	}
}
void DIO_SetPinDir(uint8 Port, uint8 Pin, DirectionType Dir) {
	switch (Port) {
	case DIO_PORTA:
		if (Dir == OUTPUT) {
			SET_BIT(DDRA, Pin);
		} else {
			CLEAR_BIT(DDRA, Pin);
		}
		break;
	case DIO_PORTB:
		if (Dir == OUTPUT) {
			SET_BIT(DDRB, Pin);
		} else {
			CLEAR_BIT(DDRB, Pin);
		}
		break;
	case DIO_PORTC:
		if (Dir == OUTPUT) {
			SET_BIT(DDRC, Pin);
		} else {
			CLEAR_BIT(DDRC, Pin);
		}
		break;
	case DIO_PORTD:
		if (Dir == OUTPUT) {
			SET_BIT(DDRD, Pin);
		} else {
			CLEAR_BIT(DDRD, Pin);
		}
		break;

	}
}

void DIO_SetPortVal(uint8 Port,uint8 Val){
	switch (Port) {
	case DIO_PORTA:
		PORTA = Val;
		break;
	case DIO_PORTB:
		PORTB = Val;
		break;
	case DIO_PORTC:
		PORTC = Val;
		break;
	case DIO_PORTD:
		PORTD = Val;
		break;

	}
}

void DIO_SetPinVal(uint8 Port,uint8 Pin,Value Val){
	switch (Port) {
	case DIO_PORTA:
		if (Val == HIGH) {
			SET_BIT(PORTA, Pin);
		} else {
			CLEAR_BIT(PORTA, Pin);
		}
		break;
	case DIO_PORTB:
		if (Val == HIGH) {
			SET_BIT(PORTB, Pin);
		} else {
			CLEAR_BIT(PORTB, Pin);
		}
		break;
	case DIO_PORTC:
		if (Val == HIGH) {
			SET_BIT(PORTC, Pin);
		} else {
			CLEAR_BIT(PORTC, Pin);
		}
		break;
	case DIO_PORTD:
		if (Val == HIGH) {
			SET_BIT(PORTD, Pin);
		} else {
			CLEAR_BIT(PORTD, Pin);
		}
		break;

	}
}
void DIO_ReadPort (uint8 Port, uint8* Val){
	switch (Port) {
	case DIO_PORTA:
		*Val=PINA;
		break;
	case DIO_PORTB:
		*Val=PINB;
		break;
	case DIO_PORTC:
		*Val=PINC;
		break;
	case DIO_PORTD:
		*Val=PIND;
		break;

	}
}
uint8 DIO_ReadPin(uint8 Port,uint8 Pin){
	uint8 Val =0;
	switch (Port) {
	case DIO_PORTA:
		Val=GET_BIT(PINA,Pin);
		break;
	case DIO_PORTB:
		Val=GET_BIT(PINB,Pin);
		break;
	case DIO_PORTC:
		Val=GET_BIT(PINC,Pin);
		break;
	case DIO_PORTD:
		Val=GET_BIT(PIND,Pin);
		break;

	}
	return Val;
}

void DIO_TogglePin(uint8 Port,uint8 Pin){
	switch (Port) {
	case DIO_PORTA:
		TOGGLE_BIT(PORTA,Pin);
		break;
	case DIO_PORTB:
		TOGGLE_BIT(PORTB,Pin);
		break;
	case DIO_PORTC:
		TOGGLE_BIT(PORTC,Pin);
		break;
	case DIO_PORTD:
		TOGGLE_BIT(PORTD,Pin);
		break;

	}
}
