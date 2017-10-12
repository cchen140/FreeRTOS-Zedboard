#ifndef SCHEDULEAK_H_
#define SCHEDULEAK_H_

#include "interval.h"
#include "xtime_l.h"

#define	OBSERVER_TASK_PERIOD_US	49000
#define	MAX_CAPTURED_EXEC_INTERVAL_LIST_SIZE	2000
#define VICTIM_TASK_ID_OFFSET	0

// The macro for getting lower 32-bit value from the global timer.
#define	GET_GTIMER_LOWER	*(volatile u32 *) (GLOBAL_TMR_BASEADDR + GTIMER_COUNTER_LOWER_OFFSET);

typedef struct CapturedExecIntervals {
	Interval intervals[MAX_CAPTURED_EXEC_INTERVAL_LIST_SIZE];
	u32 count;
} CapturedExecIntervals;

void createAttackerTasks(void);

void applyObserverTaskExecInterval(XTime u32ExecIntervalBeginTime, XTime u32ExecIntervalEndTime);
u32 getArrivalTimeInference(void);
double computeInferencePrecisionRatio(u32 victimPeriod, XTime groundTruth, XTime inference);
void computeAndPrintInferenceResult(void);

#endif // SCHEDULEAK_H_
