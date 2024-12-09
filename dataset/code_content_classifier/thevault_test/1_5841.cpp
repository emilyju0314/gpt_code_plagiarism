TEST_F(MultiThreadedMetricsTest, CounterIncrementTest) {
  scoped_refptr<Counter> counter = new Counter(&METRIC_test_counter);
  int num_threads = FLAGS_mt_metrics_test_num_threads;
  int num_increments = 1000;
  boost::function<void()> f =
      boost::bind(CountWithCounter, counter, num_increments);
  RunWithManyThreads(&f, num_threads);
  ASSERT_EQ(num_threads * num_increments, counter->value());
}