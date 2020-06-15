//#include "avr/io.h"
#include "uart.h"
void UART_init(void)
//#define FREQ 160000
{
  // Set BaudRate -> 9600/16MhZ
  UBRRL = (160000 / (96*16))-1 ;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0x86;
   
  // Enable RX and TX
  UCSRB = 0x18;
}

void UART_sendChar(uint8_t data)
{
  // Wait until transmission Register Empty
  while((UCSRA&0x20) == 0x00);
  UDR = data;
}

uint8_t UART_getChar(void)
{
  uint8_t Result;
  // Wait until Reception Complete
  while((UCSRA &0x80) == 0x00);
  Result = UDR;
  
  /* Clear Flag */
  SET_BIT(UCSRA,7);
  return Result;
  
}

void UART_sendString(uint8_t data[])
 {
		int j = 0;
		while(data[j] != '\0'){
			UART_sendChar(data[j]);
			j++;
		}
		UART_sendChar(0);
 }
 
 
uint8_t UART_getLastChar(uint8_t beforeLast)
{
	while(UART_getChar() != beforeLast)
		{_delay_ms(10);}
	return UART_getChar();
}
 
