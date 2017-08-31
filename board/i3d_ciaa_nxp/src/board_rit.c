#include "chip.h"

#include "board.h"


volatile uint8_t overflow_flag;
static void (*__counter_callback__)(void);


void Board_RIT_SetCounterWithCallback(uint32_t count, void (*func)(void))
{
   Chip_RIT_Disable(LPC_RITIMER);
   Chip_RIT_DeInit(LPC_RITIMER);

   overflow_flag = 0;
   __counter_callback__ = func;

   Chip_RIT_Init(LPC_RITIMER);
   Chip_RIT_SetTimerInterval(LPC_RITIMER, count);
   Chip_RIT_Enable(LPC_RITIMER);
}

void Board_RIT_StopCounter(void)
{
   Chip_RIT_Disable(LPC_RITIMER);
}

void Board_RIT_ResumeCounter(void)
{
   Chip_RIT_Enable(LPC_RITIMER);
}

int Board_RIT_IsOverflow(void)
{
   int status;

   Chip_RIT_Disable(LPC_RITIMER);
   status = (overflow_flag == 1);
   Chip_RIT_Enable(LPC_RITIMER);
   return status;

}

void Board_RIT_Interrupt(void)
{
   Chip_RIT_Disable(LPC_RITIMER);
   overflow_flag = 1;
   if (!__counter_callback__) return;
   __counter_callback__();
}

