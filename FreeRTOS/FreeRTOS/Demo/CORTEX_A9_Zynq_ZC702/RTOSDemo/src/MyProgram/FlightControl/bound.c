#include <stdint.h>

#include "bound.h"

void bound_float(float *number, float max, float min)
{
	if(*number > max) *number = max;
	else if(*number < min) *number = min;
}

void bound_int16(int16_t *number, int16_t max, int16_t min)
{
	if(*number > max) *number = max;
	else if(*number < min) *number = min;
}

void bound_uint16(uint16_t *number, uint16_t max, uint16_t min)
{
	if(*number > max) *number = max;
	else if(*number < min) *number = min;
}

void bound_int32(int32_t *number, int32_t max, int32_t min)
{
	if(*number > max) *number = max;
	else if(*number < min) *number = min;
}

void bound_uint32(uint32_t *number, uint32_t max, uint32_t min)
{
	if(*number > max) *number = max;
	else if(*number < min) *number = min;
}
