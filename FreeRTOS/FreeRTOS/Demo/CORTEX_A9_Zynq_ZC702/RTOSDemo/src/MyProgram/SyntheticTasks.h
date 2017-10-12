/*
 * SyntheticTasks.h
 *
 *  Created on: Mar 11, 2015
 *      Author: CY
 */

#ifndef SYTHETICTASKS_H_
#define SYTHETICTASKS_H_

#include <xil_types.h>

// The macro for getting lower 32-bit value from the global timer.
#define	GET_GTIMER_LOWER	*(volatile u32 *) (GLOBAL_TMR_BASEADDR + GTIMER_COUNTER_LOWER_OFFSET);

void createSyntheticTasks(void);
void prvGeneralSyntheticTask(void *pvParameters);
//void prvAesTask( void *pvParameters );

void usDelay(u32 usSeconds);

/* Define for application task. */
#define	SIZE_OF_APP_ARRAY			( 512000/4 ) // in u32 // 448000 for 1-way locked
//#define	LINE_OF_APP_ARRAY			SIZE_OF_APP_ARRAY*4/32
#define APP_TASK_LOWEST_PRIORITY	tskIDLE_PRIORITY + 2	// Low hacker task has (tskIDLE_PRIORITY+1) priority.
#define APP_TASK_STACK_SIZE			2000

/* Define for AES task. */
/*
#define	AES_TASK_PRIORITY			tskIDLE_PRIORITY + 2	// Bigger number means higher priority.
#define	AES_TASK_DELAY_TIME_MS		( 32/portTICK_RATE_MS )
#define AES_TASK_STACK_SIZE			1024
*/

typedef struct TaskParam {
	u32 periodUs;
	u32 priority;
	u32 computationTimeUs;
	u32 computeSize;
}TaskParam;

#endif /* SYTHETICTASKS_H_ */
