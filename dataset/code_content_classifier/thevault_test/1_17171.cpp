TEST_F(NetworkCongestionAnalyzerTest, TestComputePeakDelayMappingSampleScore) {
  TestNetworkQualityEstimator network_quality_estimator;
  base::SimpleTestTickClock tick_clock;
  NetworkCongestionAnalyzer analyzer(&network_quality_estimator, &tick_clock);

  // Insert these samples into the cache. They are used to evaluate whether a
  // new sample is valid or not.
  std::map<size_t, base::TimeDelta> cached_requests_count_peak_delay_sample = {
      {1, base::TimeDelta::FromMilliseconds(100)},
      {2, base::TimeDelta::FromMilliseconds(200)},
      {3, base::TimeDelta::FromMilliseconds(300)},
      {4, base::TimeDelta::FromMilliseconds(400)},
      {5, base::TimeDelta::FromMilliseconds(500)},
      {6, base::TimeDelta::FromMilliseconds(600)},
      {7, base::TimeDelta::FromMilliseconds(700)},
      {8, base::TimeDelta::FromMilliseconds(800)},
      {9, base::TimeDelta::FromMilliseconds(900)},
      {10, base::TimeDelta::FromMilliseconds(1000)}};

  for (const auto& sample : cached_requests_count_peak_delay_sample) {
    analyzer.count_inflight_requests_for_peak_queueing_delay_ = sample.first;
    analyzer.peak_queueing_delay_ = sample.second;
    analyzer.UpdateRequestsCountAndPeakQueueingDelayMapping();
  }

  // Checks that the scores are correctly computed.
  std::vector<std::pair<size_t, base::TimeDelta>> mapping_sample = {
      std::make_pair(1, base::TimeDelta::FromMilliseconds(100)),
      std::make_pair(2, base::TimeDelta::FromMilliseconds(200)),
      std::make_pair(3, base::TimeDelta::FromMilliseconds(400)),
      std::make_pair(4, base::TimeDelta::FromMilliseconds(800)),
      std::make_pair(5, base::TimeDelta::FromMilliseconds(400)),
      std::make_pair(6, base::TimeDelta::FromMilliseconds(200)),
      std::make_pair(7, base::TimeDelta::FromMilliseconds(200)),
      std::make_pair(8, base::TimeDelta::FromMilliseconds(200)),
      std::make_pair(9, base::TimeDelta::FromMilliseconds(200)),
      std::make_pair(10, base::TimeDelta::FromMilliseconds(900)),
      std::make_pair(11, base::TimeDelta::FromMilliseconds(500))};
  std::vector<size_t> ground_truth_mapping_score = {100, 100, 90, 60, 90, 60,
                                                    50,  40,  30, 90, 40};

  EXPECT_EQ(mapping_sample.size(), ground_truth_mapping_score.size());
  EXPECT_EQ(10u, analyzer.count_peak_queueing_delay_mapping_sample_);

  for (size_t i = 0; i < mapping_sample.size(); ++i) {
    EXPECT_EQ(analyzer.ComputePeakDelayMappingSampleScore(
                  mapping_sample[i].first, mapping_sample[i].second),
              ground_truth_mapping_score[i]);
  }

  // Checks that only samples with a score higher than a threshold would be
  // inserted into the cache.
  size_t inserted_samples_count = 0;
  size_t samples_count_before = 0;
  bool is_inserted = false;
  for (const auto& sample : mapping_sample) {
    samples_count_before =
        analyzer.count_inflight_requests_to_queueing_delay_[sample.first]
            .size();
    is_inserted =
        analyzer.ComputePeakDelayMappingSampleScore(sample.first, sample.second)
            .value_or(0) >= kMinScoreForValidSamples;
    // Inserts the new sample.
    analyzer.count_inflight_requests_for_peak_queueing_delay_ = sample.first;
    analyzer.peak_queueing_delay_ = sample.second;
    analyzer.UpdateRequestsCountAndPeakQueueingDelayMapping();
    if (is_inserted) {
      ++inserted_samples_count;
      EXPECT_EQ(
          samples_count_before + 1,
          analyzer.count_inflight_requests_to_queueing_delay_[sample.first]
              .size());
    } else {
      EXPECT_EQ(
          samples_count_before,
          analyzer.count_inflight_requests_to_queueing_delay_[sample.first]
              .size());
    }
  }

  EXPECT_EQ(10u + inserted_samples_count,
            analyzer.count_peak_queueing_delay_mapping_sample_);
}