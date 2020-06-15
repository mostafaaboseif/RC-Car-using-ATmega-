#include "phase2.h"

int state = 0;

void phase2(){

	LCD_clearScreen();
	LCD_displayString("Phase 2");

		int dist = read_front();

		if(dist<10){
			LCD_clearScreen();
			LCD_displayString("STOP");
			stop();
		}
		if(state == 0){
			forward(30);
			LCD_clearScreen();
			LCD_displayString("STATE1");
		}else if(state == 1){
			forward(60);
			LCD_clearScreen();
			LCD_displayString("STATE2");
		}else if (state == 2){
			forward(90);
			LCD_clearScreen();
			LCD_displayString("STATE3");
		}else if(state == 3){
			LCD_clearScreen();
			LCD_displayString("STOP");
			stop();
		}

		if(dist<30) {
			state++;
			_delay_ms(500);
			LCD_clearScreen();
			LCD_displayString("STATE3");
		}

		LCD_goToRowColumn(1,0);
		LCD_intgerToString(dist);
		_delay_ms(100);



}

