/*
 * LogUtility.h
 *
 *  Created on: Jan 21, 2015
 *      Author: CY
 */

#ifndef LOGUTILITY_H_
#define LOGUTILITY_H_

#include "xil_types.h"
#include "xtime_l.h"
#include "xil_cache.h"
#include "xpseudo_asm.h"	// for mfcpsr();

#include "FreeRTOS.h"
#include "task.h"
//#include "task.h"	// for entering critical section function.
//#include "AttackConfig.h"
#include <string.h>

#define	GET_GTIMER_LOWER_INLINE	*(volatile u32 *) (GLOBAL_TMR_BASEADDR + GTIMER_COUNTER_LOWER_OFFSET);

//typedef enum
//{
//	ENUM_LOG_SCHEDULER = 0,
//	ENUM_LOG_HIGH_HACKER,
//	ENUM_LOG_OBSERVER_HACKER,
//	ENUM_LOG_APP1,
//	ENUM_LOG_APP2
//} EnumTasks;

typedef struct LogNode
{
	u32 u32TimeStamp;    /* Time record. */
	int logTask;
	//char *strNote;        /* */
	char strNote[30];
	u32 u32Data;    /* Task ID logged by scheduler. */
	struct LogNode *next;    /* Pointer to the next cell. */
} LogNode;

typedef struct LogList
{
	LogNode logNodeArray[10000];
	u32 totalNodes;
	LogNode *first;
	LogNode *last;
	u32 logNodeIndex;
//	char isInitialized;
} LogList;

void initLogList(LogList *inLogList);
struct LogNode* moveToNextLogNode(LogList *inLogList);
void feedLog(LogList *inLogList, int inTaskId, u32 in_u32Data, char *in_strLogNote);
void feedLogNoCritical(LogList *inLogList, int inTaskId, u32 in_u32Data, char *in_strLogNote);
void outputLogList(LogList *inLogList);
void outputTaskList(void);
void outputHackerTaskList(void);

#endif /* LOGUTILITY_H_ */
