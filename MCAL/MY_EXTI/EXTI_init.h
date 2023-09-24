/*
 * EXTI_init.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_MY_EXTI_EXTI_INIT_H_
#define MCAL_MY_EXTI_EXTI_INIT_H_

/*defines lines of EXTI*/
#define EXTI_LINE_0    GPIO_INT_PIN_0
#define EXTI_LINE_1    GPIO_INT_PIN_1
#define EXTI_LINE_2    GPIO_INT_PIN_2
#define EXTI_LINE_3    GPIO_INT_PIN_3
#define EXTI_LINE_4    GPIO_INT_PIN_4
#define EXTI_LINE_5    GPIO_INT_PIN_5
#define EXTI_LINE_6    GPIO_INT_PIN_6
#define EXTI_LINE_7    GPIO_INT_PIN_7

/*define triggering*/
#define EXTI_RISING     GPIO_RISING_EDGE   /*Interrupt on falling edge*/
#define EXTI_FALING     GPIO_FALLING_EDGE  /*Interrupt on rising edge */
#define EXTI_ON_CHANGE  GPIO_BOTH_EDGES    /*Interrupt on both edges  */
#define EXTI_LOW_LEVEL  GPIO_LOW_LEVEL     /*Interrupt on low level   */
#define EXTI_HIGH_LEVEL GPIO_HIGH_LEVEL    /*Interrupt on high level  */

void MEXTI_voidInit (uint32_t A_uint32_tPortId , uint32_t A_uint32_tLineNum , uint32_t A_uint32_tInputPull) ;

void MEXTI_voidSetCallBack (uint32_t A_uint32_tLineNum , void (*A_fptr)(void));

#endif /* MCAL_MY_EXTI_EXTI_INIT_H_ */
