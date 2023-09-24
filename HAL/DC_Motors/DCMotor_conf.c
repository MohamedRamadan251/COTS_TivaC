/*
 * DCMotor_conf.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

#include "../../MCAL/MY_Timer/Timer_init.h"
#include "DCMotor_init.h"

DC_conf_t DC_connection =
{
 .TimerTypePin1 = TIMER0_B ,
 .TimerTypePin2 = TIMER1_B ,
 .Speed         = 50
};
