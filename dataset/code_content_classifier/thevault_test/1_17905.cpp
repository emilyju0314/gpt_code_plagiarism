TEST_F(HybridPlanningFixture, ActionAbortion)
{
  std::thread run_thread([this]() {
    // Send the goal
    auto goal_handle_future = hp_action_client_->async_send_goal(goal_action_request_, send_goal_options_);

    // Cancel the goal
    hp_action_client_->async_cancel_all_goals();
  });

  rclcpp::Rate rate(10);
  while (!action_complete_)
  {
    executor_.spin_once();
    rate.sleep();
  }
  run_thread.join();
  ASSERT_FALSE(action_successful_);
  ASSERT_TRUE(action_aborted_);
}