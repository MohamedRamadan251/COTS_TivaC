/*
 * KP_prog.c
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohammed Ramadan
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "../../MCAL/MY_GPIO/GPIO_init.h"
#include "../../MCAL/MY_Systick/Systic_init.h"

#include "KP_init.h"
#include "KP_private.h"


void HKP_voidKpInit (KP_conf_t *KP_Connections)
{
    /*initialize Systic Timer*/
    MSTK_voidInit() ;
    /* Set Columns as Output & High */
    MGPIO_voidInit(KP_Connections->COL[0].PORT, KP_Connections->COL[0].PIN, GPIO_OUTPUT) ;
    MGPIO_voidInit(KP_Connections->COL[1].PORT, KP_Connections->COL[1].PIN, GPIO_OUTPUT) ;
    MGPIO_voidInit(KP_Connections->COL[2].PORT, KP_Connections->COL[2].PIN, GPIO_OUTPUT) ;
    MGPIO_voidInit(KP_Connections->COL[3].PORT, KP_Connections->COL[3].PIN, GPIO_OUTPUT) ;

    MGPIO_voidSetPinValue(KP_Connections->COL[0].PORT, KP_Connections->COL[0].PIN, 1) ;
    MGPIO_voidSetPinValue(KP_Connections->COL[1].PORT, KP_Connections->COL[1].PIN, 1) ;
    MGPIO_voidSetPinValue(KP_Connections->COL[2].PORT, KP_Connections->COL[2].PIN, 1) ;
    MGPIO_voidSetPinValue(KP_Connections->COL[3].PORT, KP_Connections->COL[3].PIN, 1) ;

    /** Set Rows as Inputs */
    MGPIO_voidInit(KP_Connections->ROW[0].PORT, KP_Connections->ROW[0].PIN, GPIO_INPUT) ;
    MGPIO_voidInit(KP_Connections->ROW[1].PORT, KP_Connections->ROW[1].PIN, GPIO_INPUT) ;
    MGPIO_voidInit(KP_Connections->ROW[2].PORT, KP_Connections->ROW[2].PIN, GPIO_INPUT) ;
    MGPIO_voidInit(KP_Connections->ROW[3].PORT, KP_Connections->ROW[3].PIN, GPIO_INPUT) ;

    (void)MGPIO_uint32_tGetPinValue (KP_Connections->ROW[0].PORT, KP_Connections->ROW[0].PIN) ;
    (void)MGPIO_uint32_tGetPinValue (KP_Connections->ROW[1].PORT, KP_Connections->ROW[1].PIN) ;
    (void)MGPIO_uint32_tGetPinValue (KP_Connections->ROW[2].PORT, KP_Connections->ROW[2].PIN) ;
    (void)MGPIO_uint32_tGetPinValue (KP_Connections->ROW[3].PORT, KP_Connections->ROW[3].PIN) ;
}

uint8_t HKP_uint8_tGetPressedKey (KP_conf_t *KP_Connections)
{
    uint8_t L_u8IteratorCol = 0 ;
    uint8_t L_u8IteratorRow = 0 ;
    uint8_t L_u8PinVal             ;
    uint8_t L_u8PressedKey     = NOT_PRESSED;
    /**external loop to active current column that be checked */
    for (L_u8IteratorCol = 0 ; L_u8IteratorCol < 4 ; L_u8IteratorCol ++)
    {
        /**active current column by make it output low */
        MGPIO_voidSetPinValue(KP_Connections->COL [L_u8IteratorCol].PORT, KP_Connections->COL [L_u8IteratorCol].PIN, 0) ;
        /**internal loop to loop to each row
           and check pressed key that common current row and current column */
        for (L_u8IteratorRow = 0 ; L_u8IteratorCol < 4 ; L_u8IteratorCol ++)
        {
            /** read value of key that common current row and current column */
            MGPIO_uint32_tGetPinValue(KP_Connections->ROW [L_u8IteratorRow].PORT, KP_Connections->ROW [L_u8IteratorRow].PIN) ;
            /** if key is pressed ====> (MDIO_u8GetPinVal == 0) */
            if (L_u8PinVal == PRESSED)
            {
                /**get the value of the pressed key*/
                L_u8PressedKey = G_u8SwitchVal [L_u8IteratorCol][L_u8IteratorRow] ;
                /**wait untill leave the button */
                while (MGPIO_uint32_tGetPinValue (KP_Connections->ROW [L_u8IteratorRow].PORT, KP_Connections->ROW [L_u8IteratorRow].PIN == PRESSED)) ;

                /** wait 20 ms for debouncing */
                MSTK_voidSetBusyWait (DELAY_FOR_DRBOUNCING) ;
            }
        }
        /**deactive current column by make it output low */
        MGPIO_voidSetPinValue (KP_Connections->COL [L_u8IteratorCol].PORT, KP_Connections->COL [L_u8IteratorCol].PIN , 1) ;
    }
    return L_u8PressedKey ;
}
