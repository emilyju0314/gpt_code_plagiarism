auto Uav::joy_callback(sensor_msgs::msg::Joy::UniquePtr joy_message) -> void {
  double x_axis = joy_message->axes[config_.x_axis];
  double y_axis = joy_message->axes[config_.y_axis];
  double z_plus_axis = joy_message->axes[config_.z_plus_axis];
  double z_minus_axis = joy_message->axes[config_.z_minus_axis];
  double steering_axis = joy_message->axes[config_.steering_axis];
  double trigger_deadzone = config_.trigger_deadzone;
  double joystick_deadzone = config_.joystick_deadzone;

  // Scale Input Points outside of the deadzone
  x_axis = std::round(helper::scale_with_deadzone(joystick_deadzone, x_axis));
  y_axis = std::round(helper::scale_with_deadzone(joystick_deadzone, y_axis));
  steering_axis =
      std::round(helper::scale_with_deadzone(joystick_deadzone, steering_axis));
  z_plus_axis =
      std::round(helper::scale_with_deadzone(trigger_deadzone, z_plus_axis));
  z_minus_axis =
      std::round(helper::scale_with_deadzone(trigger_deadzone, z_minus_axis));

  double scale_factor = 20;

  velocity_->twist.linear.x = scale_factor * (x_axis);
  velocity_->twist.linear.y = scale_factor * (-y_axis);
  velocity_->twist.linear.z = scale_factor * (z_minus_axis - z_plus_axis);
  velocity_->twist.angular.z =
      helper::pi / (2 * scale_factor) * (steering_axis);
  velocity_->header.stamp = rclcpp::Node::now();
}