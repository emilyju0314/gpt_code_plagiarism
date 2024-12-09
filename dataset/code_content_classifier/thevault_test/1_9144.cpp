TEST_F(ProductionLotteryTest, ComputeRandomness) {
  // GIVEN
  for (const auto &value : submitted_vrf_values_) {
    lottery_.submitVRFValue(value);
  }

  // WHEN
  Buffer concat_values{};
  concat_values.put(current_epoch_.randomness);
  concat_values.put(uint64_t_to_bytes(current_epoch_.epoch_index));
  for (const auto &value : submitted_vrf_values_) {
    concat_values.put(value);
  }

  Hash256 new_randomness{};
  new_randomness.fill(1);
  new_randomness[10] = 9;
  EXPECT_CALL(*hasher_, blake2b_256(gsl::span<const uint8_t>(concat_values)))
      .WillOnce(Return(new_randomness));

  auto returned_randomness = lottery_.computeRandomness(
      current_epoch_.randomness, current_epoch_.epoch_index);

  // THEN
  ASSERT_EQ(new_randomness, returned_randomness);
}