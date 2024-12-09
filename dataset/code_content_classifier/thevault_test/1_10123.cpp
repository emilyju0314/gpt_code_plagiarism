TEST_F(RtpFecTest, FecRecoveryWithSeqNumGapTwoFrames) {
  const int kNumImportantPackets = 0;
  const bool kUseUnequalProtection = false;
  uint8_t kProtectionFactor = 20;

  // Two frames: first frame (old) with two media packets and 1 FEC packet.
  // Second frame (new) with 3 media packets, and no FEC packets.
  //       ---Frame 1----                     ----Frame 2------
  //  #0(media) #1(media) #2(FEC)     #65535(media) #0(media) #1(media).
  // If we lose either packet 0 or 1 of second frame, FEC decoding should not
  // try to decode using "old" FEC packet #2.

  // Construct media packets for first frame, starting at sequence number 0.
  fec_seq_num_ = ConstructMediaPacketsSeqNum(2, 0);

  EXPECT_EQ(0, fec_->GenerateFEC(media_packet_list_, kProtectionFactor,
                                 kNumImportantPackets, kUseUnequalProtection,
                                 webrtc::kFecMaskBursty, &fec_packet_list_));
  // Expect 1 FEC packet.
  EXPECT_EQ(1, static_cast<int>(fec_packet_list_.size()));
  // Add FEC packet (seq#2) of this first frame to received list (i.e., assume
  // the two media packet were lost).
  memset(fec_loss_mask_, 0, sizeof(fec_loss_mask_));
  ReceivedPackets(fec_packet_list_, fec_loss_mask_, true);

  // Construct media packets for second frame, with sequence number wrap.
  ClearList(&media_packet_list_);
  fec_seq_num_ = ConstructMediaPacketsSeqNum(3, 65535);

  // Expect 3 media packets for this frame.
  EXPECT_EQ(3, static_cast<int>(media_packet_list_.size()));

  // Second media packet lost (seq#0).
  memset(media_loss_mask_, 0, sizeof(media_loss_mask_));
  media_loss_mask_[1] = 1;
  // Add packets #65535, and #1 to received list.
  ReceivedPackets(media_packet_list_, media_loss_mask_, false);

  EXPECT_EQ(0,
            fec_->DecodeFEC(&received_packet_list_, &recovered_packet_list_));

  // Expect that no decoding is done to get missing packet (seq#0) of second
  // frame, using old FEC packet (seq#2) from first (old) frame. So number of
  // recovered packets is 2, and not equal to number of media packets (=3).
  EXPECT_EQ(2, static_cast<int>(recovered_packet_list_.size()));
  EXPECT_TRUE(recovered_packet_list_.size() != media_packet_list_.size());
  FreeRecoveredPacketList();
}