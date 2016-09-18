#include <math.h>

#include "vector_space.h"
#include "ahrs.h"

#define deg_to_rad(angle) angle * 0.0174532925 //Angle * (PI / 180)
#define rad_to_deg(radian) radian * 57.2957795 //Radian * (180 / PI)

void accel_estimate_euler_angle(attitude_t *attitude, vector3d_f_t accel_scaled_data)
{
	/* Acceleration boundary (Just need 1g for estimate the euler angle), cut off the
	   non-gravity acceleration */
	if(accel_scaled_data.x > 1.0) accel_scaled_data.x = 1.0;
	if(accel_scaled_data.y > 1.0) accel_scaled_data.y = 1.0;
	if(accel_scaled_data.z > 1.0) accel_scaled_data.z = 1.0;
	if(accel_scaled_data.x < -1.0) accel_scaled_data.x = -1.0;
	if(accel_scaled_data.y < -1.0) accel_scaled_data.y = -1.0;
	if(accel_scaled_data.z < -1.0) accel_scaled_data.z = -1.0;

	/* Calculate the vector magnitude  */
	float magnitude = sqrtf(accel_scaled_data.x * accel_scaled_data.x +
		accel_scaled_data.y * accel_scaled_data.y +
		accel_scaled_data.z * accel_scaled_data.z);

	/* Normalize the data (unit vector) */
	float normalized_x = accel_scaled_data.x / magnitude;
	float normalized_y = accel_scaled_data.y / magnitude;
	float normalized_z = accel_scaled_data.z / magnitude;

	//roll = arctan(-y / z)
	attitude->roll_angle = rad_to_deg(atan(-normalized_y / normalized_z));
	//pitch = arctan(x / z)
	attitude->pitch_angle = rad_to_deg(atan(normalized_x / normalized_z));
	//Accelerometer can't measure the yaw angle
	attitude->yaw_angle = 0;
}

void gyro_integrate(attitude_t *attitude, vector3d_f_t gyro_scaled_data,
	float period_time)
{
	/* Convert the body frame(sensor frame) back to the inertial frame */
	vector3d_f_t iframe_gyro;


	//x' = cos(pitch)x - sin(pitch)z
	iframe_gyro.x =
		cos(deg_to_rad(attitude->pitch_angle)) * gyro_scaled_data.x -
		sin(deg_to_rad(attitude->pitch_angle)) * gyro_scaled_data.z;
	//y' = sin(pitch)tan(roll)x + y + cos(pitch)tan(roll)z
	iframe_gyro.y =
		sin(deg_to_rad(attitude->pitch_angle)) * tan(deg_to_rad(attitude->roll_angle)) * gyro_scaled_data.x +
		gyro_scaled_data.y +
		cos(deg_to_rad(attitude->pitch_angle)) * tan(deg_to_rad(attitude->roll_angle)) * gyro_scaled_data.z;
	//z' = sec(roll)sin(pitch)x + cos(pitch)sec(roll)z
	iframe_gyro.z =
		(1 / cos(deg_to_rad(attitude->roll_angle))) * sin(deg_to_rad(attitude->pitch_angle)) *  gyro_scaled_data.x +
		cos(deg_to_rad(attitude->pitch_angle)) * (1 / cos(deg_to_rad(attitude->roll_angle))) * gyro_scaled_data.z;

	/* Intergrate the angle velocity */
	attitude->roll_angle -= iframe_gyro.x * period_time;
	attitude->pitch_angle -= iframe_gyro.y * period_time;
	attitude->yaw_angle -= iframe_gyro.z * period_time;
}

float mag_estimate_yaw_angle(attitude_t reference_attitude, vector3d_f_t mag_scaled_data)
{
	float yaw_angle;

	/* Unite the coordinate system  */
	mag_scaled_data.x = -mag_scaled_data.x;
	mag_scaled_data.y = -mag_scaled_data.y;
	mag_scaled_data.z = -mag_scaled_data.z;

	/* Convert the body frame back to the inertial frame */
	vector3d_f_t iframe_mag;

	//x' = cos(pitch_angle)x + cos(roll_angle)sin(pitch_angle)z + sin(pitch_angle)sin(roll_angle)y
	iframe_mag.x =
		cos(deg_to_rad(reference_attitude.pitch_angle)) * mag_scaled_data.x +
			cos(deg_to_rad(reference_attitude.roll_angle)) *
			sin(deg_to_rad(reference_attitude.pitch_angle)) * mag_scaled_data.z +
		sin(deg_to_rad(reference_attitude.pitch_angle)) *
			sin(deg_to_rad(reference_attitude.roll_angle)) * mag_scaled_data.y;
	//y' = cos(roll_angle)y - sin(roll_angle)z
	iframe_mag.y =
		cos(deg_to_rad(reference_attitude.roll_angle)) * mag_scaled_data.y -
		sin(deg_to_rad(reference_attitude.roll_angle)) * mag_scaled_data.z;

	//z' = cos(pitch_angle)cos(roll_angle)z - sin(pitch_angle)x + cos(pitch_angle)sin(roll_angle)y

	//yaw = arctan(-y / x)
	yaw_angle = rad_to_deg(atan2(-iframe_mag.y, iframe_mag.x));

	//General angle of trigonometry (Degree range: 0 ~ 360)
	if(yaw_angle < 0) yaw_angle += 360;

	return yaw_angle;
}

float alpha_roll, alpha_pitch;

void gyro_error_eliminate(attitude_t *gyro_attitude, attitude_t accel_attitude, float error_const,
	vector3d_f_t accel_scaled_data, float accel_svm_const)
{
	//float alpha_roll, alpha_pitch;
	float beta;

        /* Acceleration boundary (Just need 1g for estimate the euler angle), cut off the
           non-gravity acceleration */
        if(accel_scaled_data.x > 1.0) accel_scaled_data.x = 1.0;
        if(accel_scaled_data.y > 1.0) accel_scaled_data.y = 1.0;
        if(accel_scaled_data.z > 1.0) accel_scaled_data.z = 1.0;
        if(accel_scaled_data.x < -1.0) accel_scaled_data.x = -1.0;
        if(accel_scaled_data.y < -1.0) accel_scaled_data.y = -1.0;
        if(accel_scaled_data.z < -1.0) accel_scaled_data.z = -1.0;

	/* Use SVM(Signal Vector Magnitude) to determine the reliablilty of accelerometer */
	float accel_sma_value = sqrtf(accel_scaled_data.x * accel_scaled_data.x +
		accel_scaled_data.y * accel_scaled_data.y +
		accel_scaled_data.z * accel_scaled_data.z);

	//beta = accel_svm_const / accel_sma_value
	if(accel_sma_value < 1)
		beta = 1;
	else
		beta = accel_svm_const / (accel_svm_const + (accel_sma_value - 1));

	//alpha = (error_const / error_const + error) * beta
	alpha_roll =
		(error_const / (error_const + fabs(accel_attitude.roll_angle - gyro_attitude->roll_angle))) * beta;
	alpha_pitch =
		(error_const / (error_const + fabs(accel_attitude.pitch_angle - gyro_attitude->pitch_angle))) * beta;

	//Complementry filter
	gyro_attitude->roll_angle =
		(alpha_roll * accel_attitude.roll_angle) + ((1 - alpha_roll) * gyro_attitude->roll_angle);
	gyro_attitude->pitch_angle =
		(alpha_pitch * accel_attitude.pitch_angle) + ((1 - alpha_pitch) * gyro_attitude->pitch_angle);
}
