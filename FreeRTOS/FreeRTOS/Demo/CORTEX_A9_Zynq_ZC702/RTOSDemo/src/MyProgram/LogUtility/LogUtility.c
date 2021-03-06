#include "FreeRTOS.h"
#include "task.h"

#include "LogUtility.h"

#include <string.h>


//static volatile char chrInitialized = 0;
//static volatile LogList logListInstance;
////extern char chrInitialized = 0;
////extern LogList logListInstance;
//
//static volatile LogNode logNodeArray[5000];
//static volatile logNodeIndex = 0;


void initLogList(LogList *inLogList)
{
	//LogNode *logNodeNewInstance = (LogNode *)malloc( sizeof(LogNode) );
//	LogNode *logNodeNewInstance = (LogNode *)pvPortMalloc( sizeof(LogNode) );

	inLogList->first = inLogList->logNodeArray;
	inLogList->last = inLogList->logNodeArray;

	inLogList->logNodeIndex = 0;
	inLogList->totalNodes = 0;

//	inLogList->isInitialized = TRUE;
}

struct LogNode* moveToNextLogNode(LogList *inLogList)
{
	//LogNode *logNodeNewInstance = (LogNode *)malloc( sizeof(LogNode) );
	//LogNode *logNodeNewInstance = (LogNode *)pvPortMalloc( sizeof(LogNode) );

	inLogList->last->next = &(inLogList->logNodeArray[inLogList->logNodeIndex+1]);
	inLogList->last = &(inLogList->logNodeArray[inLogList->logNodeIndex+1]);

	inLogList->totalNodes++;
	inLogList->logNodeIndex++;

	return inLogList->last;
}


//void feedLog(EnumTasks in_enumTask, u32 in_u32Data, char *in_strLogNote)
void feedLog(LogList *inLogList, int inTaskId, u32 in_u32Data, char *in_strLogNote)
{
	taskENTER_CRITICAL();

	/* Time Stamp */
	inLogList->last->u32TimeStamp = GET_GTIMER_LOWER_INLINE;

	/* Log Note String */
//	u32LogStringNoteLength = strlen(in_strLogNote);
//	logListInstance.last->strNote = (char *)pvPortMalloc( u32LogStringNoteLength+1 );
	strcpy(inLogList->last->strNote, in_strLogNote);

	/* The task who pushes this log. */
	inLogList->last->logTask = inTaskId;

	/* Data parameter */
	inLogList->last->u32Data = in_u32Data;

	moveToNextLogNode(inLogList);

	taskEXIT_CRITICAL();
}

void feedLogNoCritical(LogList *inLogList, int inTaskId, u32 in_u32Data, char *in_strLogNote)
{
//	taskENTER_CRITICAL();

	/* Time Stamp */
	inLogList->last->u32TimeStamp = GET_GTIMER_LOWER_INLINE;

	/* Log Note String */
//	u32LogStringNoteLength = strlen(in_strLogNote);
//	logListInstance.last->strNote = (char *)pvPortMalloc( u32LogStringNoteLength+1 );
	strcpy(inLogList->last->strNote, in_strLogNote);

	/* The task who pushes this log. */
	inLogList->last->logTask = inTaskId;

	/* Data parameter */
	inLogList->last->u32Data = in_u32Data;

	moveToNextLogNode(inLogList);

//	taskEXIT_CRITICAL();
}

void outputLogList(LogList *inLogList)
{

//    char strOutput[300];
//    vTaskList(strOutput);
//    xil_printf(strOutput);

//    xil_printf("\r\n@MixedLog\r\n");

	u32 u32Loop = 0;
	LogNode *currentLogNode;

	currentLogNode = inLogList->first;
	for (u32Loop=0; u32Loop < inLogList->totalNodes; u32Loop++)
	{
		/* Output logs. */;
		/*
		 * Log format:
			TimeStamp (ns),
		 */
		xil_printf("%d,\t%d,\t%d,\t\"%s\"\r\n", currentLogNode->u32TimeStamp*3, currentLogNode->logTask, currentLogNode->u32Data, currentLogNode->strNote);

		currentLogNode = currentLogNode->next;
	}

//	xil_printf("#Output is done.\r\n");
}

void outputTaskList(void)
{
    xil_printf("\r\n@TaskList\r\n");

	TaskStatus_t *pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime, ulStatsAsPercentage;

    /* Take a snapshot of the number of tasks in case it changes while this
    function is executing. */
    //uxArraySize = uxCurrentNumberOfTasks();
    uxArraySize = uxTaskGetNumberOfTasks();

    /* Allocate a TaskStatus_t structure for each task.  An array could be
    allocated statically at compile time. */
    pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );

    if( pxTaskStatusArray != NULL )
    {
        /* Generate raw status information about each task. */
        uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, &ulTotalRunTime );
        /* For each populated position in the pxTaskStatusArray array,
                    format the raw data as human readable ASCII data. */
        for( x = 0; x < uxArraySize; x++ )
        {
        	xil_printf("%d, \"%s\"\r\n", pxTaskStatusArray[ x ].xTaskNumber, pxTaskStatusArray[ x ].pcTaskName);
        }
    }
}
