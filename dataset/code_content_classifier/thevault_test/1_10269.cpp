void handle_attitude(const mavlink::mavlink_message_t *msg, mavlink::common::msg::ATTITUDE &att)
	{
		if (has_att_quat)
			return;

		/** Orientation on the NED-aicraft frame:
		 *  @snippet src/plugins/imu.cpp ned_aircraft_orient1
		 */
		// [ned_aircraft_orient1]
		auto ned_aircraft_orientation = ftf::quaternion_from_rpy(att.roll, att.pitch, att.yaw);
		// [ned_aircraft_orient1]

		/** Angular velocity on the NED-aicraft frame:
		 *  @snippet src/plugins/imu.cpp ned_ang_vel1
		 */
		// [frd_ang_vel1]
		auto gyro_frd = Eigen::Vector3d(att.rollspeed, att.pitchspeed, att.yawspeed);
		// [frd_ang_vel1]

		/** The RPY describes the rotation: aircraft->NED.
		 *  It is required to change this to aircraft->base_link:
		 *  @snippet src/plugins/imu.cpp ned->baselink->enu
		 */
		// [ned->baselink->enu]
		auto enu_baselink_orientation = ftf::transform_orientation_aircraft_baselink(
					ftf::transform_orientation_ned_enu(ned_aircraft_orientation));
		// [ned->baselink->enu]

		/** The angular velocity expressed in the aircraft frame.
		 *  It is required to apply the static rotation to get it into the base_link frame:
		 *  @snippet src/plugins/imu.cpp rotate_gyro
		 */
		// [rotate_gyro]
		auto gyro_flu = ftf::transform_frame_aircraft_baselink(gyro_frd);
		// [rotate_gyro]

		publish_imu_data(att.time_boot_ms, enu_baselink_orientation, ned_aircraft_orientation, gyro_flu, gyro_frd);
	}