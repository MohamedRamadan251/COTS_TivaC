/*
 * RTOS_private.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_

typedef enum
{
	Suspende ,
	RunSTate
}RunState;

typedef struct
{
	void   (*TaskHandler)(void) ;
	uint32_t      periodicity        ;
	uint32_t      FirstDelay         ;
	RunState TaskRunState       ;
}Task;




#endif /* RTOS_RTOS_PRIVATE_H_ */
