TEST_F(QuicBatchWriterBufferTest, InPlacePushes) {
  std::vector<BufferSizeSequence> buffer_size_sequences = {
      // Push large writes until the buffer is near full, then switch to 1-byte
      // writes. This covers the edge cases when detecting insufficient buffer.
      BufferSizeSequence({{{1350}, kBatchBufferSize - 3000}, {{1}, 1e6}}),
      // A sequence that looks real.
      BufferSizeSequence({{{1, 39, 97, 150, 1350, 1350, 1350, 1350}, 1e6}}),
  };

  for (auto& buffer_size_sequence : buffer_size_sequences) {
    SwitchToNewBuffer();
    int64_t num_push_failures = 0;

    while (batch_buffer_->SizeInUse() < kBatchBufferSize) {
      size_t buf_len = buffer_size_sequence.Next();
      const bool has_enough_space =
          (kBatchBufferSize - batch_buffer_->SizeInUse() >=
           kMaxOutgoingPacketSize);

      char* buffer = batch_buffer_->GetNextWriteLocation();

      if (has_enough_space) {
        EXPECT_EQ(batch_buffer_->buffer_ + batch_buffer_->SizeInUse(), buffer);
      } else {
        EXPECT_EQ(nullptr, buffer);
      }

      SCOPED_TRACE(testing::Message()
                   << "Before Push: buf_len=" << buf_len
                   << ", has_enough_space=" << has_enough_space
                   << ", batch_buffer=" << batch_buffer_->DebugString());

      auto push_result = batch_buffer_->PushBufferedWrite(
          buffer, buf_len, self_addr_, peer_addr_, nullptr, release_time_);
      if (!push_result.succeeded) {
        ++num_push_failures;
      }
      EXPECT_EQ(has_enough_space, push_result.succeeded);
      EXPECT_FALSE(push_result.buffer_copied);
      if (!has_enough_space) {
        break;
      }
    }
    // Expect one and only one failure from the final push operation.
    EXPECT_EQ(1, num_push_failures);
  }
}