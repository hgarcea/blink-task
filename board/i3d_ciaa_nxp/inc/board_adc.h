#ifndef __BOARD_ADC_H__
#define __BOARD_ADC_H__

#include "chip.h"

// ADC channels
#define BED_ADC_CHANNEL					ADC_CH1
#define EXT_ADC_CHANNEL					ADC_CH2
#define PREHEATER_ADC_CHANNEL			ADC_CH3

void Board_ADC_Init(void);
void Board_ADC_Read(uint32_t ch, uint16_t *dataADC);

#endif

