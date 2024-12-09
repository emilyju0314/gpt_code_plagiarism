TEST_F(DelayQueueTimeCheckUnitTest, SingleTask) {
  Task task(1000); // Delay time 1s
  auto task_future = delay_queue_.AddTask(task.delay_milliseconds_,
                                          std::bind(&Task::run, &task));
  // Wait for the task to complete
  task_future.get();
}