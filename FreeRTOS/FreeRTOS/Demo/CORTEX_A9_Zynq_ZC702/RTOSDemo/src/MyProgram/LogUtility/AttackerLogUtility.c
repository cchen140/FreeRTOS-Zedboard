/*
 * AttackerLogUtility.c
 *
 *  Created on: Sep 12, 2017
 *      Author: cy
 */
#include "LogUtility.h"

extern LogList attackerLogList;	// Declared in main_myProgram.c

void feedAttackerLog(int inTaskId, u32 in_u32Data, char *in_strLogNote)
{
	feedLog(&attackerLogList, inTaskId, in_u32Data, in_strLogNote);
}

