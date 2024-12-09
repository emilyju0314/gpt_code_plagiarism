TEST_F(SemaphoreUnitTest, InitCountAsTenWithTwentyConsumers) {
  Semaphore semaphore(10);
  std::atomic<int> timeouts{0};
  auto const wait_duration = std::chrono::milliseconds(1000);
  std::vector<std::thread> threads;

  for (int i = 0; i < 20; i++) {
    threads.push_back(std::thread([&semaphore, &wait_duration, &timeouts] () {
      auto now = std::chrono::high_resolution_clock::now();
      auto wait_result = semaphore.WaitUntil(now + wait_duration);
      // Increment the timeouts counter if a consumer thread times out on wait
      if (!wait_result) {
        timeouts++;
      }
    }));
  }

  // Join the threads and clear the placeholder for threads
  for (auto& t : threads) {
    t.join();
  }
  threads.clear();

  EXPECT_EQ(timeouts.load(), 10);
}