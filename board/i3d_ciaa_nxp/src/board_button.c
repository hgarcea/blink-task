#include "chip.h"

#include "os.h"               /* <= operating system header */

#include "board.h"






uint8_t Board_Button_GetStatus(void)
{
   uint8_t ret;

   ret = BOARD_BUTTON_NO_BUTTON;
   
   if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_BUTTON1_PORT_NUM,GPIO_BUTTON1_PIN_NUM ) == 0) {
      ret |= BOARD_BUTTON_BUTTON0;
   }
   if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_BUTTON2_PORT_NUM,GPIO_BUTTON2_PIN_NUM ) == 0) {
      ret |= BOARD_BUTTON_BUTTON1;
   }
   if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_BUTTON3_PORT_NUM,GPIO_BUTTON3_PIN_NUM ) == 0) {
      ret |= BOARD_BUTTON_BUTTON2;
   }
   if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_BUTTON4_PORT_NUM,GPIO_BUTTON4_PIN_NUM ) == 0) {
      ret |= BOARD_BUTTON_BUTTON3;
   }

   return ret;
}



