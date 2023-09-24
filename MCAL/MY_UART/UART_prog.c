/*
 * UART_prog.c
 *
 *  Created on: Sep 7, 2023
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
#include "driverlib/uart.h"
#include "UART_init.h"

void MUART_voidInit (UART_InitType * A_xUARTType)
{
    switch (A_xUARTType ->UART_type)
    {
    case UART0_BASE:
                /*Enable UART0 Module*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
                /*enable GPIO PortA for UART0*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA) ;
                /*Configure the GPIO pin muxing for the UART function*/
                GPIOPinConfigure(GPIO_PA0_U0RX);
                GPIOPinConfigure(GPIO_PA1_U0TX);
                /*Since GPIO A0 and A1 are used for the UART function*/
                GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
                /*Initialize the UART0*/
                UARTConfigSetExpClk(UART0_BASE                 ,
                                    SysCtlClockGet()           ,
                                    A_xUARTType ->BaudRate     ,
                                   (A_xUARTType ->DataWidth    |
                                    A_xUARTType ->StopBits     |
                                    A_xUARTType ->Parity_Enable)
                                    );
                UARTEnable(UART0_BASE);
        break ;
    case UART1_BASE:
                /*Enable UART1 Module*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
                /*enable GPIO PortB for UART1*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB) ;
                /*Configure the GPIO pin muxing for the UART function*/
                GPIOPinConfigure(GPIO_PB0_U1RX);
                GPIOPinConfigure(GPIO_PB1_U1TX);
                /*Since GPIO B0 and B1 are used for the UART function*/
                GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
                /*Initialize the UART1*/
                UARTConfigSetExpClk(UART1_BASE                 ,
                                    SysCtlClockGet()           ,
                                    A_xUARTType ->BaudRate     ,
                                   (A_xUARTType ->DataWidth    |
                                    A_xUARTType ->StopBits     |
                                    A_xUARTType ->Parity_Enable)
                                    );
                UARTEnable(UART1_BASE);
        break ;
    case UART2_BASE:
                /*Enable UART2 Module*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
                /*enable GPIO PortD for UART2*/
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD) ;
                /*Configure the GPIO pin muxing for the UART function*/
                GPIOPinConfigure(GPIO_PD6_U2RX);
                GPIOPinConfigure(GPIO_PD7_U2TX);
                /*Since GPIO D6 and D7 are used for the UART function*/
                GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
                /*Initialize the UART2*/
                UARTConfigSetExpClk(UART2_BASE                 ,
                                    SysCtlClockGet()           ,
                                    A_xUARTType ->BaudRate     ,
                                   (A_xUARTType ->DataWidth    |
                                    A_xUARTType ->StopBits     |
                                    A_xUARTType ->Parity_Enable)
                                    );
                UARTEnable(UART2_BASE);
        break ;
    case UART3_BASE:
        /*Enable UART3 Module*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
        /*enable GPIO PortC for UART3*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC) ;
        /*Configure the GPIO pin muxing for the UART function*/
        GPIOPinConfigure(GPIO_PC6_U3RX);
        GPIOPinConfigure(GPIO_PC7_U3TX);
        /*Since GPIO C6 and C7 are used for the UART function*/
        GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
        /*Initialize the UART3*/
        UARTConfigSetExpClk(UART3_BASE                 ,
                            SysCtlClockGet()           ,
                            A_xUARTType ->BaudRate     ,
                           (A_xUARTType ->DataWidth    |
                            A_xUARTType ->StopBits     |
                            A_xUARTType ->Parity_Enable)
                            );
        UARTEnable(UART3_BASE);
        break ;
    case UART4_BASE:
        /*Enable UART4 Module*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART4);
        /*enable GPIO PortC for UART4*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC) ;
        /*Configure the GPIO pin muxing for the UART function*/
        GPIOPinConfigure(GPIO_PC4_U4RX);
        GPIOPinConfigure(GPIO_PC5_U4TX);
        /*Since GPIO C4 and C5 are used for the UART function*/
        GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        /*Initialize the UART4*/
        UARTConfigSetExpClk(UART4_BASE                 ,
                            SysCtlClockGet()           ,
                            A_xUARTType ->BaudRate     ,
                           (A_xUARTType ->DataWidth    |
                            A_xUARTType ->StopBits     |
                            A_xUARTType ->Parity_Enable)
                            );
        UARTEnable(UART4_BASE);
        break ;
    case UART5_BASE:
        /*Enable UART5 Module*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
        /*enable GPIO PortE for UART5*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE) ;
        /*Configure the GPIO pin muxing for the UART function*/
        GPIOPinConfigure(GPIO_PE4_U5RX);
        GPIOPinConfigure(GPIO_PE5_U5TX);
        /*Since GPIO E0 and E1 are used for the UART function*/
        GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_0);
        /*Initialize the UART5*/
        UARTConfigSetExpClk(UART5_BASE                 ,
                            SysCtlClockGet()           ,
                            A_xUARTType ->BaudRate     ,
                           (A_xUARTType ->DataWidth    |
                            A_xUARTType ->StopBits     |
                            A_xUARTType ->Parity_Enable)
                            );
        UARTEnable(UART5_BASE);
        break ;
    case UART7_BASE:
        /*Enable UART7 Module*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);
        /*enable GPIO PortE for UART7*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE) ;
        /*Configure the GPIO pin muxing for the UART function*/
        GPIOPinConfigure(GPIO_PE0_U7RX);
        GPIOPinConfigure(GPIO_PE1_U7TX);
        /*Since GPIO E0 and E1 are used for the UART function*/
        GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        /*Initialize the UART7*/
        UARTConfigSetExpClk(UART7_BASE                 ,
                            SysCtlClockGet()           ,
                            A_xUARTType ->BaudRate     ,
                           (A_xUARTType ->DataWidth    |
                            A_xUARTType ->StopBits     |
                            A_xUARTType ->Parity_Enable)
                            );
        UARTEnable(UART7_BASE);
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void MUART_voidSendData (UART_InitType * A_xUARTType , uint8_t A_u8Data)
{
    switch (A_xUARTType->UART_type)
    {
    case UART0_BASE :
        UARTCharPut(UART0_BASE , A_u8Data);
        break ;
    case UART1_BASE :
        UARTCharPut(UART1_BASE , A_u8Data);
        break ;
    case UART2_BASE :
        UARTCharPut(UART2_BASE , A_u8Data);
    break ;
    case UART3_BASE:
        UARTCharPut(UART3_BASE , A_u8Data);
        break ;
    case UART4_BASE:
        UARTCharPut(UART4_BASE , A_u8Data);
        break ;
    case UART5_BASE:
        UARTCharPut(UART5_BASE , A_u8Data);
        break ;
    case UART7_BASE:
        UARTCharPut(UART7_BASE , A_u8Data);
        break ;
    default :
        /*Error case*/
        break ;
    }
}

void MUART_voidSendString (UART_InitType * A_xUARTType , uint8_t* A_u8String)
{
    uint32_t L_u32Index = 0 ;
    switch (A_xUARTType->UART_type)
    {
    case UART0_BASE :
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART0_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART0_BASE , '\0');
        break ;
    case UART1_BASE :
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART1_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART1_BASE , '\0');
        break ;
    case UART2_BASE :
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART2_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART2_BASE , '\0');
        break ;
    case UART3_BASE:
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART3_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART3_BASE , '\0');
        break ;
    case UART4_BASE:
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART4_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART4_BASE , '\0');
        break ;
    case UART5_BASE:
        while (A_u8String [L_u32Index] != '\0')
        {
            UARTCharPut(UART5_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART5_BASE , '\0');
        break ;
    case UART7_BASE:
        while (A_u8String [L_u32Index++] != '\0')
        {
            UARTCharPut(UART7_BASE , A_u8String [L_u32Index]);
            L_u32Index ++ ;
        }
        UARTCharPut(UART7_BASE , '\0');
        break ;
    default :
        /*Error case*/
        break ;
    }
}

uint32_t MUART_u32ReciveData (UART_InitType * A_xUARTType)
{
    uint32_t L_u32DataRecived = 0 ;
    switch (A_xUARTType->UART_type)
    {
    case UART0_BASE :
        L_u32DataRecived = UARTCharGet(UART0_BASE);
        break ;
    case UART1_BASE :
        L_u32DataRecived = UARTCharGet(UART1_BASE);
        break ;
    case UART2_BASE :
        L_u32DataRecived = UARTCharGet(UART2_BASE);
    break ;
    case UART3_BASE:
        L_u32DataRecived = UARTCharGet(UART3_BASE);
        break ;
    case UART4_BASE:
        L_u32DataRecived = UARTCharGet(UART4_BASE);
        break ;
    case UART5_BASE:
        L_u32DataRecived = UARTCharGet(UART5_BASE);
        break ;
    case UART7_BASE:
        L_u32DataRecived = UARTCharGet(UART7_BASE);
        break ;
    default :
        /*Error case*/
        break ;
    }
    return L_u32DataRecived ;
}

void MUART_voidReciveString (UART_InitType * A_xUARTType , uint8_t A_u8StringRecived [])
{
    uint32_t L_u32Index = 0  ;
    uint32_t L_u32DataRecived = 0 ;
    switch (A_xUARTType->UART_type)
    {
    case UART0_BASE :
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART0_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART1_BASE :
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART1_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART2_BASE :
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART2_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART3_BASE:
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART3_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART4_BASE:
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART4_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART5_BASE:
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART5_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    case UART7_BASE:
        while (1)
        {
            L_u32DataRecived = UARTCharGet(UART7_BASE);
            if (L_u32DataRecived == '\0')
            {
                A_u8StringRecived [L_u32Index ++] = '\0' ;
                break ;
            }
            A_u8StringRecived [L_u32Index ++] = L_u32DataRecived ;
        }
        break ;
    default :
        /*Error case*/
        break ;
    }
}
