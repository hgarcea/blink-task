/*==================[inclusions]=============================================*/

#include <math.h>
#include <string.h>
#include "board.h"
#include "os.h"
#include "second.h"



/*==================[macros and definitions]=================================*/




/*==================[internal data declaration]==============================*/



/*==================[internal functions declaration]=========================*/


/*==================[internal data definition]===============================*/


/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

TASK(SecondTask)
{
   

   static bool on;

   uint8_t button;

   button = Board_Button_GetStatus();

   if((button & 0x01) == 0x01){

     SetEvent(FirstTask,Event1);
    
   }
   
   if((button & 0x02) == 0x02){

     SetEvent(FirstTask,Event2);
    
   }
  /* 
    if (Chip_GPIO_GetPinState(LPC_GPIO_PORT,GPIO_INTEVENT_PORT_NUM , GPIO_INTEVENT_PIN_NUM) == 0)
        
        Board_Led_Set(BOARD_LED_0_R);

      
    else Board_Led_Clear(BOARD_LED_0_R);
*/
   on= !on;

      if(on) 
        Board_Led_Set(BOARD_LED_3);
      else
        Board_Led_Clear(BOARD_LED_3);
     

      
      /* terminate task */      
   TerminateTask();
}


void second_init (void)
{

   SetRelAlarm(ActivateSecondTask,100,150);

}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/