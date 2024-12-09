TEST_F(IoTest, ConcatenatingInputStream) {
  const int kBufferSize = 256;
  uint8 buffer[kBufferSize];

  // Fill the buffer.
  ArrayOutputStream output(buffer, kBufferSize);
  WriteStuff(&output);

  // Now split it up into multiple streams of varying sizes.
  ASSERT_EQ(68, output.ByteCount());  // Test depends on this.
  ArrayInputStream input1(buffer, 12);
  ArrayInputStream input2(buffer + 12, 7);
  ArrayInputStream input3(buffer + 19, 6);
  ArrayInputStream input4(buffer + 25, 15);
  ArrayInputStream input5(buffer + 40, 0);
  // Note:  We want to make sure we have a stream boundary somewhere between
  // bytes 42 and 62, which is the range that it Skip()ed by ReadStuff().  This
  // tests that a bug that existed in the original code for Skip() is fixed.
  ArrayInputStream input6(buffer + 40, 10);
  ArrayInputStream input7(buffer + 50, 18);  // Total = 68 bytes.

  ZeroCopyInputStream* streams[] = {&input1, &input2, &input3, &input4,
                                    &input5, &input6, &input7};

  // Create the concatenating stream and read.
  ConcatenatingInputStream input(streams, GOOGLE_ARRAYSIZE(streams));
  ReadStuff(&input);
}