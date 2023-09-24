/*
 * DCMotor_prog.c
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
void HDC_init (DC_conf_t *DC_connection)
{
    MTimer_voidTimerPwmInit(DC_connection->TimerTypePin1) ;
    MTimer_voidTimerPwmInit(DC_connection->TimerTypePin2) ;
}

void HDC_CounterClockWise  (DC_conf_t *DC_connection)
{
    MTimer_voidSetPWM(DC_connection->TimerTypePin1, DC_connection->Speed) ;
    MTimer_voidSetPWM(DC_connection->TimerTypePin2, 0) ;
}

void HDC_ClockWise  (DC_conf_t *DC_connection)
{
    MTimer_voidSetPWM(DC_connection->TimerTypePin2, DC_connection->Speed) ;
    MTimer_voidSetPWM(DC_connection->TimerTypePin1, 0) ;
}

void HDC_Stop  (DC_conf_t *DC_connection)
{
    MTimer_voidSetPWM(DC_connection->TimerTypePin1, 0) ;
    MTimer_voidSetPWM(DC_connection->TimerTypePin2, 0) ;
}
