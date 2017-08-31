#include "chip.h"

#include "board.h"


static uint8_t __init = 0;


/* Initialize DAC */
void Board_DAC_Init(void)
{
   if (__init) return;
   __init = 1;

   Chip_SCU_DAC_Analog_Config(); //select DAC function

   Chip_DAC_Init(LPC_DAC); //initialize DAC
//   Chip_DAC_SetBias(LPC_DAC, DAC_MAX_UPDATE_RATE_400kHz);
   Chip_DAC_SetBias(LPC_DAC, DAC_MAX_UPDATE_RATE_1MHz);
   Chip_DAC_SetDMATimeOut(LPC_DAC, 0xffff);
   Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_CNT_ENA | DAC_DMA_ENA);
}

/* Write DAC */
void Board_DAC_Write(uint32_t value)
{
   Chip_DAC_UpdateValue(LPC_DAC, value);
   
   /* Wait for DAC (DMA) interrupt request */
//   while (!(Chip_DAC_GetIntStatus(LPC_DAC))) {}
}

