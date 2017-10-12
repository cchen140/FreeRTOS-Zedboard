/*
 * IntermittentInterval.h
 *
 *  Created on: Sep 12, 2017
 *      Author: cy
 */

#ifndef INTERMITTENTINTERVAL_H_
#define INTERMITTENTINTERVAL_H_

#include "Interval.h"

#define	MAX_INTERVAL_LIST_SIZE	100

typedef struct IntermittentInterval {
	Interval intervals[MAX_INTERVAL_LIST_SIZE];
	Interval *firstInterval;
	Interval *lastInterval;

	u32 count;

	u64 baseBegin;
	u64 baseEnd;
} IntermittentInterval;

void initInterInterval(IntermittentInterval *interInterval, u32 baseBegin, u32 baseEnd);
void InterInterval_getLargestComplementaryInterval(IntermittentInterval *interInterval, Interval *largestInterval, Boolean checkCrossIntervals);
void InterInterval_updateUnion(IntermittentInterval *interInterval, Interval *interval);
void InterInterval_addIntervalWithoutCheckingOverlaps(IntermittentInterval *interInterval, Interval *interval);
void InterInterval_removeInterval(IntermittentInterval *interInterval, Interval *intervalToBeRemoved);
Interval *InterInterval_getAnEmptyIntervalSpace(IntermittentInterval *interInterval);
void InterInterval_outputIntervals(IntermittentInterval *interInterval);

#endif /* INTERMITTENTINTERVAL_H_ */
