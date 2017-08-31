#ifndef __BOARD_TIMER_H__
#define __BOARD_TIMER_H__

#include "chip.h"

int Board_Timer_Init(LPC_TIMER_T *pTMR);
int Board_Timer_SetCallBack(LPC_TIMER_T *pTMR, int (*func)(void));
int Board_Timer_SetSpeed(LPC_TIMER_T *pTMR, int speed);
void Board_Timer_Interrupt(LPC_TIMER_T *pTMR);

#endif

