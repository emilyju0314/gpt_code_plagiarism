TEST_F(NetworkCongestionAnalyzerTest, TestComputeQueueingDelayLevel) {
  TestNetworkQualityEstimator network_quality_estimator;
  base::SimpleTestTickClock tick_clock;
  NetworkCongestionAnalyzer analyzer(&network_quality_estimator, &tick_clock);

  std::vector<std::pair<base::TimeDelta, size_t>> queueing_delay_level_samples =
      {std::make_pair(base::TimeDelta::FromMilliseconds(0), 1),
       std::make_pair(base::TimeDelta::FromMilliseconds(25), 1),
       std::make_pair(base::TimeDelta::FromMilliseconds(35), 2),
       std::make_pair(base::TimeDelta::FromMilliseconds(55), 2),
       std::make_pair(base::TimeDelta::FromMilliseconds(65), 3),
       std::make_pair(base::TimeDelta::FromMilliseconds(115), 3),
       std::make_pair(base::TimeDelta::FromMilliseconds(125), 4),
       std::make_pair(base::TimeDelta::FromMilliseconds(245), 4),
       std::make_pair(base::TimeDelta::FromMilliseconds(255), 5),
       std::make_pair(base::TimeDelta::FromMilliseconds(495), 5),
       std::make_pair(base::TimeDelta::FromMilliseconds(505), 6),
       std::make_pair(base::TimeDelta::FromMilliseconds(995), 6),
       std::make_pair(base::TimeDelta::FromMilliseconds(1005), 7),
       std::make_pair(base::TimeDelta::FromMilliseconds(1995), 7),
       std::make_pair(base::TimeDelta::FromMilliseconds(2005), 8),
       std::make_pair(base::TimeDelta::FromMilliseconds(3995), 8),
       std::make_pair(base::TimeDelta::FromMilliseconds(4005), 9),
       std::make_pair(base::TimeDelta::FromMilliseconds(7995), 9),
       std::make_pair(base::TimeDelta::FromMilliseconds(8005), 10),
       std::make_pair(base::TimeDelta::FromMilliseconds(20000), 10)};

  // Checks that all queueing delay samples are correctly mapped to
  // their corresponding levels.
  for (const auto& sample : queueing_delay_level_samples) {
    EXPECT_EQ(sample.second,
              analyzer.ComputePeakQueueingDelayLevel(sample.first));
  }
}