inline
geometry_msgs::msg::PointStamped toMsg(const tf2::Stamped<btVector3> & in)
{
  geometry_msgs::msg::PointStamped msg;
  msg.header.stamp = tf2_ros::toMsg(in.stamp_);
  msg.header.frame_id = in.frame_id_;
  msg.point.x = in[0];
  msg.point.y = in[1];
  msg.point.z = in[2];
  return msg;
}