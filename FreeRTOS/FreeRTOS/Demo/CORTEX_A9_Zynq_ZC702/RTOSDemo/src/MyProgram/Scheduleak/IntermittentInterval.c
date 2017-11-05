/*
 * IntermittentInterval.c
 *
 *  Created on: Sep 12, 2017
 *      Author: cy
 */

#include "IntermittentInterval.h"

void initInterInterval(IntermittentInterval *interInterval, u32 baseBegin, u32 baseEnd) {
	interInterval->baseBegin = baseBegin;
	interInterval->baseEnd = baseEnd;

	interInterval->count = 0;
}

void InterInterval_getLargestComplementaryInterval(IntermittentInterval *interInterval, Interval *largestInterval, Boolean checkCrossIntervals) {
	// We assume intervals are sorted already, so start from the first interval in the list.

	u32 largestLength = 0;

	/* Check the complementary interval between base_begin and the first interval. */
	if (interInterval->firstInterval->begin > interInterval->baseBegin) {
		initInterval( largestInterval, interInterval->baseBegin, interInterval->firstInterval->begin);
		largestLength = largestInterval->length;
	} else {
		initInterval( largestInterval, interInterval->baseBegin, interInterval->baseBegin);
	}

	Interval *thisInterval = interInterval->firstInterval;
	while (thisInterval != thisInterval->nextInterval) {
		u32 thisCompIntervalLength = thisInterval->nextInterval->begin - thisInterval->end;
		if ( thisCompIntervalLength > largestLength ) {
			largestLength = thisCompIntervalLength;
			initInterval( largestInterval, thisInterval->end, thisInterval->nextInterval->begin );
		}

		thisInterval = thisInterval->nextInterval;
	}

	/* Check the complementary interval between the last interval and base_end. */
	if ( (interInterval->baseEnd-thisInterval->end) > largestLength ) {
		initInterval( largestInterval, thisInterval->end, interInterval->baseEnd);
		largestLength = interInterval->baseEnd-thisInterval->end;
	}

	/* Check if the first and the last complementary intervals should be considered as one interval. */
	if (checkCrossIntervals == TRUE) {
		if ( (interInterval->firstInterval->begin!=interInterval->baseBegin) && (interInterval->baseEnd!=interInterval->lastInterval->end) ) {
			u32 crossIntervalLength = (interInterval->firstInterval->begin-interInterval->baseBegin) + (interInterval->baseEnd-interInterval->lastInterval->end);
			if (crossIntervalLength > largestLength) {
				// Note that this interval will exceed the base_end.
				initInterval( largestInterval, interInterval->lastInterval->end, interInterval->baseEnd+(interInterval->firstInterval->begin-interInterval->baseBegin));
			}
		}
	}
}

void InterInterval_updateUnion(IntermittentInterval *interInterval, Interval *interval) {

	if (interInterval->count == 0) {
		InterInterval_addIntervalWithoutCheckingOverlaps(interInterval, interval);
		return;
	}


	/* Find the first existing interval that covers the given interval. */
	Interval *thisInterval, *intersectedInterval;
	Boolean intersected = FALSE;
	Boolean firstLoop = TRUE;
	do {
		if (firstLoop == TRUE) {
			firstLoop = FALSE;
			thisInterval = interInterval->firstInterval;
		} else {
			thisInterval = thisInterval->nextInterval;
		}

		if ( isIntersected( thisInterval, interval ) == TRUE ) {
			intersectedInterval = thisInterval;
			intersected = TRUE;
			break;
		}
	} while (thisInterval->nextInterval != thisInterval);

	if (intersected == FALSE) {
		// No intersection. Just add this interval.
		InterInterval_addIntervalWithoutCheckingOverlaps(interInterval, interval);
	} else {
		updateIntervalByUnion( intersectedInterval, interval);

		Interval tempInterval;
		initInterval(&tempInterval, intersectedInterval->begin, intersectedInterval->end);
		InterInterval_removeInterval(interInterval, intersectedInterval);

		/* Continue to check whether the result is overlapped with other existing intervals. */
		InterInterval_updateUnion(interInterval, &tempInterval);

	}
}

/* Please assume that the added interval has no overlaps with other existing intervals. */
void InterInterval_addIntervalWithoutCheckingOverlaps(IntermittentInterval *interInterval, Interval *interval) {
	Interval *newInterval;

	if (interInterval->count == 0) {
		newInterval = &(interInterval->intervals[0]);
		initInterval( newInterval, interval->begin, interval->end );

		interInterval->firstInterval = newInterval;
		interInterval->lastInterval = newInterval;

		newInterval->nextInterval = newInterval;
		newInterval->prevInterval = newInterval;
	} else {
		newInterval = InterInterval_getAnEmptyIntervalSpace(interInterval);
		initInterval( newInterval, interval->begin, interval->end );

		// Find the interval where new interval should be inserted before.
		Interval *thisInterval;
		thisInterval = interInterval->firstInterval;
		while ( newInterval->begin > thisInterval->begin ) {
			if (thisInterval->nextInterval == thisInterval) {
				break;
			} else {
				thisInterval = thisInterval->nextInterval;
			}
		}


		if ( (thisInterval->nextInterval == thisInterval) && (newInterval->begin > thisInterval->begin) ) { // Check if newInterval is to be added to the last slot.
			// thisInterval is the last element.
			// newInterval should be after thisInterval
			// Insert into the last.

			newInterval->nextInterval = newInterval;
			newInterval->prevInterval = thisInterval;

			interInterval->lastInterval = newInterval;
			thisInterval->nextInterval = newInterval;
		} else if (thisInterval->prevInterval == thisInterval) {	// Check if thisInterval is the first element.
			// thisInterval is the first element.
			// New Interval should be before thisInterval.
			interInterval->firstInterval = newInterval;

			newInterval->nextInterval = thisInterval;
			newInterval->prevInterval = newInterval;

			//thisInterval->nextInterval = // no change on this one
			thisInterval->prevInterval = newInterval;
		} else {
			// Again, new Interval should be before thisInterval.
			newInterval->nextInterval = thisInterval;
			newInterval->prevInterval = thisInterval->prevInterval;

			//thisInterval->nextInterval = // no change on this one
			thisInterval->prevInterval = newInterval;

			newInterval->prevInterval->nextInterval = newInterval;
		}

	}


	//newInterval->used = TRUE; // No need to do that since it's done in initInterval().
	interInterval->count++;

}

void InterInterval_removeInterval(IntermittentInterval *interInterval, Interval *intervalToBeRemoved) {
	if (interInterval->firstInterval == intervalToBeRemoved) {
		interInterval->firstInterval = intervalToBeRemoved->nextInterval;
		intervalToBeRemoved->nextInterval->prevInterval = intervalToBeRemoved->nextInterval;
	} else {
		intervalToBeRemoved->nextInterval->prevInterval = intervalToBeRemoved->prevInterval;
	}

	if (interInterval->lastInterval == intervalToBeRemoved) {
		interInterval->lastInterval = intervalToBeRemoved->prevInterval;
		intervalToBeRemoved->prevInterval->nextInterval = intervalToBeRemoved->prevInterval;
	} else {
		intervalToBeRemoved->prevInterval->nextInterval = intervalToBeRemoved->nextInterval;
	}

	intervalToBeRemoved->used = FALSE;

	interInterval->count--;
}

Interval *InterInterval_getAnEmptyIntervalSpace(IntermittentInterval *interInterval) {
	u32 i;
	for (i=0; i<MAX_INTERVAL_LIST_SIZE; i++) {
		if (interInterval->intervals[i].used == FALSE) {
			return &(interInterval->intervals[i]);
		}
	}
	/* It should never reach here. */

	while(1) {
		i++;
	}
}

void InterInterval_outputIntervals(IntermittentInterval *interInterval) {
	xil_printf("\r\nCaptured Intervals (ns)(count=%d):\r\n", interInterval->count);
	/*
	u32 i;
	for (i=0; i<MAX_INTERVAL_LIST_SIZE; i++) {
		if (interInterval->intervals[i].used == TRUE) {
			u32 begin = interInterval->intervals[i].begin;
			u32 end = interInterval->intervals[i].end;
			xil_printf("[%d - %d]\r\n", begin*3, end*3);
		}
	}
	*/
	// Print in order
	Interval *thisInterval;
	Boolean firstLoop = TRUE;
	do {
		if (firstLoop == TRUE) {
			firstLoop = FALSE;
			thisInterval = interInterval->firstInterval;
		} else {
			thisInterval = thisInterval->nextInterval;
		}

		xil_printf("[%d - %d]\r\n", (u32)(thisInterval->begin*3), (u32)(thisInterval->end*3));
	} while (thisInterval->nextInterval != thisInterval);
}

void InterInterval_outputComplementaryInterval(IntermittentInterval *interInterval) {
	// We assume intervals are sorted already, so start from the first interval in the list.

	//printf("Complementary Intervals (ns):\r\n");

	/* Check if complementatry interval is empty. */
	if ( (interInterval->firstInterval->begin == interInterval->baseBegin) && (interInterval->firstInterval->end == interInterval->baseEnd) ) {
		printf("= no complementary interval =\r\n");
	}


	/* Output the complementary interval between base_begin and the first interval. */
	if (interInterval->firstInterval->begin > interInterval->baseBegin) {
		printf("[%lld - %lld]\t(%lld)\r\n", interInterval->baseBegin*3, interInterval->firstInterval->begin*3, (interInterval->firstInterval->begin - interInterval->baseBegin)*3);
	}

	Interval *thisInterval = interInterval->firstInterval;
	while (thisInterval != thisInterval->nextInterval) {
		printf("[%lld - %lld]\t(%lld)\r\n", thisInterval->end*3, thisInterval->nextInterval->begin*3, (thisInterval->nextInterval->begin - thisInterval->end)*3);
		thisInterval = thisInterval->nextInterval;
	}

	/* Output the complementary interval between the last interval and base_end. */
	if ( interInterval->baseEnd > thisInterval->end ) {
		printf("[%lld - %lld]\t(%lld)\r\n", thisInterval->end*3, interInterval->baseEnd*3, (interInterval->baseEnd - thisInterval->end)*3);
	}

}
