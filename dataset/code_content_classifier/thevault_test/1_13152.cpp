TEST_F(ThreadSafeQueueUnitTest, BasicCase) {
  ThreadsafeQueue<int> t_queue;
  int num_of_items(100);

  EXPECT_TRUE(t_queue.Empty());
  for (int i = 0; i < num_of_items; i++) {
    t_queue.Push(i);
  }

  for (int i = 0; i < num_of_items; i++) {
    int val;
    EXPECT_TRUE(t_queue.TryPop(val));
    EXPECT_EQ(val, i);
  }
}