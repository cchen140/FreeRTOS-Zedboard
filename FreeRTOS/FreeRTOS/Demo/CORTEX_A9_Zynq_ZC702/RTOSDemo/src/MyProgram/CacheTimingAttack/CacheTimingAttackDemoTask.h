/*
 * CacheTimingAttackDemoTask.h
 *
 *  Created on: Oct 22, 2016
 *      Author: CY Chen
 */

#ifndef CACHETIMINGATTACKDEMOTASK_H_
#define CACHETIMINGATTACKDEMOTASK_H_

#include "FreeRTOS.h"	// for portTICK_RATE_MS
#include "task.h"		// for tskIDLE_PRIORITY

#define	SIZE_OF_CACHE_ATTACK_ARRAY		( 512000/4 ) // in u32, 448000 for 1-way locked
#define	Line_OF_CACHE_ATTACK_ARRAY		SIZE_OF_CACHE_ATTACK_ARRAY*4/32

/* Define for the cache attack task. */
#define	CACHE_ATTACK_TASK_PRIORITY		tskIDLE_PRIORITY + 20	// Bigger number means higher priority.
#define	CACHE_ATTACK_TASK_DELAY_TIME_MS	( 2/portTICK_RATE_MS )
#define CACHE_ATTACK_TASK_STACK_SIZE		1024	// in unit of 32-bit
#define	CACHE_ATTACK_TASK_AVERAGE_TIMES	5

/* These two values are obtained by experiments.
 * See slides to understand how to estimate these values. */
#define	C_H_LINE	3.51	// 56093/16000
#define	C_M_LINE	9.84	// 157514/16000

void createCacheAttackTask(void);
void prvCacheAttackTask( void *pvParameters );

#endif /* CACHETIMINGATTACKDEMOTASK_H_ */
