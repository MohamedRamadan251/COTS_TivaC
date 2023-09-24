/*
 * GPIO_init.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_GPIO_GPIO_INIT_H_
#define MCAL_GPIO_GPIO_INIT_H_
#include "driverlib/gpio.h"

/*define ports*/
#define GPIO_PORTA                  1
#define GPIO_PORTB                  2
#define GPIO_PORTC                  3
#define GPIO_PORTD                  4
#define GPIO_PORTE                  5
#define GPIO_PORTF                  6

/*define direction*/
#define GPIO_INPUT                  0
#define GPIO_OUTPUT                 1



/**
    Function Name        : MGPIO_voidInit
    Function Returns     : void
    Function Arguments   : MGPIO_Config_t * A_PstructPinConfig
    Function Description : initialize the  GPIO Peripheral
*/
void MGPIO_voidInit ( uint32_t A_uint32_tPort , uint32_t A_uint32_tPin , uint32_t A_uint32_tType) ;

void MGPIO_voidSetPinValue (uint32_t A_uint32_tPort , uint32_t A_uint32_tPin , uint32_t A_uint32_tValue) ;
uint32_t   MGPIO_uint32_tGetPinValue (uint32_t A_uint32_tPort , uint32_t A_uint32_tPin) ;
#endif /* MCAL_GPIO_GPIO_INIT_H_ */
