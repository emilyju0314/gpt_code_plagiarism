TEST_F(FakeNetworkPipeTest, ExtraDelayTest) {
  FakeNetworkPipe::Config config;
  config.queue_length_packets = 20;
  config.queue_delay_ms = 100;
  config.link_capacity_kbps = 80;
  rtc::scoped_ptr<FakeNetworkPipe> pipe(
      new FakeNetworkPipe(&fake_clock_, config));
  pipe->SetReceiver(receiver_.get());

  const int kNumPackets = 2;
  const int kPacketSize = 1000;
  SendPackets(pipe.get(), kNumPackets , kPacketSize);

  // Time to get one packet through the link.
  const int kPacketTimeMs = PacketTimeMs(config.link_capacity_kbps,
                                         kPacketSize);

  // Increase more than kPacketTimeMs, but not more than the extra delay.
  fake_clock_.AdvanceTimeMilliseconds(kPacketTimeMs);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(0);
  pipe->Process();

  // Advance the network delay to get the first packet.
  fake_clock_.AdvanceTimeMilliseconds(config.queue_delay_ms);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
  pipe->Process();

  // Advance one more kPacketTimeMs to get the last packet.
  fake_clock_.AdvanceTimeMilliseconds(kPacketTimeMs);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
  pipe->Process();
}