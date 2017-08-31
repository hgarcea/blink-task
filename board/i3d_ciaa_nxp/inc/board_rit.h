#ifndef __BOARD_RIT_H__
#define __BOARD_RIT_H__

#include "chip.h"

void Board_RIT_SetCounterWithCallback(uint32_t count, void (*func)(void));
void Board_RIT_StopCounter(void);
void Board_RIT_ResumeCounter(void);
int Board_RIT_IsOverflow(void);
void Board_RIT_Interrupt(void);

#endif

