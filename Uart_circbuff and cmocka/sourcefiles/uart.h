/**
 * @file uart.h 
 * @brief This file is to be used to project 2.
 *
 * @author Gautham
 * @date Oct 28, 2017
 *
 */
#ifndef __uart_H__
#define __uart_H__

#include <stdint.h>

typedef enum{
	UART_Success,
	UART_Null_Error
}uart_status;


void uart_init(void);

uart_status send(uint8_t *ch);

uart_status  send_n(uint8_t *str,uint8_t length);

uart_status  receive(uint8_t *ptra);

uart_status  receive_n(uint8_t *str,uint8_t length);

void UART0_IRQHandler (void);

#endif

 
