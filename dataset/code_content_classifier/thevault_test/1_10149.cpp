TEST_F(ViERembTest, NoSendingRtpModule) {
  MockRtpRtcp rtp;
  vie_remb_->AddReceiveChannel(&rtp);

  unsigned int bitrate_estimate = 456;
  unsigned int ssrc = 1234;
  std::vector<unsigned int> ssrcs(&ssrc, &ssrc + 1);

  vie_remb_->OnReceiveBitrateChanged(ssrcs, bitrate_estimate);

  // Call OnReceiveBitrateChanged twice to get a first estimate.
  fake_clock_.AdvanceTimeMilliseconds(1000);
  EXPECT_CALL(rtp, SetREMBData(_, _))
      .Times(1);
  vie_remb_->OnReceiveBitrateChanged(ssrcs, bitrate_estimate);

  // Lower the estimate to trigger a new packet REMB packet.
  bitrate_estimate = bitrate_estimate - 100;
  EXPECT_CALL(rtp, SetREMBData(_, _))
      .Times(1);
  vie_remb_->OnReceiveBitrateChanged(ssrcs, bitrate_estimate);
}