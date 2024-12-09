TEST_F(DelayQueueSmallUnitTest, AddTaskInReverseSequenceMultiThread) {
  const int num_tasks(100);
  std::vector<std::future<int>> task_future(num_tasks);
  std::vector<std::thread> threads;
  
  // Insert each task by a separate thread
  for (int i = 0; i < num_tasks; i++) {
    threads.push_back(std::thread( [i, this, &task_future] () {
      task_future[i] =  this->delay_queue_.AddTask(
                            (num_tasks - i) * 200, 
                            std::bind(&DelayQueueSmallUnitTest::add, 
                                this, i, i + 1));

      EXPECT_EQ(task_future[i].get(), 2 * i + 1);
    }));
  }

  // Join the threads
  for (auto& t : threads) {
    t.join();
  }
  threads.clear();

  // Check that the results are showing up in sequence in int_res_queue_
  for (int i = num_tasks - 1; i >= 0; i--) {
    int val;
    EXPECT_TRUE(int_res_queue_.TryPop(val));
    EXPECT_EQ(val, 2 * i + 1);
  }
  EXPECT_TRUE(int_res_queue_.Empty());
}