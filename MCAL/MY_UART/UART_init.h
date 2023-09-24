/*
 * UART_init.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_MY_UART_UART_INIT_H_
#define MCAL_MY_UART_UART_INIT_H_
typedef struct
{
    uint32_t UART_type           ;
    uint32_t BaudRate            ;
    uint8_t  DataWidth           ;
    uint8_t  StopBits            ;
    uint8_t  Parity_Enable       ;
}UART_InitType;

void MUART_voidInit (UART_InitType * A_xUARTType) ;

void MUART_voidSendData (UART_InitType * A_xUARTType , uint8_t A_u8Data) ;

void MUART_voidSendString (UART_InitType * A_xUARTType , uint8_t* A_u8String) ;

uint32_t MUART_u32ReciveData  (UART_InitType * A_xUARTType) ;

void MUART_voidReciveString (UART_InitType * A_xUARTType  , uint8_t arr []) ;
#endif /* MCAL_MY_UART_UART_INIT_H_ */
