/*
 * LCD_conf.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"
#include "../../MCAL/MY_Systick/Systic_init.h"

#include "LCD_init.h"
#include "LCD_private.h"


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

LCD_conf_t LCDEightConf =
{
 .ConnectionMode = EIGHT_BIT_MODE  ,

 .D0 = {GPIO_PORTB , GPIO_PIN_0}   ,
 .D1 = {GPIO_PORTB , GPIO_PIN_1}   ,
 .D2 = {GPIO_PORTB , GPIO_PIN_2}   ,
 .D3 = {GPIO_PORTB , GPIO_PIN_3}   ,
 .D4 = {GPIO_PORTB , GPIO_PIN_4}   ,
 .D5 = {GPIO_PORTB , GPIO_PIN_5}   ,
 .D6 = {GPIO_PORTB , GPIO_PIN_6}   ,
 .D7 = {GPIO_PORTB , GPIO_PIN_7}   ,

 .RS = {GPIO_PORTE , GPIO_PIN_0}   ,
 .RW = {GPIO_PORTE , GPIO_PIN_1}   ,
 .EN = {GPIO_PORTE , GPIO_PIN_2}
};

LCD_conf_t LCDFourConf =
{
 .ConnectionMode = FOUR_BIT_MODE   ,

 .D4 = {GPIO_PORTB , GPIO_PIN_4}   ,
 .D5 = {GPIO_PORTB , GPIO_PIN_5}   ,
 .D6 = {GPIO_PORTB , GPIO_PIN_6}   ,
 .D7 = {GPIO_PORTB , GPIO_PIN_7}   ,

 .RS = {GPIO_PORTE , GPIO_PIN_0}   ,
 .RW = {GPIO_PORTE , GPIO_PIN_1}   ,
 .EN = {GPIO_PORTE , GPIO_PIN_2}
};
