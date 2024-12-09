TEST_F(MultiThreadedMetricsTest, AddCounterToRegistryTest) {
  scoped_refptr<MetricEntity> entity = METRIC_ENTITY_test_entity.Instantiate(&registry_, "my-test");
  int num_threads = FLAGS_mt_metrics_test_num_threads;
  int num_counters = 1000;
  boost::function<void()> f =
      boost::bind(RegisterCounters, entity, "prefix", num_counters);
  RunWithManyThreads(&f, num_threads);
  ASSERT_EQ(num_threads * num_counters, entity->UnsafeMetricsMapForTests().size());
}