#ifndef __BOARD_LED_H__
#define __BOARD_LED_H__

#include "chip.h"

#define BOARD_LED_0_R      0x01
#define BOARD_LED_0_G      0x02
#define BOARD_LED_0_B      0x04
#define BOARD_LED_1        0x08
#define BOARD_LED_2        0x10
#define BOARD_LED_3        0x20


void Board_Led_Set(uint8_t value);
void Board_Led_Clear(uint8_t value);
int8_t Board_Led_GetStatus(void);
void Board_Led_Toggle(uint8_t value);

#endif

