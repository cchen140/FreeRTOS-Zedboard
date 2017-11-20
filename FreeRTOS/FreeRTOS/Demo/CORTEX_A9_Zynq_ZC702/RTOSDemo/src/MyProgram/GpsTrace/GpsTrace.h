/*
 * GpsTrace.h
 *
 *  Created on: Nov 14, 2017
 *      Author: cy
 */

#ifndef SRC_MYPROGRAM_GPSTRACE_GPSTRACE_H_
#define SRC_MYPROGRAM_GPSTRACE_GPSTRACE_H_

#include <xil_types.h>
#include "../GeneralTypeDef.h"
#include "../LogUtility/LogUtility.h"	// for ulltostr()

#define GPS_UPDATER_TASK_PERIOD_MS	( 300/portTICK_RATE_MS )//( 400/portTICK_RATE_MS )

typedef struct GpsPoint {
	float lat;
	float lng;
	int mode;
}GpsPoint;

void prvGpsUpdaterTask(void *pvParameters);
void updateGpsTraceProgress();
void printMarker(int markerMode, char *label);
char * floatToString(char * outstr, float value, int places, int minwidth, Boolean rightjustify);
float getDistance(GpsPoint a, GpsPoint b);

#endif /* SRC_MYPROGRAM_GPSTRACE_GPSTRACE_H_ */
