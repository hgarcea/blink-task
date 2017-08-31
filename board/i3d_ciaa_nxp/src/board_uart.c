
#include "chip.h"

#include "board.h"


static uint8_t __init0 = 0;
static uint8_t __init1 = 0;
static uint8_t __init2 = 0;
static uint8_t __init3 = 0;
static int __board_usart0_echo__;
static int __board_usart2_echo__;
static int __board_usart3_echo__;
static int (*__board_usart0_callback__)(char);
static int (*__board_usart2_callback__)(char);
static int (*__board_usart3_callback__)(char);


void Board_UART_Init(LPC_USART_T *pUART, uint32_t rate)
{
   if (pUART == LPC_USART0)
   {
      if (__init0) return;
      __init0 = 1;

      __board_usart0_echo__ = 0;
      __board_usart0_callback__ = NULL;

      Chip_SCU_PinMuxSet(0x9, 5, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC7));     /* P9.5 : UART0_TXD */
      Chip_SCU_PinMuxSet(0x9, 6, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC7));/* P9.6 : UART0_RXD */
   }
   else if (pUART == LPC_UART1)
   {
      if (__init1) return;
      __init1 = 1;
   }
   else if (pUART == LPC_USART2)
   {
      if (__init2) return;
      __init2 = 1;

      __board_usart2_echo__ = 0;
      __board_usart2_callback__ = NULL;

      Chip_SCU_PinMuxSet(0x7, 1, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC6));    /* P7.1 : UART2_TXD */
      Chip_SCU_PinMuxSet(0x7, 2, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC6)); /* P7.2 : UART2_RXD */
   }
   else if (pUART == LPC_USART3)
   {
      if (__init3) return;
      __init3 = 1;

      __board_usart3_echo__ = 0;
      __board_usart3_callback__ = NULL;

      Chip_SCU_PinMuxSet(0x2, 3, (SCU_MODE_PULLDOWN | SCU_MODE_FUNC2));    /* P2.3 : UART3_TXD */
      Chip_SCU_PinMuxSet(0x2, 4, (SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | SCU_MODE_FUNC2)); /* P2.4 : UART3_RXD */
   }

   Chip_UART_SetupFIFOS(pUART, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);
   Chip_UART_SetBaud(pUART, rate);
   Chip_UART_ConfigData(pUART, UART_LCR_WLEN8 | UART_LCR_SBS_1BIT | UART_LCR_PARITY_DIS);

   /* Enable UART Transmit */
   Chip_UART_TXEnable(pUART);
   /* Restart FIFOS: set Enable, Reset content, set trigger level */
   Chip_UART_SetupFIFOS(pUART, UART_FCR_FIFO_EN | UART_FCR_TX_RS | UART_FCR_RX_RS | UART_FCR_TRG_LEV0);
   /* dummy read */
   Chip_UART_ReadByte(pUART);
   /* enable rx interrupt */
   Chip_UART_IntEnable(pUART, UART_IER_RBRINT);
}

/* Sends a character on the UART */
void Board_UART_PutChar(LPC_USART_T *pUART, char ch)
{
   /* Wait for space in FIFO */
   while ((Chip_UART_ReadLineStatus(pUART) & UART_LSR_THRE) == 0) {}
   Chip_UART_SendByte(pUART, (uint8_t) ch);
}

/* Gets a character from the UART, returns EOF if no character is ready */
int Board_UART_GetChar(LPC_USART_T *pUART)
{
   if (Chip_UART_ReadLineStatus(pUART) & UART_LSR_RDR)
   {
      return (int) Chip_UART_ReadByte(pUART);
   }
   return EOF;
}

/* Outputs a string on the debug UART */
void Board_UART_PutSTR(LPC_USART_T *pUART, const char *str)
{
   uint8_t *p8 = (uint8_t *) str;

   while (*p8 != 0)
   {
      p8 += Chip_UART_Send(pUART, p8, 1);
   }
}

void Board_UART_EnableEcho(LPC_USART_T *pUART)
{
   if (pUART == LPC_USART0)
   {
      __board_usart0_echo__ = 1;
   }
   else if (pUART == LPC_USART2)
   {
      __board_usart2_echo__ = 1;
   }
   else if(pUART == LPC_USART3)
   {
      __board_usart3_echo__ = 1;
   }
}

void Board_UART_DisableEcho(LPC_USART_T *pUART)
{
   if (pUART == LPC_USART0)
   {
      __board_usart0_echo__ = 0;
   }
   else if (pUART == LPC_USART2)
   {
      __board_usart2_echo__ = 0;
   }
   else if(pUART == LPC_USART3)
   {
      __board_usart3_echo__ = 0;
   }
}

void Board_UART_SetCallBack(LPC_USART_T *pUART, int (*func)(char))
{
   if (pUART == LPC_USART0)
   {
      __board_usart0_callback__ = func;
   }
   else if (pUART == LPC_USART2)
   {
      __board_usart2_callback__ = func;
   }
   else if(pUART == LPC_USART3)
   {
      __board_usart3_callback__ = func;
   }
}

void Board_UART_Interrupt(LPC_USART_T *pUART)
{
   uint8_t stat;
   uint8_t byte;

   if (Chip_UART_ReadLineStatus(pUART) & UART_LSR_RDR)
   {
      stat = 1;
      byte = Chip_UART_ReadByte(pUART);

      if (pUART == LPC_USART0)
      {
         if (__board_usart0_callback__) 
            stat = __board_usart0_callback__((char) byte);
         if ((stat > 0) && (__board_usart0_echo__ == 1))
            Chip_UART_SendByte(pUART, byte);
      }
      else if (pUART == LPC_USART2)
      {
         if (__board_usart2_callback__) 
            stat = __board_usart2_callback__((char) byte);
         if ((stat > 0) && (__board_usart2_echo__ == 1))
            Chip_UART_SendByte(pUART, byte);
      }
      else if(pUART == LPC_USART3)
      {
         if (__board_usart3_callback__) 
            stat = __board_usart3_callback__((char) byte);
         if ((stat > 0) && (__board_usart3_echo__ == 1))
            Chip_UART_SendByte(pUART, byte);
      }
   }
}

