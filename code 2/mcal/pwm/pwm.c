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

#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void pwm_init()//TIMER
{
	TCNT1 = 0; // Timer initial value

	DDRD  = DDRD | (1<<PD5); //set OC4 as output pin --> pin where the PWM signal is generated from MC
	DDRD  = DDRD | (1<<PD4); //set OC5 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR1A = 0b10100001;
	TCCR1B = 0b00001101;
}

void pwm0_set_duty(uint8_t duty_cycle)
{
	OCR1A  = (duty_cycle*255)*0.01; //compare value
}

void pwm1_set_duty(uint8_t duty_cycle)
{
	OCR1B  = (duty_cycle*255)*0.01; //compare value
}
