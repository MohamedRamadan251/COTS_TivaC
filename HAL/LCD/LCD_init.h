/*
 * LCD_init.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

/**for 16x2 LCD ===> the number of rows = 2*/
#define MAX_NUM_OF_ROW    2
#define MIN_NUM_OF_ROW    1

/**for 16x2 LCD ===> the number of columns = 16*/
#define MAX_NUM_OF_COL    16
#define MIN_NUM_OF_COL    1

/**Define IDs of rows*/
#define  LCD_ROW1         1
#define  LCD_ROW2         2

/**Define IDs of columns*/
#define  LCD_COL1         1
#define  LCD_COL2         2
#define  LCD_COL3         3
#define  LCD_COL4         4
#define  LCD_COL5         5
#define  LCD_COL6         6
#define  LCD_COL7         7
#define  LCD_COL8         8
#define  LCD_COL9         9
#define  LCD_COL10        10
#define  LCD_COL11        11
#define  LCD_COL13        13
#define  LCD_COL14        14
#define  LCD_COL15        15
#define  LCD_COL16        16

/*Define Connection Mode*/
#define FOUR_BIT_MODE     4
#define EIGHT_BIT_MODE    8


typedef struct
{
    uint8_t PORT ;
    uint8_t PIN ;
}Data_conf_t;
typedef struct
{
    uint8_t ConnectionMode ;
    Data_conf_t RS         ;
    Data_conf_t EN         ;
    Data_conf_t RW         ;
    Data_conf_t D0         ;
    Data_conf_t D1         ;
    Data_conf_t D2         ;
    Data_conf_t D3         ;
    Data_conf_t D4         ;
    Data_conf_t D5         ;
    Data_conf_t D6         ;
    Data_conf_t D7         ;
}LCD_conf_t;
/*
    Function Name        : HLCD_voidInit
    Function Returns     : void
    Function Arguments   : LCD_conf_t *A_xLCDConf
    Function Description : initialize LCD
*/
void HLCD_voidInit(LCD_conf_t *A_xLCDConf);

/*
    Function Name        : HLCD_voidDisplayChar
    Function Returns     : void
    Function Arguments   : A_uint8_tChar
    Function Description : display character
*/
void HLCD_voidDisplayChar (LCD_conf_t *A_xLCDConf , uint8_t A_u8Char) ;

/*
    Function Name        : HLCD_voidDispStr
    Function Returns     : void
    Function Arguments   : uint8_t A_Puint8_tString
    Function Description : display string
*/
void HLCD_voidDispStr(LCD_conf_t *A_xLCDConf , uint8_t* A_Puint8_tString);

/*
    Function Name        : HLCD_voidDispIntNum
    Function Returns     : void
    Function Arguments   : uint8_t A_uint32_tNumber
    Function Description : display integer number
*/
void HLCD_voidDispIntNum(LCD_conf_t *A_xLCDConf , uint32_t A_uint32_tNumber);

/*
    Function Name        : HLCD_voidDispFloatNum
    Function Returns     : void
    Function Arguments   : float A_f32Number , uint8_t A_uint8_tAfterDigit
    Function Description : display floating number
*/
void HLCD_voidDispFloatNum(LCD_conf_t *A_xLCDConf , float A_f32Number , uint8_t A_uint8_tAfterDigit);

/*
    Function Name        : HLCD_voidClrScreen
    Function Returns     : void
    Function Arguments   : void
    Function Description : clear screan and move cursor to row = 1 , col = 1
*/
void HLCD_voidClrScreen(LCD_conf_t *A_xLCDConf);

/*
    Function Name        : HLCD_voidShiftDisplayRight
    Function Returns     : void
    Function Arguments   : void
    Function Description : shift display to right
*/
void HLCD_voidShiftDisplayRight(LCD_conf_t *A_xLCDConf);

/*
    Function Name        : HLCD_voidShiftDisplayLeft
    Function Returns     : void
    Function Arguments   : void
    Function Description : shift display to left
*/
void HLCD_voidShiftDisplayLeft(LCD_conf_t *A_xLCDConf);

/*
    Function Name        : HLCD_voidoidMovCursor
    Function Returns     : void
    Function Arguments   : uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId
    Function Description : move the cursor to posetion (row , col)
*/
void HLCD_voidMovCursor(LCD_conf_t *A_xLCDConf , uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId);

/*
    Function Name        : HLCD_voidDispSpecialChar
    Function Returns     : void
    Function Arguments   : uint8_t * A_uint8_tArray, uint8_t A_uint8_tBlock, uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId
    Function Description : display special character like Arabic letter
*/
void HLCD_voidDispSpecialChar(LCD_conf_t *A_xLCDConf ,  uint8_t * A_uint8_tArray, uint8_t A_uint8_tBlock, uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId);




#endif /* HAL_LCD_LCD_INIT_H_ */
