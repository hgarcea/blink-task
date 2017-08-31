#include "chip.h"

#include "board.h"


#define SCU_SDMMC_MOSI_PORT_NUM        1 /* P1        */
#define SCU_SDMMC_MOSI_PIN_NUM         4 /* P1.4      */
#define SCU_SDMMC_MISO_PORT_NUM        1 /* P1        */
#define SCU_SDMMC_MISO_PIN_NUM         3 /* P1.3      */
#define SCU_SDMMC_SCK_PORT_NUM      0x0f /* PF        */
#define SCU_SDMMC_SCK_PIN_NUM          4 /* PF.4      */
#define SCU_SDMMC_CS_PORT_NUM          1 /* P1        */
#define SCU_SDMMC_CS_PIN_NUM           5 /* P1.5      */
#define SCU_SPI_CH_SEL_PORT_NUM        3 /* P3        */
#define SCU_SPI_CH_SEL_PIN_NUM         1 /* P3.1      */
#define SCU_SD_DET_PORT_NUM            3 /* P3        */
#define SCU_SD_DET_PIN_NUM             2 /* P3.2      */


#define GPIO_SDMMC_MOSI_PORT_NUM       0 /* GPIO0     */
#define GPIO_SDMMC_MOSI_PIN_NUM       11 /* GPIO0[11] */
#define GPIO_SDMMC_MISO_PORT_NUM       0 /* GPIO0     */
#define GPIO_SDMMC_MISO_PIN_NUM       10 /* GPIO0[10] */
#define GPIO_SDMMC_CS_PORT_NUM         1 /* GPIO1     */
#define GPIO_SDMMC_CS_PIN_NUM          8 /* GPIO1[8]  */ 
#define GPIO_SPI_CH_SEL_PORT_NUM       5 /* GPIO5     */
#define GPIO_SPI_CH_SEL_PIN_NUM        8 /* GPIO5[8] */
#define GPIO_SD_DET_PORT_NUM           5 /* GPIO5     */
#define GPIO_SD_DET_PIN_NUM            9 /* GPIO5[9] */


#define BOARD_SPI_GENERIC_MODE         0x00
#define BOARD_SPI_SDMMC_MODE           0x01
#define BOARD_SPI_DISPLAY_MODE         0x02


static uint8_t __init = 0;
static uint8_t spi_mode;
uint32_t sdmmc_rate;
uint32_t display_rate;


static void Board_SPI_Init(void)
{
   if (__init) return;
   __init = 1;

   Board_GPIO_Init();

   Chip_SCU_PinMuxSet(SCU_SDMMC_MOSI_PORT_NUM, SCU_SDMMC_MOSI_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_FUNC5));//MOSI
   Chip_SCU_PinMuxSet(SCU_SDMMC_MISO_PORT_NUM, SCU_SDMMC_MISO_PIN_NUM, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC5));//MISO
   Chip_SCU_PinMuxSet(SCU_SDMMC_SCK_PORT_NUM, SCU_SDMMC_SCK_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_FUNC0));//SCK
   Chip_SCU_PinMuxSet(SCU_SDMMC_CS_PORT_NUM, SCU_SDMMC_CS_PIN_NUM, (SCU_MODE_PULLUP | FUNC5));//CS
   Chip_SCU_PinMuxSet(SCU_SPI_CH_SEL_PORT_NUM, SCU_SPI_CH_SEL_PIN_NUM, (SCU_MODE_PULLUP | FUNC4));//SPI_CH_SEL
   Chip_SCU_PinMuxSet(SCU_SD_DET_PORT_NUM, SCU_SD_DET_PIN_NUM, (SCU_MODE_PULLUP | FUNC4));//SD_DET 

   Chip_GPIO_SetDir(LPC_GPIO_PORT,GPIO_SD_DET_PORT_NUM, (1 << GPIO_SD_DET_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT,GPIO_SPI_CH_SEL_PORT_NUM, (1 << GPIO_SPI_CH_SEL_PIN_NUM), 1); /*output*/

   Chip_SSP_Init(LPC_SSP1);
   Chip_SSP_SetMaster(LPC_SSP1, 1);

   spi_mode = BOARD_SPI_GENERIC_MODE;
}

static void Board_SPI_Select_SDMMC(void)
{
   if (spi_mode == BOARD_SPI_SDMMC_MODE) return;
   spi_mode = BOARD_SPI_SDMMC_MODE;

   Chip_GPIO_SetValue(LPC_GPIO_PORT,GPIO_SPI_CH_SEL_PORT_NUM, (1 << GPIO_SPI_CH_SEL_PIN_NUM));

   Chip_SSP_Disable(LPC_SSP1);
   Chip_SSP_SetFormat(LPC_SSP1, SSP_BITS_8, SSP_FRAMEFORMAT_SPI, SSP_CLOCK_CPHA1_CPOL1);
   Chip_SSP_SetBitRate(LPC_SSP1, sdmmc_rate);
   Chip_SSP_DisableLoopBack(LPC_SSP1);
   Chip_SSP_Enable(LPC_SSP1);
}

static void Board_SPI_Select_Display(void)
{
   if (spi_mode == BOARD_SPI_DISPLAY_MODE) return;
   spi_mode = BOARD_SPI_DISPLAY_MODE;

   Chip_GPIO_ClearValue(LPC_GPIO_PORT,GPIO_SPI_CH_SEL_PORT_NUM, (1 << GPIO_SPI_CH_SEL_PIN_NUM));   // Select display

   Chip_SSP_Disable(LPC_SSP1);
   Chip_SSP_SetFormat(LPC_SSP1, SSP_BITS_8,SSP_FRAMEFORMAT_SPI, SSP_CLOCK_CPHA0_CPOL0); // OK signal reprap 
   Chip_SSP_SetBitRate(LPC_SSP1, display_rate); 
   Chip_SSP_DisableLoopBack(LPC_SSP1);  
   Chip_SSP_Enable(LPC_SSP1);
}


/* SPI para comunicación con tarjeta SDMMC */

void Board_SPI_SDMMC_Init(uint32_t rate)
{
   Board_SPI_Init();
   Board_SPI_SDMMC_SetRate(rate);
   Board_SPI_Select_SDMMC();
}

void Board_SPI_SDMMC_SetRate(uint32_t rate)
{
   sdmmc_rate = rate;
   spi_mode = BOARD_SPI_GENERIC_MODE;
}

void Board_SPI_SDMMC_Write(uint8_t data)
{
   Board_SPI_Select_SDMMC();

   if (Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_TNF) != SET) return;
   Chip_SSP_SendFrame(LPC_SSP1, data);
   while(Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_BSY) == SET);
}

void Board_SPI_SDMMC_Read(uint8_t *data)
{
   Board_SPI_Select_SDMMC();

//   if (Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_TNF) != SET) return;
//   Chip_SSP_SendFrame(LPC_SSP1, 0xff);
//   while(Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_BSY) == SET);
   Board_SPI_SDMMC_Write(0xff);
   while(Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_RNE) == SET) 
     *data = Chip_SSP_ReceiveFrame(LPC_SSP1);
}


/* SPI para comunicación con display */

void Board_SPI_Display_Init(uint32_t rate)
{
   Board_SPI_Init();
   Board_SPI_Display_SetRate(rate);
   Board_SPI_Select_Display();
}

void Board_SPI_Display_SetRate(uint32_t rate)
{
   display_rate = rate;
   spi_mode = BOARD_SPI_GENERIC_MODE;
}

void Board_SPI_Display_Write(uint8_t data)
{
   Board_SPI_Select_Display();

   if (Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_TNF) != SET)
      return;
   Chip_SSP_SendFrame(LPC_SSP1, data);

   while(Chip_SSP_GetStatus(LPC_SSP1, SSP_STAT_BSY) == SET);
}

