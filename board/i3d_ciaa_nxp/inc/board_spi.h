#ifndef __BOARD_SPI_H__
#define __BOARD_SPI_H__

#include "chip.h"

/* SPI para comunicación con tarjeta SDMMC */
void Board_SPI_SDMMC_Init(uint32_t rate);
void Board_SPI_SDMMC_SetRate(uint32_t rate);
void Board_SPI_SDMMC_Write(uint8_t data);
void Board_SPI_SDMMC_Read(uint8_t *data);


/* SPI para comunicación con display */
void Board_SPI_Display_Init(uint32_t rate);
void Board_SPI_Display_SetRate(uint32_t rate);
void Board_SPI_Display_Write(uint8_t data);

#endif

