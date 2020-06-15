#ifndef _TIMER_H_
#define _TIMER_H_

#include "../../micro_config.h"
#include "../../std_types.h"
#include "../macros/common_macros.h"


void timer0_init(uint16_t period , ptr_func callback);


#endif /* _TIMER_H_ */
