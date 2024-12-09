bool EBandPlanner::interpolateBubbles(geometry_msgs::PoseStamped start_center, geometry_msgs::PoseStamped end_center, geometry_msgs::PoseStamped& interpolated_center)
  {
    // check if plugin initialized
    if(!initialized_)
    {
      ROS_ERROR("This planner has not been initialized, please call initialize() before using this planner");
      return false;
    }

    // instantiate local variables
    geometry_msgs::Pose2D start_pose2D, end_pose2D, interpolated_pose2D;
    double delta_theta;

    // copy header
    interpolated_center.header = start_center.header;

    // interpolate angles
    // TODO make this in a better way
    // - for instance use "slerp" to interpolate directly between quaternions
    // - or work with pose2D right from the beginnning
    // convert quaternions to euler angles - at this point this no longer works in 3D !!
    PoseToPose2D(start_center.pose, start_pose2D);
    PoseToPose2D(end_center.pose, end_pose2D);
    // calc mean of theta angle
    delta_theta = end_pose2D.theta - start_pose2D.theta;
    delta_theta = angles::normalize_angle(delta_theta) / 2.0;
    interpolated_pose2D.theta = start_pose2D.theta + delta_theta;
    interpolated_pose2D.theta = angles::normalize_angle(interpolated_pose2D.theta);
    // convert back to quaternion
    interpolated_pose2D.x = 0.0;
    interpolated_pose2D.y = 0.0;
    Pose2DToPose(interpolated_center.pose, interpolated_pose2D);

    // interpolate positions
    interpolated_center.pose.position.x = (end_center.pose.position.x + start_center.pose.position.x)/2.0;
    interpolated_center.pose.position.y = (end_center.pose.position.y + start_center.pose.position.y)/2.0;
    interpolated_center.pose.position.z = (end_center.pose.position.z + start_center.pose.position.z)/2.0;

    // TODO ideally this would take into account kinematics of the robot and for instance use splines

    return true;
  }