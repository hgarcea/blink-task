#ifndef __BOARD_H__
#define __BOARD_H__

#include "chip.h"


/* Board name */
#define BOARD_I3D_CIAA_4337

#include "board_gpio.h"

#include "board_button.h"

#include "board_led.h"

#include "board_uart.h"

#include "board_motor.h"

#include "board_timer.h"

#include "board_adc.h"

#include "board_dac.h"

#include "board_pwm.h"

#include "board_i2c.h"

#include "board_spi.h"

#include "board_rit.h"


/* board_api.h is included at the bottom of this file after DEBUG setup */
#include "board_api.h"



#define SCU_BUTTON1_PORT_NUM            1 	/* P1      */
#define SCU_BUTTON1_PIN_NUM             0 	/* P1.0    */
#define SCU_BUTTON2_PORT_NUM            1 	/* P1      */
#define SCU_BUTTON2_PIN_NUM             1 	/* P1.1    */
#define SCU_BUTTON3_PORT_NUM            1 	/* P1      */
#define SCU_BUTTON3_PIN_NUM             2 	/* P1.2    */
#define SCU_BUTTON4_PORT_NUM            1 	/* P1      */
#define SCU_BUTTON4_PIN_NUM             6 	/* P1.6	 */

#define GPIO_BUTTON1_PORT_NUM			0	/* GPIO0    */	
#define GPIO_BUTTON1_PIN_NUM			4	/* GPIO0[4] */
#define GPIO_BUTTON2_PORT_NUM			0	/* GPIO0    */	
#define GPIO_BUTTON2_PIN_NUM			8	/* GPIO0[8] */
#define GPIO_BUTTON3_PORT_NUM			0	/* GPIO0    */	
#define GPIO_BUTTON3_PIN_NUM			9	/* GPIO0[9] */
#define GPIO_BUTTON4_PORT_NUM			1	/* GPIO1    */	
#define GPIO_BUTTON4_PIN_NUM			9	/* GPIO1[9] */

	/* Board Led*/
#define SCU_LED0_R_PORT_NUM            2	/* 	P2		*/
#define SCU_LED0_R_PIN_NUM             0	/*	P2.0	*/
#define SCU_LED0_G_PORT_NUM            2	/*	P2 		*/
#define SCU_LED0_G_PIN_NUM             1	/*	P2.1	*/
#define SCU_LED0_B_PORT_NUM            2	/*	P2 		*/	
#define SCU_LED0_B_PIN_NUM             2	/*	P2.2	*/
#define SCU_LED1_PORT_NUM              2	/*	P2 		*/
#define SCU_LED1_PIN_NUM               10	/*	P2.10	*/
#define SCU_LED2_PORT_NUM              2	/*	P2 		*/
#define SCU_LED2_PIN_NUM               11	/*	P2.11	*/
#define SCU_LED3_PORT_NUM              2	/*	P2 		*/
#define SCU_LED3_PIN_NUM               12	/*	P2.12	*/

		
#define GPIO_LED0_R_PORT_NUM            5	/* GPIO5    */	
#define GPIO_LED0_R_PIN_NUM             0	/* GPIO5[0] */	
#define GPIO_LED0_G_PORT_NUM            5	/* GPIO5    */	
#define GPIO_LED0_G_PIN_NUM             1	/* GPIO5[1] */	
#define GPIO_LED0_B_PORT_NUM            5	/* GPIO5    */	
#define GPIO_LED0_B_PIN_NUM             2	/* GPIO5[2] */	
#define GPIO_LED1_PORT_NUM              0	/* GPIO0    */	
#define GPIO_LED1_PIN_NUM               14	/* GPIO0[14]*/	
#define GPIO_LED2_PORT_NUM              1	/* GPIO1    */	
#define GPIO_LED2_PIN_NUM               11	/* GPIO2[11]*/	
#define GPIO_LED3_PORT_NUM              1	/* GPIO1    */		
#define GPIO_LED3_PIN_NUM               12	/* GPIO2[12]*/	


	/* Hardware interrupt */


#define SCU_INTEVENT_PORT_NUM 			6	/* P6		*/
#define SCU_INTEVENT_PIN_NUM		    10	/* P6.10	*/

#define GPIO_INTEVENT_PORT_NUM			3	/* GPIO3   	*/
#define GPIO_INTEVENT_PIN_NUM			6 	/* GPIO3[6] */

#endif

