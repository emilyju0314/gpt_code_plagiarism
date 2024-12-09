void send_position_target(const ros::Time &stamp, const Eigen::Affine3d &tr)
	{
		using mavlink::common::MAV_FRAME;

		/* Documentation start from bit 1 instead 0;
		 * Ignore velocity and accel vectors, yaw rate.
		 *
		 * In past versions on PX4 there been bug described in #273.
		 * If you got similar issue please try update firmware first.
		 */
		const uint16_t ignore_all_except_xyz_y = (1 << 11) | (7 << 6) | (7 << 3);

		auto p = [&] () {
				if (static_cast<MAV_FRAME>(mav_frame) == MAV_FRAME::BODY_NED || static_cast<MAV_FRAME>(mav_frame) == MAV_FRAME::BODY_OFFSET_NED) {
					return ftf::transform_frame_baselink_aircraft(Eigen::Vector3d(tr.translation()));
				} else {
					return ftf::transform_frame_enu_ned(Eigen::Vector3d(tr.translation()));
				}
			} ();

		auto q = [&] () {
				if (mav_frame == MAV_FRAME::BODY_NED || mav_frame == MAV_FRAME::BODY_OFFSET_NED) {
					return ftf::transform_orientation_baselink_aircraft(Eigen::Quaterniond(tr.rotation()));
				} else {
					return ftf::transform_orientation_enu_ned(
						ftf::transform_orientation_baselink_aircraft(Eigen::Quaterniond(tr.rotation())));
				}
			} ();

		set_position_target_local_ned(stamp.toNSec() / 1000000,
			utils::enum_value(mav_frame),
			ignore_all_except_xyz_y,
			p,
			Eigen::Vector3d::Zero(),
			Eigen::Vector3d::Zero(),
			ftf::quaternion_get_yaw(q), 0.0);
	}