TEST_F(RtpFecTest, FecRecoveryWithFecOutOfOrder) {
  const int kNumImportantPackets = 0;
  const bool kUseUnequalProtection = false;
  uint8_t kProtectionFactor = 20;

  // One frame: 3 media packets, 1 FEC packet.
  //         -----Frame 1----
  //  #0(media) #1(media) #2(media) #3(FEC).
  fec_seq_num_ = ConstructMediaPacketsSeqNum(3, 0);

  EXPECT_EQ(0, fec_->GenerateFEC(media_packet_list_, kProtectionFactor,
                                 kNumImportantPackets, kUseUnequalProtection,
                                 webrtc::kFecMaskBursty, &fec_packet_list_));

  // Expect 1 FEC packet.
  EXPECT_EQ(1, static_cast<int>(fec_packet_list_.size()));

  // Lose one media packet (seq# 1).
  memset(media_loss_mask_, 0, sizeof(media_loss_mask_));
  memset(fec_loss_mask_, 0, sizeof(fec_loss_mask_));
  media_loss_mask_[1] = 1;
  // Add FEC packet to received list before the media packets.
  ReceivedPackets(fec_packet_list_, fec_loss_mask_, true);
  // Add media packets to received list.
  ReceivedPackets(media_packet_list_, media_loss_mask_, false);

  EXPECT_EQ(0,
            fec_->DecodeFEC(&received_packet_list_, &recovered_packet_list_));

  // Expect 3 media packets in recovered list, and complete recovery.
  EXPECT_EQ(3, static_cast<int>(recovered_packet_list_.size()));
  EXPECT_TRUE(IsRecoveryComplete());
  FreeRecoveredPacketList();
}