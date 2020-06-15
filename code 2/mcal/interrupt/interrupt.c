#include "interrupt.h"

ptr_func int0_callback;
ptr_func int1_callback;
ptr_func int2_callback;

uint8_t type_flag=0;
uint8_t type2;

ISR(INT0_vect)
{
	int0_callback();
}

ISR(INT1_vect)
{
	int1_callback();
}

ISR(INT2_vect)
{
	int2_callback();
	if(type_flag==1)
	CLEAR_BIT(GICR,INT2);
	TOGGLE_BIT(MCUCSR,ISC2);
	SET_BIT(GICR,INT2);
	CLEAR_BIT(GIFR,INTF2);

}


void interrupt0_init(uint8_t type, ptr_func callback){
	int0_callback = callback;
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));										// Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);											// Enable external interrupt pin INT0
	if(type != BOTH) {MCUCR |= (type<<ISC00) | (1<<ISC01);}     // Trigger INT0 with the rising/falling edge
	else {MCUCR |= (1<<ISC00);									// Trigger INT0 with the both edges
	SREG = SREG | (1<<7);										// Enable interrupts by setting I-bit
}

void interrupt1_init(uint8_t type, ptr_func callback){
	int1_callback = callback;
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD3));										// Configure INT0/PD2 as input pin
	GICR  |= (1<<INT1);											// Enable external interrupt pin INT0
	if(type != BOTH) {MCUCR |= (type<<ISC10) | (1<<ISC11);}     // Trigger INT0 with the rising/falling edge
	else {MCUCR |= (1<<ISC10);	}								// Trigger INT0 with the both edges
	}
	SREG = SREG | (1<<7);										// Enable interrupts by setting I-bit
}

void interrupt2_init(uint8_t type, ptr_func callback){
	int2_callback = callback;
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRB  &= (~(1<<PB2));										// Configure INT0/PD2 as input pin
	GICR  |= (1<<INT2);											// Enable external interrupt pin INT0
	if(type != BOTH) {MCUCSR |= (type<<ISC2);}				     // Trigger INT0 with the rising/falling edge
	else {
		type_flag=1;
	}															// Trigger INT0 with the both edges
	sei();														// Enable interrupts by setting I-bit
}

