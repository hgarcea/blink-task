#ifndef __BOARD_BUTTON_H__
#define __BOARD_BUTTON_H__

#include "chip.h"


#define BOARD_BUTTON_NO_BUTTON         0x00
#define BOARD_BUTTON_BUTTON0           0x01
#define BOARD_BUTTON_BUTTON1           0x02
#define BOARD_BUTTON_BUTTON2           0x04
#define BOARD_BUTTON_BUTTON3           0x08



uint8_t Board_Button_GetStatus(void);

#endif
