/*
 * DCMotor_init.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_DC_MOTORS_DCMOTOR_INIT_H_
#define HAL_DC_MOTORS_DCMOTOR_INIT_H_

typedef struct
{
    uint8_t TimerTypePin1 ;
    uint8_t TimerTypePin2 ;
    uint8_t Speed     ; /*from 0 to 100*/
}DC_conf_t;

void HDC_init (DC_conf_t *DC_connection) ;

void HDC_CounterClockWise  (DC_conf_t *DC_connection) ;

void HDC_ClockWise  (DC_conf_t *DC_connection) ;

void HDC_Stop  (DC_conf_t *DC_connection) ;

#endif /* HAL_DC_MOTORS_DCMOTOR_INIT_H_ */
