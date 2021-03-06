#include "SyntheticTasks.h"

/* AES Cryptography */
//#include "crypto_aes/TI_aes_128_encr_only.h"

/* For recording log. */
#include "LogUtility/AppLogUtility.h"

u32 u32AppArray[SIZE_OF_APP_ARRAY];	// Too big to fit the stack size limit of a FreeRTOS task.
u32 u32AesArray[SIZE_OF_APP_ARRAY];

TaskParam appTaskParamArray[] = {
	//  period (us), priority, computation time (us), computing size
		{32000, APP_TASK_LOWEST_PRIORITY, 9600, 0},
		{20000, APP_TASK_LOWEST_PRIORITY+1, 4300, 0},
		{10000, APP_TASK_LOWEST_PRIORITY+2, 1900, 0}
//		,
//		{20000, APP_TASK_LOWEST_PRIORITY+3, 100, 0},
//		{18000, APP_TASK_LOWEST_PRIORITY+4, 100, 0},
//		{18000, APP_TASK_LOWEST_PRIORITY+5, 100, 0},
//		{18000, APP_TASK_LOWEST_PRIORITY+6, 100, 0},
//		{20000, APP_TASK_LOWEST_PRIORITY+7, 100, 0},
//		{20000, APP_TASK_LOWEST_PRIORITY+8, 100, 0},
//		{32000, APP_TASK_LOWEST_PRIORITY+9, 100, 0}
////		,
//		{32000, APP_TASK_LOWEST_PRIORITY+10, 100, 0}
//		,
//		{32000, APP_TASK_LOWEST_PRIORITY+11, 100, 0}
//		,
//		{10000, APP_TASK_LOWEST_PRIORITY+12, 100, 0}
////		,
//		{10000, APP_TASK_LOWEST_PRIORITY+13, 100, 0}
//		,
//		{10000, APP_TASK_LOWEST_PRIORITY+14, 100, 0}

//		{200/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY, SIZE_OF_APP_ARRAY/64},
//		{150/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+1, SIZE_OF_APP_ARRAY/32},
//		{66/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+2, SIZE_OF_APP_ARRAY/4},
//		{33/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+3, SIZE_OF_APP_ARRAY},
//		{20/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+4, SIZE_OF_APP_ARRAY/64},
//		{20/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+4, SIZE_OF_APP_ARRAY/8},
//		{20/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+4, SIZE_OF_APP_ARRAY/16},
//		{13/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+5, SIZE_OF_APP_ARRAY/64},
//		{10/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+6, SIZE_OF_APP_ARRAY/2},
//		{7/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+7, SIZE_OF_APP_ARRAY/32},
//		{5/portTICK_RATE_MS, APP_TASK_LOWEST_PRIORITY+8, SIZE_OF_APP_ARRAY/64}
	};

void createSyntheticTasks(void)
{
	int numberOfAppTask = sizeof(appTaskParamArray)/sizeof(TaskParam);
	char taskName[10];	// Format is APP-1, APP-2, and so on.
	int loop;

	for (loop=0; loop<numberOfAppTask; loop++)
	{
		// Build the string of task name.
		sprintf(taskName, "APP-%d", loop+1);

		xTaskCreate( 	prvGeneralSyntheticTask,	/* The function that implements the task. */
						taskName, 			/* The text name assigned to the task - for debug only as it is not used by the kernel. */
						APP_TASK_STACK_SIZE,/* The size of the stack to allocate to the task. */
						&(appTaskParamArray[loop]),	/* The parameter passed to the task. */
						appTaskParamArray[loop].priority, 	/* The priority assigned to the task. */
						NULL );				/* The task handle is not required, so NULL is passed. */
	}
}


// Note that the arrays all the tasks read in this function are the same one.
TickType_t firstTickCount = 0;
void prvGeneralSyntheticTask(void *pvParameters)
{
	TaskParam *pvTaskParam = pvParameters;

	char logString[30];

	// For measuring execution time for analysis.
//	u32 executionTime = 0;

	// Initialize the xLastWakeTime variable with the current time.
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	// To align the start point of every application task.
	if (firstTickCount == 0)
	{
		firstTickCount = xLastWakeTime;
	}
	else
	{
		xLastWakeTime = firstTickCount;
	}

	while (TRUE)
	{
//		taskENTER_CRITICAL();
//		executionTime = GET_GTIMER_LOWER;

//		sprintf(logString, "Loading %d.", pvTaskParam->computeSize*4);
		sprintf(logString, "BEGIN");    // print "BEGIN" to indicate the beginning of a task.
		feedAppLog(getTaskId(), pvTaskParam->computeSize*4, logString);

//		getTimeLoadLineIntArrayRange(u32AppArray, pvTaskParam->computeSize);	// Line read function.
		usDelay(pvTaskParam->computationTimeUs);


//		executionTime = executionTime - GET_GTIMER_LOWER;
//		xil_printf("T%d: %d ns\r\n", getTaskId(), executionTime);
//		taskEXIT_CRITICAL();

		vTaskDelayUntil( &xLastWakeTime, pvTaskParam->periodUs/1000/portTICK_RATE_MS );
	}
}


///*****************************************************************************/
///**
//* The AES task, a FreeRTOS task function
//* It keeps a loop filling (reading) the cache from 0KB~512KB.
//*
//* @param	None
//*
//* @return	None
//*
//* @note		None.
//*
//******************************************************************************/
//////u32 u32AppArray[SIZE_OF_APP_ARRAY];	// Too big to fit the stack size limit of a FreeRTOS task.
////void prvAesTask(void *pvParameters){
////	unsigned char state[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
////							   0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
////
////	unsigned char ciphertext[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
////								0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};
////	unsigned char key[]   = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
////						   0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
////	u32 i, j, k;
////	unsigned char err_count = 0;
////
////	while (1) {
////
////		for (j=0; j<=10; j++) {
////			//xil_printf("\t@0@\t");
////			//taskENTER_CRITICAL();
////			//feedLog(getTaskId(), 0, "AES 0KB.");
////			//taskENTER_CRITICAL();
////			vTaskDelay( AES_TASK_DELAY_TIME_MS );
////		}
////
//////		for (j=0; j<=50; j++) {
//////			//taskENTER_CRITICAL();
//////			//xil_printf("\t@32@\t");
//////			for (k=0;k<2000;k++) {	//32KB
//////				feedLog(getTaskId(), 32, "AES 32KB.");
//////				aes_encrypt(u32AesArray+(k*16),key);
//////				for (i=0;i<16;i++) {
//////					if (u32AesArray[k*16+i] != ciphertext[i]) {
//////						err_count++;
//////					}
//////				}
//////			}
//////			//taskENTER_CRITICAL();
//////			vTaskDelay( AES_TASK_DELAY_TIME_MS );
//////			;
//////		}
/////*
////		for (j=0; j<=100; j++) {
////			xil_printf("\t@0@\t");
////			;
////			vTaskDelay( AES_TASK_DELAY_TIME_MS );
////		}*/
////
//////		for (j=0; j<=20; j++) {
//////			//taskENTER_CRITICAL();
//////			//xil_printf("\t@100@\t");
//////			for (k=0;k<6250;k++) {	//100kB
//////				feedLog(getTaskId(), 32, "AES 100KB.");
//////				aes_encrypt(u32AesArray+(k*16),key);
//////				for (i=0;i<16;i++) {
//////					if (u32AesArray[k*16+i] != ciphertext[i]) {
//////						err_count++;
//////					}
//////				}
//////			}
//////
//////			//taskENTER_CRITICAL();
//////			vTaskDelay( AES_TASK_DELAY_TIME_MS );
//////
//////		}
////
////
////	}
////}

#define COUNTS_PER_USECOND  (XPAR_CPU_CORTEXA9_CORE_CLOCK_FREQ_HZ / (2*1000000))
void usDelay(u32 usSeconds)
{
	u32 loop;
	u32 endCounts = ((XTime) usSeconds) * COUNTS_PER_USECOND / 39.4;
	for (loop=0; loop<endCounts; loop++)
		;
}
