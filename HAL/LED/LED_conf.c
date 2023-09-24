/*
 * LED_conf.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Mohammed Ramadan
 */



#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"
#include "LED_int.h"

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
LED_CONF_T LED1_ID =
{
 .PORT = GPIO_PORTF ,
 .PIN  = GPIO_PIN_1
};

LED_CONF_T LED2_ID =
{
 .PORT = GPIO_PORTF ,
 .PIN  = GPIO_PIN_2
};

LED_CONF_T LED3_ID =
{
 .PORT = GPIO_PORTF ,
 .PIN  = GPIO_PIN_3
};
