/*
 * UART_ocnf.c
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


UART_InitType UART_0 =
{
 .UART_type     = UART0_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_1 =
{
 .UART_type     = UART1_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_2 =
{
 .UART_type     = UART2_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_3 =
{
 .UART_type     = UART3_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_4 =
{
 .UART_type     = UART4_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_5 =
{
 .UART_type     = UART5_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};

UART_InitType UART_7 =
{
 .UART_type     = UART7_BASE          ,
 .BaudRate      = 38400               ,
 .DataWidth     = UART_CONFIG_WLEN_8  ,
 .StopBits      = UART_CONFIG_STOP_ONE,
 .Parity_Enable = UART_CONFIG_PAR_NONE
};
