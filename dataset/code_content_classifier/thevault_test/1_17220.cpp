TEST_F(IoTest, LimitingInputStreamByteCount) {
  const int kHalfBufferSize = 128;
  const int kBufferSize = kHalfBufferSize * 2;
  uint8 buffer[kBufferSize];

  // Set up input. Only allow half to be read at once.
  ArrayInputStream array_input(buffer, kBufferSize, kHalfBufferSize);
  const void* data;
  int size;
  EXPECT_TRUE(array_input.Next(&data, &size));
  EXPECT_EQ(kHalfBufferSize, array_input.ByteCount());
  // kHalfBufferSize - 1 to test limiting logic as well.
  LimitingInputStream input(&array_input, kHalfBufferSize - 1);
  EXPECT_EQ(0, input.ByteCount());
  EXPECT_TRUE(input.Next(&data, &size));
  EXPECT_EQ(kHalfBufferSize - 1, input.ByteCount());
}