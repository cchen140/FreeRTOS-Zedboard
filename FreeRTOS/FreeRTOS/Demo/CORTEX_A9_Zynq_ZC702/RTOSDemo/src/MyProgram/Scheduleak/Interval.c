/*
 * Interval.c
 *
 *  Created on: Aug 3, 2015
 *      Author: CY
 */

#include "Interval.h"

void initInterval( Interval *interval, u64 begin, u64 end )
{
	interval->begin = begin;
	interval->end = end;
	interval->length = end - begin;

	interval->nextInterval = interval;
	interval->prevInterval = interval;

	interval->used = TRUE;

	if (interval->length < 0 ) {
		int i = 0;
		i++;
	}
}

/**
 *
 * Return the length of the intersection.
 */
Boolean getIntersection( Interval *intervalA, Interval *intervalB, Interval *resultInterval )
{
	Interval *leftInterval, *rightInterval;
	u64 resultBegin=0, resultEnd=0;

    // Check which one is on the left.
	if ( intervalA->begin <= intervalB->begin )
	{// IntervalA is on the left
		leftInterval = intervalA;
		rightInterval = intervalB;
	}
	else
	{
		leftInterval = intervalB;
		rightInterval = intervalA;
	}

	/* Determine begin value. */
	if ( leftInterval->end < rightInterval->begin )
	{
		// They have no intersection.
		//resultInterval->length = 0;
		return FALSE;
	}
	else
	{
		resultBegin = rightInterval->begin;
	}

	/* Determine end value. */
	if ( leftInterval->end < rightInterval->end )
	{
		resultEnd = leftInterval->end;
	}
	else
	{
		resultEnd = rightInterval->end;
	}

	initInterval( resultInterval, resultBegin, resultEnd );

	return TRUE;
}

/* This function will discard the interval that is below 0. */
void shiftInterval( Interval *inInterval, int inOffset )
{
    inInterval->begin += inOffset;
    inInterval->end += inOffset;

    if ((signed long long)inInterval->begin < 0) {
    	inInterval->begin = 0;
    }

    if ((signed long long)inInterval->end < 0) {
		inInterval->end = 0;
	}

    inInterval->length = inInterval->end - inInterval->begin;
}

Boolean contains( Interval *inInterval, u64 inPoint )
{
	if ( (inInterval->begin <= inPoint)
		&& (inInterval->end >= inPoint) )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Boolean isIntersected( Interval *intervalA, Interval *intervalB ) {
	Interval *leftInterval, *rightInterval;

    // Check which one is on the left.
	if ( intervalA->begin <= intervalB->begin )
	{// IntervalA is on the left
		leftInterval = intervalA;
		rightInterval = intervalB;
	}
	else
	{
		leftInterval = intervalB;
		rightInterval = intervalA;
	}

	/* Determine begin value. */
	if ( leftInterval->end < rightInterval->begin )
	{
		// They have no intersection.
		//resultInterval->length = 0;
		return FALSE;
	} else {
		return TRUE;
	}
}

void updateIntervalByUnion( Interval *intervalHost, Interval *intervalGuest) {
	if (isIntersected(intervalHost, intervalGuest) == TRUE) {
		if (intervalGuest->begin < intervalHost->begin) {
			intervalHost->begin = intervalGuest->begin;
		}
		if (intervalGuest->end > intervalHost->end) {
			intervalHost->end = intervalGuest->end;
		}
	}
}
