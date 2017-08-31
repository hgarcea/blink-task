#include "chip.h"

#include "board.h"


static int (*__timer1_callback__)(void);


int Board_Timer_Init(LPC_TIMER_T *pTMR)
{
   if (pTMR == LPC_TIMER1)
   {
      /* Enable timer 1 clock */
      Chip_TIMER_Init(LPC_TIMER1);

      /* Timer setup for match and interrupt at TICKRATE_HZ */
      Chip_TIMER_Reset(LPC_TIMER1);
      Chip_TIMER_MatchEnableInt(LPC_TIMER1, 1);
      Chip_TIMER_ResetOnMatchEnable(LPC_TIMER1, 1);

      Chip_TIMER_Disable(LPC_TIMER1);
      NVIC_DisableIRQ(TIMER1_IRQn);
      return 1;
   }
   return -1;
}

int Board_Timer_SetCallBack(LPC_TIMER_T *pTMR, int (*func)(void))
{
   if (pTMR == LPC_TIMER1)
   {
      Chip_TIMER_Disable(LPC_TIMER1);
      NVIC_DisableIRQ(TIMER1_IRQn);
      __timer1_callback__ = func;
      Chip_TIMER_Enable(LPC_TIMER1);
      NVIC_ClearPendingIRQ(TIMER1_IRQn);
      NVIC_EnableIRQ(TIMER1_IRQn);
      return 1;
   }
   return -1;
}

int Board_Timer_SetSpeed(LPC_TIMER_T *pTMR, int speed)
{
   if (pTMR == LPC_TIMER1)
   {
      /* speed null, stop timer */
      if (speed == 0)
      {
         Chip_TIMER_Disable(LPC_TIMER1);
         NVIC_DisableIRQ(TIMER1_IRQn);
      }
      /* Config timer interrupt and start timer */
      else
      {
         if (speed < 0) speed = -speed;
         Chip_TIMER_SetMatch(LPC_TIMER1, 1, SystemCoreClock / speed);
         Chip_TIMER_Enable(LPC_TIMER1);
         NVIC_ClearPendingIRQ(TIMER1_IRQn);
         NVIC_EnableIRQ(TIMER1_IRQn);
      }
      return 1;
   }
   return -1;
}

void Board_Timer_Interrupt(LPC_TIMER_T *pTMR)
{
   if (pTMR == LPC_TIMER1)
   {
      /* Check for end of count condition */
      if (!Chip_TIMER_MatchPending(LPC_TIMER1, 1)) return;

      Chip_TIMER_ClearMatch(LPC_TIMER1, 1);

      /* Run callback function, if exist */
      if (!__timer1_callback__) return;
      if (__timer1_callback__() > 0) return;

      /* If callback function return error, stop timer */
      Chip_TIMER_Disable(LPC_TIMER1);
      NVIC_DisableIRQ(TIMER1_IRQn);
   }
}

