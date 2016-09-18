#ifndef __VECTOR_SPACE_H
#define __VECTOR_SPACE_H

#include "stdint.h"

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
} vector3d_16_t;

typedef struct {
	float x;
	float y;
	float z;
} vector3d_f_t;

#endif
