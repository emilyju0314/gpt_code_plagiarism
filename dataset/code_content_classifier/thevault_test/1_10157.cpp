TEST_F(RtpPacketizerVp8Test, TestTIDAndKeyIdx) {
  const size_t kSizeVector[] = {10, 10, 10};
  const size_t kNumPartitions = GTEST_ARRAY_SIZE_(kSizeVector);
  ASSERT_TRUE(Init(kSizeVector, kNumPartitions));

  hdr_info_.temporalIdx = 1;
  hdr_info_.keyIdx = 5;
  // kMaxSize is only limited by allocated buffer size.
  const size_t kMaxSize = helper_->buffer_size();
  RtpPacketizerVp8 packetizer(hdr_info_, kMaxSize, kAggregate);
  packetizer.SetPayloadData(helper_->payload_data(),
                            helper_->payload_size(),
                            helper_->fragmentation());

  // Expect one single packet of payload_size() + 3 bytes header.
  const size_t kExpectedSizes[1] = {helper_->payload_size() + 3};
  const int kExpectedPart[1] = {0};  // Packet starts with partition 0.
  const bool kExpectedFragStart[1] = {true};
  const size_t kExpectedNum = GTEST_ARRAY_SIZE_(kExpectedSizes);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedPart);
  CHECK_ARRAY_SIZE(kExpectedNum, kExpectedFragStart);

  helper_->GetAllPacketsAndCheck(&packetizer,
                                 kExpectedSizes,
                                 kExpectedPart,
                                 kExpectedFragStart,
                                 kExpectedNum);
}