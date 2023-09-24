/*
 * Systic_prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

/*pointer to function to set call back of sys tick*/
static void (*G_u32SysTickSetCallBack)(void) ;
/*flag to differ from single interval and periodic interval*/
static uint8_t GS_u8SingleFlag = 0;
/*store number of over flows from 2^24 to 0*/
static uint32_t GS_u32FullOverFlowCounts ;
/*store again number of over flows from 2^24 to 0*/
static uint32_t GS_u32ResumeFullOverFlowCounts ;
/*store number of counts from value to 0*/
static uint32_t GS_u32PartOverFlowCounts ;

void MSTK_voidInit (void)
{
    SysTickDisable () ;
    SysTickIntEnable () ;
}

void MSTK_voidSetBusyWait (uint32_t A_uint32_tTimeInMill)
{
    uint32_t L_uint32_tTicksNumbers = A_uint32_tTimeInMill * 16000U ;
    while (L_uint32_tTicksNumbers != 0)
    {
        if (L_uint32_tTicksNumbers > 16777215)
        {
            SysTickPeriodSet (16777215) ;
            SysTickEnable () ;
            while ((((*((volatile uint32_t *)(0xE000E010))) & (1<<16))>>16) == 0) ;
            SysTickDisable () ;
            L_uint32_tTicksNumbers -= 16777215 ;
        }
        else
        {
            SysTickPeriodSet (L_uint32_tTicksNumbers) ;
            SysTickEnable () ;
            while ((((*((volatile uint32_t *)(0xE000E010))) & (1<<16))>>16) == 0) ;
            SysTickDisable () ;
            L_uint32_tTicksNumbers = 0 ;
        }
    }
}

void MSTK_voidSetIntervalSingle (uint32_t A_uint32_tTimeInMill , void (*fptr)(void))
{
    /*set call back*/
    G_u32SysTickSetCallBack = fptr ;

    /*set single flag for single interval*/
    GS_u8SingleFlag = 1 ;

    uint32_t L_uint32_tTicksNumbers = A_uint32_tTimeInMill * 16000U ;

    GS_u32FullOverFlowCounts       = ( L_uint32_tTicksNumbers / 16777215 ) + 1;
    GS_u32PartOverFlowCounts       = L_uint32_tTicksNumbers % 16777215 ;
    GS_u32ResumeFullOverFlowCounts = GS_u32FullOverFlowCounts ;

    /*load timer with value*/
    if (GS_u32FullOverFlowCounts > 1)
    {
        SysTickPeriodSet (16777215) ;
    }
    else
    {
        GS_u32FullOverFlowCounts = 0 ;
        SysTickPeriodSet (L_uint32_tTicksNumbers) ;
    }
    /*start the timer*/
    SysTickEnable () ;
}

void MSTK_voidSetIntervalPeriodic (uint32_t A_uint32_tTimeInMill , void (*fptr)(void))
{
    /*set call back*/
    G_u32SysTickSetCallBack = fptr ;

    /*set single flag for single interval*/
    GS_u8SingleFlag = 0 ;

    uint32_t L_uint32_tTicksNumbers = A_uint32_tTimeInMill * 16000U ;

    GS_u32FullOverFlowCounts       = ( L_uint32_tTicksNumbers / 16777215 ) + 1;
    GS_u32PartOverFlowCounts       = L_uint32_tTicksNumbers % 16777215 ;
    GS_u32ResumeFullOverFlowCounts = GS_u32FullOverFlowCounts ;

    /*load timer with value*/
    if (GS_u32FullOverFlowCounts > 1)
    {
        SysTickPeriodSet (16777215) ;
    }
    else
    {
        GS_u32FullOverFlowCounts = 0 ;
        SysTickPeriodSet (L_uint32_tTicksNumbers) ;
    }
    /*start the timer*/
    SysTickEnable () ;
}

void SysTick_Handler (void)
{
    if (GS_u32FullOverFlowCounts > 1)
    {
        GS_u32FullOverFlowCounts -- ;
    }
    else if (GS_u32FullOverFlowCounts > 0 )
    {
        GS_u32FullOverFlowCounts -- ;
        /*load timer with value*/
        SysTickPeriodSet (GS_u32PartOverFlowCounts) ;
        /*start the timer*/
        SysTickEnable () ;
    }
    else
    {
        if (G_u32SysTickSetCallBack != 0)
        {
            GS_u32FullOverFlowCounts = GS_u32ResumeFullOverFlowCounts ;
            G_u32SysTickSetCallBack () ;
        }
        /*check for interrupt occures from single interval or periodic interval*/
        if (GS_u8SingleFlag)
        {
            /*clear flag*/
            GS_u8SingleFlag = 0 ;
            /*stop the timer*/
            SysTickDisable () ;
        }
    }
}
