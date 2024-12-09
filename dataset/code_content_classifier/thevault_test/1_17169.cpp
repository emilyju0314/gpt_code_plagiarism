TEST_F(NetworkCongestionAnalyzerTest, TestDetectLowQueueingDelay) {
  TestNetworkQualityEstimator network_quality_estimator;
  base::SimpleTestTickClock tick_clock;
  NetworkCongestionAnalyzer analyzer(&network_quality_estimator, &tick_clock);

  // Checks that computations are done correctly under all different ECTs.
  for (int i = 0; i != net::EFFECTIVE_CONNECTION_TYPE_LAST; ++i) {
    auto type = static_cast<net::EffectiveConnectionType>(i);
    network_quality_estimator.set_effective_connection_type(type);
    base::TimeDelta low_queueing_delay = kLowQueueingDelayThresholds[type];

    EXPECT_TRUE(analyzer.IsQueueingDelayLow(low_queueing_delay));
    EXPECT_FALSE(analyzer.IsQueueingDelayLow(
        low_queueing_delay + base::TimeDelta::FromMilliseconds(1)));
  }
}