#include "chip.h"

#include "board.h"


// X axis motor
#define SCU_X_AXIS_ENABLE_PORT_NUM         6 /* P6        */
#define SCU_X_AXIS_ENABLE_PIN_NUM          7 /* P6.7      */ /***** USADO para CS del SSP1 ** P1.5 *******/
#define SCU_X_AXIS_DIRECTION_PORT_NUM      4 /* P4        */
#define SCU_X_AXIS_DIRECTION_PIN_NUM       1 /* P4.1      */
#define SCU_X_AXIS_STEP_PORT_NUM           4 /* P4        */
#define SCU_X_AXIS_STEP_PIN_NUM            0 /* P4.0      */
// Y axis motor
#define SCU_Y_AXIS_ENABLE_PORT_NUM         1 /* P1        */
#define SCU_Y_AXIS_ENABLE_PIN_NUM         18 /* P1.18     */
#define SCU_Y_AXIS_DIRECTION_PORT_NUM      4 /* P4        */
#define SCU_Y_AXIS_DIRECTION_PIN_NUM       3 /* P4.3      */
#define SCU_Y_AXIS_STEP_PORT_NUM           4 /* P4        */
#define SCU_Y_AXIS_STEP_PIN_NUM            2 /* P4.2      */
// Z axis motor
#define SCU_Z_AXIS_ENABLE_PORT_NUM         1 /* P1        */
#define SCU_Z_AXIS_ENABLE_PIN_NUM         20 /* P1.20     */
#define SCU_Z_AXIS_DIRECTION_PORT_NUM      4 /* P4        */
#define SCU_Z_AXIS_DIRECTION_PIN_NUM       8 /* P4.8      */
#define SCU_Z_AXIS_STEP_PORT_NUM           4 /* P4        */
#define SCU_Z_AXIS_STEP_PIN_NUM            9 /* P4.9      */
// Extrusor motor
#define SCU_E_MOTOR_ENABLE_PORT_NUM        1 /* P1        */
#define SCU_E_MOTOR_ENABLE_PIN_NUM        17 /* P1.17     */
#define SCU_E_MOTOR_DIRECTION_PORT_NUM     6 /* P6        */
#define SCU_E_MOTOR_DIRECTION_PIN_NUM      8 /* P6.8      */
#define SCU_E_MOTOR_STEP_PORT_NUM          4 /* P4        */
#define SCU_E_MOTOR_STEP_PIN_NUM          10 /* P4.10     */
// Endstops
#define SCU_ENDSTOP_X_ORG_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_X_ORG_PIN_NUM          1 /* P6.1      */
#define SCU_ENDSTOP_X_END_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_X_END_PIN_NUM          4 /* P6.4      */
#define SCU_ENDSTOP_Y_ORG_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_Y_ORG_PIN_NUM          5 /* P6.5      */
#define SCU_ENDSTOP_Y_END_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_Y_END_PIN_NUM          9 /* P6.9      */
#define SCU_ENDSTOP_Z_ORG_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_Z_ORG_PIN_NUM         10 /* P6.10     */
#define SCU_ENDSTOP_Z_END_PORT_NUM         6 /* P6        */
#define SCU_ENDSTOP_Z_END_PIN_NUM         11 /* P6.11     */


// X axis motor
#define GPIO_X_AXIS_ENABLE_PORT_NUM        5 /* GPIO5     */
#define GPIO_X_AXIS_ENABLE_PIN_NUM        15 /* GPIO5[15] */ /***** USADO para CS del SSP1 ** GPIO1[8] *******/
#define GPIO_X_AXIS_DIRECTION_PORT_NUM     2 /* GPIO2     */
#define GPIO_X_AXIS_DIRECTION_PIN_NUM      1 /* GPIO2[1]  */
#define GPIO_X_AXIS_STEP_PORT_NUM          2 /* GPIO2     */
#define GPIO_X_AXIS_STEP_PIN_NUM           0 /* GPIO2[0]  */
// Y axis motor
#define GPIO_Y_AXIS_ENABLE_PORT_NUM        0 /* GPIO0     */
#define GPIO_Y_AXIS_ENABLE_PIN_NUM        13 /* GPIO0[13] */
#define GPIO_Y_AXIS_DIRECTION_PORT_NUM     2 /* GPIO2     */
#define GPIO_Y_AXIS_DIRECTION_PIN_NUM      3 /* GPIO2[3]  */
#define GPIO_Y_AXIS_STEP_PORT_NUM          2 /* GPIO2     */
#define GPIO_Y_AXIS_STEP_PIN_NUM           2 /* GPIO2[2]  */
// Z axis motor
#define GPIO_Z_AXIS_ENABLE_PORT_NUM        0 /* GPIO0     */
#define GPIO_Z_AXIS_ENABLE_PIN_NUM        15 /* GPIO0[15] */
#define GPIO_Z_AXIS_DIRECTION_PORT_NUM     5 /* GPIO5     */
#define GPIO_Z_AXIS_DIRECTION_PIN_NUM     12 /* GPIO5[12] */
#define GPIO_Z_AXIS_STEP_PORT_NUM          5 /* GPIO5     */
#define GPIO_Z_AXIS_STEP_PIN_NUM          13 /* GPIO5[13] */
// Extrusor motor
#define GPIO_E_MOTOR_ENABLE_PORT_NUM       0 /* GPIO0     */
#define GPIO_E_MOTOR_ENABLE_PIN_NUM       12 /* GPIO0[12] */
#define GPIO_E_MOTOR_DIRECTION_PORT_NUM    5 /* GPIO5     */
#define GPIO_E_MOTOR_DIRECTION_PIN_NUM    16 /* GPIO5[16] */
#define GPIO_E_MOTOR_STEP_PORT_NUM         5 /* GPIO5     */
#define GPIO_E_MOTOR_STEP_PIN_NUM         14 /* GPIO5[14] */
// Endstops
#define GPIO_ENDSTOP_X_ORG_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_X_ORG_PIN_NUM         0 /* GPIO3[0]  */
#define GPIO_ENDSTOP_X_END_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_X_END_PIN_NUM         3 /* GPIO3[3]  */
#define GPIO_ENDSTOP_Y_ORG_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_Y_ORG_PIN_NUM         4 /* GPIO3[4]  */
#define GPIO_ENDSTOP_Y_END_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_Y_END_PIN_NUM         5 /* GPIO3[5]  */
#define GPIO_ENDSTOP_Z_ORG_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_Z_ORG_PIN_NUM         6 /* GPIO3[6]  */
#define GPIO_ENDSTOP_Z_END_PORT_NUM        3 /* GPIO3     */
#define GPIO_ENDSTOP_Z_END_PIN_NUM         7 /* GPIO3[7]  */


static uint8_t __init = 0;


void Board_Motor_Init(void)
{
   if (__init) return;
   __init = 1;
   Board_GPIO_Init();

   /* Pins muxing */
   // X axis motor
   Chip_SCU_PinMux(SCU_X_AXIS_ENABLE_PORT_NUM, SCU_X_AXIS_ENABLE_PIN_NUM, MD_PUP, FUNC4);
   Chip_SCU_PinMux(SCU_X_AXIS_DIRECTION_PORT_NUM, SCU_X_AXIS_DIRECTION_PIN_NUM, MD_PUP, FUNC0);
   Chip_SCU_PinMux(SCU_X_AXIS_STEP_PORT_NUM, SCU_X_AXIS_STEP_PIN_NUM, MD_PUP, FUNC0);
   // Y axis motor
   Chip_SCU_PinMux(SCU_Y_AXIS_ENABLE_PORT_NUM, SCU_Y_AXIS_ENABLE_PIN_NUM, MD_PUP, FUNC0);
   Chip_SCU_PinMux(SCU_Y_AXIS_DIRECTION_PORT_NUM, SCU_Y_AXIS_DIRECTION_PIN_NUM, MD_PUP, FUNC0);
   Chip_SCU_PinMux(SCU_Y_AXIS_STEP_PORT_NUM, SCU_Y_AXIS_STEP_PIN_NUM, MD_PUP, FUNC0);
   // Z axis motor
   Chip_SCU_PinMux(SCU_Z_AXIS_ENABLE_PORT_NUM, SCU_Z_AXIS_ENABLE_PIN_NUM, MD_PUP, FUNC0);
   Chip_SCU_PinMux(SCU_Z_AXIS_DIRECTION_PORT_NUM, SCU_Z_AXIS_DIRECTION_PIN_NUM, MD_PUP, FUNC4);
   Chip_SCU_PinMux(SCU_Z_AXIS_STEP_PORT_NUM, SCU_Z_AXIS_STEP_PIN_NUM, MD_PUP, FUNC4);
   // Extrusor motor
   Chip_SCU_PinMux(SCU_E_MOTOR_ENABLE_PORT_NUM, SCU_E_MOTOR_ENABLE_PIN_NUM, MD_PUP, FUNC0);
   Chip_SCU_PinMux(SCU_E_MOTOR_DIRECTION_PORT_NUM, SCU_E_MOTOR_DIRECTION_PIN_NUM,MD_PUP, FUNC4);
   Chip_SCU_PinMux(SCU_E_MOTOR_STEP_PORT_NUM, SCU_E_MOTOR_STEP_PIN_NUM, MD_PUP, FUNC4);
   //Endstops (use INTERNAL pullup)
   Chip_SCU_PinMux(SCU_ENDSTOP_X_ORG_PORT_NUM, SCU_ENDSTOP_X_ORG_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS), FUNC0);
   Chip_SCU_PinMux(SCU_ENDSTOP_Y_ORG_PORT_NUM, SCU_ENDSTOP_Y_ORG_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN), FUNC0);
   Chip_SCU_PinMux(SCU_ENDSTOP_Z_ORG_PORT_NUM, SCU_ENDSTOP_Z_ORG_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN), FUNC0);
   Chip_SCU_PinMux(SCU_ENDSTOP_X_END_PORT_NUM, SCU_ENDSTOP_X_END_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN), FUNC0);
   Chip_SCU_PinMux(SCU_ENDSTOP_Y_END_PORT_NUM, SCU_ENDSTOP_Y_END_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN), FUNC0);
   Chip_SCU_PinMux(SCU_ENDSTOP_Z_END_PORT_NUM, SCU_ENDSTOP_Z_END_PIN_NUM, (SCU_MODE_PULLUP | SCU_MODE_INBUFF_EN), FUNC0);

   /* Pins direction */
   // X axis motor
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_X_AXIS_ENABLE_PORT_NUM, (1 << GPIO_X_AXIS_ENABLE_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_X_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_X_AXIS_DIRECTION_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_X_AXIS_STEP_PORT_NUM, (1 << GPIO_X_AXIS_STEP_PIN_NUM), 1); /*output*/
   // Y axis motor
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Y_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Y_AXIS_ENABLE_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Y_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Y_AXIS_DIRECTION_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Y_AXIS_STEP_PORT_NUM, (1 << GPIO_Y_AXIS_STEP_PIN_NUM), 1); /*output*/
   // Z axis motor
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Z_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Z_AXIS_ENABLE_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Z_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Z_AXIS_DIRECTION_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_Z_AXIS_STEP_PORT_NUM, (1 << GPIO_Z_AXIS_STEP_PIN_NUM), 1); /*output*/
   // Extrusor motor
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_E_MOTOR_ENABLE_PORT_NUM, (1 << GPIO_E_MOTOR_ENABLE_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_E_MOTOR_DIRECTION_PORT_NUM, (1 << GPIO_E_MOTOR_DIRECTION_PIN_NUM), 1); /*output*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_E_MOTOR_STEP_PORT_NUM, (1 << GPIO_E_MOTOR_STEP_PIN_NUM), 1); /*output*/
   // Endstops
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_X_ORG_PORT_NUM, (1 << GPIO_ENDSTOP_X_ORG_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_Y_ORG_PORT_NUM, (1 << GPIO_ENDSTOP_Y_ORG_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_Z_ORG_PORT_NUM, (1 << GPIO_ENDSTOP_Z_ORG_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_X_END_PORT_NUM, (1 << GPIO_ENDSTOP_X_END_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_Y_END_PORT_NUM, (1 << GPIO_ENDSTOP_Y_END_PIN_NUM), 0); /*input*/
   Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO_ENDSTOP_Z_END_PORT_NUM, (1 << GPIO_ENDSTOP_Z_END_PIN_NUM), 0); /*input*/

   /* Outputs default values */
   // X, Y, Z, E: Enables (all ENABLES pins of motor drivers are "disabled" in high state)
   Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_X_AXIS_ENABLE_PORT_NUM, (1 << GPIO_X_AXIS_ENABLE_PIN_NUM));
   Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Y_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Y_AXIS_ENABLE_PIN_NUM));
   Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Z_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Z_AXIS_ENABLE_PIN_NUM));
   Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_E_MOTOR_ENABLE_PORT_NUM, (1 << GPIO_E_MOTOR_ENABLE_PIN_NUM));
}

int8_t Board_Motor_Endstops_GetStatus(Endstop_t endstopName)
{
   int8_t ret;

   ret = 0;
   switch(endstopName)
   {
      case ENDSTOP_X_ORG:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_X_ORG_PORT_NUM, GPIO_ENDSTOP_X_ORG_PIN_NUM) == 0) {
            ret = 1;
         }
      break;

      case ENDSTOP_Y_ORG:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_Y_ORG_PORT_NUM, GPIO_ENDSTOP_Y_ORG_PIN_NUM) == 0) {
            ret = 1;
         }
      break;

      case ENDSTOP_Z_ORG:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_Z_ORG_PORT_NUM, GPIO_ENDSTOP_Z_ORG_PIN_NUM) == 0) {
            ret = 1;
         }
      break;

      // Endstop ENDs not implemented in hardware!
      case ENDSTOP_X_END:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_X_END_PORT_NUM, GPIO_ENDSTOP_X_END_PIN_NUM) == 0) {
            ret = 1;
         }
      break;

      case ENDSTOP_Y_END:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_Y_END_PORT_NUM, GPIO_ENDSTOP_Y_END_PIN_NUM) == 0) {
            ret = 1;
      }
      break;

      case ENDSTOP_Z_END:
         if (Chip_GPIO_GetPinState(LPC_GPIO_PORT, GPIO_ENDSTOP_Z_END_PORT_NUM, GPIO_ENDSTOP_Z_END_PIN_NUM) == 0) {
            ret = 1;
      }
      break;

      default:
      break;
   }
   return ret;
}

void Board_Motor_SetEnable(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_X_AXIS_ENABLE_PORT_NUM, (1 << GPIO_X_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Y_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Y_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Z_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Z_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_E_MOTOR_ENABLE_PORT_NUM, (1 << GPIO_E_MOTOR_ENABLE_PIN_NUM));
}

void Board_Motor_ClearEnable(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_X_AXIS_ENABLE_PORT_NUM, (1 << GPIO_X_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Y_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Y_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Z_AXIS_ENABLE_PORT_NUM, (1 << GPIO_Z_AXIS_ENABLE_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_E_MOTOR_ENABLE_PORT_NUM, (1 << GPIO_E_MOTOR_ENABLE_PIN_NUM));
}

void Board_Motor_SetDir(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_X_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_X_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Y_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Y_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Z_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Z_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_E_MOTOR_DIRECTION_PORT_NUM, (1 << GPIO_E_MOTOR_DIRECTION_PIN_NUM));
}

void Board_Motor_ClearDir(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_X_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_X_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Y_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Y_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Z_AXIS_DIRECTION_PORT_NUM, (1 << GPIO_Z_AXIS_DIRECTION_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_E_MOTOR_DIRECTION_PORT_NUM, (1 << GPIO_E_MOTOR_DIRECTION_PIN_NUM));
}

void Board_Motor_SetStep(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_X_AXIS_STEP_PORT_NUM, (1 << GPIO_X_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Y_AXIS_STEP_PORT_NUM, (1 << GPIO_Y_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_Z_AXIS_STEP_PORT_NUM, (1 << GPIO_Z_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_SetValue(LPC_GPIO_PORT, GPIO_E_MOTOR_STEP_PORT_NUM, (1 << GPIO_E_MOTOR_STEP_PIN_NUM));
}

void Board_Motor_ClearStep(uint8_t pin)
{
   if (pin & BOARD_MOTOR_X) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_X_AXIS_STEP_PORT_NUM, (1 << GPIO_X_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_Y) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Y_AXIS_STEP_PORT_NUM, (1 << GPIO_Y_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_Z) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_Z_AXIS_STEP_PORT_NUM, (1 << GPIO_Z_AXIS_STEP_PIN_NUM));
   if (pin & BOARD_MOTOR_E) Chip_GPIO_ClearValue(LPC_GPIO_PORT, GPIO_E_MOTOR_STEP_PORT_NUM, (1 << GPIO_E_MOTOR_STEP_PIN_NUM));
}

