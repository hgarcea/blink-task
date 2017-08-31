#include "chip.h"

#include "board.h"


#define SCU_BED_HEATER_PORT_NUM            4 /* P4        */
#define SCU_BED_HEATER_PIN_NUM             6 /* P4.6      */
#define SCU_EXT_HEATER_PORT_NUM            4 /* P4        */
#define SCU_EXT_HEATER_PIN_NUM             5 /* P4.5      */
#define SCU_PRE_HEATER_PORT_NUM            6 /* P6        */
#define SCU_PRE_HEATER_PIN_NUM            12 /* P6.12     */
#define SCU_PIECE_FAN_PORT_NUM             4 /* P4        */
#define SCU_PIECE_FAN_PIN_NUM              4 /* P4.4      */


static uint8_t __init = 0;


void Board_PWM_Init(void)
{
   if (__init) return;
   __init = 1;
   Board_GPIO_Init();

   Chip_SCU_PinMuxSet(SCU_PIECE_FAN_PORT_NUM, SCU_PIECE_FAN_PIN_NUM, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC1)); //CTOUT_2
   Chip_SCU_PinMuxSet(SCU_BED_HEATER_PORT_NUM, SCU_BED_HEATER_PIN_NUM, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC1)); //CTOUT_4
   Chip_SCU_PinMuxSet(SCU_EXT_HEATER_PORT_NUM, SCU_EXT_HEATER_PIN_NUM, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC1)); //CTOUT_5
   Chip_SCU_PinMuxSet(SCU_PRE_HEATER_PORT_NUM, SCU_PRE_HEATER_PIN_NUM, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC1)); //CTOUT_7

   Chip_SCTPWM_Init(LPC_SCT);
   Chip_SCTPWM_SetRate(LPC_SCT, 1000);
   Chip_SCTPWM_SetOutPin(LPC_SCT, FAN_PWM_CHANNEL, 2 /*CTOUT_2*/);
   Chip_SCTPWM_SetOutPin(LPC_SCT, BED_PWM_CHANNEL, 4 /*CTOUT_4*/);
   Chip_SCTPWM_SetOutPin(LPC_SCT, EXT_PWM_CHANNEL, 5 /*CTOUT_5*/);
   Chip_SCTPWM_SetOutPin(LPC_SCT, PREHEATER_PWM_CHANNEL, 7 /*CTOUT_7*/);
   Chip_SCTPWM_Start(LPC_SCT);
}

void Board_PWM_Write(uint8_t ch, uint8_t value)
{
   Chip_SCTPWM_SetDutyCycle(LPC_SCT, ch, Chip_SCTPWM_PercentageToTicks(LPC_SCT, value));
}

