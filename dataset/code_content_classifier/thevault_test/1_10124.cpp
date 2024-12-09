TEST_F(RtpFecTest, FecRecoveryWithSeqNumGapOneFrameRecovery) {
  const int kNumImportantPackets = 0;
  const bool kUseUnequalProtection = false;
  uint8_t kProtectionFactor = 20;

  // One frame, with sequence number wrap in media packets.
  //         -----Frame 1----
  //  #65534(media) #65535(media) #0(media) #1(FEC).
  fec_seq_num_ = ConstructMediaPacketsSeqNum(3, 65534);

  EXPECT_EQ(0, fec_->GenerateFEC(media_packet_list_, kProtectionFactor,
                                 kNumImportantPackets, kUseUnequalProtection,
                                 webrtc::kFecMaskBursty, &fec_packet_list_));

  // Expect 1 FEC packet.
  EXPECT_EQ(1, static_cast<int>(fec_packet_list_.size()));

  // Lose one media packet (seq# 65535).
  memset(media_loss_mask_, 0, sizeof(media_loss_mask_));
  memset(fec_loss_mask_, 0, sizeof(fec_loss_mask_));
  media_loss_mask_[1] = 1;
  ReceivedPackets(media_packet_list_, media_loss_mask_, false);
  // Add FEC packet to received list following the media packets.
  ReceivedPackets(fec_packet_list_, fec_loss_mask_, true);

  EXPECT_EQ(0,
            fec_->DecodeFEC(&received_packet_list_, &recovered_packet_list_));

  // Expect 3 media packets in recovered list, and complete recovery.
  // Wrap-around won't remove FEC packet, as it follows the wrap.
  EXPECT_EQ(3, static_cast<int>(recovered_packet_list_.size()));
  EXPECT_TRUE(IsRecoveryComplete());
  FreeRecoveredPacketList();
}