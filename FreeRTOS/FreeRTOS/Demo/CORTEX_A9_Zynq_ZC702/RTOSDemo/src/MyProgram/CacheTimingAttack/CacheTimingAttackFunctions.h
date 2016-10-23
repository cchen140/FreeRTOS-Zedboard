/*
 * CacheAttackFunction.h
 *
 *  Created on: Oct 29, 2014
 *      Author: CY
 */

#ifndef CACHE_ATTACK_FUNCTION_H_
#define CACHE_ATTACK_FUNCTION_H_

#include "xil_types.h"
#include "xtime_l.h"
#include "xil_cache.h"
#include "xpseudo_asm.h"	// for mfcpsr();

/*
 * Program configuration:
 * Comment out the line if the function is unused.
 */
//#define		USE_L1_I_CACHE
//#define		USE_L1_D_CACHE
#define			USE_L2_CACHE

#define CHACHE_FLUSH_TYPE			1

#define	GET_GTIMER_LOWER	*(volatile u32 *) (GLOBAL_TMR_BASEADDR + GTIMER_COUNTER_LOWER_OFFSET);

u32 getTimeLoadIntArrayRange( u32 *pulArray, u32 ulNumOfU32);
u32 getTimeLoadLineIntArrayRange( u32 *pulArray, u32 ulNumOfLine);
u32 getTimeLoadRandomIntArrayRange( u32 *pulArray, u32 ulNumOfU32);
void vDataCacheFlush(void);

#endif /* CACHE_ATTACK_FUNCTION_H_ */
