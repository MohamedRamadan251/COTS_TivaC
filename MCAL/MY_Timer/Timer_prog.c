/*
 * Timer_init_prog.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "Timer_init.h"

uint8_t flags_pwm      [20] = {0} ;
uint8_t flags_periodic [20] = {0} ;

uint32_t G_u32NumberOfOverFlowsTimer0A ;
uint32_t G_u32NumberOfOverFlowsTimer0B ;
uint32_t G_u32NumberOfOverFlowsTimer1A ;
uint32_t G_u32NumberOfOverFlowsTimer1B ;
uint32_t G_u32NumberOfOverFlowsTimer2A ;
uint32_t G_u32NumberOfOverFlowsTimer2B ;
uint32_t G_u32NumberOfOverFlowsTimer3A ;
uint32_t G_u32NumberOfOverFlowsTimer3B ;

uint32_t G_u32NumberOfOverFlowsWTimer0A ;
uint32_t G_u32NumberOfOverFlowsWTimer0B ;
uint32_t G_u32NumberOfOverFlowsWTimer1A ;
uint32_t G_u32NumberOfOverFlowsWTimer1B ;
uint32_t G_u32NumberOfOverFlowsWTimer2A ;
uint32_t G_u32NumberOfOverFlowsWTimer2B ;
uint32_t G_u32NumberOfOverFlowsWTimer3A ;
uint32_t G_u32NumberOfOverFlowsWTimer3B ;
uint32_t G_u32NumberOfOverFlowsWTimer4A ;
uint32_t G_u32NumberOfOverFlowsWTimer4B ;
uint32_t G_u32NumberOfOverFlowsWTimer5A ;
uint32_t G_u32NumberOfOverFlowsWTimer5B ;

/*pointer to function to set call back of Timer0A*/
static void (*Timer0A_CallBack) (void) ;
/*pointer to function to set call back of Timer0B*/
static void (*Timer0B_CallBack) (void) ;
/*pointer to function to set call back of Timer1A*/
static void (*Timer1A_CallBack) (void) ;
/*pointer to function to set call back of Timer1B*/
static void (*Timer1B_CallBack) (void) ;
/*pointer to function to set call back of Timer2A*/
static void (*Timer2A_CallBack) (void) ;
/*pointer to function to set call back of Timer2B*/
static void (*Timer2B_CallBack) (void) ;
/*pointer to function to set call back of Timer3A*/
static void (*Timer3A_CallBack) (void) ;
/*pointer to function to set call back of Timer3B*/
static void (*Timer3B_CallBack) (void) ;

/*pointer to function to set call back of WTimer0A*/
static void (*WTimer0A_CallBack) (void) ;
/*pointer to function to set call back of WTimer0B*/
static void (*WTimer0B_CallBack) (void) ;
/*pointer to function to set call back of WTimer1A*/
static void (*WTimer1A_CallBack) (void) ;
/*pointer to function to set call back of WTimer1B*/
static void (*WTimer1B_CallBack) (void) ;
/*pointer to function to set call back of WTimer2A*/
static void (*WTimer2A_CallBack) (void) ;
/*pointer to function to set call back of WTimer2B*/
static void (*WTimer2B_CallBack) (void) ;
/*pointer to function to set call back of WTimer3A*/
static void (*WTimer3A_CallBack) (void) ;
/*pointer to function to set call back of WTimer3B*/
static void (*WTimer3B_CallBack) (void) ;
/*pointer to function to set call back of WTimer4A*/
static void (*WTimer4A_CallBack) (void) ;
/*pointer to function to set call back of WTimer4B*/
static void (*WTimer4B_CallBack) (void) ;
/*pointer to function to set call back of WTimer5A*/
static void (*WTimer5A_CallBack) (void) ;
/*pointer to function to set call back of WTimer5B*/
static void (*WTimer5B_CallBack) (void) ;

/*********************       PWM        *********************/
void MTimer_voidTimerPwmInit (uint8_t A_u8TimerType)
{
    switch (A_u8TimerType)
    {
    case TIMER0_A :
        /* Enable Timer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
        /*Enable portF pin 0 for T0CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF0_T0CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER0_BASE, TIMER_A);
        /*Configure Timer0A as a 16-bit periodic timer*/
        TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER0_BASE, TIMER_A, 1) ;
        /*Set the Timer0A load value to 0xffff*/
        TimerLoadSet(TIMER0_BASE, TIMER_A, 0xffff);
        break ;
    case TIMER0_B :
        /* Enable Timer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
        /*Enable portF pin 1 for T0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_1) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF1_T0CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER0_BASE, TIMER_B);
        /*Configure Timer0B as a 16-bit periodic timer*/
        TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER0_BASE, TIMER_B, 1) ;
        /*Set the Timer0B load value to 0xffff*/
        TimerLoadSet(TIMER0_BASE, TIMER_B, 0xffff);
        break ;
    case TIMER1_A :
        /* Enable Timer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
        /*Enable portF pin 2 for T1CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF2_T1CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER1_BASE, TIMER_A);
        /*Configure Timer1A as a 16-bit periodic timer*/
        TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER1_BASE, TIMER_A, 1) ;
        /*Set the Timer1A load value to 0xffff*/
        TimerLoadSet(TIMER1_BASE, TIMER_A, 0xffff);
        break ;
    case TIMER1_B :
        /* Enable Timer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
        /*Enable portF pin 3 for T1CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF3_T1CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER1_BASE, TIMER_B);
        /*Configure Timer1B as a 16-bit periodic timer*/
        TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER1_BASE, TIMER_B, 1) ;
        /*Set the Timer1B load value to 0xffff*/
        TimerLoadSet(TIMER1_BASE, TIMER_B, 0xffff);
        break ;
    case TIMER2_A :
        /* Enable Timer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
        /*Enable portB pin 0 for T2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB0_T2CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER2_BASE, TIMER_A);
        /*Configure Timer2A as a 16-bit periodic timer*/
        TimerConfigure(TIMER2_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER2_BASE, TIMER_A, 1) ;
        /*Set the Timer2A load value to 0xffff*/
        TimerLoadSet(TIMER2_BASE, TIMER_A, 0xffff);
        break ;
    case TIMER2_B :
        /* Enable Timer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
        /*Enable portB pin 1 for T2CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB1_T2CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER2_BASE, TIMER_B);
        /*Configure Timer2B as a 16-bit periodic timer*/
        TimerConfigure(TIMER2_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER2_BASE, TIMER_B, 1) ;
        /*Set the Timer2B load value to 0xffff*/
        TimerLoadSet(TIMER2_BASE, TIMER_B, 0xffff);
        break ;
    case TIMER3_A :
        /* Enable Timer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
        /*Enable portB pin 2 for T2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB2_T3CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER3_BASE, TIMER_A);
        /*Configure Timer3A as a 16-bit periodic timer*/
        TimerConfigure(TIMER3_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER3_BASE, TIMER_A, 1) ;
        /*Set the Timer3A load value to 0xffff*/
        TimerLoadSet(TIMER3_BASE, TIMER_A, 0xffff);
        break ;
    case TIMER3_B :
        /* Enable Timer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
        /*Enable portB pin 3 for T3CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB3_T3CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER3_BASE, TIMER_B);
        /*Configure Timer3B as a 16-bit periodic timer*/
        TimerConfigure(TIMER3_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(TIMER3_BASE, TIMER_B, 1) ;
        /*Set the Timer3B load value to 0xffff*/
        TimerLoadSet(TIMER3_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER0_A :
        /* Enable WTimer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
        /*Enable portC pin 4 for WT0CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_4) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC4_WT0CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_4);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER0_BASE, TIMER_A);
        /*Configure WTimer0A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER0_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER0_BASE, TIMER_A, 1) ;
        /*Set the WTimer0A load value to 0xffff*/
        TimerLoadSet(WTIMER0_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER0_B :
        /* Enable WTimer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
        /*Enable portC pin 5 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_5) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC5_WT0CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_5);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER0_BASE, TIMER_B);
        /*Configure WTimer0B as a 32-bit periodic timer*/
        TimerConfigure(WTIMER0_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER0_BASE, TIMER_B, 1) ;
        /*Set the WTimer0B load value to 0xffff*/
        TimerLoadSet(WTIMER0_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER1_A :
        /* Enable WTimer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER1);
        /*Enable portC pin 6 for WT1CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_6) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC6_WT1CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_6);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER1_BASE, TIMER_A);
        /*Configure WTimer1A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER1_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER1_BASE, TIMER_A, 1) ;
        /*Set the WTimer1A load value to 0xffff*/
        TimerLoadSet(WTIMER1_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER1_B :
        /* Enable WTimer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER1);
        /*Enable portC pin 7 for WT1CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_7) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC7_WT1CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_7);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER1_BASE, TIMER_B);
        /*Configure WTimer1B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER1_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER1_BASE, TIMER_B, 1) ;
        /*Set the WTimer1B load value to 0xffff*/
        TimerLoadSet(WTIMER1_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER2_A :
        /* Enable WTimer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);
        /*Enable portD pin 0 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_0) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD0_WT2CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER2_BASE, TIMER_A);
        /*Configure WTimer2A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER2_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER2_BASE, TIMER_A, 1) ;
        /*Set the WTimer2A load value to 0xffff*/
        TimerLoadSet(WTIMER2_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER2_B :
        /* Enable WTimer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);
        /*Enable portC pin 5 for WT2CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_1) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD1_WT2CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER2_BASE, TIMER_B);
        /*Configure WTimer2B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER2_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER2_BASE, TIMER_B, 1) ;
        /*Set the WTimer2B load value to 0xffff*/
        TimerLoadSet(WTIMER2_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER3_A :
        /* Enable WTimer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER3);
        /*Enable portD pin 0 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_2) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD2_WT3CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER3_BASE, TIMER_A);
        /*Configure WTimer3A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER3_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER3_BASE, TIMER_A, 1) ;
        /*Set the WTimer3A load value to 0xffff*/
        TimerLoadSet(WTIMER3_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER3_B :
        /* Enable WTimer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER3);
        /*Enable portD pin 3 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_3) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD3_WT3CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER3_BASE, TIMER_B);
        /*Configure WTimer3B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER3_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER3_BASE, TIMER_B, 1) ;
        /*Set the WTimer3B load value to 0xffff*/
        TimerLoadSet(WTIMER3_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER4_A :
        /* Enable WTimer4 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4);
        /*Enable portD pin 4 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_4) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD4_WT4CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_4);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER4_BASE, TIMER_A);
        /*Configure WTimer4A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER4_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER4_BASE, TIMER_A, 1) ;
        /*Set the WTimer4A load value to 0xffff*/
        TimerLoadSet(WTIMER4_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER4_B :
        /* Enable WTimer4 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4);
        /*Enable portD pin 5 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_5) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD5_WT4CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_5);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER4_BASE, TIMER_B);
        /*Configure WTimer4B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER4_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER4_BASE, TIMER_B, 1) ;
        /*Set the WTimer4B load value to 0xffff*/
        TimerLoadSet(WTIMER4_BASE, TIMER_B, 0xffff);
        break ;
    case WTIMER5_A :
        /* Enable WTimer5 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER5);
        /*Enable portD pin 6 for WT5CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_6) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD6_WT5CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_6);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER5_BASE, TIMER_A);
        /*Configure WTimer5A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER5_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER5_BASE, TIMER_A, 1) ;
        /*Set the WTimer5A load value to 0xffff*/
        TimerLoadSet(WTIMER5_BASE, TIMER_A, 0xffff);
        break ;
    case WTIMER5_B :
        /* Enable WTimer5 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER5);
        /*Enable portD pin 7 for WT5CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_7) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD7_WT5CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_7);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER5_BASE, TIMER_B);
        /*Configure WTimer5B as a 32-bit periodic timer*/
        TimerConfigure(WTIMER5_BASE, TIMER_CFG_SPLIT_PAIR | 0xA0A);
        /*choose Controls the output level.*/
        TimerControlLevel(WTIMER5_BASE, TIMER_B, 1) ;
        /*Set the WTimer5B load value to 0xffff*/
        TimerLoadSet(WTIMER5_BASE, TIMER_B, 0xffff);
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void MTimer_voidSetPWM (uint8_t A_u8TimerType , uint32_t A_u32Value)
{
    switch (A_u8TimerType)
    {
    case TIMER0_A :
        /* Set the Timer0A match to value*/
        TimerMatchSet(TIMER0_BASE, TIMER_A, A_u32Value);
        /*Enable Timer0A*/
        if (!flags_pwm [0])
        {
            flags_pwm [0] = 1 ;
            TimerEnable(TIMER0_BASE, TIMER_A);
        }
        break ;
    case TIMER0_B :
        /* Set the Timer0B match to value*/
        TimerMatchSet(TIMER0_BASE, TIMER_B, A_u32Value);
        /*Enable Timer0B*/
        if (!flags_pwm [1])
        {
            flags_pwm [1] = 1 ;
            TimerEnable(TIMER0_BASE, TIMER_B);
        }
        break ;
    case TIMER1_A :
        /* Set the Timer1B match to value*/
        TimerMatchSet(TIMER1_BASE, TIMER_A, A_u32Value);
        /*Enable Timer1A*/
        if (!flags_pwm [2])
        {
            flags_pwm [2] = 1 ;
            TimerEnable(TIMER1_BASE, TIMER_A);
        }
        break ;
    case TIMER1_B :
        /* Set the Timer1B match to value*/
        TimerMatchSet(TIMER1_BASE, TIMER_B, A_u32Value);
        /*Enable Timer1B*/
        if (!flags_pwm [3])
        {
            flags_pwm [3] = 1 ;
            TimerEnable(TIMER1_BASE, TIMER_B);
        }
        break ;
    case TIMER2_A :
        /* Set the Timer2A match to value*/
        TimerMatchSet(TIMER2_BASE, TIMER_A, A_u32Value);
        /*Enable Timer2A*/
        if (!flags_pwm [4])
        {
            flags_pwm [4] = 1 ;
            TimerEnable(TIMER2_BASE, TIMER_A);
        }
        break ;
    case TIMER2_B :
        /* Set the Timer2B match to value*/
        TimerMatchSet(TIMER2_BASE, TIMER_B, A_u32Value);
        /*Enable Timer2B*/
        if (!flags_pwm [5])
        {
            flags_pwm [5] = 1 ;
            TimerEnable(TIMER2_BASE, TIMER_B);
        }
        break ;
    case TIMER3_A :
        /* Set the Timer3A match to value*/
        TimerMatchSet(TIMER3_BASE, TIMER_A, A_u32Value);
        /*Enable Timer3A*/
        if (!flags_pwm [6])
        {
            flags_pwm [6] = 1 ;
            TimerEnable(TIMER3_BASE, TIMER_A);
        }
        break ;
    case TIMER3_B :
        /* Set the Timer3B match to value*/
        TimerMatchSet(TIMER3_BASE, TIMER_B, A_u32Value);
        /*Enable Timer3B*/
        if (!flags_pwm [7])
        {
            flags_pwm [7] = 1 ;
            TimerEnable(TIMER3_BASE, TIMER_B);
        }
        break ;
    case WTIMER0_A :
        /* Set the Timer0A match to value*/
        TimerMatchSet(WTIMER0_BASE, TIMER_A, A_u32Value);
        /*Enable Timer0A*/
        if (!flags_pwm [8])
        {
            flags_pwm [8] = 1 ;
            TimerEnable(WTIMER0_BASE, TIMER_A);
        }
        break ;
    case WTIMER0_B :
        /* Set the Timer0B match to value*/
        TimerMatchSet(WTIMER0_BASE, TIMER_B, A_u32Value);
        /*Enable Timer0B*/
        if (!flags_pwm [9])
        {
            flags_pwm [9] = 1 ;
            TimerEnable(WTIMER0_BASE, TIMER_B);
        }
        break ;
    case WTIMER1_A :
        /* Set the Timer1A match to value*/
        TimerMatchSet(WTIMER1_BASE, TIMER_A, A_u32Value);
        /*Enable Timer1A*/
        if (!flags_pwm [10])
        {
            flags_pwm [10] = 1 ;
            TimerEnable(WTIMER1_BASE, TIMER_A);
        }
        break ;
    case WTIMER1_B :
        /* Set the Timer1B match to value*/
        TimerMatchSet(WTIMER1_BASE, TIMER_B, A_u32Value);
        /*Enable Timer1B*/
        if (!flags_pwm [11])
        {
            flags_pwm [11] = 1 ;
            TimerEnable(WTIMER1_BASE, TIMER_B);
        }
        break ;
    case WTIMER2_A :
        /* Set the Timer2A match to value*/
        TimerMatchSet(WTIMER2_BASE, TIMER_A, A_u32Value);
        /*Enable Timer2A*/
        if (!flags_pwm [12])
        {
            flags_pwm [12] = 1 ;
            TimerEnable(WTIMER2_BASE, TIMER_A);
        }
        break ;
    case WTIMER2_B :
        /* Set the Timer2B match to value*/
        TimerMatchSet(WTIMER2_BASE, TIMER_B, A_u32Value);
        /*Enable Timer2B*/
        if (!flags_pwm [13])
        {
            flags_pwm [13] = 1 ;
            TimerEnable(WTIMER2_BASE, TIMER_B);
        }
        break ;
    case WTIMER3_A :
        /* Set the Timer3A match to value*/
        TimerMatchSet(WTIMER3_BASE, TIMER_A, A_u32Value);
        /*Enable Timer3A*/
        if (!flags_pwm [14])
        {
            flags_pwm [14] = 1 ;
            TimerEnable(WTIMER3_BASE, TIMER_A);
        }
        break ;
    case WTIMER3_B :
        /* Set the Timer3B match to value*/
        TimerMatchSet(WTIMER3_BASE, TIMER_B, A_u32Value);
        /*Enable Timer3B*/
        if (!flags_pwm [15])
        {
            flags_pwm [15] = 1 ;
            TimerEnable(WTIMER3_BASE, TIMER_B);
        }
        break ;
    case WTIMER4_A :
        /* Set the Timer4A match to value*/
        TimerMatchSet(WTIMER4_BASE, TIMER_A, A_u32Value);
        /*Enable Timer4A*/
        if (!flags_pwm [16])
        {
            flags_pwm [10] = 1 ;
            TimerEnable(WTIMER4_BASE, TIMER_A);
        }
        break ;
    case WTIMER4_B :
        /* Set the Timer4B match to value*/
        TimerMatchSet(WTIMER4_BASE, TIMER_B, A_u32Value);
        /*Enable Timer4B*/
        if (!flags_pwm [17])
        {
            flags_pwm [17] = 1 ;
            TimerEnable(WTIMER4_BASE, TIMER_B);
        }
        break ;
    case WTIMER5_A :
        /* Set the Timer5A match to value*/
        TimerMatchSet(WTIMER5_BASE, TIMER_A, A_u32Value);
        /*Enable Timer5A*/
        if (!flags_pwm [18])
        {
            flags_pwm [18] = 1 ;
            TimerEnable(WTIMER5_BASE, TIMER_A);
        }
        break ;
    case WTIMER5_B :
        /* Set the Timer5B match to value*/
        TimerMatchSet(WTIMER5_BASE, TIMER_B, A_u32Value);
        /*Enable Timer5B*/
        if (!flags_pwm [19])
        {
            flags_pwm [19] = 1 ;
            TimerEnable(WTIMER5_BASE, TIMER_B);
        }
        break ;
    default :
        /*Error case*/
        break ;
    }
}


/*********************     Periodic     *********************/
void MTimer_voidTimerPeriodicInit (uint8_t A_u8TimerType)
{
    /* Enable processor interrupts*/
    IntMasterEnable();
    switch (A_u8TimerType)
    {
    case TIMER0_A :
        /* Enable Timer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
        /*Enable portF pin 0 for T0CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_0) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF0_T0CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER0_BASE, TIMER_A);
        /*Configure Timer0A as a 16-bit periodic timer*/
        TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer0A interrupt for timer timeout*/
        TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the Timer0A interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER0A);
        break ;
    case TIMER0_B :
        /* Enable Timer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
        /*Enable portF pin 1 for T0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTF_BASE, GPIO_PIN_1) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF1_T0CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER0_BASE, TIMER_B);
        /*Configure Timer0B as a 16-bit periodic timer*/
        TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer0B interrupt for timer timeout*/
        TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the Timer0B interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER0B);
        break ;
    case TIMER1_A :
        /* Enable Timer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
        /*Enable portF pin 2 for T1CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF2_T1CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER1_BASE, TIMER_A);
        /*Configure Timer1A as a 16-bit periodic timer*/
        TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer1A interrupt for timer timeout*/
        TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the Timer1A interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER1A);
        break ;
    case TIMER1_B :
        /* Enable Timer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
        /*Enable portF pin 3 for T1CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PF3_T1CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER1_BASE, TIMER_B);
        /*Configure Timer1B as a 16-bit periodic timer*/
        TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer1B interrupt for timer timeout*/
        TimerIntEnable(TIMER1_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the Timer1B interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER1B);
        break ;
    case TIMER2_A :
        /* Enable Timer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
        /*Enable portB pin 0 for T2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB0_T2CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER2_BASE, TIMER_A);
        /*Configure Timer2A as a 16-bit periodic timer*/
        TimerConfigure(TIMER2_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer2A interrupt for timer timeout*/
        TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the Timer2A interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER2A);
        break ;
    case TIMER2_B :
        /* Enable Timer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
        /*Enable portB pin 1 for T2CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB1_T2CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER2_BASE, TIMER_B);
        /*Configure Timer2B as a 16-bit periodic timer*/
        TimerConfigure(TIMER2_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer2B interrupt for timer timeout*/
        TimerIntEnable(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the Timer2B interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER2B);
        break ;
    case TIMER3_A :
        /* Enable Timer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
        /*Enable portB pin 2 for T2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB2_T3CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER3_BASE, TIMER_A);
        /*Configure Timer3A as a 16-bit periodic timer*/
        TimerConfigure(TIMER3_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer3A interrupt for timer timeout*/
        TimerIntEnable(TIMER3_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the Timer3A interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER3A);
        break ;
    case TIMER3_B :
        /* Enable Timer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
        /*Enable portB pin 3 for T3CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PB3_T3CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(TIMER3_BASE, TIMER_B);
        /*Configure Timer3B as a 16-bit periodic timer*/
        TimerConfigure(TIMER3_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the Timer3B interrupt for timer timeout*/
        TimerIntEnable(TIMER3_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the Timer3B interrupt on the processor (NVIC) */
        IntEnable(INT_TIMER3B);
        break ;
    case WTIMER0_A :
        /* Enable WTimer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
        /*Enable portC pin 4 for WT0CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_4) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC4_WT0CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_4);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER0_BASE, TIMER_A);
        /*Configure WTimer0A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer0A interrupt for timer timeout*/
        TimerIntEnable(WTIMER0_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer0A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER0A);
        break ;
    case WTIMER0_B :
        /* Enable WTimer0 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
        /*Enable portC pin 5 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_5) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC5_WT0CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_5);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER0_BASE, TIMER_B);
        /*Configure WTimer0B as a 32-bit periodic timer*/
        TimerConfigure(WTIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer0B interrupt for timer timeout*/
        TimerIntEnable(WTIMER0_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer0B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER0B);
        break ;
    case WTIMER1_A :
        /* Enable WTimer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER1);
        /*Enable portC pin 6 for WT1CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_6) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC6_WT1CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_6);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER1_BASE, TIMER_A);
        /*Configure WTimer1A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer1A interrupt for timer timeout*/
        TimerIntEnable(WTIMER1_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer1A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER1A);
        break ;
    case WTIMER1_B :
        /* Enable WTimer1 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER1);
        /*Enable portC pin 7 for WT1CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTC_BASE, GPIO_PIN_7) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PC7_WT1CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTC_BASE, GPIO_PIN_7);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER1_BASE, TIMER_B);
        /*Configure WTimer1B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer1B interrupt for timer timeout*/
        TimerIntEnable(WTIMER1_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer1B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER1B);
        break ;
    case WTIMER2_A :
        /* Enable WTimer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);
        /*Enable portD pin 0 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_0) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD0_WT2CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_0);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER2_BASE, TIMER_A);
        /*Configure WTimer2A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER2_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer2A interrupt for timer timeout*/
        TimerIntEnable(WTIMER2_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer2A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER2A);
        break ;
    case WTIMER2_B :
        /* Enable WTimer2 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);
        /*Enable portC pin 5 for WT2CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_1) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD1_WT2CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_1);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER2_BASE, TIMER_B);
        /*Configure WTimer2B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER2_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer2B interrupt for timer timeout*/
        TimerIntEnable(WTIMER2_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer2B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER2B);
        break ;
    case WTIMER3_A :
        /* Enable WTimer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER3);
        /*Enable portD pin 0 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_2) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD2_WT3CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_2);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER3_BASE, TIMER_A);
        /*Configure WTimer3A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER3_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer3A interrupt for timer timeout*/
        TimerIntEnable(WTIMER3_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer3A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER3A);
        break ;
    case WTIMER3_B :
        /* Enable WTimer3 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER3);
        /*Enable portD pin 3 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_3) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD3_WT3CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_3);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER3_BASE, TIMER_B);
        /*Configure WTimer3B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER3_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer3B interrupt for timer timeout*/
        TimerIntEnable(WTIMER3_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer3B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER3B);
        break ;
    case WTIMER4_A :
        /* Enable WTimer4 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4);
        /*Enable portD pin 4 for WT2CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_4) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD4_WT4CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_4);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER4_BASE, TIMER_A);
        /*Configure WTimer4A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER4_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer4A interrupt for timer timeout*/
        TimerIntEnable(WTIMER4_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer4A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER4A);
        break ;
    case WTIMER4_B :
        /* Enable WTimer4 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4);
        /*Enable portD pin 5 for WT0CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_5) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD5_WT4CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_5);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER4_BASE, TIMER_B);
        /*Configure WTimer4B as a 16-bit periodic timer*/
        TimerConfigure(WTIMER4_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer4B interrupt for timer timeout*/
        TimerIntEnable(WTIMER4_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer4B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER4B);
        break ;
    case WTIMER5_A :
        /* Enable WTimer5 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER5);
        /*Enable portD pin 6 for WT5CCP0*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_6) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD6_WT5CCP0);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_6);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER5_BASE, TIMER_A);
        /*Configure WTimer5A as a 32-bit periodic timer*/
        TimerConfigure(WTIMER5_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer5A interrupt for timer timeout*/
        TimerIntEnable(WTIMER5_BASE, TIMER_TIMA_TIMEOUT);
        /* Enable the WTimer5A interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER5A);
        break ;
    case WTIMER5_B :
        /* Enable WTimer5 peripheral */
        SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER5);
        /*Enable portD pin 7 for WT5CCP1*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        /*unlock pin before used*/
        GPIOUnlockPin(GPIO_PORTD_BASE, GPIO_PIN_7) ;
        /*Configure the GPIO pin muxing for the Timer/CCP function*/
        GPIOPinConfigure(GPIO_PD7_WT5CCP1);
        /*Configure the ccp settings for CCP pin*/
        GPIOPinTypeTimer(GPIO_PORTD_BASE, GPIO_PIN_7);
        /*Ensure the timer is disabled (the TnEN bit is cleared) before making any changes*/
        TimerDisable(WTIMER5_BASE, TIMER_B);
        /*Configure WTimer5B as a 32-bit periodic timer*/
        TimerConfigure(WTIMER5_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC);
        /* Configure the WTimer5B interrupt for timer timeout*/
        TimerIntEnable(WTIMER5_BASE, TIMER_TIMB_TIMEOUT);
        /* Enable the WTimer5B interrupt on the processor (NVIC) */
        IntEnable(INT_WTIMER5B);
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void MTimer_voidTimerPeriodicSetCallBack (uint8_t A_u8TimerType ,uint32_t A_u32TimeInMill , void (*fptr)(void))
{
    switch (A_u8TimerType)
    {
    case TIMER0_A :
        G_u32NumberOfOverFlowsTimer0A = A_u32TimeInMill ;
        Timer0A_CallBack = fptr ;
        TimerLoadSet(TIMER0_BASE, TIMER_A, 16000);
        /*Enable Timer0A*/
        if (!flags_periodic [0])
        {
            flags_periodic [0] = 1 ;
            TimerEnable(TIMER0_BASE, TIMER_A);
        }
        break ;
    case TIMER0_B :
        G_u32NumberOfOverFlowsTimer0B = A_u32TimeInMill ;
        Timer0B_CallBack = fptr ;
        TimerLoadSet(TIMER0_BASE, TIMER_B, 16000);
        /*Enable Timer0B*/
        if (!flags_periodic [1])
        {
            flags_periodic [1] = 1 ;
            TimerEnable(TIMER0_BASE, TIMER_B);
        }
        break ;
    case TIMER1_A :
        G_u32NumberOfOverFlowsTimer1A = A_u32TimeInMill ;
        Timer1A_CallBack = fptr ;
        /*Enable Timer1A*/
        if (!flags_periodic [2])
        {
            flags_periodic [2] = 1 ;
            TimerEnable(TIMER1_BASE, TIMER_A);
        }
        break ;
    case TIMER1_B :
        G_u32NumberOfOverFlowsTimer1B = A_u32TimeInMill ;
        Timer1B_CallBack = fptr ;
        TimerLoadSet(TIMER1_BASE, TIMER_B, 16000);
        /*Enable Timer1B*/
        if (!flags_periodic [3])
        {
            flags_periodic [3] = 1 ;
            TimerEnable(TIMER1_BASE, TIMER_B);
        }
        break ;
    case TIMER2_A :
        G_u32NumberOfOverFlowsTimer2A = A_u32TimeInMill ;
        Timer3A_CallBack = fptr ;
        TimerLoadSet(TIMER2_BASE, TIMER_A, 16000);
        /*Enable Timer2A*/
        if (!flags_periodic [4])
        {
            flags_periodic [4] = 1 ;
            TimerEnable(TIMER2_BASE, TIMER_A);
        }
        break ;
    case TIMER2_B :
        G_u32NumberOfOverFlowsTimer2B = A_u32TimeInMill ;
        Timer2B_CallBack = fptr ;
        TimerLoadSet(TIMER2_BASE, TIMER_B, 16000);
        /*Enable Timer2B*/
        if (!flags_periodic [5])
        {
            flags_periodic [5] = 1 ;
            TimerEnable(TIMER2_BASE, TIMER_B);
        }
        break ;
    case TIMER3_A :
        G_u32NumberOfOverFlowsTimer3A = A_u32TimeInMill ;
        Timer3A_CallBack = fptr ;
        TimerLoadSet(TIMER3_BASE, TIMER_A, 16000);
        /*Enable Timer3A*/
        if (!flags_periodic [6])
        {
            flags_periodic [6] = 1 ;
            TimerEnable(TIMER3_BASE, TIMER_A);
        }
        break ;
    case TIMER3_B :
        G_u32NumberOfOverFlowsTimer3B = A_u32TimeInMill ;
        Timer3A_CallBack = fptr ;
        TimerLoadSet(TIMER3_BASE, TIMER_B, 16000);
        /*Enable Timer3B*/
        if (!flags_periodic [7])
        {
            flags_periodic [7] = 1 ;
            TimerEnable(TIMER3_BASE, TIMER_B);
        }
        break ;
    case WTIMER0_A :
        /*Enable Timer0A*/
        if (!flags_periodic [8])
        {
            flags_periodic [8] = 1 ;
            TimerEnable(WTIMER0_BASE, TIMER_A);
        }
        break ;
    case WTIMER0_B :
        /*Enable Timer0B*/
        if (!flags_periodic [9])
        {
            flags_periodic [9] = 1 ;
            TimerEnable(WTIMER0_BASE, TIMER_B);
        }
        break ;
    case WTIMER1_A :
        /*Enable Timer1A*/
        if (!flags_periodic [10])
        {
            flags_periodic [10] = 1 ;
            TimerEnable(WTIMER1_BASE, TIMER_A);
        }
        break ;
    case WTIMER1_B :
        /*Enable Timer1B*/
        if (!flags_periodic [11])
        {
            flags_periodic [11] = 1 ;
            TimerEnable(WTIMER1_BASE, TIMER_B);
        }
        break ;
    case WTIMER2_A :
        /*Enable Timer2A*/
        if (!flags_periodic [12])
        {
            flags_periodic [12] = 1 ;
            TimerEnable(WTIMER2_BASE, TIMER_A);
        }
        break ;
    case WTIMER2_B :
        /*Enable Timer2B*/
        if (!flags_periodic [13])
        {
            flags_periodic [13] = 1 ;
            TimerEnable(WTIMER2_BASE, TIMER_B);
        }
        break ;
    case WTIMER3_A :
        /*Enable Timer3A*/
        if (!flags_periodic [14])
        {
            flags_periodic [14] = 1 ;
            TimerEnable(WTIMER3_BASE, TIMER_A);
        }
        break ;
    case WTIMER3_B :
        /*Enable Timer3B*/
        if (!flags_periodic [15])
        {
            flags_periodic [15] = 1 ;
            TimerEnable(WTIMER3_BASE, TIMER_B);
        }
        break ;
    case WTIMER4_A :
        /*Enable Timer4A*/
        if (!flags_periodic [16])
        {
            flags_periodic [10] = 1 ;
            TimerEnable(WTIMER4_BASE, TIMER_A);
        }
        break ;
    case WTIMER4_B :
        /*Enable Timer4B*/
        if (!flags_periodic [17])
        {
            flags_periodic [17] = 1 ;
            TimerEnable(WTIMER4_BASE, TIMER_B);
        }
        break ;
    case WTIMER5_A :
        /*Enable Timer5A*/
        if (!flags_periodic [18])
        {
            flags_periodic [18] = 1 ;
            TimerEnable(WTIMER5_BASE, TIMER_A);
        }
        break ;
    case WTIMER5_B :
        /*Enable Timer5B*/
        if (!flags_periodic [19])
        {
            flags_periodic [19] = 1 ;
            TimerEnable(WTIMER5_BASE, TIMER_B);
        }
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void Timer0AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer0A == L_u32Counter)
    {
        Timer0A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer0BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer0B == L_u32Counter)
    {
        Timer0B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer1AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer1A == L_u32Counter)
    {
        Timer1A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer1BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER1_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer1B == L_u32Counter)
    {
        Timer1B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer2AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer2A == L_u32Counter)
    {
        Timer2A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer2BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer2B == L_u32Counter)
    {
        Timer2B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer3AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER3_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer3A == L_u32Counter)
    {
        Timer3A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void Timer3BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(TIMER3_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsTimer3B == L_u32Counter)
    {
        Timer3B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer0AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER0_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer0A == L_u32Counter)
    {
        WTimer0A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer0BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER0_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer0B == L_u32Counter)
    {
        WTimer0B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer1AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER1_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer1A == L_u32Counter)
    {
        WTimer1A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer1BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER1_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer1B == L_u32Counter)
    {
        WTimer1B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer2AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER2_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer2A == L_u32Counter)
    {
        WTimer2A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer2BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER2_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer2B == L_u32Counter)
    {
        WTimer2B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer3AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER3_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer3A == L_u32Counter)
    {
        WTimer3A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer3BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER3_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer3B == L_u32Counter)
    {
        WTimer3B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer4AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER4_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer4A == L_u32Counter)
    {
        WTimer4A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer4BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER4_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer4B == L_u32Counter)
    {
        WTimer4B_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer5AIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER5_BASE, TIMER_TIMA_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer5A == L_u32Counter)
    {
        WTimer5A_CallBack () ;
        L_u32Counter = 0 ;
    }
}

void WTimer5BIntHandler(void)
{
    static int L_u32Counter = 0 ;
    /*clear interrupt flag*/
    TimerIntClear(WTIMER5_BASE, TIMER_TIMB_TIMEOUT);
    L_u32Counter ++ ;
    if (G_u32NumberOfOverFlowsWTimer5B == L_u32Counter)
    {
        WTimer5B_CallBack () ;
        L_u32Counter = 0 ;
    }
}
