/*
 * Timer_init.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_MY_TIMER_TIMER_INIT_H_
#define MCAL_MY_TIMER_TIMER_INIT_H_

#define TIMER0_A   1  /*PF0*/
#define TIMER0_B   2  /*PF1*/
#define TIMER1_A   3  /*PF2*/
#define TIMER1_B   4  /*PF3*/
#define TIMER2_A   5  /*PB0*/
#define TIMER2_B   6  /*PB1*/
#define TIMER3_A   7  /*PB2*/
#define TIMER3_B   8  /*PB3*/

/* Â‰« „ «Õ „⁄«Ì« «Œ“‰ ﬁÌ„Â ·Õœ 32 »  »” Â‰ﬂ ›Ì » 16 »  »” “Ì «·⁄«œÌ ⁄‘«‰ «· «Ì„— »Ì«Œœ Êﬁ  ⁄·Ì „« ÌÊ’· ··„«ﬂ”*/
#define WTIMER0_A  9  /*PC4*/
#define WTIMER0_B  10 /*PC5*/
#define WTIMER1_A  11 /*PC6*/
#define WTIMER1_B  12 /*PC7*/
#define WTIMER2_A  13 /*PD0*/
#define WTIMER2_B  14 /*PD1*/
#define WTIMER3_A  15 /*PD2*/
#define WTIMER3_B  16 /*PD3*/
#define WTIMER4_A  17 /*PD4*/
#define WTIMER4_B  18 /*PD5*/
#define WTIMER5_A  19 /*PD6*/
#define WTIMER5_B  20 /*PD7*/

void MTimer_voidTimerPwmInit (uint8_t A_u8TimerType) ;

void MTimer_voidSetPWM (uint8_t A_u8TimerType , uint32_t A_u32Value) ;

void MTimer_voidTimerPeriodicInit (uint8_t A_u8TimerType) ;

void MTimer_voidTimerPeriodicSetCallBack (uint8_t A_u8TimerType ,uint32_t A_u32TimeInMill , void (*fptr)(void)) ;
#endif /* MCAL_MY_TIMER_TIMER_INIT_H_ */
