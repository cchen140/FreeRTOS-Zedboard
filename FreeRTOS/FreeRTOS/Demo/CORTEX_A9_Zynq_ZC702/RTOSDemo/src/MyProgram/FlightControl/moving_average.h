#ifndef __MOVING_AVERAGE_H
#define __MOVING_AVERAGE_H

void vector3d_simple_moving_average(vector3d_f_t new_sampling_data, vector3d_f_t *data_fifo,
	vector3d_f_t *data_result, int sampling_count);
void vector3d_weight_moving_average(vector3d_f_t new_sampling_data, vector3d_f_t *data_fifo,
	vector3d_f_t *data_result, int sampling_count);
void vector3d_exponential_moving_average(vector3d_f_t new_sampling_data, vector3d_f_t *last_ema_data,
	vector3d_f_t *data_result, float alpha);

#endif
