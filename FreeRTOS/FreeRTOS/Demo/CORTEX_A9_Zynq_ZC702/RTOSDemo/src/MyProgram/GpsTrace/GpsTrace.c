/*
 * GpsTraceUpdaterTask.c
 *
 *  Created on: Nov 14, 2017
 *      Author: cy
 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <math.h>

#include "GpsTrace.h"
u32 u32TraceProgress = 0;
u32 u32TraceSubProgress = 0;
float fMoveUnit = 0.0002;
GpsPoint currentGpsPoint;
GpsPoint gpsPoints[] = {
//	{-12.044012922866312, -77.02470665341184, 0},
//	{-12.05449279282314, -77.03024273281858, 0},
//	{-12.055122327623378, -77.03039293652341, 0},
//	{-12.075917129727586, -77.02764635449216, 0},
//	{-12.07635776902266, -77.02792530422971, 0},
//	{-12.076819390363665, -77.02893381481931, 0},
//	{-12.088527520066453, -77.0241058385925, 0},
//	{-12.090814532191756, -77.02271108990476, 0}
	{40.1298784, -90.3409376, 0},
	{40.12976, -90.34116, 0},
	{40.12823, -90.34339, 0},
	{40.12588, -90.34645, 0},
	{40.12556, -90.34668, 0},
	{40.12503, -90.34745, 0},
	{40.12438, -90.34855, 0},
	{40.12349, -90.3495, 0},
	{40.12134, -90.35054, 0},
	//{40.1207, -90.35048, 0},
	//{40.11911, -90.34934, 0},
	{40.11856, -90.34937, 0},
	{40.11831, -90.34913, 1},
	{40.11812, -90.3485, 0},
	{40.11819, -90.3476, 0},
	{40.11856, -90.34617, 0},
	{40.11875, -90.34498, 0},
	{40.11882, -90.34152, 0},
	{40.11873, -90.34083, 1},
	{40.11852, -90.34023, 0},
	{40.11841, -90.34008, 0},
	{40.11832, -90.33997, 0},
	{40.11794, -90.34, 0},
	{40.11769, -90.34021, 0},
	{40.1171, -90.34134, 0},
	{40.11681, -90.34152, 1},
	{40.1162, -90.34155, 0},
	{40.11531, -90.34108, 0},
	{40.1145, -90.34102, 0},
	{40.1143, -90.34093, 0},
	{40.11345, -90.34007, 0},
	{40.1128, -90.33978, 0},
	{40.11231, -90.33975, 1},
	{40.11112, -90.34029, 0},
	{40.11047, -90.34077, 0},
	{40.11006, -90.34087, 0},
	{40.1100606, -90.3408696, 0}
};
//[-12.044012922866312, -77.02470665341184], [-12.05449279282314, -77.03024273281858], [-12.055122327623378, -77.03039293652341], [-12.075917129727586, -77.02764635449216], [-12.07635776902266, -77.02792530422971], [-12.076819390363665, -77.02893381481931], [-12.088527520066453, -77.0241058385925], [-12.090814532191756, -77.02271108990476]];

void prvGpsUpdaterTask(void *pvParameters)
{
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	int numberOfGpsPoints = sizeof(gpsPoints)/sizeof(GpsPoint);


	//float testFloat = -34.56;
	char floatString[20];
	while (1)
	{
		updateGpsTraceProgress();
		printWaypoint(1, "Waypoint");

		// Set the next wake-up time which exactly the experiment period.
		vTaskDelayUntil( &xLastWakeTime, GPS_UPDATER_TASK_PERIOD_MS );

	}

}

float fLatMoveUnit, fLngMoveUnit;
void updateGpsTraceProgress() {
	if (u32TraceSubProgress == 0) {
		u32TraceProgress++;
		float fDistance = getDistance(gpsPoints[u32TraceProgress-1], gpsPoints[u32TraceProgress]);
		u32TraceSubProgress = fDistance/fMoveUnit;
		fLatMoveUnit = (gpsPoints[u32TraceProgress].lat - gpsPoints[u32TraceProgress-1].lat)/(float)u32TraceSubProgress;
		fLngMoveUnit = (gpsPoints[u32TraceProgress].lng - gpsPoints[u32TraceProgress-1].lng)/(float)u32TraceSubProgress;
		currentGpsPoint.lat = gpsPoints[u32TraceProgress-1].lat;
		currentGpsPoint.lng = gpsPoints[u32TraceProgress-1].lng;
		currentGpsPoint.mode = gpsPoints[u32TraceProgress-1].mode;
		if (gpsPoints[u32TraceProgress].mode == 1) {
			printMarker(1, "marker");
		}
	} else {
		u32TraceSubProgress--;
		currentGpsPoint.lat += fLatMoveUnit;
		currentGpsPoint.lng += fLngMoveUnit;
	}
}

void printMarker(int markerMode, char *label) {	// typeId = 1
	printGpsRecord(1, markerMode, label);
}

void printWaypoint(int markerMode, char *label) {	// typeId = 2
	printGpsRecord(2, markerMode, label);
}

void printGpsRecord(int typeId, int markerMode, char *label) {
	u64 currentTimeNs;
	XTime_GetTime(&currentTimeNs);
	currentTimeNs = currentTimeNs * 3;
	char timeStampNsString[20];
	ulltostr(currentTimeNs, timeStampNsString, 10);

	char latString[20];
	char lngString[20];

	floatToString(latString, currentGpsPoint.lat, 5, 0, false);
	floatToString(lngString, currentGpsPoint.lng, 5, 0, false);

	xil_printf("%s;\t %d;\t %d;\t \";%s;%s;%s;\"\r\n", timeStampNsString, typeId, markerMode, latString, lngString, label);
}

// https://github.com/vinceallenvince/floatToString/blob/master/floatToString.h
//
// Tim Hirzel
// tim@growdown.com
// March 2008
// float to string
//
// If you don't save this as a .h, you will want to remove the default arguments
//     uncomment this first line, and swap it for the next.  I don't think keyword arguments compile in .pde files

//char * floatToString(char * outstr, float value, int places, int minwidth=, bool rightjustify) {
char * floatToString(char * outstr, float value, int places, int minwidth, Boolean rightjustify) {
    // this is used to write a float value to string, outstr.  oustr is also the return value.
    int digit;
    float tens = 0.1;
    int tenscount = 0;
    int i;
    float tempfloat = value;
    int c = 0;
    int charcount = 1;
    int extra = 0;
    // make sure we round properly. this could use pow from <math.h>, but doesn't seem worth the import
    // if this rounding step isn't here, the value  54.321 prints as 54.3209

    // calculate rounding term d:   0.5/pow(10,places)
    float d = 0.5;
    if (value < 0)
        d *= -1.0;
    // divide by ten for each decimal place
    for (i = 0; i < places; i++)
        d/= 10.0;
    // this small addition, combined with truncation will round our values properly
    tempfloat +=  d;

    // first get value tens to be the large power of ten less than value
    if (value < 0)
        tempfloat *= -1.0;
    while ((tens * 10.0) <= tempfloat) {
        tens *= 10.0;
        tenscount += 1;
    }

    if (tenscount > 0)
        charcount += tenscount;
    else
        charcount += 1;

    if (value < 0)
        charcount += 1;
    charcount += 1 + places;

    minwidth += 1; // both count the null final character
    if (minwidth > charcount){
        extra = minwidth - charcount;
        charcount = minwidth;
    }

    if ((extra > 0) && (rightjustify==true)) {
        for (i = 0; i< extra; i++) {
            outstr[c++] = ' ';
        }
    }

    // write out the negative if needed
    if (value < 0)
        outstr[c++] = '-';

    if (tenscount == 0)
        outstr[c++] = '0';

    for (i=0; i< tenscount; i++) {
        digit = (int) (tempfloat/tens);
        sprintf(&outstr[c++], "%d", digit);
        //itoa(digit, &outstr[c++], 10);
        tempfloat = tempfloat - ((float)digit * tens);
        tens /= 10.0;
    }

    // if no places after decimal, stop now and return

    // otherwise, write the point and continue on
    if (places > 0)
    outstr[c++] = '.';


    // now write out each decimal place by shifting digits one by one into the ones place and writing the truncated value
    for (i = 0; i < places; i++) {
        tempfloat *= 10.0;
        digit = (int) tempfloat;
        sprintf(&outstr[c++], "%d", digit);
        //itoa(digit, &outstr[c++], 10);
        // once written, subtract off that digit
        tempfloat = tempfloat - (float) digit;
    }
    if ((extra > 0) && (rightjustify==false)) {
        for (i = 0; i< extra; i++) {
            outstr[c++] = ' ';
        }
    }


    outstr[c++] = '\0';
    return outstr;
}

//float sqrtf(int x) {
//    int i;
//    float s;
//    s=((x/2.0)+x/(x/2.0)) / 2.0; /*first guess*/
//    for(i=1;i<=4;i++) { /*average of guesses*/
//        s=(s+x/s)/2.0;
//    }
//    return s;
//}

// If you have build error, then add m library in the linker as the link says:
// http://zedboard.com/content/problems-fpu-commands-sqrt-atan
float getDistance(GpsPoint a, GpsPoint b)
{
    float distance;
    distance = sqrtf((a.lat - b.lat) * (a.lat - b.lat) + (a.lng-b.lng) *(a.lng-b.lng));
    return distance;
}
