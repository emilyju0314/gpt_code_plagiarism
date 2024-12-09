void calibrate() {
	for (int i = 0; i < 6; i++) {
		calibration_params[i] = 0;
	}

	mpu6050_t buf;
	int32_t motion_buffers[6] = {0, 0, 0, 0, 0, 0};
	for (int i = 0; i < (1 << I2C_ACC_CALIBRATION_SCALE + 1); i++) {
		buf = read();

		// Dismissed first half and use only second half.
		if (i >= (1 << I2C_ACC_CALIBRATION_SCALE)) {
			motion_buffers[0] += buf.acc_x;
			motion_buffers[1] += buf.acc_y;
			motion_buffers[2] += buf.acc_z;
			motion_buffers[3] += buf.gyro_x;
			motion_buffers[4] += buf.gyro_y;
			motion_buffers[5] += buf.gyro_z;
		}
		_delay_us(200);
	}

	for (int i = 0; i < 6; i++) {
		calibration_params[i] = - (motion_buffers[i] >> I2C_ACC_CALIBRATION_SCALE);
	}
	calibration_params[2] += 4096; // for acc_z => value must +1.00g
}