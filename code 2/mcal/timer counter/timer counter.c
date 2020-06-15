#include "timer counter.h"


#define MASK 0x00

volatile uint32_t nbOfOverflows=0;

ISR(TIMER2_COMP_vect){
	nbOfOverflows++;
}

void timer2_init(uint8_t prescaler)
{
	SREG  |= (1<<7);// enable global interrupts in MC.
	TCNT2 = 0; //timer initial value
	OCR2  = 255; //compare value
	TIMSK |= (1<<OCIE2); //enable compare interrupt
	TCCR2 = (1<<FOC2) | (1<<WGM21);
	TCCR2 &= 0b11111000;
	TCCR2 |= (MASK | prescaler);
}

void timer2_reset()
{
	nbOfOverflows = 0;
}

uint32_t timer2_read()
{
	return nbOfOverflows*0.16;
}

