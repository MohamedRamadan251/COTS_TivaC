/*
 * GPIO_prog.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

#include "GPIO_init.h"
void MGPIO_voidInit (uint32_t A_uint32_tPort , uint32_t A_uint32_tPin , uint32_t A_uint32_tType)
{
    switch (A_uint32_tPort)
    {
    case GPIO_PORTA :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA) ;
            GPIOUnlockPin (GPIO_PORTA_BASE ,A_uint32_tPin) ;
            if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOOutput (GPIO_PORTA_BASE , A_uint32_tPin) ;
            }
            else if (A_uint32_tType == GPIO_INPUT)
            {
                GPIOPinTypeGPIOInput (GPIO_PORTA_BASE , A_uint32_tPin) ;
            }
        }
        break ;
    case GPIO_PORTB :
        SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOB) ;
        GPIOUnlockPin (GPIO_PORTB_BASE ,A_uint32_tPin) ;
        if (A_uint32_tType == GPIO_OUTPUT)
        {
            GPIOPinTypeGPIOOutput (GPIO_PORTB_BASE , A_uint32_tPin) ;
        }
        else if (A_uint32_tType == GPIO_OUTPUT)
        {
            GPIOPinTypeGPIOInput (GPIO_PORTB_BASE , A_uint32_tPin) ;
        }
        break ;
    case GPIO_PORTC :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1 &&
            A_uint32_tPin != GPIO_PIN_2 && A_uint32_tPin != GPIO_PIN_3)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOC) ;
            GPIOUnlockPin (GPIO_PORTC_BASE ,A_uint32_tPin) ;
            if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOOutput (GPIO_PORTC_BASE , A_uint32_tPin) ;
            }
            else if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOInput (GPIO_PORTC_BASE , A_uint32_tPin) ;
            }
        }
        break ;
    case GPIO_PORTD :
        if (A_uint32_tPin != GPIO_PIN_4 && A_uint32_tPin != GPIO_PIN_5)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOD) ;
            GPIOUnlockPin (GPIO_PORTD_BASE ,A_uint32_tPin) ;
            if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOOutput (GPIO_PORTD_BASE , A_uint32_tPin) ;
            }
            else if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOInput (GPIO_PORTD_BASE , A_uint32_tPin) ;
            }
        }
        break ;
    case GPIO_PORTE :
        if (A_uint32_tPin != GPIO_PIN_6 && A_uint32_tPin != GPIO_PIN_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE) ;
            GPIOUnlockPin (GPIO_PORTE_BASE ,A_uint32_tPin) ;
            if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOOutput (GPIO_PORTE_BASE , A_uint32_tPin) ;
            }
            else if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOInput (GPIO_PORTE_BASE , A_uint32_tPin) ;
            }
        }
        break ;
    case GPIO_PORTF :
        if (A_uint32_tPin != GPIO_PIN_5 && A_uint32_tPin != GPIO_PIN_6 &&
                A_uint32_tPin != GPIO_PIN_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF) ;
            GPIOUnlockPin (GPIO_PORTF_BASE ,A_uint32_tPin) ;
            if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE , A_uint32_tPin) ;
            }
            else if (A_uint32_tType == GPIO_OUTPUT)
            {
                GPIOPinTypeGPIOInput (GPIO_PORTF_BASE , A_uint32_tPin) ;
            }
        }
        break ;
    default :
            /*Error case*/
        break ;
    }
}

void MGPIO_voidSetPinValue (uint32_t A_uint32_tPort , uint32_t A_uint32_tPin , uint32_t A_uint32_tValue)
{
    switch (A_uint32_tPort)
    {
    case GPIO_PORTA :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1)
        {
            GPIOPinWrite (GPIO_PORTF_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        }
        break ;
    case GPIO_PORTB :
        GPIOPinWrite (GPIO_PORTB_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        break ;
    case GPIO_PORTC :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1 &&
            A_uint32_tPin != GPIO_PIN_2 && A_uint32_tPin != GPIO_PIN_3)
        {
            GPIOPinWrite (GPIO_PORTC_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_uint32_tPin != GPIO_PIN_4 && A_uint32_tPin != GPIO_PIN_5)
        {
            GPIOPinWrite (GPIO_PORTD_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_uint32_tPin != GPIO_PIN_6 && A_uint32_tPin != GPIO_PIN_7)
        {
            GPIOPinWrite (GPIO_PORTE_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_uint32_tPin != GPIO_PIN_5 && A_uint32_tPin != GPIO_PIN_6 &&
            A_uint32_tPin != GPIO_PIN_7)
        {
            GPIOPinWrite (GPIO_PORTF_BASE , A_uint32_tPin , (A_uint32_tValue)?0xff:0) ;
        }
        break ;
    default :
            /*Error case*/
        break ;
    }
}

uint32_t   MGPIO_uint32_tGetPinValue (uint32_t A_uint32_tPort , uint32_t A_uint32_tPin)
{
    uint32_t L_uint32_tGetVal ;
    switch (A_uint32_tPort)
    {
    case GPIO_PORTA :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1)
        {
            GPIOPadConfigSet(GPIO_PORTA_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            L_uint32_tGetVal = GPIOPinRead(GPIO_PORTA_BASE, A_uint32_tPin) ;
        }
        break ;
    case GPIO_PORTB :
        GPIOPadConfigSet(GPIO_PORTB_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
        L_uint32_tGetVal = GPIOPinRead(GPIO_PORTB_BASE, A_uint32_tPin) ;
        break ;
    case GPIO_PORTC :
        if (A_uint32_tPin != GPIO_PIN_0 && A_uint32_tPin != GPIO_PIN_1 &&
                A_uint32_tPin != GPIO_PIN_2 && A_uint32_tPin != GPIO_PIN_3)
        {
            GPIOPadConfigSet(GPIO_PORTC_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            L_uint32_tGetVal = GPIOPinRead(GPIO_PORTC_BASE, A_uint32_tPin) ;
        }
        break ;
    case GPIO_PORTD :
        if (A_uint32_tPin != GPIO_PIN_4 && A_uint32_tPin != GPIO_PIN_5)
        {
            GPIOPadConfigSet(GPIO_PORTD_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            L_uint32_tGetVal = GPIOPinRead(GPIO_PORTD_BASE, A_uint32_tPin) ;
        }
        break ;
    case GPIO_PORTE :
        if (A_uint32_tPin != GPIO_PIN_6 && A_uint32_tPin != GPIO_PIN_7)
        {
            GPIOPadConfigSet(GPIO_PORTE_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            L_uint32_tGetVal = GPIOPinRead(GPIO_PORTE_BASE, A_uint32_tPin) ;
        }
        break ;
    case GPIO_PORTF :
        if (A_uint32_tPin != GPIO_PIN_5 && A_uint32_tPin != GPIO_PIN_6 &&
            A_uint32_tPin != GPIO_PIN_7)
        {
            GPIOPadConfigSet(GPIO_PORTF_BASE, A_uint32_tPin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            L_uint32_tGetVal = GPIOPinRead(GPIO_PORTF_BASE, A_uint32_tPin) ;
        }
        break ;
    default :
        /*Error case*/
        break ;
        }
    return L_uint32_tGetVal ;
}
