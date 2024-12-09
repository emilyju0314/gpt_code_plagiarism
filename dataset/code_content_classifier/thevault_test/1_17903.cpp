TEST(time_optimal_trajectory_generation, test_custom_limits)
{
  constexpr auto robot_name{ "panda" };
  constexpr auto group_name{ "panda_arm" };

  auto robot_model = moveit::core::loadTestingRobotModel(robot_name);
  ASSERT_TRUE((bool)robot_model) << "Failed to load robot model" << robot_name;
  auto group = robot_model->getJointModelGroup(group_name);
  ASSERT_TRUE((bool)group) << "Failed to load joint model group " << group_name;
  moveit::core::RobotState waypoint_state(robot_model);
  waypoint_state.setToDefaultValues();

  const double delta_t = 0.1;
  robot_trajectory::RobotTrajectory trajectory(robot_model, group);
  waypoint_state.setJointGroupPositions(group, std::vector<double>{ -0.5, -3.52, 1.35, -2.51, -0.88, 0.63, 0.0 });
  trajectory.addSuffixWayPoint(waypoint_state, delta_t);
  waypoint_state.setJointGroupPositions(group, std::vector<double>{ -0.45, -3.2, 1.2, -2.4, -0.8, 0.6, 0.0 });
  trajectory.addSuffixWayPoint(waypoint_state, delta_t);

  TimeOptimalTrajectoryGeneration totg;
  // Custom velocity & acceleration limits for some joints
  std::unordered_map<std::string, double> vel_limits{ { "panda_joint1", 1.3 } };
  std::unordered_map<std::string, double> accel_limits{ { "panda_joint2", 2.3 }, { "panda_joint3", 3.3 } };
  ASSERT_TRUE(totg.computeTimeStamps(trajectory, vel_limits, accel_limits)) << "Failed to compute time stamps";
}