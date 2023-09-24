/*
 * RTOS_init.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef RTOS_RTOS_INIT_H_
#define RTOS_RTOS_INIT_H_

/**
	Function Name        : RTOS_uint8_tCreatTask
	Function Returns     : uint8_t Error states
	                       *if L_uint8_tErrorState equal 0 : then the task has been ceriation
	                                                    and you in correct statte

	                       *if L_uint8_tErrorState equal 1 : error state
	                                                    wrong priority

	                       *if L_uint8_tErrorState equal 2 : error state
	                                                    the required periority is already reserved
	Function Arguments   : void (*Copy_TaskHandler)(void)
                           uint32_t     Copy_periodicity
                           uint32_t     Copy_priority
                           uint32_t     Copy_FirstDelay
	Function Description : cereate task into stack
*/
uint8_t RTOS_uint8_tCreatTask (void (*Copy_TaskHandler)(void),
		             uint32_t     Copy_periodicity        ,
		             uint32_t     Copy_priority           ,
					 uint32_t     Copy_FirstDelay       ) ;

/**
	Function Name        : RTOS_voidScheduler
	Function Returns     : void
	Function Arguments   : void
	Function Description : call task at certain time
*/
void RTOS_voidScheduler (void) ;

/**
	Function Name        : RTOS_uint8_tDeleteTask
	Function Returns     : uint8_t Error states
                           *if L_uint8_tErrorState equal 0 : then the task has been removed
	                                                    and you in correct statte

                           *if L_uint8_tErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : uint32_t Copy_periodicity
	Function Description : delete task from stack
*/
uint8_t RTOS_uint8_tDeleteTask (uint32_t Copy_priority) ;

/**
	Function Name        : RTOS_uint8_tResumeTask
	Function Returns     : uint8_t Error states
                           *if L_uint8_tErrorState equal 0 : then the task has been resummed
	                                                    and you in correct statte

                           *if L_uint8_tErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : uint32_t Copy_periodicity
	Function Description : resume task
*/
uint8_t RTOS_uint8_tResumeTask (uint32_t Copy_priority) ;

/**
	Function Name        : RTOS_uint8_tSuspendTask
	Function Returns     : uint8_t Error states
                           *if L_uint8_tErrorState equal 0 : then the task has been suspended
	                                                    and you in correct statte

                           *if L_uint8_tErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : uint32_t Copy_periodicity
	Function Description : suspend task
*/
uint8_t RTOS_uint8_tSuspendTask (uint32_t Copy_priority) ;

/**
	Function Name        : RTOS_uint8_tSuspendTask
	Function Returns     : void
	Function Arguments   : void
	Function Description : start os to start systic to call schedular
*/
void RTOS_voidStartOS (void) ;
#endif /* RTOS_RTOS_INIT_H_ */
