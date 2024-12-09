TEST_F(PacketQueueTest, LockUnlockBuffer) {
  auto packet_queue = CreatePacketQueue();

  auto packet_frame = FractionalFrames<int64_t>(0);
  auto packet_length = FractionalFrames<uint32_t>(20);

  // Enqueue some packets.
  ASSERT_TRUE(packet_queue->empty());
  auto packet0 = CreatePacket(0, packet_frame, packet_length);
  packet_frame += packet_length;
  auto packet1 = CreatePacket(1, packet_frame, packet_length);
  packet_frame += packet_length;
  auto packet2 = CreatePacket(2, packet_frame, packet_length);

  packet_queue->PushPacket(packet0);
  packet_queue->PushPacket(packet1);
  packet_queue->PushPacket(packet2);
  ASSERT_FALSE(packet_queue->empty());
  ASSERT_EQ(0u, released_packet_count());

  // Now pop off the packets in FIFO order.
  //
  // Packet #0:
  auto buffer = packet_queue->LockBuffer();
  ASSERT_TRUE(buffer);
  ASSERT_FALSE(buffer->is_continuous());
  ASSERT_EQ(0, buffer->start());
  ASSERT_EQ(20u, buffer->length());
  ASSERT_EQ(20, buffer->end());
  ASSERT_EQ(packet0->payload(), buffer->payload());
  ASSERT_FALSE(packet_queue->empty());
  ASSERT_EQ(0u, released_packet_count());
  packet0 = nullptr;
  packet_queue->UnlockBuffer(true);
  RunLoopUntilIdle();
  ASSERT_FALSE(packet_queue->empty());
  ASSERT_EQ(1u, released_packet_count());

  // Packet #1
  buffer = packet_queue->LockBuffer();
  ASSERT_TRUE(buffer);
  ASSERT_TRUE(buffer->is_continuous());
  ASSERT_EQ(20, buffer->start());
  ASSERT_EQ(20u, buffer->length());
  ASSERT_EQ(40, buffer->end());
  ASSERT_EQ(packet1->payload(), buffer->payload());
  packet1 = nullptr;
  packet_queue->UnlockBuffer(true);
  RunLoopUntilIdle();
  ASSERT_FALSE(packet_queue->empty());
  ASSERT_EQ(2u, released_packet_count());

  // ...and #2
  buffer = packet_queue->LockBuffer();
  ASSERT_TRUE(buffer);
  ASSERT_TRUE(buffer->is_continuous());
  ASSERT_EQ(40, buffer->start());
  ASSERT_EQ(20u, buffer->length());
  ASSERT_EQ(60, buffer->end());
  ASSERT_EQ(packet2->payload(), buffer->payload());
  packet2 = nullptr;
  packet_queue->UnlockBuffer(true);
  RunLoopUntilIdle();
  ASSERT_TRUE(packet_queue->empty());
  ASSERT_EQ(3u, released_packet_count());
}