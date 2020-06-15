#include "timer.h"

uint32_t maxOverflows;
uint32_t nbOfOverflows0=0;
ptr_func timer0_callback; //initiate null pointer

ISR(TIMER0_COMP_vect)
{
	nbOfOverflows0++;
	if(nbOfOverflows0 == maxOverflows){
		timer0_callback();
		nbOfOverflows0 = 0;

	}
}

void timer0_init(uint16_t period ,ptr_func callback){
	timer0_callback = callback;
	maxOverflows = (period*0.001)*16000000/255;
	TCNT0 = 0; //timer initial value
	OCR0  = 255; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS00);
	SREG  |= (1<<7);           // enable global interrupts in MC.

}
