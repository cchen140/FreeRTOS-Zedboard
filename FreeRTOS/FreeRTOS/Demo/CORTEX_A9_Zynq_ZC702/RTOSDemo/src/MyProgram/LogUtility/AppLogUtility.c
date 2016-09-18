/*
 * AppLogUtility.c
 *
 *  Created on: Apr 2, 2015
 *      Author: CY
 */
#include "LogUtility.h"

extern LogList appLogList;	// Declared in main_myProgram.c

void feedAppLog(int inTaskId, u32 in_u32Data, char *in_strLogNote)
{
	feedLog(&appLogList, inTaskId, in_u32Data, in_strLogNote);
}
