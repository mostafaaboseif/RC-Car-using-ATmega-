#ifndef INTERRUPT_H_
#define INTERRUPT_H_
//TODO include & delete typedef

#include "../../micro_config.h"
#include "../../std_types.h"
#include "../macros/common_macros.h"

#define RISING 1
#define FALLING 0
#define BOTH 2

void interrupt0_init(uint8_t type, ptr_func callback);
void interrupt0_deinit();
void interrupt1_init(uint8_t type, ptr_func callback);
void interrupt1_deinit();
void interrupt2_init(uint8_t type, ptr_func callback);
void interrupt2_deinit();

#endif /* INTERRUPT_H_ */
