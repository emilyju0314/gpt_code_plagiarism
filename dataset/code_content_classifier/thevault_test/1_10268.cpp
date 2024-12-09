void publish_mag(std_msgs::Header &header, Eigen::Vector3d &mag_field)
	{
		auto magn_msg = boost::make_shared<sensor_msgs::MagneticField>();

		// Fill message header
		magn_msg->header = header;

		tf::vectorEigenToMsg(mag_field, magn_msg->magnetic_field);
		magn_msg->magnetic_field_covariance = magnetic_cov;

		// Publish message [ENU frame]
		magn_pub.publish(magn_msg);
	}