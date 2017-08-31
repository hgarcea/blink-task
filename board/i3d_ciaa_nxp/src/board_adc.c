#include "chip.h"

#include "board.h"


static uint8_t __init = 0;


void Board_ADC_Init(void)
{
   if (__init) return;
   __init = 1;

   ADC_CLOCK_SETUP_T ADCSetup;

   Chip_ADC_Init(LPC_ADC0, &ADCSetup);
   Chip_ADC_SetBurstCmd(LPC_ADC0, DISABLE);

   Chip_ADC_Int_SetChannelCmd(LPC_ADC0, BED_ADC_CHANNEL, DISABLE);
   Chip_ADC_EnableChannel(LPC_ADC0, BED_ADC_CHANNEL, DISABLE);
   Chip_ADC_Int_SetChannelCmd(LPC_ADC0, EXT_ADC_CHANNEL, DISABLE);
   Chip_ADC_EnableChannel(LPC_ADC0, EXT_ADC_CHANNEL, DISABLE);

   Chip_ADC_SetSampleRate(LPC_ADC0, &ADCSetup, ADC_MAX_SAMPLE_RATE);
   Chip_ADC_SetResolution(LPC_ADC0, &ADCSetup, ADC_10BITS);
}

void Board_ADC_Read(uint32_t ch, uint16_t *dataADC)
{
   Chip_ADC_EnableChannel(LPC_ADC0, ch, ENABLE);
   Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, ADC_TRIGGERMODE_RISING);

   /* Waiting for A/D conversion complete */
   while (Chip_ADC_ReadStatus(LPC_ADC0, ch, ADC_DR_DONE_STAT) != SET) {}

   /* Read ADC value */
   Chip_ADC_ReadValue(LPC_ADC0, ch, dataADC);
   Chip_ADC_EnableChannel(LPC_ADC0, ch, DISABLE);
}

