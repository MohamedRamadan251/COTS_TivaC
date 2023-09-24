/*
 * CAN_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_can.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "../MY_GPIO/GPIO_init.h"
#include "../MY_Systick/Systic_init.h"
#include "CAN_init.h"

tCANMsgObject sCANMessage_TX ;
tCANMsgObject sCANMessage_RX ;

/*
 A counter that keeps track of the number of times the TX interrupt has
 occurred, which should match the number of TX messages that were sent.
 */
volatile uint32_t g_ui32MsgCount = 0;
/*A flag to indicate that some transmission error occurred */
volatile bool g_bErrFlag = 0;
/*A flag for the interrupt handler to indicate that a message was received */
volatile bool g_bRXFlag = 0;

void MCAN_voidInit (void)
{
    MSTK_voidInit() ;
    /*Enable PortB for using can TX and RX pins*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    /*Configure the GPIO pin muxing to select CAN0 functions for these pins*/
    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);
    /*Enable the alternate function on the GPIO pins.  The above step selects */
    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    /*Enable CAN peripheral*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
    /*Initialize the CAN controller*/
    CANInit(CAN0_BASE);
    /*set up the baud rate to 500 kHZ*/
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
    /*Enable interrupts on the CAN peripheral*/
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
    /*Enable the CAN interrupt on the processor (NVIC) */
    IntEnable(INT_CAN0);
    /*Enable the CAN for operation */
    CANEnable(CAN0_BASE);
}

void MCAN_voidTx (uint8_t A_u8DataSend)
{
   sCANMessage_TX.ui32MsgID     = 1                       ;
   sCANMessage_TX.ui32MsgIDMask = 0                       ;
   sCANMessage_TX.ui32Flags     = MSG_OBJ_TX_INT_ENABLE   ;
   sCANMessage_TX.ui32MsgLen    = sizeof(A_u8DataSend)    ;
   sCANMessage_TX.pui8MsgData   = &A_u8DataSend           ;
   /*Send the CAN message */
   CANMessageSet(CAN0_BASE, 1, &sCANMessage_TX, MSG_OBJ_TYPE_TX);
   /*Delay cycles for 1 second */
   MSTK_voidSetBusyWait(1000);
}

void MCAN_voidInitRx (void)
{
    sCANMessage_RX.ui32MsgID     = 0   ;
    sCANMessage_RX.ui32MsgIDMask = 0   ;
    sCANMessage_RX.ui32Flags     = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER   ;
    sCANMessage_RX.ui32MsgLen    = 1   ;
    CANMessageSet(CAN0_BASE, 1, &sCANMessage_RX, MSG_OBJ_TYPE_RX);
}
uint8_t MCAN_voidRx (void)
{
    uint8_t L_u8RecivedData ;
    if (g_bRXFlag)
    {
        sCANMessage_RX.pui8MsgData   = &L_u8RecivedData ;
        /*Receive data*/
        CANMessageGet(CAN0_BASE, 1, &sCANMessage_RX, 0);
        g_bRXFlag = 0 ;
    }
    return L_u8RecivedData ;
}

void CANIntHandler(void)
{
    uint32_t ui32Status;
    /*Read the CAN interrupt status to find the cause of the interrupt */
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);
    /*If the cause is a controller status interrupt, then get the status */
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        /*
         *Read the controller status.  This will return a field of status
         *error bits that can indicate various errors
         */
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
        /* Set a flag to indicate some errors may have occurred */
        g_bErrFlag = 1;
    }
    /* Check if the cause is message object 1*/
    else if(ui32Status == 1)
    {
        /*
         * Getting to this point means that the TX interrupt occurred on
         * message object 1, and the message TX is complete.  Clear the
         * message object interrupt.
         */
        CANIntClear(CAN0_BASE, 1);
        /* Increment a counter to keep track of how many messages have been sent */
        g_ui32MsgCount++;

        if (sCANMessage_RX.ui32Flags == MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER )
        {
            /* Set flag to indicate received message is pending */
            g_bRXFlag = 1;
        }
        /*Since the message was sent, clear any error flags*/
        g_bErrFlag = 0;
    }
    else
    {
        /*do Nothing*/
    }
}
