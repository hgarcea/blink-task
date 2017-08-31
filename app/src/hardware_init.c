
/* Use of initialization 
 *  The hardware is configured by the init function of any aplication using 
 *  a hardware_init_function. It will specifies de use of the hardware */  

#include "first.h"
#include "second.h"
#include "third.h"


void hardware_init(void)
{
    /* Inicializa hardware para la aplicacion first */
    Board_Gpio_Init();
    first_init();
    second_init();
    third_init();

}