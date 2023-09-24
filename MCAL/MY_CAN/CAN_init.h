/*
 * CAN_init.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_MY_CAN_CAN_INIT_H_
#define MCAL_MY_CAN_CAN_INIT_H_


void MCAN_voidInit (void) ;
void MCAN_voidInitRx (void) ;
void MCAN_voidTx (uint8_t A_u8DataSend) ;

uint8_t MCAN_voidRx (void) ;


#endif /* MCAL_MY_CAN_CAN_INIT_H_ */
