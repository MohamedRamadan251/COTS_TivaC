/*
 * LCD_prog.c
 *
 *  Created on: Aug 20, 2023
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

#include "LCD_init.h"
#include "LCD_private.h"

/**
    Function Name        : HLCD_voidSendComm (A_xLCDConf , &A_xLCDConf ,
    Function Returns     : void
    Function Arguments   : uint8_t A_uint8_tCmdID
    Function Description : send command to lcd
*/
void HLCD_voidSendComm (LCD_conf_t *A_xLCDConf , uint8_t A_uint8_tCommmand) ;

void HLCD_voidSendComm (LCD_conf_t *A_xLCDConf , uint8_t A_uint8_tCommmand)
{
    if (A_xLCDConf->ConnectionMode == EIGHT_BIT_MODE)
    {
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 0) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send cmd to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D0.PORT, A_xLCDConf->D0.PIN , ((A_uint8_tCommmand & (1<<0))>>0)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D1.PORT, A_xLCDConf->D1.PIN , ((A_uint8_tCommmand & (1<<1))>>1)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D2.PORT, A_xLCDConf->D2.PIN , ((A_uint8_tCommmand & (1<<2))>>2)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D3.PORT, A_xLCDConf->D3.PIN , ((A_uint8_tCommmand & (1<<3))>>3)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tCommmand & (1<<4))>>4)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tCommmand & (1<<5))>>5)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tCommmand & (1<<6))>>6)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tCommmand & (1<<7))>>7)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
    }
    else if (A_xLCDConf->ConnectionMode == FOUR_BIT_MODE)
    {
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 0) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send comm to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tCommmand & (1<<4))>>4)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tCommmand & (1<<5))>>5)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tCommmand & (1<<6))>>6)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tCommmand & (1<<7))>>7)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 0) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send comm to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tCommmand & (1<<0))>>0)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tCommmand & (1<<1))>>1)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tCommmand & (1<<2))>>2)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tCommmand & (1<<3))>>3)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
    }
    else
    {
        /*Error statement*/
    }
}

void HLCD_voidDisplayChar (LCD_conf_t *A_xLCDConf , uint8_t A_uint8_tChar)
{
    if (A_xLCDConf->ConnectionMode == EIGHT_BIT_MODE)
    {
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 1) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send char to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D0.PORT, A_xLCDConf->D0.PIN , ((A_uint8_tChar & (1<<0))>>0)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D1.PORT, A_xLCDConf->D1.PIN , ((A_uint8_tChar & (1<<1))>>1)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D2.PORT, A_xLCDConf->D2.PIN , ((A_uint8_tChar & (1<<2))>>2)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D3.PORT, A_xLCDConf->D3.PIN , ((A_uint8_tChar & (1<<3))>>3)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tChar & (1<<4))>>4)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tChar & (1<<5))>>5)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tChar & (1<<6))>>6)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tChar & (1<<7))>>7)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
    }
    else if (A_xLCDConf->ConnectionMode == FOUR_BIT_MODE)
    {
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 1) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send char to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tChar & (1<<4))>>4)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tChar & (1<<5))>>5)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tChar & (1<<6))>>6)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tChar & (1<<7))>>7)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
        /**set register select to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN , 1) ;
        /**set read/write to low */
        MGPIO_voidSetPinValue (A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN , 0) ;
        /**send char to control register */
        MGPIO_voidSetPinValue (A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN , ((A_uint8_tChar & (1<<0))>>0)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN , ((A_uint8_tChar & (1<<1))>>1)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN , ((A_uint8_tChar & (1<<2))>>2)) ;
        MGPIO_voidSetPinValue (A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN , ((A_uint8_tChar & (1<<3))>>3)) ;
        /**set enable to high */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 1) ;
        /* Wait for E to settle */
        MSTK_voidSetBusyWait (2);
        /**set enable to low */
        MGPIO_voidSetPinValue  (A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN , 0) ;
        MSTK_voidSetBusyWait (2);
    }
    else
    {
        /*Error statement*/
    }
}

void HLCD_voidInit(LCD_conf_t *A_xLCDConf)
{
    MSTK_voidInit() ; /*initialization systick timer*/
    MSTK_voidSetBusyWait (50); /* Wait for more than 30ms after VDD rise to 4.5v */
    if (A_xLCDConf->ConnectionMode == EIGHT_BIT_MODE)
    {
        /** set direction of PINS to be output */
        MGPIO_voidInit(A_xLCDConf->D0.PORT, A_xLCDConf->D0.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D1.PORT, A_xLCDConf->D1.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D2.PORT, A_xLCDConf->D2.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D3.PORT, A_xLCDConf->D3.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN, GPIO_OUTPUT) ;

        MGPIO_voidInit(A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN, GPIO_OUTPUT) ;

        /** function set */
        HLCD_voidSendComm (A_xLCDConf , EIGHT_BIT_CONNECTION) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (2) ;
        /** Display ON/OFF Control */
        HLCD_voidSendComm (A_xLCDConf , CMD_CURSOR_On_DISPLAY_ON) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (2) ;
        /** Display Clear */
        HLCD_voidSendComm (A_xLCDConf , CMD_CLEAR) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (10) ;
        /** Entry mode set */
        HLCD_voidSendComm (A_xLCDConf , CMD_ENTRY_MODE) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (10) ;
    }
    else if (A_xLCDConf->ConnectionMode == FOUR_BIT_MODE)
    {
        /** set direction of PINS to be output */
        MGPIO_voidInit(A_xLCDConf->D4.PORT, A_xLCDConf->D4.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D5.PORT, A_xLCDConf->D5.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D6.PORT, A_xLCDConf->D6.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->D7.PORT, A_xLCDConf->D7.PIN, GPIO_OUTPUT) ;

        MGPIO_voidInit(A_xLCDConf->RS.PORT, A_xLCDConf->RS.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->RW.PORT, A_xLCDConf->RW.PIN, GPIO_OUTPUT) ;
        MGPIO_voidInit(A_xLCDConf->EN.PORT, A_xLCDConf->EN.PIN, GPIO_OUTPUT) ;

        /** Return home*/
        HLCD_voidSendComm (A_xLCDConf , CMD_RETURN_HOME) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (10) ;
        /** function set */
        HLCD_voidSendComm (A_xLCDConf , FOUR_BIT_CONNECTION) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (1) ;
        /** Display ON/OFF Control */
        HLCD_voidSendComm (A_xLCDConf , CMD_CURSOR_OFF_DISPLAY_ON) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (1) ;
        /** Display Clear */
        HLCD_voidSendComm (A_xLCDConf , CMD_CLEAR) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (10) ;
        /** Entry mode set */
        HLCD_voidSendComm (A_xLCDConf , CMD_ENTRY_MODE) ;
        /* Wait for command to settle */
        MSTK_voidSetBusyWait (1) ;
    }
    else
    {
        /*Error statement*/
    }
}

void HLCD_voidDispStr(LCD_conf_t *A_xLCDConf , uint8_t* A_Puint8_tString)
{
    /**Local loop index */
    uint8_t L_uint8_tIndex = 0 ;
    while (A_Puint8_tString [L_uint8_tIndex] != '\0')
    {
        /* Write Character on LCD */
        HLCD_voidDisplayChar (A_xLCDConf , A_Puint8_tString [L_uint8_tIndex]) ;

        /* Increment local loop index */
        L_uint8_tIndex ++ ;
    }
}

void HLCD_voidDispIntNum(LCD_conf_t *A_xLCDConf , uint32_t A_uint32_tNumber)
{
    if (A_uint32_tNumber < (uint32_t)MIN_INT_NUM && A_uint32_tNumber > (uint32_t)MAX_INT_NUM)
    {
        /**
         * if the integer is more than MAX_INT_NUM or less than MIN_INT_NUM
                  **** "Overflow !!!!" will be displayed
         */
        HLCD_voidClrScreen (A_xLCDConf) ;
        HLCD_voidDispStr (A_xLCDConf , (uint8_t*)"Overflow !!!!") ;
    }
    else
    {
        /**array to stored conversion character*/
        int8_t L_Pint8_tString [16] = {0} ;

        /** convert integer to string*/
        ltoa ((long int)A_uint32_tNumber , (char*)L_Pint8_tString) ;
        /**display number after convesion*/
        HLCD_voidDispStr (A_xLCDConf , (uint8_t*)L_Pint8_tString) ;
    }
}

void HLCD_voidDispFloatNum(LCD_conf_t *A_xLCDConf , float A_floatNumber , uint8_t A_uint8_tAfterDigit)
{
    uint16_t L_uint16_tAfterDigit = 1 ;
    uint8_t  L_uint8_tIterator = 0 ;
    /** display integer part */
    HLCD_voidDispIntNum (A_xLCDConf , (uint32_t)A_floatNumber) ;

    /** display dot */
    HLCD_voidDisplayChar(A_xLCDConf,',') ;

    for (L_uint8_tIterator = 0 ; L_uint8_tIterator < A_uint8_tAfterDigit ; L_uint8_tIterator ++)
    {
        L_uint16_tAfterDigit = L_uint16_tAfterDigit * BASE ;
    }

    /** display fraction part */
    HLCD_voidDispIntNum (A_xLCDConf , (A_floatNumber - (uint32_t) A_floatNumber) * L_uint16_tAfterDigit) ;
}

void HLCD_voidClrScreen (LCD_conf_t *A_xLCDConf)
{
    /**clear data and move cursor to first position*/
    HLCD_voidSendComm (A_xLCDConf , CMD_CLEAR) ;
}

void HLCD_voidShiftDisplayRight(LCD_conf_t *A_xLCDConf)
{
    /**shift display to right*/
    HLCD_voidSendComm (A_xLCDConf , SHIFT_DISPLAY_TO_RIGHT) ;
}

void HLCD_voidShiftDisplayLeft(LCD_conf_t *A_xLCDConf)
{
    /**shift display to left*/
    HLCD_voidSendComm (A_xLCDConf , SHIFT_DISPLAY_TO_LEFT) ;
}

void HLCD_voidMovCursor(LCD_conf_t *A_xLCDConf , uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId)
{
    /**local variable to stored DDRAM address*/
    uint8_t L_uint8_tDDRAMAddress ;

    /**if the row and col are out of range
             *** Do nothing
      */
    if (A_uint8_tRowId >= MIN_NUM_OF_ROW && A_uint8_tRowId <= MAX_NUM_OF_ROW &&
    A_uint8_tColId >= MIN_NUM_OF_COL && A_uint8_tColId <= MAX_NUM_OF_COL)
    {
        /**for first row*/
        if (A_uint8_tRowId == LCD_ROW1)
        {
            L_uint8_tDDRAMAddress = FIRST_ROW_ADDRESS + A_uint8_tColId - 1 ;
            /**set DDRAM address*/
            HLCD_voidSendComm (A_xLCDConf , L_uint8_tDDRAMAddress) ;
        }

        /**for second row*/
        else if (A_uint8_tRowId == LCD_ROW2)
        {
            L_uint8_tDDRAMAddress = SECOND_ROW_ADDRESS + A_uint8_tColId - 1 ;
            /**set DDRAM address*/
            HLCD_voidSendComm (A_xLCDConf , L_uint8_tDDRAMAddress) ;
        }
    }
    else
    {
        /** DO Nothing */
    }
}

void HLCD_voidDispSpecialChar(LCD_conf_t *A_xLCDConf , uint8_t * A_uint8_tArray, uint8_t A_uint8_tBlock, uint8_t A_uint8_tRowId, uint8_t A_uint8_tColId)
{
    /**iterator for for loop*/
    uint8_t L_uint8_tIterator ;

    /**set CGRAM address (001x xxxx) */
    HLCD_voidSendComm (A_xLCDConf , (A_uint8_tBlock * NUMBER_OF_BLOCKS_OF_CGRAM) | SET_CGRAM_ADDRESS) ;

    /** Send the array to be stored */
    for (L_uint8_tIterator =  FIRST_INDEX_OF_EACH_BLOCK ;
         L_uint8_tIterator <= END_INDEX_OF_EACH_BLOCK   ;
         L_uint8_tIterator ++ )
         {
             HLCD_voidDisplayChar (A_xLCDConf , A_uint8_tArray [L_uint8_tIterator]) ;
         }

    /* Move the cursor to required position */
    HLCD_voidMovCursor (A_xLCDConf , A_uint8_tRowId , A_uint8_tColId) ;

    /* Set the block to be displayed */
    HLCD_voidDisplayChar (A_xLCDConf , A_uint8_tBlock) ;
}
