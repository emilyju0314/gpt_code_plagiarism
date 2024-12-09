TEST_F(NetworkCongestionAnalyzerTest, TestUpdatePeakDelayMapping) {
  TestNetworkQualityEstimator network_quality_estimator;
  base::SimpleTestTickClock tick_clock;

  network_quality_estimator.set_effective_connection_type(
      EFFECTIVE_CONNECTION_TYPE_2G);
  NetworkCongestionAnalyzer analyzer(&network_quality_estimator, &tick_clock);
  EXPECT_EQ(base::nullopt,
            analyzer.count_inflight_requests_causing_high_delay());

  // Checks that the count of in-flight requests for peak queueing delay is
  // correctly recorded.
  // Case #1: the peak queueing delay was observed after the max count (7) of
  // in-flight requests was observed.
  const size_t expected_count_requests_1 = 7;
  std::vector<std::pair<base::TimeDelta, size_t>> queueing_delay_samples_1 = {
      std::make_pair(base::TimeDelta::FromMilliseconds(10), 1),
      std::make_pair(base::TimeDelta::FromMilliseconds(10), 3),
      std::make_pair(base::TimeDelta::FromMilliseconds(400), 5),
      std::make_pair(base::TimeDelta::FromMilliseconds(800),
                     expected_count_requests_1),
      std::make_pair(base::TimeDelta::FromMilliseconds(kHighQueueingDelayMsec),
                     5),
      std::make_pair(base::TimeDelta::FromMilliseconds(1000), 3),
      std::make_pair(base::TimeDelta::FromMilliseconds(700), 3),
      std::make_pair(base::TimeDelta::FromMilliseconds(600), 1),
      std::make_pair(base::TimeDelta::FromMilliseconds(300), 0),
  };
  for (const auto& sample : queueing_delay_samples_1) {
    analyzer.UpdatePeakDelayMapping(sample.first, sample.second);
  }
  EXPECT_EQ(expected_count_requests_1,
            analyzer.count_inflight_requests_causing_high_delay().value_or(0));

  // Case #2: the peak queueing delay is observed before the max count (11) of
  // in-flight requests was observed. The 8 requests should be responsible for
  // the peak queueing delay.
  const size_t expected_count_requests_2 = 10;
  std::vector<std::pair<base::TimeDelta, size_t>> queueing_delay_samples_2 = {
      std::make_pair(base::TimeDelta::FromMilliseconds(10), 1),
      std::make_pair(base::TimeDelta::FromMilliseconds(10), 3),
      std::make_pair(base::TimeDelta::FromMilliseconds(400), 5),
      std::make_pair(base::TimeDelta::FromMilliseconds(800), 5),
      std::make_pair(base::TimeDelta::FromMilliseconds(kHighQueueingDelayMsec),
                     expected_count_requests_2),
      std::make_pair(base::TimeDelta::FromMilliseconds(3000), 11),
      std::make_pair(base::TimeDelta::FromMilliseconds(700), 3),
      std::make_pair(base::TimeDelta::FromMilliseconds(600), 1),
      std::make_pair(base::TimeDelta::FromMilliseconds(300), 0),
  };
  for (const auto& sample : queueing_delay_samples_2) {
    analyzer.UpdatePeakDelayMapping(sample.first, sample.second);
  }
  EXPECT_EQ(expected_count_requests_2,
            analyzer.count_inflight_requests_causing_high_delay().value_or(0));
}