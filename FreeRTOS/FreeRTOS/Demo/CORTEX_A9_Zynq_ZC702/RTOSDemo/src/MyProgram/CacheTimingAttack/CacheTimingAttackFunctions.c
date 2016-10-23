#include "CacheTimingAttackFunctions.h"

/* Read every int from the given array range. */
u32 getTimeLoadIntArrayRange( u32 *pulArray, u32 ulNumOfU32){
    u32 u32StartTimeLow = 0;
    u32 u32FinishTimeLow = 0;
    u32 u32TimeDiffLow = 0;
    u32 numOfByteRead = ulNumOfU32*4;

	asm volatile("ldr r2, [%0]" :: "r" (&numOfByteRead));	// Load number of bytes to be read to r2 (loop boundary).

	u32StartTimeLow = GET_GTIMER_LOWER;

	asm volatile("movs r3, %0" :: "r" (pulArray) );	// Use r3 as pointer, r3 = g_u32DummyArray
	asm volatile(
			"	movs r0, #0		\n"		// Use r0 as loop counter (+4 in each loop). Set initial value as 0.
			"_RLOOP:			\n"
			"	cmp r0, r2		\n"
			"	beq _END_RLOOP	\n"		// If r0==r2, finishes reading all desired data and breaking loop.
			"	ldr r1, [r3]	\n"		// Load g_u32DummyArray[r0] to r1 (r1 no use)
			"	add r3, r3, #4	\n"		// r3 pointer+=4 (the same as &(g_u32DummyArray[r0])++ )
			"	add r0, r0, #4	\n"		// loop counter += 4
			"	b _RLOOP		\n"		// continue;
			"_END_RLOOP:		\n");

	u32FinishTimeLow = GET_GTIMER_LOWER;

	if (u32FinishTimeLow >= u32StartTimeLow){
		u32TimeDiffLow = u32FinishTimeLow - u32StartTimeLow;
	} else {
		u32TimeDiffLow = ((u32)(-1)) - u32StartTimeLow + u32FinishTimeLow;
	}

	//xil_printf("%d\t%d\t(0x%x, 0x%x) \r\n", numOfByteRead, u32TimeDiffLow, u32StartTimeLow, u32FinishTimeLow);

	return u32TimeDiffLow;
}

/* Read one word for each line.
 * It is because a data cache automatically loads one line when reading something in that line,
 * so reading one word (minimum unit in 32-bit CPU) represents loading 4-word. */
u32 getTimeLoadLineIntArrayRange( u32 *pulArray, u32 ulNumOfLine){
    u32 u32StartTimeLow = 0;
    u32 u32FinishTimeLow = 0;
    u32 u32TimeDiffLow = 0;
    //u32 numOfByteRead = ulNumOfU32*4;

	asm volatile("ldr r2, [%0]" :: "r" (&ulNumOfLine));	// Load number of lines to be read to r2 (loop boundary).

	u32StartTimeLow = GET_GTIMER_LOWER;

	asm volatile("movs r3, %0" :: "r" (pulArray) );	// Use r3 as pointer, r3 = pulArray
	asm volatile(
			"	movs r0, #0			\n"	// Use r0 as loop counter (+1 in each loop). Set initial value as 0.
			"_RLOOP_LINE:			\n"
			"	cmp r0, r2			\n"
			"	beq _END_RLOOP_LINE	\n"	// If r0==r2, finishes reading all desired data and breaking loop.
			"	ldr r1, [r3]		\n"	// Load pulArray[r0*32] to r1 (r1 no use)
			"	add r3, r3, #32		\n"	// r3 pointer+=32, jump to next line (the same as &(pulArray[r0*32])+=32 )
			"	add r0, r0, #1		\n"	// loop counter += 4
			"	b _RLOOP_LINE		\n"	// continue;
			"_END_RLOOP_LINE:		\n");

	u32FinishTimeLow = GET_GTIMER_LOWER;

	if (u32FinishTimeLow >= u32StartTimeLow){
		u32TimeDiffLow = u32FinishTimeLow - u32StartTimeLow;
	} else {
		u32TimeDiffLow = ((u32)(-1)) - u32StartTimeLow + u32FinishTimeLow;
	}

	//xil_printf("%d\t%d\t(0x%x, 0x%x) \r\n", numOfByteRead, u32TimeDiffLow, u32StartTimeLow, u32FinishTimeLow);

	return u32TimeDiffLow;
}

/* For fun. */
u32 getTimeLoadRandomIntArrayRange( u32 *pulArray, u32 ulNumOfU32)
{
    u32 u32StartTimeLow = 0;
    u32 u32FinishTimeLow = 0;
    u32 u32TimeDiffLow = 0;
    u32 loop, temp_random;
    u32 u32ReadOut;

    u32StartTimeLow = GET_GTIMER_LOWER;
    for (loop=0; loop<ulNumOfU32; loop++) {
    	temp_random = GET_GTIMER_LOWER;
    	temp_random %= ulNumOfU32;
    	u32ReadOut = pulArray[temp_random];
    }
	u32FinishTimeLow = GET_GTIMER_LOWER;

	if (u32FinishTimeLow >= u32StartTimeLow){
		u32TimeDiffLow = u32FinishTimeLow - u32StartTimeLow;
	} else {
		u32TimeDiffLow = ((u32)(-1)) - u32StartTimeLow + u32FinishTimeLow;
	}

	//xil_printf("%d\t%d\t(0x%x, 0x%x) \r\n", numOfByteRead, u32TimeDiffLow, u32StartTimeLow, u32FinishTimeLow);

	return u32TimeDiffLow;
}

#define IRQ_FIQ_MASK 0xC0	/* Mask IRQ and FIQ interrupts in cpsr */
void vDataCacheFlush(void){

#if CHACHE_FLUSH_TYPE == 0
	/* Flush all data cache to make cache empty.
	 * Note:
	 *   The Flush function provided in the driver only works when both L1 D-cache
	 *   and L2 cache are enabled. Thus, the workaround here is to enable them and
	 *   perform cache Flush. Once the Flush is done, set caches back as you want.
	 */
	Xil_L1DCacheEnable();
	Xil_L1ICacheEnable();
	Xil_L2CacheEnable();

	Xil_DCacheFlush();
	//Xil_L2CacheFlush();

	#ifndef	USE_L1_I_CACHE
		Xil_L1ICacheDisable();
	#endif

	#ifndef	USE_L1_D_CACHE
		Xil_L1DCacheDisable();
	#endif

	#ifndef	USE_L2_CACHE
		Xil_L2CacheDisable();
	#endif

#elif	CHACHE_FLUSH_TYPE == 1
	unsigned int currmask;
	currmask = mfcpsr();
	mtcpsr(currmask | IRQ_FIQ_MASK);

	#ifdef	USE_L1_D_CACHE
		Xil_L1DCacheFlush();
	#endif

	#ifdef	USE_L2_CACHE
		Xil_L2CacheFlush();
	#endif

	mtcpsr(currmask);

#elif	CHACHE_FLUSH_TYPE == 2
	#error "Cache flush type 2 is unchecked in this file."
	// To be implemented
#endif

}
