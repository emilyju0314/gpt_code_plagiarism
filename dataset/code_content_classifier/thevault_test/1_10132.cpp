TEST_F(FakeNetworkPipeTest, ChangingCapacityWithPacketsInPipeTest) {
  FakeNetworkPipe::Config config;
  config.queue_length_packets = 20;
  config.link_capacity_kbps = 80;
  rtc::scoped_ptr<FakeNetworkPipe> pipe(
      new FakeNetworkPipe(&fake_clock_, config));
  pipe->SetReceiver(receiver_.get());

  // Add 10 packets of 1000 bytes, = 80 kb.
  const int kNumPackets = 10;
  const int kPacketSize = 1000;
  SendPackets(pipe.get(), kNumPackets, kPacketSize);

  // Time to get one packet through the link at the initial speed.
  int packet_time_1_ms = PacketTimeMs(config.link_capacity_kbps, kPacketSize);

  // Change the capacity.
  config.link_capacity_kbps *= 2;  // Double the capacity.
  pipe->SetConfig(config);

  // Add another 10 packets of 1000 bytes, = 80 kb, and verify it takes two
  // seconds to get them through the pipe.
  SendPackets(pipe.get(), kNumPackets, kPacketSize);

  // Time to get one packet through the link at the new capacity.
  int packet_time_2_ms = PacketTimeMs(config.link_capacity_kbps, kPacketSize);

  // Time hasn't increased yet, so we souldn't get any packets.
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(0);
  pipe->Process();

  // Advance time in steps to release one packet at a time.
  for (int i = 0; i < kNumPackets; ++i) {
    fake_clock_.AdvanceTimeMilliseconds(packet_time_1_ms);
    EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
    pipe->Process();
  }

  // Advance time in steps to release one packet at a time.
  for (int i = 0; i < kNumPackets; ++i) {
    fake_clock_.AdvanceTimeMilliseconds(packet_time_2_ms);
    EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
    pipe->Process();
  }

  // Check that all the packets were sent.
  EXPECT_EQ(static_cast<size_t>(2 * kNumPackets), pipe->sent_packets());
  fake_clock_.AdvanceTimeMilliseconds(pipe->TimeUntilNextProcess());
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(0);
  pipe->Process();
}