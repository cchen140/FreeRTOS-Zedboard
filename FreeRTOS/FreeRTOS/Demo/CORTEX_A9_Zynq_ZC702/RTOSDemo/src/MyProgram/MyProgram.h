/*
 * MyProgram.h
 *
 *  Created on: Nov 2, 2014
 *      Author: CY
 */

#ifndef MYPROGRAM_H_
#define MYPROGRAM_H_

//#include <xil_types.h>

// The macro for getting lower 32-bit value from the global timer.
#define	GET_GTIMER_LOWER	*(volatile u32 *) (GLOBAL_TMR_BASEADDR + GTIMER_COUNTER_LOWER_OFFSET);

/* Define for experiment task. */
void prvExperimentControlTask( void *pvParameters );

#define	EXP_TASK_PRIORITY		tskIDLE_PRIORITY + 5	// Bigger number means higher priority.
#define	EXP_TASK_PERIOD_MS		( 4000/portTICK_RATE_MS )//( 400/portTICK_RATE_MS )
#define EXP_TASK_STACK_SIZE		500

#define	STOP_AFTER_EXP_PERIOD	FALSE//TRUE

#endif /* MYPROGRAM_H_ */
