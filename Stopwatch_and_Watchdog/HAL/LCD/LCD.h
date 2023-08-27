/*
 * LCD.h
 *
 *  Created on: Aug 18, 2023
 *      Author: SeifS
 */

#ifndef LCD_H_
#define LCD_H_
#include "../../Commons/std_types.h"
#include "../../MCAL/DIO/DIO.h"

#define LCD_MODE  4

#define LCD_4BIT_CMD_PORT     DIO_PORTA
#define LCD_4BIT_DATA_PORT    DIO_PORTB

#define LCD_RS_PIN    DIO_PIN3
//#define LCD_RW_PIN    DIO_PIN1
#define LCD_E_PIN     DIO_PIN2

#define LCD_D4 DIO_PIN0
#define LCD_D5 DIO_PIN1
#define LCD_D6 DIO_PIN2
#define LCD_D7 DIO_PIN4

#define LCD_DATA_PINS_DIR 0x17

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR                       0x80
#define LCD_CURSOR_BLINKING                  0x0F
#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_moveCursor(uint8 row,uint8 col);

void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_DisplayChar(uint8 character);

void LCD_DisplayString(char* string);

void LCD_ClearScreen();

void LCD_WriteNumber(int number);
#endif /* LCD_H_ */
