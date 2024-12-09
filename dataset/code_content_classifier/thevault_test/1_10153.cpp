TEST_F(RtpPacketizerVp8Test, DISABLED_TestStrictEqualTightPartitions) {
  const size_t kSizeVector[] = {10, 10, 10};
  const size_t kNumPartitions = GTEST_ARRAY_SIZE_(kSizeVector);
  ASSERT_TRUE(Init(kSizeVector, kNumPartitions));

  hdr_info_.pictureId = 200;  // > 0x7F should produce 2-byte PictureID.
  const int kMaxSize = 14;
  RtpPacketizerVp8 packetizer(hdr_info_, kMaxSize, kStrict);
  packetizer.SetPayloadData(helper_->payload_data(), helper_->payload_size(),
                            helper_->fragmentation());

  // The expected sizes are obtained by running a verified good implementation.
  const size_t kExpectedSizes[] = {14, 14, 14};
  const int kExpectedPart[] = {0, 1, 2};
  const bool kExpectedFragStart[] = {true, true, true};
  const size_t kExpectedNum = GTEST_ARRAY_SIZE_(kExpectedSizes);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedPart);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedFragStart);

  helper_->GetAllPacketsAndCheck(&packetizer, kExpectedSizes, kExpectedPart,
                                 kExpectedFragStart, kExpectedNum);
}