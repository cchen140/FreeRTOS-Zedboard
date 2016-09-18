#ifndef __AHRS_H
#define __AHRS_H

#include "vector_space.h"

/* IMU management structure */
typedef struct {
	vector3d_16_t accel_unscaled_data;
	vector3d_16_t gyro_unscaled_data;
	vector3d_16_t mag_unscaled_data;

	vector3d_f_t accel_raw_data;
	vector3d_f_t gyro_raw_data;
	vector3d_f_t mag_raw_data;

	vector3d_f_t accel_filtered_data;
	vector3d_f_t gyro_filtered_data;
	vector3d_f_t mag_filtered_data;
} imu_data_t;

typedef struct {
	float roll_angle;
	float pitch_angle;
	float yaw_angle;
} attitude_t;

/* AHRS data management structure */
typedef struct {
	attitude_t accel_attitude;
	attitude_t gyro_attitude;
	attitude_t mag_attitude;
	attitude_t fusion_attitude;
} ahrs_data_t;

void accel_estimate_euler_angle(attitude_t *attitude, vector3d_f_t accel_scaled_data);
void gyro_integrate(attitude_t *attitude, vector3d_f_t gyro_scaled_data, float period_time);
float mag_estimate_yaw_angle(attitude_t reference_attitude, vector3d_f_t mag_scaled_data);

void gyro_error_eliminate(attitude_t *gyro_attitude, attitude_t accel_attitude, float error_const,
	vector3d_f_t accel_scaled_data, float acceleration_const);

#endif
