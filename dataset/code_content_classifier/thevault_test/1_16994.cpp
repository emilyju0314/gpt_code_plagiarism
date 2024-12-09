TEST_F(UberLossAlgorithmTest, LossDetectionTuning_OnMinRttAvailableFirst) {
  const int old_reordering_shift = loss_algorithm_.GetPacketReorderingShift();
  const QuicPacketCount old_reordering_threshold =
      loss_algorithm_.GetPacketReorderingThreshold();

  loss_algorithm_.OnUserAgentIdKnown();

  // Not owned.
  TestLossTuner* test_tuner = new TestLossTuner(
      /*forced_start_result=*/true,
      LossDetectionParameters{
          /*reordering_shift=*/old_reordering_shift + 1,
          /*reordering_threshold=*/old_reordering_threshold * 2});
  loss_algorithm_.SetLossDetectionTuner(
      std::unique_ptr<LossDetectionTunerInterface>(test_tuner));

  loss_algorithm_.OnMinRttAvailable();
  EXPECT_FALSE(test_tuner->start_called());
  EXPECT_EQ(old_reordering_shift, loss_algorithm_.GetPacketReorderingShift());
  EXPECT_EQ(old_reordering_threshold,
            loss_algorithm_.GetPacketReorderingThreshold());

  // Pretend a reodering has happened.
  loss_algorithm_.OnReorderingDetected();
  EXPECT_FALSE(test_tuner->start_called());

  QuicConfig config;
  QuicTagVector connection_options;
  connection_options.push_back(kELDT);
  config.SetInitialReceivedConnectionOptions(connection_options);
  // Should start tuning since MinRtt is available.
  loss_algorithm_.SetFromConfig(config, Perspective::IS_SERVER);

  EXPECT_TRUE(test_tuner->start_called());
  EXPECT_NE(old_reordering_shift, loss_algorithm_.GetPacketReorderingShift());
  EXPECT_NE(old_reordering_threshold,
            loss_algorithm_.GetPacketReorderingThreshold());
}