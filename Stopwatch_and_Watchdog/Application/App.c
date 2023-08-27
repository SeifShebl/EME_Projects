#include"App.h"

ISR(TIMER0_OVF_vect) {
	if (overflows == OVERFLOWS_PER_SECOND) {
		Timer0_Set_Start(TIMER_INITIAL_VALUE);
		watchdog++;
		counter++;
		DIO_TogglePin(DIO_PORTB, DIO_PIN7);
		overflows = 0;
		LCD_moveCursor(0, 0);
		LCD_WriteNumber(counter);

	}

	if (watchdog == TIME_OUT_SECONDS) {
		LCD_ClearScreen();
		LCD_moveCursor(1, 5);
		LCD_DisplayString("WATCHDOG");
		LCD_moveCursor(2, 5);
		LCD_DisplayString("TIMEOUT");

		watchdog = 0;
		TCCR0 = 0;
	}
	overflows++;
}
void app_init() {
	LCD_Init();
	LCD_WriteNumber(0);
	Timer0_Init();
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, OUTPUT);
	DIO_SetPinVal(DIO_PORTB, DIO_PIN7, LOW);
}

void app() {
	/* Do Nothing*/
}
