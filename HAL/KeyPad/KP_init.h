/*
 * KP_init.h
 *
 *  Created on: Sep 15, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_KEYPAD_KP_INIT_H_
#define HAL_KEYPAD_KP_INIT_H_

static const uint8_t G_u8SwitchVal[4][4] =
{
    {
        '1', /* Row 0 Column 0 */
        '4', /* Row 1 Column 0 */
        '7', /* Row 2 Column 0 */
        'D'  /* Row 3 Column 0 */
    },
    {
        '2', /* Row 0 Column 1 */
        '5', /* Row 1 Column 1 */
        '8', /* Row 2 Column 1 */
        '0'  /* Row 4 Column 1 */
    },
    {
        '3', /* Row 0 Column 2 */
        '6', /* Row 1 Column 2 */
        '9', /* Row 2 Column 2 */
        '='  /* Row 3 Column 2 */
    },
    {
        '+', /* Row 0 Column 3 */
        '-', /* Row 1 Column 3 */
        '*', /* Row 2 Column 3 */
        '/'  /* Row 3 Column 3 */
    }
};

typedef struct
{
    uint8_t PORT ;
    uint8_t PIN ;
}Data_conf_t;
typedef struct
{
    Data_conf_t COL [4] ;
    Data_conf_t ROW [4] ;
}KP_conf_t;

/*
    Function Name        : HKP_voidKpInit
    Function Returns     : KP_conf_t *KP_Connections
    Function Arguments   : KP_conf_t *KP_Connections
    Function Description : Initialize the Rows & columns of keypad
*/
void HKP_voidKpInit (KP_conf_t *KP_Connections) ;

/*
    Function Name        : HKP_u8GetPressedKey
    Function Returns     : uint8_t
    Function Arguments   : KP_conf_t *KP_Connections
    Function Description : read the value of pressed  key
*/
uint8_t HKP_u8GetPressedKey (KP_conf_t *KP_Connections) ;

#endif /* HAL_KEYPAD_KP_INIT_H_ */
