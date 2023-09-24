/*
 * PButton_prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/STD_TYPES.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"

#include "PButton_int.h"


void HPB_voidPBInitial (PB_CONF_T* A_u8PB_ID)
{
    switch (A_u8PB_ID->PORT)
    {
    case GPIO_PORTA :
        if (A_u8PB_ID->PIN != GPIO_PIN_0 && A_u8PB_ID->PIN != GPIO_PIN_1)
        {
            MGPIO_voidInit(GPIO_PORTA , A_u8PB_ID->PIN, GPIO_INPUT) ;
        }
        break ;
    case GPIO_PORTB :
        MGPIO_voidInit(GPIO_PORTB , A_u8PB_ID->PIN, GPIO_INPUT) ;
        break ;
    case GPIO_PORTC :
        if (A_u8PB_ID->PIN != GPIO_PIN_0 && A_u8PB_ID->PIN != GPIO_PIN_1 &&
            A_u8PB_ID->PIN != GPIO_PIN_2 && A_u8PB_ID->PIN != GPIO_PIN_3)
        {
            MGPIO_voidInit(GPIO_PORTC , A_u8PB_ID->PIN, GPIO_INPUT) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_u8PB_ID->PIN != GPIO_PIN_4 && A_u8PB_ID->PIN != GPIO_PIN_5)
        {
            MGPIO_voidInit(GPIO_PORTD , A_u8PB_ID->PIN, GPIO_INPUT) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_u8PB_ID->PIN != GPIO_PIN_6 && A_u8PB_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidInit(GPIO_PORTE , A_u8PB_ID->PIN, GPIO_INPUT) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_u8PB_ID->PIN != GPIO_PIN_5 && A_u8PB_ID->PIN != GPIO_PIN_6 &&
            A_u8PB_ID->PIN != GPIO_PIN_7)
        {
            MGPIO_voidInit(GPIO_PORTF , A_u8PB_ID->PIN, GPIO_INPUT) ;
        }
        break ;
    default : /*Error Case*/
        break ;
    }
}

uint32_t HPB_uint32_tPBGetStatues (PB_CONF_T* A_u8PB_ID)
{
    uint32_t L_uint32Staues = NOT_PRESSED ;
    switch (A_u8PB_ID->PORT)
    {
    case GPIO_PORTA :
        if (A_u8PB_ID->PIN != GPIO_PIN_0 && A_u8PB_ID->PIN != GPIO_PIN_1)
        {
            L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        }
        break ;
    case GPIO_PORTB :
        L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        break ;
    case GPIO_PORTC :
        if (A_u8PB_ID->PIN != GPIO_PIN_0 && A_u8PB_ID->PIN != GPIO_PIN_1 &&
            A_u8PB_ID->PIN != GPIO_PIN_2 && A_u8PB_ID->PIN != GPIO_PIN_3)
        {
            L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_u8PB_ID->PIN != GPIO_PIN_4 && A_u8PB_ID->PIN != GPIO_PIN_5)
        {
            L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_u8PB_ID->PIN != GPIO_PIN_6 && A_u8PB_ID->PIN != GPIO_PIN_7)
        {
            L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_u8PB_ID->PIN != GPIO_PIN_5 && A_u8PB_ID->PIN != GPIO_PIN_6 &&
            A_u8PB_ID->PIN != GPIO_PIN_7)
        {
            L_uint32Staues = MGPIO_uint32_tGetPinValue (A_u8PB_ID->PORT , A_u8PB_ID->PIN) ;
        }
        break ;
    default : /*Error Case*/
    break ;
    }
    return L_uint32Staues ;
}



