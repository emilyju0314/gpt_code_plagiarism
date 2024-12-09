TEST_F(ThreadPoolUnitTest, SingleTask) {
  std::future<int> add_future = threadpool_.Submit(std::bind(test_add, 1, 1));
  int res = add_future.get();
  EXPECT_EQ(res, 2);
}