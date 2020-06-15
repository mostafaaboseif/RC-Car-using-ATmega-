
#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

/*******************************************************************************
 *                              INCLUDES                                       *
 *******************************************************************************/
#include "../../micro_config.h"
#include "../../std_types.h"
#include "../../mcal/macros/common_macros.h"
#include "../../mcal/timer counter/timer counter.h"
#include "../../mcal/timer/timer.h"
#include "../../mcal/interrupt/interrupt.h"

/*******************************************************************************
 *                              CONSTANTS                                       *
 *******************************************************************************/
#define ULTRASONIC_PERIOD 70
#define TRIG1 PB1
#define PORT_TRIG1 PORTB
#define DDR_TRIG1 DDRB
#define TRIG2 PC2
#define ECHO2 PC3
#define PORT2u PORTC
#define PIN2u PINC
#define DDR2 DDRC

/*******************************************************************************
 *                     LOCAL FUNCTIONS PROTOTYPES                              *
 *******************************************************************************/
void ultrasonic_init_polling();
void ultrasonic_init_interrupt();
int read_right();
void timer0_callback_function();
void interrupt0_callback_function();
uint16_t read_front();

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */



