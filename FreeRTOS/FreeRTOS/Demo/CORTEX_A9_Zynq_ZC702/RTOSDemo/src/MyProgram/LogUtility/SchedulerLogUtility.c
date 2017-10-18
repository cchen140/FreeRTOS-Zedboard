#include "LogUtility.h"
#include "SchedulerLogUtility.h"

extern LogList schedulerLogList;	// Declared in main_myProgram.c

void feedSchedulerLog(u32 in_u32Data, char *in_strLogNote)
{
	//feedLogNoCritical(&schedulerLogList, 0, in_u32Data, in_strLogNote);	// 0 indicates that it is from scheduler.
}
