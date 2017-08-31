#include "chip.h"

#include "board.h"


/* Initialize the I2C bus */
void Board_I2C_Init(I2C_ID_T id, int speed)//
{
   if (id == I2C0) 
   {
      Chip_SCU_I2C0PinConfig(I2C0_STANDARD_FAST_MODE);

      /* Initialize I2C */
      Chip_I2C_Init(id);
      Chip_I2C_SetClockRate(id, speed);

      /* Set default mode to interrupt */
      NVIC_DisableIRQ(id == I2C0 ? I2C0_IRQn : I2C1_IRQn);
      Chip_I2C_SetMasterEventHandler(id, Chip_I2C_EventHandlerPolling);
   }
}

/* Function that probes all available slaves connected to an I2C bus */
void i2c_probe_slaves(I2C_ID_T i2c, int i)
{
   uint8_t ch[2];

   /* Address 0x48 points to LM75AIM device which needs 2 bytes be read */
   Chip_I2C_MasterRead(i2c, i, ch, 1 + (i == 0x48));
}

