#ifndef UART_H_
#define UART_H_

#include "../../mcal/macros/common_macros.h"
#include  "../../micro_config.h"

void UART_init(void);

void UART_sendChar(uint8_t data);

uint8_t UART_getChar(void);

void UART_sendString(uint8_t data[]);

uint8_t UART_getLastChar(uint8_t beforeLast);

#endif /* UART_H_ */
