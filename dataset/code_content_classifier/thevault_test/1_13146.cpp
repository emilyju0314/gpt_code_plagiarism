TEST_F(SemaphoreUnitTest, InitCountAsOneAndOneWaitAndOneNotify) {
  Semaphore semaphore;
  for (int i = 0; i < 100; i++) {
    auto producer_thread(std::thread([&semaphore] () { semaphore.Notify(); }));
    auto consumer_thread(std::thread([&semaphore] () { semaphore.Wait(); }));
    // We expect both threads to complete so join should return successfully
    producer_thread.join();
    consumer_thread.join();
  }
}