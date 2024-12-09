TEST_F(NetworkCongestionAnalyzerTest, TestStartingNewMeasurementPeriod) {
  TestNetworkQualityEstimator network_quality_estimator;
  base::SimpleTestTickClock tick_clock;

  network_quality_estimator.set_effective_connection_type(
      EFFECTIVE_CONNECTION_TYPE_2G);
  NetworkCongestionAnalyzer analyzer(&network_quality_estimator, &tick_clock);
  base::TimeDelta low_queueing_delay_sample =
      kLowQueueingDelayThresholds[EFFECTIVE_CONNECTION_TYPE_2G];

  // Checks that a new measurement period starts immediately if the queueing
  // delay is low and the number of in-flight requests are equal or less than 1.
  EXPECT_FALSE(
      analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 2));
  EXPECT_TRUE(analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 1));
  EXPECT_TRUE(analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 0));

  // Checks that a new measurement period starts after waiting for a sufficient
  // time interval when the number of in-flight requests is 2.
  EXPECT_FALSE(
      analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 2));
  tick_clock.Advance(
      base::TimeDelta::FromMilliseconds(kMinEmptyQueueObservingTimeMsec / 2));
  EXPECT_FALSE(
      analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 2));
  tick_clock.Advance(
      base::TimeDelta::FromMilliseconds(kMinEmptyQueueObservingTimeMsec / 2));
  EXPECT_TRUE(analyzer.ShouldStartNewMeasurement(low_queueing_delay_sample, 2));
}