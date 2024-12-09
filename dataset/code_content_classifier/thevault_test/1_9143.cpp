TEST_F(ProductionLotteryTest, SlotsLeadership) {
  // GIVEN
  for (const auto &value : submitted_vrf_values_) {
    lottery_.submitVRFValue(value);
  }

  std::vector<VRFOutput> vrf_outputs;
  vrf_outputs.reserve(2);
  vrf_outputs.push_back({uint256_t_to_bytes(3749373), {}});
  vrf_outputs.push_back({uint256_t_to_bytes(1057472095), {}});

  Buffer vrf_input(vrf_constants::OUTPUT_SIZE + 8, 0);
  std::copy(current_epoch_.randomness.begin(),
            current_epoch_.randomness.end(),
            vrf_input.begin());
  for (size_t i = 0; i < current_epoch_.epoch_duration; ++i) {
    auto slot_bytes = uint64_t_to_bytes(i);
    std::copy(slot_bytes.begin(),
              slot_bytes.end(),
              vrf_input.begin() + vrf_constants::OUTPUT_SIZE);
    if (i == 2) {
      // just random case for testing
      EXPECT_CALL(*vrf_provider_, sign(vrf_input, keypair_, threshold_))
          .WillOnce(Return(boost::none));
      continue;
    }
    EXPECT_CALL(*vrf_provider_, sign(vrf_input, keypair_, threshold_))
        .WillOnce(Return(vrf_outputs[i]));
  }

  // WHEN
  auto leadership =
      lottery_.slotsLeadership(current_epoch_, threshold_, keypair_);

  // THEN
  ASSERT_TRUE(leadership[0]);
  EXPECT_EQ(leadership[0]->output, uint256_t_to_bytes(3749373));
  ASSERT_TRUE(leadership[1]);
  EXPECT_EQ(leadership[1]->output, uint256_t_to_bytes(1057472095));
  ASSERT_FALSE(leadership[2]);
}