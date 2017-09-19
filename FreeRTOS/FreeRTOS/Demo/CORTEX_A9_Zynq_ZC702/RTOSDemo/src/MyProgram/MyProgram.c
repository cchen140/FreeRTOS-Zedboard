/*
 * main_myProgram.c
 *
 *  Created on: Oct 29, 2014
 *      Author: CY
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
//#include "partest.h"

/* L2 event counter */
//#include "xl2cc_counter.h"

/* For recording log. */
#include "LogUtility/LogUtility.h"

#include "SyntheticTasks.h"
#include "Scheduleak/ScheduleakAttacker.h"
#include "Scheduleak/IntermittentInterval.h"

#include "MyProgram.h"

u32 u32EventCounter0, u32EventCounter1;
//u32 mainTestArray[SIZE_OF_HACKER_ARRAY];
//u32 mainTestArray2[SIZE_OF_HACKER_ARRAY];

LogList appLogList;
LogList schedulerLogList;
LogList attackerLogList;


void main_myProgram( void )
{
    xil_printf("My program starts. \r\n");

    // Disable caches (if needed).
    //Xil_L1ICacheDisable();
    //Xil_L1DCacheDisable();
    //Xil_L2CacheDisable();

	// Initialize logs
	initLogList(&appLogList);
	initLogList(&schedulerLogList);
	initLogList(&attackerLogList);

	createSyntheticTasks();

	createAttackerTasks();

	xTaskCreate( prvExperimentControlTask,	/* The function that implements the task. */
					"ExpCtrl", 		/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					EXP_TASK_STACK_SIZE,/* The size of the stack to allocate to the task. */
					NULL, 				/* The parameter passed to the task - not used in this case. */
					EXP_TASK_PRIORITY, 	/* The priority assigned to the task. */
					NULL );				/* The task handle is not required, so NULL is passed. */

	/* Start the tasks and timer running. */
	vTaskStartScheduler();


	while (1);

}

void prvExperimentControlTask( void *pvParameters )
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while (1)
	{
		// Set the next wake-up time which exactly the experiment period.
		vTaskDelayUntil( &xLastWakeTime, EXP_TASK_PERIOD_MS );

		taskENTER_CRITICAL();


		computeAndPrintInferenceResult();


		outputTaskList();

		xil_printf("\r\n@SchedulerLog\r\n");
		outputLogList(&schedulerLogList);

		xil_printf("\r\n@AppLog\r\n");
		outputLogList(&appLogList);

		xil_printf("\r\n@AttackerLog\r\n");
		outputLogList(&attackerLogList);

		if (STOP_AFTER_EXP_PERIOD)
		{
			while (1);	// Loop forever to stop the experiment.
		}
		else
		{
			// Exit critical section and continue the experiment.
			taskEXIT_CRITICAL();
		}
	}
}


