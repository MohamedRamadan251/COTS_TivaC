/*
 * Systic_init.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_MY_SYSTICK_SYSTIC_INIT_H_
#define MCAL_MY_SYSTICK_SYSTIC_INIT_H_

/**
    Function Name        : MSTK_voidInit
    Function Returns     : void
    Function Arguments   : void
    Function Description : initial the clock source of systick
*/
void MSTK_voidInit (void) ;

/**
    Function Name        : MSTK_voidSetBusyWait
    Function Returns     : void
    Function Arguments   : uint32_t A_uint32_tTimeInMill
    Function Description : delay with selected time
*/
void MSTK_voidSetBusyWait (uint32_t A_uint32_tTimeInMill) ;

/**
    Function Name        : MSTK_voidSetIntervalSingle
    Function Returns     : void
    Function Arguments   : uint32_t A_uint32_tTimeInMill , void (*fptr)(void)
    Function Description : go to handler single time
*/
void MSTK_voidSetIntervalSingle (uint32_t A_uint32_tTimeInMill , void (*fptr)(void)) ;

/**
    Function Name        : MSTK_voidSetIntervalPeriodic
    Function Returns     : void
    Function Arguments   : uint32_t A_uint32_tTimeInMill , void (*fptr)(void)
    Function Description : go to handler previous time
*/
void MSTK_voidSetIntervalPeriodic (uint32_t A_uint32_tTimeInMill , void (*fptr)(void)) ;




#endif /* MCAL_MY_SYSTICK_SYSTIC_INIT_H_ */
