TEST_F(QuicBatchWriterBufferTest, MixedPushes) {
  // First, a in-place push.
  char* buffer = batch_buffer_->GetNextWriteLocation();
  auto push_result = batch_buffer_->PushBufferedWrite(
      FillPacketBuffer('A', buffer), kDefaultMaxPacketSize, self_addr_,
      peer_addr_, nullptr, release_time_);
  EXPECT_TRUE(push_result.succeeded);
  EXPECT_FALSE(push_result.buffer_copied);
  CheckBufferedWriteContent(0, 'A', kDefaultMaxPacketSize, self_addr_,
                            peer_addr_, nullptr);

  // Then a push with external buffer.
  push_result = batch_buffer_->PushBufferedWrite(
      FillPacketBuffer('B'), kDefaultMaxPacketSize, self_addr_, peer_addr_,
      nullptr, release_time_);
  EXPECT_TRUE(push_result.succeeded);
  EXPECT_TRUE(push_result.buffer_copied);
  CheckBufferedWriteContent(1, 'B', kDefaultMaxPacketSize, self_addr_,
                            peer_addr_, nullptr);

  // Then another in-place push.
  buffer = batch_buffer_->GetNextWriteLocation();
  push_result = batch_buffer_->PushBufferedWrite(
      FillPacketBuffer('C', buffer), kDefaultMaxPacketSize, self_addr_,
      peer_addr_, nullptr, release_time_);
  EXPECT_TRUE(push_result.succeeded);
  EXPECT_FALSE(push_result.buffer_copied);
  CheckBufferedWriteContent(2, 'C', kDefaultMaxPacketSize, self_addr_,
                            peer_addr_, nullptr);

  // Then another push with external buffer.
  push_result = batch_buffer_->PushBufferedWrite(
      FillPacketBuffer('D'), kDefaultMaxPacketSize, self_addr_, peer_addr_,
      nullptr, release_time_);
  EXPECT_TRUE(push_result.succeeded);
  EXPECT_TRUE(push_result.buffer_copied);
  CheckBufferedWriteContent(3, 'D', kDefaultMaxPacketSize, self_addr_,
                            peer_addr_, nullptr);
}