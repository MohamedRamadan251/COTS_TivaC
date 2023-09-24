/*
 * LED_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

typedef struct
{
    uint32_t PORT ;
    uint32_t PIN ;
}LED_CONF_T;
/*
	Function Name        : HLED_voidLedInitial
	Function Returns     : void
	Function Arguments   : LED_CONF_T* A_xLED_ID
	Function Description : Define the led as OUTPUT
*/
void HLED_voidLedInitial (LED_CONF_T* A_xLED_ID) ;

/*
	Function Name        : HLED_voidLedOn
	Function Returns     : void
	Function Arguments   : LED_CONF_T* A_xLED_ID
	Function Description : Turn on LED
*/
void HLED_voidLedOn (LED_CONF_T* A_xLED_ID) ;

/*
	Function Name        : HLED_voidLedOff
	Function Returns     : void
	Function Arguments   : LED_CONF_T* A_xLED_ID
	Function Description : Turn off LED
*/
void HLED_voidLedOff (LED_CONF_T* A_xLED_ID) ;

#endif /* HAL_LED_LED_INT_H_ */
