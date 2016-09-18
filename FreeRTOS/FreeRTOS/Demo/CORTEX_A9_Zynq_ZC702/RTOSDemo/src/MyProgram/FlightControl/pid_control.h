#ifndef __PID_CONTROL_H
#define __PID_CONTROL_H

typedef struct {
	/* PID parameter */
	float kp;
	float ki;
	float kd;
	/* Error */
	float error_current;
	float error_last;
	float error_integral;
	float error_derivative;
	/* Output */
	float output;
	float output_max;
	float output_min;
} pid_control_t;

#endif
