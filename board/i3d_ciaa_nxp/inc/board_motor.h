#ifndef __BOARD_MOTOR_H__
#define __BOARD_MOTOR_H__

#include "chip.h"

#define BOARD_MOTOR_X       0x01
#define BOARD_MOTOR_Y       0x02
#define BOARD_MOTOR_Z       0x04
#define BOARD_MOTOR_E       0x08

typedef enum
{
   ENDSTOP_X_ORG,
   ENDSTOP_X_END,
   ENDSTOP_Y_ORG,
   ENDSTOP_Y_END,
   ENDSTOP_Z_ORG,
   ENDSTOP_Z_END,
} Endstop_t;


void Board_Motor_Init(void);
int8_t Board_Motor_Endstops_GetStatus(Endstop_t endstopName);
void Board_Motor_SetEnable(uint8_t pin);
void Board_Motor_ClearEnable(uint8_t pin);
void Board_Motor_SetDir(uint8_t pin);
void Board_Motor_ClearDir(uint8_t pin);
void Board_Motor_SetStep(uint8_t pin);
void Board_Motor_ClearStep(uint8_t pin);

#endif

