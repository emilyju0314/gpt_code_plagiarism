void publish_imu_data(uint32_t time_boot_ms, Eigen::Quaterniond &orientation_enu,
				Eigen::Quaterniond &orientation_ned, Eigen::Vector3d &gyro_flu, Eigen::Vector3d &gyro_frd)
	{
		auto imu_ned_msg = boost::make_shared<sensor_msgs::Imu>();
		auto imu_enu_msg = boost::make_shared<sensor_msgs::Imu>();

		// Fill message header
		imu_enu_msg->header = m_uas->synchronized_header(frame_id, time_boot_ms);
		imu_ned_msg->header = m_uas->synchronized_header("aircraft", time_boot_ms);

		// Convert from Eigen::Quaternond to geometry_msgs::Quaternion
		tf::quaternionEigenToMsg(orientation_enu, imu_enu_msg->orientation);
		tf::quaternionEigenToMsg(orientation_ned, imu_ned_msg->orientation);

		// Convert from Eigen::Vector3d to geometry_msgs::Vector3
		tf::vectorEigenToMsg(gyro_flu, imu_enu_msg->angular_velocity);
		tf::vectorEigenToMsg(gyro_frd, imu_ned_msg->angular_velocity);

		// Eigen::Vector3d from HIGHRES_IMU or RAW_IMU, to geometry_msgs::Vector3
		tf::vectorEigenToMsg(linear_accel_vec_flu, imu_enu_msg->linear_acceleration);
		tf::vectorEigenToMsg(linear_accel_vec_frd, imu_ned_msg->linear_acceleration);

		// Pass ENU msg covariances
		imu_enu_msg->orientation_covariance = orientation_cov;
		imu_enu_msg->angular_velocity_covariance = angular_velocity_cov;
		imu_enu_msg->linear_acceleration_covariance = linear_acceleration_cov;

		// Pass NED msg covariances
		imu_ned_msg->orientation_covariance = orientation_cov;
		imu_ned_msg->angular_velocity_covariance = angular_velocity_cov;
		imu_ned_msg->linear_acceleration_covariance = linear_acceleration_cov;

		if (!received_linear_accel) {
			// Set element 0 of covariance matrix to -1 if no data received as per sensor_msgs/Imu defintion
			imu_enu_msg->linear_acceleration_covariance[0] = -1;
			imu_ned_msg->linear_acceleration_covariance[0] = -1;
		}

		/** Store attitude in base_link ENU
		 *  @snippet src/plugins/imu.cpp store_enu
		 */
		// [store_enu]
		m_uas->update_attitude_imu_enu(imu_enu_msg);
		// [store_enu]

		/** Store attitude in aircraft NED
		 *  @snippet src/plugins/imu.cpp store_ned
		 */
		// [store_enu]
		m_uas->update_attitude_imu_ned(imu_ned_msg);
		// [store_ned]

		/** Publish only base_link ENU message
		 *  @snippet src/plugins/imu.cpp pub_enu
		 */
		// [pub_enu]
		imu_pub.publish(imu_enu_msg);
		// [pub_enu]
	}