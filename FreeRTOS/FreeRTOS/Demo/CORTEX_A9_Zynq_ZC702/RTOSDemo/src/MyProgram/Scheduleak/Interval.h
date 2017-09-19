/*
 * Interval.h
 *
 *  Created on: Aug 3, 2015
 *      Author: CY
 */

#ifndef INTERVAL_H_
#define INTERVAL_H_

#include "xil_types.h"
#include "../GeneralTypeDef.h"

typedef struct Interval {
	u64 begin;
	u64 end;
	int length;

	/* These two pointers are used when intervals are employed with linked-list. */
	struct Interval *prevInterval;
	struct Interval *nextInterval;

	Boolean used;
} Interval;

void initInterval( Interval *interval, u64 begin, u64 end );
Boolean getIntersection( Interval *intervalA, Interval *intervalB, Interval *resultInterval );
void shiftInterval( Interval *inInterval, int inOffset );
Boolean contains( Interval *inInterval, u64 inPoint );
Boolean isIntersected( Interval *intervalA, Interval *intervalB );
void updateIntervalByUnion( Interval *intervalHost, Interval *intervalGuest);


#endif /* INTERVAL_H_ */
