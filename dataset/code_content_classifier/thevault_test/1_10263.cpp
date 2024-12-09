void transform_cb(const geometry_msgs::TransformStamped &transform)
	{
		Eigen::Affine3d tr;
		// TODO: later, when tf2 5.12 will be released need to revisit and replace this to
		// tf2::convert()
		tf::transformMsgToEigen(transform.transform, tr);

		send_position_target(transform.header.stamp, tr);
	}