TEST_F(BweReceiverTest, PacketLossWideGap) {
  const int64_t kTimeWindowMs = BweReceiver::kPacketLossTimeWindowMs;

  const MediaPacket media_packet1(0, 0, 0, 1);
  const MediaPacket media_packet2(0, 0, 0, 1000);
  // Only these two packets will be considered.
  bwe_receiver_.ReceivePacket(0, media_packet1);
  bwe_receiver_.ReceivePacket(0, media_packet2);
  EXPECT_NEAR(bwe_receiver_.RecentPacketLossRatio(), 0.998f, 0.0001f);

  const MediaPacket media_packet3(0, 0, 0, 0);
  const MediaPacket media_packet4(0, 0, 0, 0x8000);
  // Only these two packets will be considered.
  bwe_receiver_.ReceivePacket(2 * kTimeWindowMs, media_packet3);
  bwe_receiver_.ReceivePacket(2 * kTimeWindowMs, media_packet4);
  EXPECT_NEAR(bwe_receiver_.RecentPacketLossRatio(), 0.99994f, 0.00001f);
}