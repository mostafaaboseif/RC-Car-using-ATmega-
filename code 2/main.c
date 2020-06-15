//Phase 5
#include "micro_config.h"
#include "std_types.h"
#include "mcal/macros/common_macros.h"
#include "mcal/pwm/pwm.h"
#include "hal/motor/motor.h"
#include "mcal/interrupt/interrupt.h"
#include "mcal/timer/timer.h"
#include "mcal/timer counter/timer counter.h"
#include "hal/lcd/lcd.h"
#include <stdio.h>
#include "hal/ultrasonic/ultrasonic.h"
#include "mcal/uart/uart.h"
#include "hal/wifi/wifi.h"
char p;
//void main(){
//	motor_init();
//	LCD_init();
//	WIFI_init();
//	_delay_ms(2000);
//	WIFI_Connect(MGTMM,8111998alia);
//	_delay_ms(20000);
//	WIFI_CreateServer(80);
//	_delay_ms(20000);
//	WIFI_PrintIP();
//	while(1){
//
//				p= WIFI_Read();
//
//				if(p=='w'){
//					forward(40);
//					//LCD_clearScreen();
//					//LCD_displayCharacter(p);
//				}else if(p=='a'){
//					left(40);
//					//LCD_clearScreen();
//					//LCD_displayCharacter(p);
//				}else if(p=='d'){
//					right(40);
//					//LCD_clearScreen();
//					//LCD_displayCharacter(p);
//				}else if(p=='s'){
//					backward(40);
//					//LCD_clearScreen();
//					//LCD_displayCharacter(p);
//				}else if(p=='b'){
//					stop();
//					//LCD_clearScreen();
//					//LCD_displayCharacter(p);
//				}
//	}
//}
//int main(){
//	ultrasonic_init_interrupt();
//	WIFI_init();
//	_delay_ms(20000);
//	WIFI_ConnectToTCPServer(192.168.43.43,8080);
//	_delay_ms(10000);
//
//	int fd;
//
//	forward(30);
//	while(read_front() > 10);
//	forward(0);
//	stop();
//	WIFI_SendTcpMessage(13,PHASE 5 ENDED);
//	_delay_ms(10000);
//	WIFI_SendTcpMessage(1,S);
//}
//



//Phase X
//		p= WIFI_Read();
//if(p=='0') stop();
//else if(p=='2')phase=2;
//else if(p=='3')phase=3;
//else if(p=='4')phase=4;
//else if(p=='5')phase=5;
//
//if(phase=='0') stop();
//else if(phase=='2')phase2();
//else if(phase=='3')phase3();
//else if(phase=='4')phase4();
//
//	}
//}
//
