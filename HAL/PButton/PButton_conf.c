/*
 * PButton_conf.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohammed Ramadan
 */


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"
#include "PButton_int.h"

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
PB_CONF_T PB1_ID =
{
 .PORT = GPIO_PORTF ,
 .PIN  = GPIO_PIN_0
};


