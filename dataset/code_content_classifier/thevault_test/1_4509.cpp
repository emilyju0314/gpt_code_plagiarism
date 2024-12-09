inline
void fromMsg(const geometry_msgs::msg::PointStamped & msg, tf2::Stamped<btVector3> & out)
{
  out.stamp_ = tf2_ros::fromMsg(msg.header.stamp);
  out.frame_id_ = msg.header.frame_id;
  out[0] = static_cast<float>(msg.point.x);
  out[1] = static_cast<float>(msg.point.y);
  out[2] = static_cast<float>(msg.point.z);
}