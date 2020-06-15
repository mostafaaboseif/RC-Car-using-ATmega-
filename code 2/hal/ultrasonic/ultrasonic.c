
/*******************************************************************************
 *                              INCLUDES                                       *
 *******************************************************************************/
#include "ultrasonic.h"

/*******************************************************************************
 *                     LOCAL FUNCTIONS PROTOTYPES                              *
 *******************************************************************************/
void ultrasonic_init_polling();
int read_right();
void timer0_callback_function();
void interrupt0_callback_function();
void ultrasonic_init_interrupt();
uint16_t read_front();

/*******************************************************************************
 *                       GLOBAL STATIC VARIABLES                               *
 *******************************************************************************/
uint32_t ultra1_beg ;
uint32_t ultra1_end ;
uint16_t ultra_distance;

/*******************************************************************************
 *                       GLOBAL EXTERN VARIABLES                               *
 *******************************************************************************/
extern volatile uint32_t nbOfOverflows;

/*******************************************************************************
 *                    LOCAL FUNCTIONS IMPLEMENTATIONS                          *
 *******************************************************************************/

void timer0_callback_function(){
	CLEAR_BIT(PORT_TRIG1, TRIG1);
	_delay_us(10);
	SET_BIT(PORT_TRIG1, TRIG1);
	_delay_us(10);
	CLEAR_BIT(PORT_TRIG1, TRIG1);
}

void interrupt0_callback_function(){
	if((GET_BIT(MCUCSR,ISC2))){
		ultra1_beg = nbOfOverflows;
	}
	else {
		ultra1_end = nbOfOverflows;
		ultra_distance = (ultra1_end - ultra1_beg)*0.16;
	}
}

void ultrasonic_init_interrupt()
{
	timer0_init(ULTRASONIC_PERIOD ,timer0_callback_function);
	timer2_init(PRE_1);
	interrupt2_init(BOTH, interrupt0_callback_function);
	SET_BIT(DDRB,1);
	CLEAR_BIT(PORTB,1);
}

uint16_t read_front()
{
	return ultra_distance ;
}


void ultrasonic_init_polling(){
	SET_BIT(DDR2, TRIG2);
	CLEAR_BIT(DDR2, ECHO2);
	timer2_init(PRE_1);
}
int read_right(){

	CLEAR_BIT(PORT2u, TRIG2);
	_delay_us(10);
	SET_BIT(PORT2u, TRIG2);
	_delay_us(10);
	CLEAR_BIT(PORT2u, TRIG2);
	int t1 = nbOfOverflows;
	while(!GET_BIT(PIN2u,ECHO2));
	while(PIN2u & (1 << ECHO2));
	int t2 = nbOfOverflows;
	return ((t2 - t1) * 0.16 - 5);
}


