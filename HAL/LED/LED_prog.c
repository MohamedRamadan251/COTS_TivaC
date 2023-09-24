/*
 * LED_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"

#include "LED_int.h"


void HLED_voidLedInitial (LED_CONF_T* A_u8LED_ID)
{
    switch (A_u8LED_ID->PORT)
    {
    case GPIO_PORTA :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1)
        {
            MGPIO_voidInit(GPIO_PORTA , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        }
        break ;
    case GPIO_PORTB :
        MGPIO_voidInit(GPIO_PORTB , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        break ;
    case GPIO_PORTC :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1 &&
            A_u8LED_ID->PIN != GPIO_PIN_2 && A_u8LED_ID->PIN != GPIO_PIN_3)
        {
            MGPIO_voidInit(GPIO_PORTC , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_u8LED_ID->PIN != GPIO_PIN_4 && A_u8LED_ID->PIN != GPIO_PIN_5)
        {
            MGPIO_voidInit(GPIO_PORTD , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_u8LED_ID->PIN != GPIO_PIN_6 && A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidInit(GPIO_PORTE , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_u8LED_ID->PIN != GPIO_PIN_5 && A_u8LED_ID->PIN != GPIO_PIN_6 &&
            A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidInit(GPIO_PORTF , A_u8LED_ID->PIN, GPIO_OUTPUT) ;
        }
        break ;
    default : /*Error Case*/
        break ;
    }
}

void HLED_voidLedOn (LED_CONF_T* A_u8LED_ID)
{
    switch (A_u8LED_ID->PORT)
    {
    case GPIO_PORTA :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        }
        break ;
    case GPIO_PORTB :
        MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        break ;
    case GPIO_PORTC :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1 &&
            A_u8LED_ID->PIN != GPIO_PIN_2 && A_u8LED_ID->PIN != GPIO_PIN_3)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_u8LED_ID->PIN != GPIO_PIN_4 && A_u8LED_ID->PIN != GPIO_PIN_5)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_u8LED_ID->PIN != GPIO_PIN_6 && A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_u8LED_ID->PIN != GPIO_PIN_5 && A_u8LED_ID->PIN != GPIO_PIN_6 &&
            A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 1) ;
        }
        break ;
    default : /*Error Case*/
    break ;
    }
}

void HLED_voidLedOff (LED_CONF_T* A_u8LED_ID)
{
    switch (A_u8LED_ID->PORT)
    {
    case GPIO_PORTA :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        }
        break ;
    case GPIO_PORTB :
        MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        break ;
    case GPIO_PORTC :
        if (A_u8LED_ID->PIN != GPIO_PIN_0 && A_u8LED_ID->PIN != GPIO_PIN_1 &&
            A_u8LED_ID->PIN != GPIO_PIN_2 && A_u8LED_ID->PIN != GPIO_PIN_3)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_u8LED_ID->PIN != GPIO_PIN_4 && A_u8LED_ID->PIN != GPIO_PIN_5)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_u8LED_ID->PIN != GPIO_PIN_6 && A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_u8LED_ID->PIN != GPIO_PIN_5 && A_u8LED_ID->PIN != GPIO_PIN_6 &&
            A_u8LED_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidSetPinValue (A_u8LED_ID->PORT , A_u8LED_ID->PIN , 0) ;
        }
        break ;
    default : /*Error Case*/
    break ;
    }
}


