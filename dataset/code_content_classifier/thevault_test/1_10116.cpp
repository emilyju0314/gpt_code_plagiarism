TEST(PacketBuffer, InsertPacketList) {
  PacketBuffer buffer(10);  // 10 packets.
  PacketGenerator gen(0, 0, 0, 10);
  PacketList list;
  const int payload_len = 10;

  // Insert 10 small packets.
  for (int i = 0; i < 10; ++i) {
    Packet* packet = gen.NextPacket(payload_len);
    list.push_back(packet);
  }

  MockDecoderDatabase decoder_database;
  EXPECT_CALL(decoder_database, IsComfortNoise(0))
      .WillRepeatedly(Return(false));
  EXPECT_CALL(decoder_database, IsDtmf(0))
      .WillRepeatedly(Return(false));
  uint8_t current_pt = 0xFF;
  uint8_t current_cng_pt = 0xFF;
  EXPECT_EQ(PacketBuffer::kOK, buffer.InsertPacketList(&list,
                                                       decoder_database,
                                                       &current_pt,
                                                       &current_cng_pt));
  EXPECT_TRUE(list.empty());  // The PacketBuffer should have depleted the list.
  EXPECT_EQ(10u, buffer.NumPacketsInBuffer());
  EXPECT_EQ(0, current_pt);  // Current payload type changed to 0.
  EXPECT_EQ(0xFF, current_cng_pt);  // CNG payload type not changed.

  buffer.Flush();  // Clean up.

  EXPECT_CALL(decoder_database, Die());  // Called when object is deleted.
}