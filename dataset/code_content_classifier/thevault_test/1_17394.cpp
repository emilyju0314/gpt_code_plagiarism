auto Uav::pose_callback() -> void {
  // Connection Error if we have not communicated with the controller in 10
  // seconds
  if (velocity_->header.stamp.sec == 0) return;
  double last_message_diff =
      (rclcpp::Node::now().seconds() - velocity_->header.stamp.sec);
  if (last_message_diff >= 10) {
    std::cout << "Connection Lost ... Please Reconnect Controller" << std::endl;
    // Set the time back to zero so that we don't get message spam
    velocity_->header.stamp.sec = 0;
    return;
  }

  // Spin the rotors
  for (unsigned int i = 0; i < rotors.size(); i++) {
    auto const new_heading = shapelist_z_ / 100;
    auto const new_heading_q =
        tf2::Quaternion(tf2::Vector3(0, 0, 1), new_heading);

    tf2::Quaternion q_original;
    tf2::fromMsg((rotors[i].get()).pose.orientation, q_original);

    tf2::Quaternion q_new = new_heading_q * q_original;
    (rotors[i].get()).pose.orientation = tf2::toMsg(q_new);
  }

  // Timer is called every 100ms = 0.1s
  double dt = 0.1;

  // Change Velocity of Uav if needed
  double scale_factor = 1;

  // Move shape to appropriate location
  move_by(XAxis{dt * scale_factor * velocity_->twist.linear.x},
          YAxis{dt * scale_factor * velocity_->twist.linear.y},
          ZAxis{dt * scale_factor * velocity_->twist.linear.z});

  // Check for collisions
  move_to(XAxis{helper::bound_value(shapelist_x_, config_.side_bound,
                                    -config_.side_bound)},
          YAxis{helper::bound_value(shapelist_y_, config_.side_bound,
                                    -config_.side_bound)},
          ZAxis{helper::bound_value(shapelist_z_, config_.ceiling_bound,
                                    config_.floor_bound)});

  // Limit the Uav's movement based off config bounds
  shapelist_x_ = helper::bound_value(shapelist_x_, config_.side_bound,
                                     -config_.side_bound);
  shapelist_y_ = helper::bound_value(shapelist_y_, config_.side_bound,
                                     -config_.side_bound);
  shapelist_z_ = helper::bound_value(shapelist_z_, config_.ceiling_bound,
                                     config_.floor_bound);

  // Spin UAV based on trigger
  rotate_about_axis_to(
      ZAxis(get_orientation().get_value() + velocity_->twist.angular.z));
}