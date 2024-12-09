void connection_cb(bool connected) override
	{
		has_hr_imu = false;
		has_scaled_imu = false;
		has_att_quat = false;
	}