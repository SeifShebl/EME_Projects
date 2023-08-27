#define F_CPU 16000000

#include "LCD.h"
#include <util/delay.h>

void LCD_Init(void){
DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_RS_PIN, OUTPUT);
DIO_SetPinDir(LCD_4BIT_CMD_PORT, LCD_E_PIN, OUTPUT);

DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D4, OUTPUT);
DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D5, OUTPUT);
DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D6, OUTPUT);
DIO_SetPinDir(LCD_4BIT_DATA_PORT, LCD_D7, OUTPUT);
_delay_ms(20);

LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);
LCD_WriteCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
LCD_WriteCommand(LCD_CLEAR_COMMAND);
LCD_WriteCommand(LCD_CURSOR_OFF);
_delay_ms(10);
}

void LCD_WriteCommand(uint8 cmd){
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RS_PIN, LOW);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, HIGH);
	_delay_ms(1);


	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D4, GET_BIT(cmd,4));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D5, GET_BIT(cmd,5));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D6, GET_BIT(cmd,6));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D7, GET_BIT(cmd,7));
	_delay_ms(1);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, LOW);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, HIGH);
	_delay_ms(1);


	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D4, GET_BIT(cmd,0));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D5, GET_BIT(cmd,1));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D6, GET_BIT(cmd,2));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D7, GET_BIT(cmd,3));
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, LOW);
	_delay_ms(1);

}

void LCD_DisplayChar(uint8 character){
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RS_PIN, HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, HIGH);

	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D4, GET_BIT(character,4));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D5, GET_BIT(character,5));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D6, GET_BIT(character,6));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D7, GET_BIT(character,7));
	_delay_ms(1);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, LOW);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, HIGH);

	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D4, GET_BIT(character,0));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D5, GET_BIT(character,1));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D6, GET_BIT(character,2));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT,LCD_D7, GET_BIT(character,3));
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN, LOW);
}

void LCD_DisplayString(char* string){
	while(*string != '\0'){
		LCD_DisplayChar(*string);
		string++;
	}
}
void LCD_moveCursor(uint8 row,uint8 col)
{
uint8 lcd_memory_address;;

	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x14;
				break;
		case 3:
			lcd_memory_address=col+0x54;
				break;
	}
	LCD_WriteCommand( lcd_memory_address |LCD_SET_CURSOR_LOCATION);

}

void LCD_ClearScreen(){
	LCD_WriteCommand(LCD_CLEAR_COMMAND);
	_delay_ms(10);
}
void LCD_WriteNumber(int number){
	if (number==0){
		LCD_DisplayChar('0');
		return;
	}
	int n=number;
	uint8 count=0;
	uint8 digit=0;
	for (uint8 i=0;n!=0;i++){
		n=n/10;
		count++;
	}
	uint8 arr[count];
	n=number;
	for (int i=(count-1);i>=0 ;--i){
		digit=n%10;
		digit= digit+'0';
		arr[i]=digit;
		n=n/10;
	}
	for (uint8 i=0;i<count;i++){
		LCD_DisplayChar(arr[i]);
	}

}
