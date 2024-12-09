TEST_P(PriorityUpdatePayloadDecoderTest, Truncated) {
  auto approve_size = [](size_t size) {
    return size != Http2PriorityUpdateFields::EncodedSize();
  };
  Http2FrameBuilder fb;
  fb.Append(Http2PriorityUpdateFields(123));
  EXPECT_TRUE(VerifyDetectsFrameSizeError(0, fb.buffer(), approve_size));
}