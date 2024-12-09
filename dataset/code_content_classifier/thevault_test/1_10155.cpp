TEST_F(RtpPacketizerVp8Test, TestNonReferenceBit) {
  const size_t kSizeVector[] = {10, 10, 10};
  const size_t kNumPartitions = GTEST_ARRAY_SIZE_(kSizeVector);
  ASSERT_TRUE(Init(kSizeVector, kNumPartitions));

  hdr_info_.nonReference = true;
  const size_t kMaxSize = 25;  // Small enough to produce two packets.
  RtpPacketizerVp8 packetizer(hdr_info_, kMaxSize);
  packetizer.SetPayloadData(
      helper_->payload_data(), helper_->payload_size(), NULL);

  // EqualSize mode => First packet full; other not.
  const size_t kExpectedSizes[] = {16, 16};
  const int kExpectedPart[] = {0, 0};  // Always 0 for equal size mode.
  // Frag start only true for first packet in equal size mode.
  const bool kExpectedFragStart[] = {true, false};
  const size_t kExpectedNum = GTEST_ARRAY_SIZE_(kExpectedSizes);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedPart);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedFragStart);

  helper_->set_sloppy_partitioning(true);
  helper_->GetAllPacketsAndCheck(&packetizer,
                                 kExpectedSizes,
                                 kExpectedPart,
                                 kExpectedFragStart,
                                 kExpectedNum);
}