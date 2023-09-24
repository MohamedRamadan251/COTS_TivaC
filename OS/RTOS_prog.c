/*
 * RTOS_prog.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Mohammed Ramadan
 */

#include <stdint.h>
#include <stdbool.h>

#include "../MCAL/MY_Systick/Systic_init.h"

#include "RTOS_private.h"
#include "RTOS_config.h"
#include "RTOS_init.h"

/*array of tasks in system*/
Task R_structSystemTasks [MAX_NO_OF_TASKS] = {0} ;

/*array to check the timming of task*/
uint32_t   R_uint8_tTaskTiming      [MAX_NO_OF_TASKS]       ;

Task R_structEmpty = {0} ;
uint8_t RTOS_uint8_tCreatTask (void (*Copy_TaskHandler)(void) ,
		             uint32_t     Copy_uint32_tperiodicity    ,
		             uint32_t     Copy_uint32_tpriority       ,
					 uint32_t     Copy_uint32_tFirstDelay     )
{
	uint8_t L_uint8_tErrorState = 0 ;
	/*verify that the priority index with in the correct range*/
	if (Copy_uint32_tpriority < MAX_NO_OF_TASKS)
	{
		if (R_structSystemTasks [Copy_uint32_tpriority].TaskHandler == 0)
		{
			/*create task*/
			R_structSystemTasks [Copy_uint32_tpriority].TaskHandler  = Copy_TaskHandler ;
			R_structSystemTasks [Copy_uint32_tpriority].periodicity  = Copy_uint32_tperiodicity ;
			R_uint8_tTaskTiming      [Copy_uint32_tpriority]              = Copy_uint32_tFirstDelay ;
			/*Initial state of task is runing*/
			R_structSystemTasks [Copy_uint32_tpriority].TaskRunState = RunSTate ;
		}
		else
		{
			/*the required priority is already reserved*/
			L_uint8_tErrorState = 2 ;
		}
	}
	else
	{
		/*wrong priority*/
		L_uint8_tErrorState = 1 ;
	}
	/*if L_uint8_tErrorState equal 0 : then the task has been ceriation
	 *                            and you in correct state
	 *
	 *if L_uint8_tErrorState equal 1 : error state
	 *                            wrong priority
	 *
	 *if L_uint8_tErrorState equal 2 : error state
	 *                            the required priority is already reserved
	 */
	return L_uint8_tErrorState ;
}

void RTOS_voidScheduler (void)
{
	/*counter for for loop*/
	uint8_t L_uint8_tCounter ;
	/*loop for all  tasks*/
	for (L_uint8_tCounter = 0 ; L_uint8_tCounter < MAX_NO_OF_TASKS ; L_uint8_tCounter ++)
	{
		/*check for the task ceriation*/
		if (R_structSystemTasks [L_uint8_tCounter].TaskHandler != 0)
		{
			/*check for task is running or suspended*/
			if (R_structSystemTasks [L_uint8_tCounter].TaskRunState == RunSTate)
			{
				if (R_uint8_tTaskTiming [L_uint8_tCounter] == 0)
				{
					/*run the task*/
					R_structSystemTasks [L_uint8_tCounter].TaskHandler () ;
					/*reload the aperiodicity*/
					R_uint8_tTaskTiming [L_uint8_tCounter] = R_structSystemTasks [L_uint8_tCounter].periodicity ;
				}
				else
				{
					R_uint8_tTaskTiming [L_uint8_tCounter] -- ;
				}
			}
		}
	}
}

uint8_t RTOS_uint8_tDeleteTask (uint32_t Copy_uint32_tpriority)
{
	uint8_t L_uint8_tErrorState = 0 ;
	/*verify that the task has been cerieated*/
	if (R_structSystemTasks [Copy_uint32_tpriority].TaskHandler != 0)
	{
		/*task exist , execute the removable*/
		R_structSystemTasks [Copy_uint32_tpriority] = R_structEmpty ;
	}
	else
	{
		/*Task not exist*/
		L_uint8_tErrorState = 1 ;
	}
	/*if L_uint8_tErrorState equal 0 : then the task has been removed
	 *                            and you in correct state
	 *
	 *if L_uint8_tErrorState equal 1 : error state
	 *                            Task not exist
	 */
	return L_uint8_tErrorState ;
}

uint8_t RTOS_uint8_tSuspendTask (uint32_t Copy_uint32_tpriority)
{
	uint8_t L_uint8_tErrorState = 0 ;
	/*verify that the task has been cerieated or not*/
	if (R_structSystemTasks [Copy_uint32_tpriority].TaskHandler != 0)
	{
		/*task exist , execute the suspended*/
		R_structSystemTasks [Copy_uint32_tpriority].TaskRunState = RunSTate ;
	}
	else
	{
		/*Task not exist*/
		L_uint8_tErrorState = 1 ;
	}
	/*if L_uint8_tErrorState equal 0 : then the task has been Suspended
	 *                            and you in correct state
	 *
	 *if L_uint8_tErrorState equal 1 : error state
	 *                            Task not exist
	 */
	return L_uint8_tErrorState ;
}

uint8_t RTOS_uint8_tResumeTask (uint32_t Copy_uint32_tpriority)
{
	uint8_t L_uint8_tErrorState = 0 ;
		/*verify that the task has been cerieated or not*/
		if (R_structSystemTasks [Copy_uint32_tpriority].TaskHandler != 0)
		{
			/*task exist , execute the resumed*/
			R_structSystemTasks [Copy_uint32_tpriority].TaskRunState = RunSTate ;
		}
		else
		{
			/*Task not exist*/
			L_uint8_tErrorState = 1 ;
		}
		/*if L_uint8_tErrorState equal 0 : then the task has been run
		 *                            and you in correct statte
		 *
		 *if L_uint8_tErrorState equal 1 : error state
		 *                            Task not exist
		 */
		return L_uint8_tErrorState ;
}

void RTOS_voidStartOS (void)
{
	MSTK_voidInit() ;
	MSTK_voidSetIntervalPeriodic(TICK_TIME , RTOS_voidScheduler) ;
}

