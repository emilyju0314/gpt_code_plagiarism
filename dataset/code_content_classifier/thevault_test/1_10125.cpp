TEST_F(RtpFecTest, FecRecoveryWithSeqNumGapOneFrameNoRecovery) {
  const int kNumImportantPackets = 0;
  const bool kUseUnequalProtection = false;
  uint8_t kProtectionFactor = 200;

  // 1 frame: 3 media packets and 2 FEC packets.
  // Sequence number wrap in FEC packets.
  //           -----Frame 1----
  // #65532(media) #65533(media) #65534(media) #65535(FEC) #0(FEC).
  fec_seq_num_ = ConstructMediaPacketsSeqNum(3, 65532);

  EXPECT_EQ(0, fec_->GenerateFEC(media_packet_list_, kProtectionFactor,
                                 kNumImportantPackets, kUseUnequalProtection,
                                 webrtc::kFecMaskBursty, &fec_packet_list_));

  // Expect 2 FEC packets.
  EXPECT_EQ(2, static_cast<int>(fec_packet_list_.size()));

  // Lose the last two media packets (seq# 65533, 65534).
  memset(media_loss_mask_, 0, sizeof(media_loss_mask_));
  memset(fec_loss_mask_, 0, sizeof(fec_loss_mask_));
  media_loss_mask_[1] = 1;
  media_loss_mask_[2] = 1;
  ReceivedPackets(media_packet_list_, media_loss_mask_, false);
  ReceivedPackets(fec_packet_list_, fec_loss_mask_, true);

  EXPECT_EQ(0,
            fec_->DecodeFEC(&received_packet_list_, &recovered_packet_list_));

  // The two FEC packets are received and should allow for complete recovery,
  // but because of the wrap the second FEC packet will be discarded, and only
  // one media packet is recoverable. So exepct 2 media packets on recovered
  // list and no complete recovery.
  EXPECT_EQ(2, static_cast<int>(recovered_packet_list_.size()));
  EXPECT_TRUE(recovered_packet_list_.size() != media_packet_list_.size());
  EXPECT_FALSE(IsRecoveryComplete());
  FreeRecoveredPacketList();
}