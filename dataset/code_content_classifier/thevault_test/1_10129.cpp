TEST_F(FakeNetworkPipeTest, QueueLengthTest) {
  FakeNetworkPipe::Config config;
  config.queue_length_packets = 2;
  config.link_capacity_kbps = 80;
  rtc::scoped_ptr<FakeNetworkPipe> pipe(
      new FakeNetworkPipe(&fake_clock_, config));
  pipe->SetReceiver(receiver_.get());

  const int kPacketSize = 1000;
  const int kPacketTimeMs = PacketTimeMs(config.link_capacity_kbps,
                                         kPacketSize);

  // Send three packets and verify only 2 are delivered.
  SendPackets(pipe.get(), 3, kPacketSize);

  // Increase time enough to deliver all three packets, verify only two are
  // delivered.
  fake_clock_.AdvanceTimeMilliseconds(3 * kPacketTimeMs);
  EXPECT_CALL(*receiver_, DeliverPacket(_, _, _, _)).Times(2);
  pipe->Process();
}