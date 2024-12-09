TEST_F(SemaphoreUnitTest, InitCountAsZeroAndSingleWaitUntil) {
  Semaphore sempahore;
  // Set the timeout duration to be 1 second
  auto now = std::chrono::high_resolution_clock::now();
  auto wait_duration = std::chrono::milliseconds(1000);
  
  // Because there is only one thread and because the count is initialized as 
  // zero, we expect WaitUntil to timeout and therefore return false
  EXPECT_FALSE(sempahore.WaitUntil(now + wait_duration));
  
  // Just some sanity check on the time that elapses
  auto now2 = std::chrono::high_resolution_clock::now();
  EXPECT_TRUE(now2 - now >= wait_duration);
}