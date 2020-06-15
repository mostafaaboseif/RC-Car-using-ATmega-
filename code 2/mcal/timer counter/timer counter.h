#ifndef _TIMER_COUNTER_H_
#define _TIMER_COUNTER_H_

#include "../../micro_config.h"
#include "../../std_types.h"
#include "../macros/common_macros.h"


void timer2_init(uint8_t prescaler);
void timer2_reset();
uint32_t timer2_read();


#endif /* _TIMER_COUNTER_H_ */
