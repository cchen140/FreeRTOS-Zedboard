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
		if ( thisInterval->nextInterval > largestLength ) {
			largestLength = thisInterval->nextInterval;
			initInterval( largestInterval, thisInterval->end, thisInterval->nextInterval->begin );
		}

		thisInterval = thisInterval->nextInterval;
	}

	/* Check the complementary interval between the last interval and base_end. */
	if ( (interInterval->baseEnd-thisInterval->end) > largestLength ) {
		initInterval( largestInterval, thisInterval->end, interInterval->baseEnd);
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
		} else {
			thisInterval = thisInterval->nextInterval;
		}
	} while (thisInterval->nextInterval != thisInterval);

	if (intersected == FALSE) {
		// No intersection. Just add this interval.
		InterInterval_addIntervalWithoutCheckingOverlaps(interInterval, interval);
	} else {
		updateIntervalByUnion( intersectedInterval, interval);

		// Then check if it is overlapped with its consecutive intervals.
		while ( (intersectedInterval->nextInterval!=intersectedInterval) && (isIntersected(intersectedInterval, intersectedInterval->nextInterval)==TRUE) ) {
			updateIntervalByUnion( intersectedInterval, intersectedInterval->nextInterval);
			InterInterval_removeInterval(interInterval, intersectedInterval->nextInterval);
		}
	}
}

/* Please assume that the added interval has no overlaps with other existing intervals. */
void InterInterval_addIntervalWithoutCheckingOverlaps(IntermittentInterval *interInterval, Interval *interval) {
	Interval *newInterval;

	if (interInterval->count == 0) {
		interInterval->firstInterval = &(interInterval->intervals[0]);
		interInterval->lastInterval = &(interInterval->intervals[0]);

		interInterval->intervals[0].nextInterval = &(interInterval->intervals[0]);
		interInterval->intervals[0].prevInterval = &(interInterval->intervals[0]);

		newInterval = &(interInterval->intervals[0]);
		initInterval( newInterval, interval->begin, interval->end );

	} else {
		newInterval = InterInterval_getAnEmptyIntervalSpace(interInterval);
		initInterval( newInterval, interval->begin, interval->end );

		// Find the interval where new interval should be inserted before.
		Interval *thisInterval;
		thisInterval = interInterval->firstInterval;
		while ( newInterval->begin < thisInterval->end ) {
			if (thisInterval->nextInterval == thisInterval) {
				break;
			} else {
				thisInterval = thisInterval->nextInterval;
			}
		}

		if (newInterval->begin < thisInterval->end) {
			// New interval will be the first element then.
			thisInterval->prevInterval = newInterval;
			newInterval->nextInterval = thisInterval;
			newInterval->prevInterval = newInterval;
			interInterval->firstInterval = newInterval;
		} else {
			// New interval will be after thisInterval.

			// Check if thisInterval is the last element.
			if (thisInterval->nextInterval == thisInterval) {
				// Yes it is.
				newInterval->nextInterval = newInterval;
				interInterval->lastInterval = newInterval;

				thisInterval->nextInterval = newInterval;
				newInterval->prevInterval = thisInterval;
			} else {
				newInterval->nextInterval = thisInterval->nextInterval;
				newInterval->nextInterval->prevInterval = newInterval;

				thisInterval->nextInterval = newInterval;
				newInterval->prevInterval = thisInterval;
			}

		}

	}

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
