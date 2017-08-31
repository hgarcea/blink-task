#include "chip.h"

#include "board.h"



void Board_Led_Set(uint8_t value)
{
   if (value & BOARD_LED_0_R) Chip_GPIO_SetValue(LPC_GPIO_PORT, 5, 1 << 0);
   if (value & BOARD_LED_0_G) Chip_GPIO_SetValue(LPC_GPIO_PORT, 5, 1 << 1);
   if (value & BOARD_LED_0_B) Chip_GPIO_SetValue(LPC_GPIO_PORT, 5, 1 << 2);
   if (value & BOARD_LED_1) Chip_GPIO_SetValue(LPC_GPIO_PORT, 0, 1 << 14);
   if (value & BOARD_LED_2) Chip_GPIO_SetValue(LPC_GPIO_PORT, 1, 1 << 11);
   if (value & BOARD_LED_3) Chip_GPIO_SetValue(LPC_GPIO_PORT, 1, 1 << 12);
}

void Board_Led_Clear(uint8_t value)
{
   if (value & BOARD_LED_0_R) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5, 1 << 0);
   if (value & BOARD_LED_0_G) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5, 1 << 1);
   if (value & BOARD_LED_0_B) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5, 1 << 2);
   if (value & BOARD_LED_1) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 0, 1 << 14);
   if (value & BOARD_LED_2) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1, 1 << 11);
   if (value & BOARD_LED_3) Chip_GPIO_ClearValue(LPC_GPIO_PORT, 1, 1 << 12);
}

int8_t Board_Led_GetStatus(void)
{
   int8_t ret;

   ret = 0;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 5, 0)) ret |= BOARD_LED_0_R;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 5, 1)) ret |= BOARD_LED_0_G;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 5, 2)) ret |= BOARD_LED_0_B;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 0, 14)) ret |= BOARD_LED_1;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 1, 11)) ret |= BOARD_LED_2;
   if (!Chip_GPIO_GetPinState(LPC_GPIO_PORT, 1, 12)) ret |= BOARD_LED_3;
   return ret;
}

void Board_Led_Toggle(uint8_t value)
{
   uint8_t status;

   status = Board_Led_GetStatus();
   Board_Led_Clear(status & value);
   status ^= 0xff;
   Board_Led_Set(status & value);
}

