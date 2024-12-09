TEST_F(HybridPlanningFixture, ActionCompletion)
{
  std::thread run_thread([this]() {
    // Send the goal
    auto goal_handle_future = hp_action_client_->async_send_goal(goal_action_request_, send_goal_options_);
  });

  rclcpp::Rate rate(10);
  while (!action_complete_)
  {
    executor_.spin_once();
    rate.sleep();
  }
  run_thread.join();
  ASSERT_TRUE(action_successful_);
}