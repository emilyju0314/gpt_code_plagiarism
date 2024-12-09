bool moveToCartPose(const geometry_msgs::PoseStamped& pose, moveit::planning_interface::MoveGroupInterface& group,
                    const std::string& end_effector_link)
{
  group.clearPoseTargets();
  group.setEndEffectorLink(end_effector_link);
  group.setStartStateToCurrentState();
  group.setPoseTarget(pose);

  moveit::planning_interface::MoveGroupInterface::Plan myplan;
  if (group.plan(myplan) && group.execute(myplan))
  {
    return true;
  }

  ROS_WARN("Failed to perform motion.");
  return false;
}