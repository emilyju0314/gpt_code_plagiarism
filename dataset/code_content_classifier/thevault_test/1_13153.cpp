TEST_F(DelayQueueFloodUnitTest, ManyTasksSameDelayTime) {
  int num_tasks(10);
  int num_tasks_per_thread(10000);
  uint64_t delay(100);
  std::vector<std::thread> threads;

  for (int i = 0; i < num_tasks; i++) {
    threads.push_back(std::thread( [i, delay, num_tasks_per_thread, this] () {
      std::vector<std::future<int>> task_futures;
      for (int j = 0; j < num_tasks_per_thread; j++) {
        task_futures.push_back(
            this->delay_queue_.AddTask(delay, std::bind(&foo, i, i+1)));
      }

      for (auto& task_future : task_futures) {
        EXPECT_EQ(task_future.get(), 2 * i + 1);
      }
    }));
  }

  for (auto& th : threads) {
    th.join();
  }
  threads.clear();
}