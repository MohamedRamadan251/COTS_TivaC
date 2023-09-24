/*
 * EXTI_prog.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "../MY_GPIO/GPIO_init.h"
#include "EXTI_init.h"

/*pointer to function to set call back of EXTI0*/
static void (*EXTI_LINE_0_CallBack) (void) ;
/*pointer to function to set call back of EXTI1*/
static void (*EXTI_LINE_1_CallBack) (void) ;
/*pointer to function to set call back of EXTI2*/
static void (*EXTI_LINE_2_CallBack) (void) ;
/*pointer to function to set call back of EXTI3*/
static void (*EXTI_LINE_3_CallBack) (void) ;
/*pointer to function to set call back of EXTI4*/
static void (*EXTI_LINE_4_CallBack) (void) ;
/*pointer to function to set call back of EXTI5*/
static void (*EXTI_LINE_5_CallBack) (void) ;
/*pointer to function to set call back of EXTI6*/
static void (*EXTI_LINE_6_CallBack) (void) ;
/*pointer to function to set call back of EXTI7*/
static void (*EXTI_LINE_7_CallBack) (void) ;

void MEXTI_voidInit (uint32_t A_uint32_tPortId , uint32_t A_uint32_tLineNum , uint32_t A_uint32_tTrrigType)
{
    switch (A_uint32_tPortId)
    {
    case GPIO_PORTA :
        if (A_uint32_tLineNum >= EXTI_LINE_2 && A_uint32_tLineNum <= EXTI_LINE_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA) ;
            GPIOUnlockPin (GPIO_PORTA_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTA_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTA_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTA_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTA_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTA_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOA) ;
            IntMasterEnable() ;
        }
        break ;
    case GPIO_PORTB :
        if (A_uint32_tLineNum <= EXTI_LINE_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOB) ;
            GPIOUnlockPin (GPIO_PORTB_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTB_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTB_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTB_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTB_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTB_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOB) ;
            IntMasterEnable() ;
        }
        break ;
    case GPIO_PORTC :
        if (A_uint32_tLineNum >= EXTI_LINE_4 && A_uint32_tLineNum <= EXTI_LINE_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOC) ;
            GPIOUnlockPin (GPIO_PORTC_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTC_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTC_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTC_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTC_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTC_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOC) ;
            IntMasterEnable() ;
        }
        break ;
    case GPIO_PORTD :
        if (A_uint32_tLineNum != EXTI_LINE_4 && A_uint32_tLineNum != EXTI_LINE_5 && A_uint32_tLineNum <= EXTI_LINE_7)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOD) ;
            GPIOUnlockPin (GPIO_PORTD_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTD_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTD_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTD_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTD_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTD_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOD) ;
            IntMasterEnable() ;
        }
        break ;
    case GPIO_PORTE :
        if (A_uint32_tLineNum <= EXTI_LINE_5)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE) ;
            GPIOUnlockPin (GPIO_PORTE_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTE_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTE_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTE_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTE_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTE_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOE) ;
            IntMasterEnable() ;
        }
        break ;
    case GPIO_PORTF :
        if (A_uint32_tLineNum <= EXTI_LINE_4)
        {
            SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF) ;
            GPIOUnlockPin (GPIO_PORTF_BASE ,A_uint32_tLineNum) ;
            GPIOPinTypeGPIOInput (GPIO_PORTF_BASE , A_uint32_tLineNum) ;
            if (A_uint32_tTrrigType == EXTI_HIGH_LEVEL || A_uint32_tTrrigType == EXTI_RISING)
            {
                GPIOPadConfigSet(GPIO_PORTF_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD) ;
            }
            else
            {
                GPIOPadConfigSet(GPIO_PORTF_BASE, A_uint32_tLineNum, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
            }
            GPIOIntTypeSet(GPIO_PORTF_BASE, A_uint32_tLineNum, A_uint32_tTrrigType);
            GPIOIntEnable(GPIO_PORTF_BASE, A_uint32_tLineNum);
            IntEnable (INT_GPIOF) ;
            IntMasterEnable() ;
        }
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void MEXTI_voidSetCallBack (uint32_t A_uint32_tLineNum , void (*A_fptr)(void))
{
    switch (A_uint32_tLineNum)
    {
    case EXTI_LINE_0 :
        EXTI_LINE_0_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_1 :
        EXTI_LINE_1_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_2 :
        EXTI_LINE_2_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_3 :
        EXTI_LINE_3_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_4 :
        EXTI_LINE_4_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_5 :
        EXTI_LINE_5_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_6 :
        EXTI_LINE_6_CallBack = A_fptr ;
        break ;
    case EXTI_LINE_7 :
        EXTI_LINE_7_CallBack = A_fptr ;
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void PortAIntHandler (void)
{
    if (EXTI_LINE_2_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<2))>>2) == 1)
    {
        EXTI_LINE_2_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_2) ;
    }
    if (EXTI_LINE_3_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<3))>>3) == 1)
    {
        EXTI_LINE_3_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_3) ;
    }
    if (EXTI_LINE_4_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<4))>>4) == 1)
    {
        EXTI_LINE_4_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_4) ;
    }
    if (EXTI_LINE_5_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<5))>>5) == 1)
    {
        EXTI_LINE_5_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_5) ;
    }
    if (EXTI_LINE_6_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<6))>>6) == 1)
    {
        EXTI_LINE_6_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_6) ;
    }
    if (EXTI_LINE_7_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTA_BASE))) & (1<<7))>>7) == 1)
    {
        EXTI_LINE_7_CallBack () ;
        GPIOIntClear (GPIO_PORTA_BASE , EXTI_LINE_7) ;
    }
}

void PortBIntHandler (void)
{
    if (EXTI_LINE_0_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<0))>>0) == 1)
    {
        EXTI_LINE_0_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_0) ;
    }
    if (EXTI_LINE_1_CallBack != 0&&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<1))>>1) == 1)
    {
        EXTI_LINE_1_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_1) ;
    }
    if (EXTI_LINE_2_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<2))>>2) == 1)
    {
        EXTI_LINE_2_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_2) ;
    }
    if (EXTI_LINE_3_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<3))>>3) == 1)
    {
        EXTI_LINE_3_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_3) ;
    }
    if (EXTI_LINE_4_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<4))>>4) == 1)
    {
        EXTI_LINE_4_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_4) ;
    }
    if (EXTI_LINE_5_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<5))>>5) == 1)
    {
        EXTI_LINE_5_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_5) ;
    }
    if (EXTI_LINE_6_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<6))>>6) == 1)
    {
        EXTI_LINE_6_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_6) ;
    }
    if (EXTI_LINE_7_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTB_BASE))) & (1<<7))>>7) == 1)
    {
        EXTI_LINE_7_CallBack () ;
        GPIOIntClear (GPIO_PORTB_BASE , EXTI_LINE_7) ;
    }
}

void PortCIntHandler (void)
{
    if (EXTI_LINE_4_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTC_BASE))) & (1<<4))>>4) == 1)
    {
        EXTI_LINE_4_CallBack () ;
        GPIOIntClear (GPIO_PORTC_BASE , EXTI_LINE_4) ;
    }
    if (EXTI_LINE_5_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTC_BASE))) & (1<<5))>>5) == 1)
    {
        EXTI_LINE_5_CallBack () ;
        GPIOIntClear (GPIO_PORTC_BASE , EXTI_LINE_5) ;
    }
    if (EXTI_LINE_6_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTC_BASE))) & (1<<6))>>6) == 1)
    {
        EXTI_LINE_6_CallBack () ;
        GPIOIntClear (GPIO_PORTC_BASE , EXTI_LINE_6) ;
    }
    if (EXTI_LINE_7_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTC_BASE))) & (1<<7))>>7) == 1)
    {
        EXTI_LINE_7_CallBack () ;
        GPIOIntClear (GPIO_PORTC_BASE , EXTI_LINE_7) ;
    }
}

void PortDIntHandler (void)
{
    if (EXTI_LINE_0_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<0))>>0) == 1)
    {
        EXTI_LINE_0_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_0) ;
    }
    if (EXTI_LINE_1_CallBack != 0&&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<1))>>1) == 1)
    {
        EXTI_LINE_1_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_1) ;
    }
    if (EXTI_LINE_2_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<2))>>2) == 1)
    {
        EXTI_LINE_2_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_2) ;
    }
    if (EXTI_LINE_3_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<3))>>3) == 1)
    {
        EXTI_LINE_3_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_3) ;
    }
    if (EXTI_LINE_6_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<6))>>6) == 1)
    {
        EXTI_LINE_6_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_6) ;
    }
    if (EXTI_LINE_7_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTD_BASE))) & (1<<7))>>7) == 1)
    {
        EXTI_LINE_7_CallBack () ;
        GPIOIntClear (GPIO_PORTD_BASE , EXTI_LINE_7) ;
    }
}

void PortEIntHandler (void)
{
    if (EXTI_LINE_0_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<0))>>0) == 1)
    {
        EXTI_LINE_0_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_0) ;
    }
    if (EXTI_LINE_1_CallBack != 0&&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<1))>>1) == 1)
    {
        EXTI_LINE_1_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_1) ;
    }
    if (EXTI_LINE_2_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<2))>>2) == 1)
    {
        EXTI_LINE_2_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_2) ;
    }
    if (EXTI_LINE_3_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<3))>>3) == 1)
    {
        EXTI_LINE_3_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_3) ;
    }
    if (EXTI_LINE_4_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<4))>>4) == 1)
    {
        EXTI_LINE_4_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_4) ;
    }
    if (EXTI_LINE_5_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTE_BASE))) & (1<<5))>>5) == 1)
    {
        EXTI_LINE_5_CallBack () ;
        GPIOIntClear (GPIO_PORTE_BASE , EXTI_LINE_5) ;
    }
}

void PortFIntHandler (void)
{
    if (EXTI_LINE_0_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTF_BASE))) & (1<<0))>>0) == 1)
    {
        EXTI_LINE_0_CallBack () ;
        GPIOIntClear (GPIO_PORTF_BASE , EXTI_LINE_0) ;
    }
    if (EXTI_LINE_1_CallBack != 0&&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTF_BASE))) & (1<<1))>>1) == 1)
    {
        EXTI_LINE_1_CallBack () ;
        GPIOIntClear (GPIO_PORTF_BASE , EXTI_LINE_1) ;
    }
    if (EXTI_LINE_2_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTF_BASE))) & (1<<2))>>2) == 1)
    {
        EXTI_LINE_2_CallBack () ;
        GPIOIntClear (GPIO_PORTF_BASE , EXTI_LINE_2) ;
    }
    if (EXTI_LINE_3_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTF_BASE))) & (1<<3))>>3) == 1)
    {
        EXTI_LINE_3_CallBack () ;
        GPIOIntClear (GPIO_PORTF_BASE , EXTI_LINE_3) ;
    }
    if (EXTI_LINE_4_CallBack != 0 &&
        (((*((volatile uint32_t *)(GPIO_O_RIS + GPIO_PORTF_BASE))) & (1<<4))>>4) == 1)
    {
        EXTI_LINE_4_CallBack () ;
        GPIOIntClear (GPIO_PORTF_BASE , EXTI_LINE_4) ;
    }
}
