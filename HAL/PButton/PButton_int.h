/*
 * PButton_int.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_PBUTTON_PBUTTON_INT_H_
#define HAL_PBUTTON_PBUTTON_INT_H_

typedef struct
{
    uint32_t PORT ;
    uint32_t PIN ;
}PB_CONF_T;

#define NOT_PRESSED   1
#define PRESSED       0
/*
    Function Name        : HPB_voidPBInitial
    Function Returns     : void
    Function Arguments   : PB_CONF_T* A_xPB_ID
    Function Description : Define the PB as OUTPUT
*/
void HPB_voidPBInitial (PB_CONF_T* A_xPB_ID) ;

/*
    Function Name        : HPB_voidPBOn
    Function Returns     : void
    Function Arguments   : PB_CONF_T* A_xPB_ID
    Function Description : Turn on PB
*/
uint32_t HPB_uint32_tPBGetStatues (PB_CONF_T* A_xPB_ID) ;




#endif /* HAL_PBUTTON_PBUTTON_INT_H_ */
