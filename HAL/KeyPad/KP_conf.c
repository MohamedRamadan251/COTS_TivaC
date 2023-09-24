/*
 * KP_conf.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohammed Ramadan
 */


#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"
#include "../../MCAL/MY_Systick/Systic_init.h"

#include "KP_init.h"
#include "KP_private.h"


/**
 * connections of PORT = GPIO_PORTA
 *                       GPIO_PORTB
 *                       GPIO_PORTC
 *                       GPIO_PORTD
 *                       GPIO_PORTE
 *                       GPIO_PORTF
 *
 * connection of PIN = GPIO_PIN_0
 *                     GPIO_PIN_1
 *                     GPIO_PIN_2
 *                     GPIO_PIN_3
 *                     GPIO_PIN_4
 *                     GPIO_PIN_5
 *                     GPIO_PIN_6
 *                     GPIO_PIN_7
 */

KP_conf_t KP_Connections =
{
 .COL[0] = {GPIO_PORTB , GPIO_PIN_0}   ,
 .COL[1] = {GPIO_PORTB , GPIO_PIN_1}   ,
 .COL[2] = {GPIO_PORTB , GPIO_PIN_2}   ,
 .COL[3] = {GPIO_PORTB , GPIO_PIN_3}   ,
 .ROW[0] = {GPIO_PORTB , GPIO_PIN_4}   ,
 .ROW[1] = {GPIO_PORTB , GPIO_PIN_5}   ,
 .ROW[2] = {GPIO_PORTB , GPIO_PIN_6}   ,
 .ROW[3] = {GPIO_PORTB , GPIO_PIN_7}
};
