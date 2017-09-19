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

extern CapturedExecIntervals capturedExecIntervals;
extern IntermittentInterval inferenceBase;
extern u32 firstGtTimeCount;
void prvExperimentControlTask( void *pvParameters )
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while (1)
	{
		// Set the next wake-up time which exactly the experiment period.
		vTaskDelayUntil( &xLastWakeTime, EXP_TASK_PERIOD_MS );

		taskENTER_CRITICAL();

		u32 i;
		Interval *thisInterval;
		for (i=0; i<capturedExecIntervals.count; i++) {
			thisInterval = &(capturedExecIntervals.intervals[i]);
			applyObserverTaskExecInterval(thisInterval->begin, thisInterval->end);
		}
		u32 inferenceResult = getArrivalTimeInference()*3;

		xil_printf("\r\nInference Result = %d \r\n", inferenceResult);


		/* Compute precision ratio. */
		u32 victimPeriod = inferenceBase.baseEnd*1000;
		u32 initialArrival = (firstGtTimeCount%victimPeriod)*3;

		double precisionRatio = computeInferencePrecisionRatio(victimPeriod, initialArrival, inferenceResult);

		char output[50];
		gcvt(precisionRatio,10,output);

		xil_printf("PrecisionRatio = %s\r\n", output);



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

