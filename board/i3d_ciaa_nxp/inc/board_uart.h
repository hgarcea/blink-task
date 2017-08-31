#ifndef __BOARD_UART_H__
#define __BOARD_UART_H__

#include "chip.h"

void Board_UART_Init(LPC_USART_T *pUART, uint32_t rate);
void Board_UART_PutChar(LPC_USART_T *pUART, char ch);
int Board_UART_GetChar(LPC_USART_T *pUART);
void Board_UART_PutSTR(LPC_USART_T *pUART, const char *str);
void Board_UART_EnableEcho(LPC_USART_T *pUART);
void Board_UART_DisableEcho(LPC_USART_T *pUART);
void Board_UART_SetCallBack(LPC_USART_T *pUART, int (*func)(char));
void Board_UART_Interrupt(LPC_USART_T *pUART);

#endif

