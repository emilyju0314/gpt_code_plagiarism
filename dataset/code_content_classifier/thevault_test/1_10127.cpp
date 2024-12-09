TEST_F(FakeNetworkPipeTest, CapacityTest) {
  FakeNetworkPipe::Config config;
  config.queue_length_packets = 20;
  config.link_capacity_kbps = 80;
  rtc::scoped_ptr<FakeNetworkPipe> pipe(
      new FakeNetworkPipe(&fake_clock_, config));
  pipe->SetReceiver(receiver_.get());

  // Add 10 packets of 1000 bytes, = 80 kb, and verify it takes one second to
  // get through the pipe.
  const int kNumPackets = 10;
  const int kPacketSize = 1000;
  SendPackets(pipe.get(), kNumPackets , kPacketSize);

  // Time to get one packet through the link.
  const int kPacketTimeMs = PacketTimeMs(config.link_capacity_kbps,
                                         kPacketSize);

  // Time haven't increased yet, so we souldn't get any packets.
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(0);
  pipe->Process();

  // Advance enough time to release one packet.
  fake_clock_.AdvanceTimeMilliseconds(kPacketTimeMs);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
  pipe->Process();

  // Release all but one packet
  fake_clock_.AdvanceTimeMilliseconds(9 * kPacketTimeMs - 1);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(8);
  pipe->Process();

  // And the last one.
  fake_clock_.AdvanceTimeMilliseconds(1);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(1);
  pipe->Process();
}