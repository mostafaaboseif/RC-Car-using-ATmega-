 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Source file for the PWM AVR driver
 *
 * Author: Ventor
 *
 *******************************************************************************/

#ifndef _PWM_H_
#define _PWM_H_

#include "../../micro_config.h"
#include "../../std_types.h"
#include "../macros/common_macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void pwm_init();
void pwm0_set_duty(uint8_t duty_cycle);
void pwm1_set_duty(uint8_t duty_cycle);


#endif /* _PWM_H_ */
