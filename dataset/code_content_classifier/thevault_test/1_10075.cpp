TEST_F(ExpandTest, CheckOutageStatsAfterReset) {
  AudioMultiVector output(num_channels_);
  size_t sum_output_len_samples = 0;
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(0, expand_.Process(&output));
    EXPECT_GT(output.Size(), 0u);
    sum_output_len_samples += output.Size();
    if (i == 5) {
      expand_.Reset();
      sum_output_len_samples = 0;
    }
    EXPECT_EQ(0, statistics_.last_outage_duration_ms());
  }
  expand_.SetParametersForNormalAfterExpand();
  // Convert |sum_output_len_samples| to milliseconds.
  EXPECT_EQ(rtc::checked_cast<int>(sum_output_len_samples /
                                   (test_sample_rate_hz_ / 1000)),
            statistics_.last_outage_duration_ms());
}