#include "phase4.h"

void phase4(void){


	LCD_clearScreen();
	LCD_displayString("Phase 4");

		p= WIFI_Read();

		if(p=='w'){
			forward(40);
			LCD_clearScreen();
			LCD_displayCharacter(p);
		}else if(p=='a'){
			left(40);
			LCD_clearScreen();
			LCD_displayCharacter(p);
		}else if(p=='d'){
			right(40);
			LCD_clearScreen();
			LCD_displayCharacter(p);
		}else if(p=='s'){
			backward(40);
			LCD_clearScreen();
			LCD_displayCharacter(p);
		}else if(p=='b'){
			stop();
			LCD_clearScreen();
			LCD_displayCharacter(p);
		}


	}

