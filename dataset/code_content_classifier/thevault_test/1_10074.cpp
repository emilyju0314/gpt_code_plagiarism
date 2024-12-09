TEST_F(ExpandTest, LostPacketOutage) {
  AudioMultiVector output(num_channels_);
  size_t sum_output_len_samples = 0;
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(0, expand_.Process(&output));
    EXPECT_GT(output.Size(), 0u);
    sum_output_len_samples += output.Size();
    EXPECT_EQ(0, statistics_.last_outage_duration_ms());
  }
  expand_.SetParametersForMergeAfterExpand();
  EXPECT_EQ(0, statistics_.last_outage_duration_ms());
}