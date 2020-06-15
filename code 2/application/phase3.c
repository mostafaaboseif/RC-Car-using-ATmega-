#include "phase3.h"

void phase3(){
	int fd,rd;

	LCD_clearScreen();
	LCD_displayString("Phase 3");

		fd=read_front();
		rd=read_right();

		if((fd>0)&&(fd<30)){
			if(rd<10) {
				stop();
				_delay_ms(200);
				left(30);
				_delay_ms(200);
			}else if(rd>40){
				stop();
				_delay_ms(200);
				right (30);
				_delay_ms(200);
			}else {
				stop();
				_delay_ms(100);
			}
		}else{
			forward(30);
			_delay_ms(100);
	}
}

//#include "micro_config.h"
//#include "std_types.h"
//#include "mcal/macros/common_macros.h"
//#include "mcal/pwm/pwm.h"
//#include "hal/motor/motor.h"
//#include "mcal/interrupt/interrupt.h"
//#include "mcal/timer/timer.h"
//#include "mcal/timer counter/timer counter.h"
//#include "hal/lcd/lcd.h"
//#include <stdio.h>
//#include "hal/ultrasonic/ultrasonic.h"
//#include "mcal/uart/uart.h"
//char p=0;
//int main(){
//	int fd,rd;
//	ultrasonic_init_interrupt();
//	ultrasonic_init_polling();
//	motor_init();
//	LCD_init();
//	char *fdChar[10];
//	char *rdChar[10];
//
//
//	while(1){
//		fd= read_front(); //read front sensor
//				if( ( (fd<0)||(fd>15) ) ) /// if front dist is infinite or more than 20 cm
//
//				    forward (15);
//
//					else
//					{
//						stop (); /*add optional delay */
//						rd=( read_right()+read_right()+read_right() ) / 3 ; // read right sensor 3 times and take average
//
//						if ( ( (rd<0)||(rd>15) )) /// if right dist is infinite or more than 20 cm
//										/// priority to forward then right then left
//									{
//									right (30);
//									_delay_ms(250); //rotation time
//									stop();
//									//_delay_ms (100);
//									}
//
//						else
//						{
//									left (30);
//									_delay_ms(250); //rotation time
//									stop();
//									//_delay_ms (100);
//									}
//
//
//					}
//	}
//
//}
//
//
//
