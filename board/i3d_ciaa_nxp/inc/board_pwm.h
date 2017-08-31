#ifndef __BOARD_PWM_H__
#define __BOARD_PWM_H__

#include "chip.h"

// PWM channels
#define FAN_PWM_CHANNEL					1
#define BED_PWM_CHANNEL					2
#define EXT_PWM_CHANNEL					3
#define PREHEATER_PWM_CHANNEL			4

void Board_PWM_Init(void);
void Board_PWM_Write(uint8_t ch, uint8_t value);

#endif

