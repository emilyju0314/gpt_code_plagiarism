TEST_F(UberLossAlgorithmTest, LossDetectionTuning_SetFromConfigFirst) {
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

  QuicConfig config;
  QuicTagVector connection_options;
  connection_options.push_back(kELDT);
  config.SetInitialReceivedConnectionOptions(connection_options);
  loss_algorithm_.SetFromConfig(config, Perspective::IS_SERVER);

  // MinRtt was not available when SetFromConfig was called.
  EXPECT_FALSE(test_tuner->start_called());
  EXPECT_EQ(old_reordering_shift, loss_algorithm_.GetPacketReorderingShift());
  EXPECT_EQ(old_reordering_threshold,
            loss_algorithm_.GetPacketReorderingThreshold());

  // MinRtt available. Tuner should not start yet because no reordering yet.
  loss_algorithm_.OnMinRttAvailable();
  EXPECT_FALSE(test_tuner->start_called());

  // Reordering happened. Tuner should start now.
  loss_algorithm_.OnReorderingDetected();
  EXPECT_TRUE(test_tuner->start_called());
  EXPECT_NE(old_reordering_shift, loss_algorithm_.GetPacketReorderingShift());
  EXPECT_NE(old_reordering_threshold,
            loss_algorithm_.GetPacketReorderingThreshold());
}