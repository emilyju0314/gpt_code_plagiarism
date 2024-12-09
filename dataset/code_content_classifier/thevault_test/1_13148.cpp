TEST_F(DelayQueueSmallUnitTest, AddTaskInSequence) {
  int num_tasks(10);
  std::vector<std::future<int>> task_future;
  // Insert tasks with different delay
  for (int i = 0; i < num_tasks; i++) {
    task_future.emplace_back(
        delay_queue_.AddTask(i * 200, 
            std::bind(&DelayQueueSmallUnitTest::add, this, i, i + 1)));
  }

  // Wait for tasks to complete 
  for (int i = 0; i < num_tasks; i++) {
    EXPECT_EQ(task_future[i].get(), 2 * i + 1);
  }

  // Check that the results are showing up in sequence in int_res_queue_
  for (int i = 0; i < num_tasks; i++) {
    int val;
    EXPECT_TRUE(int_res_queue_.TryPop(val));
    EXPECT_EQ(val, 2 * i + 1);
  }
  EXPECT_TRUE(int_res_queue_.Empty());
}