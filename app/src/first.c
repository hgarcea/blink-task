/*==================[inclusions]=============================================*/

#include <math.h>
#include <string.h>
#include "board.h"
#include "os.h"
#include "first.h"
/*==================[macros and definitions]=================================*/




/*==================[internal data declaration]==============================*/



/*==================[internal functions declaration]=========================*/


/*==================[internal data definition]===============================*/


/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

TASK(FirstTask)
{
   
 static bool on;
  /* Eventes, almacena la mascara de eventos que devueve GetEvent*/
 EventMaskType events;  
      
while(1){
      
     WaitEvent (Event1 | Event2);
     GetEvent(FirstTask, &events);

      if( events & Event1  ){
          ClearEvent(events);
          if((Board_Led_GetStatus() & BOARD_LED_1) == BOARD_LED_1)
              Board_Led_Set(BOARD_LED_1);
          else 
              Board_Led_Clear(BOARD_LED_1);                      
      }    
        
      else if( events & Event2 ){
         ClearEvent(events); 
         if((Board_Led_GetStatus() & BOARD_LED_2) == BOARD_LED_2)
             Board_Led_Set(BOARD_LED_2);
         else 
           Board_Led_Clear(BOARD_LED_2);
      } 


     }  
   	
   	
      /* terminate task */      

   TerminateTask();
}


void first_init (void)
{

   
   ActivateTask(FirstTask);

   
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

