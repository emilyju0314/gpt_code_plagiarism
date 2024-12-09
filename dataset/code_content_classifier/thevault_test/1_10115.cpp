TEST(PacketBuffer, OverfillBuffer) {
  PacketBuffer buffer(10);  // 10 packets.
  PacketGenerator gen(0, 0, 0, 10);

  // Insert 10 small packets; should be ok.
  const int payload_len = 10;
  int i;
  for (i = 0; i < 10; ++i) {
    Packet* packet = gen.NextPacket(payload_len);
    EXPECT_EQ(PacketBuffer::kOK, buffer.InsertPacket(packet));
  }
  EXPECT_EQ(10u, buffer.NumPacketsInBuffer());
  uint32_t next_ts;
  EXPECT_EQ(PacketBuffer::kOK, buffer.NextTimestamp(&next_ts));
  EXPECT_EQ(0u, next_ts);  // Expect first inserted packet to be first in line.

  // Insert 11th packet; should flush the buffer and insert it after flushing.
  Packet* packet = gen.NextPacket(payload_len);
  EXPECT_EQ(PacketBuffer::kFlushed, buffer.InsertPacket(packet));
  EXPECT_EQ(1u, buffer.NumPacketsInBuffer());
  EXPECT_EQ(PacketBuffer::kOK, buffer.NextTimestamp(&next_ts));
  // Expect last inserted packet to be first in line.
  EXPECT_EQ(packet->header.timestamp, next_ts);

  // Flush buffer to delete all packets.
  buffer.Flush();
}