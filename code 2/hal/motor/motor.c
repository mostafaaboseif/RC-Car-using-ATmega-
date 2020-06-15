 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM AVR driver
 *
 * Author: Ventor
 *
 *******************************************************************************/

#include "motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void motor_init(){
	 pwm_init();
	SET_BIT(DDRD, 3);
	SET_BIT(DDRD, 2);
	SET_BIT(DDRD, 6);
	SET_BIT(DDRD, 7);
}
void motorA(uint8_t direction,uint8_t speed)
{
	 pwm0_set_duty(speed);
	if(speed<=255)
	{
		if(direction) //clkwise
		{
			SET_BIT(PORTD,2);
			CLEAR_BIT(PORTD,3);
		}
		else if(!direction) //aclkwise
		{
			CLEAR_BIT(PORTD,2);
			SET_BIT(PORTD,3);
		}
	}

}

void motorB(uint8_t direction ,uint8_t speed)
{
	 pwm1_set_duty(speed);
	if(speed<=255)
	{
		if(direction) //clkwise
		{
			SET_BIT(PORTD,6);
			CLEAR_BIT(PORTD,7);

		}
		else if(!direction) //aclkwise
		{
			CLEAR_BIT(PORTD,6);
			SET_BIT(PORTD,7);
		}
	}

}
void forward(uint8_t spd){

	motorA(clkwise,spd);
	motorB(clkwise,0.75*spd);
}

void backward(uint8_t spd){

	motorA(aclkwise,spd);
	motorB(aclkwise,spd);
}

void left(uint8_t spd){
	motorA(aclkwise,spd);
	motorB(clkwise,spd);
}

void right(uint8_t spd){
	motorA(clkwise,spd);
	motorB(aclkwise,spd);
}

void stop(){
	motorA(aclkwise,0);
	motorB(aclkwise,0);
}
