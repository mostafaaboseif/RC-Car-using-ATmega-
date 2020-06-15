/*
 * motor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */



 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: motor.h
 *
 * Description: Source file for the motor AVR driver
 *
 * Author: Ventor
 *
 *******************************************************************************/

#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

#include "../../micro_config.h"
#include "../../std_types.h"
#include "../../mcal/macros/common_macros.h"
#include "../../mcal/pwm/pwm.h"

/*******************************************************************************
 *                     preprocessors Prototypes                                   *
 *******************************************************************************/
#define clkwise 1
#define aclkwise 0


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void motor_init();
void forward(uint8_t spd);
void backward(uint8_t spd);
void left(uint8_t spd);
void right(uint8_t spd);
void motorA(uint8_t direction ,uint8_t speed);
void motorB(uint8_t direction ,uint8_t speed);
void stop();





#endif /* HAL_MOTOR_MOTOR_H_ */
