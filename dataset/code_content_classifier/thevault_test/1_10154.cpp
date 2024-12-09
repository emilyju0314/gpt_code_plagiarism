TEST_F(RtpPacketizerVp8Test, TestEqualSizeModeFallback) {
  const size_t kSizeVector[] = {10, 10, 10};
  const size_t kNumPartitions = GTEST_ARRAY_SIZE_(kSizeVector);
  ASSERT_TRUE(Init(kSizeVector, kNumPartitions));

  hdr_info_.pictureId = 200;   // > 0x7F should produce 2-byte PictureID
  const size_t kMaxSize = 12;  // Small enough to produce 4 packets.
  RtpPacketizerVp8 packetizer(hdr_info_, kMaxSize);
  packetizer.SetPayloadData(
      helper_->payload_data(), helper_->payload_size(), NULL);

  // Expecting three full packets, and one with the remainder.
  const size_t kExpectedSizes[] = {12, 11, 12, 11};
  const int kExpectedPart[] = {0, 0, 0, 0};  // Always 0 for equal size mode.
  // Frag start only true for first packet in equal size mode.
  const bool kExpectedFragStart[] = {true, false, false, false};
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