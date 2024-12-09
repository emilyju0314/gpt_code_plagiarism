TEST_F(Utf8ValidationTest, WriteArbitraryBytes) {
  std::string wire_buffer;
  protobuf_unittest::OneBytes input;
  std::vector<std::string> errors;
  {
    ScopedMemoryLog log;
    WriteMessage(kInvalidUTF8String, &input, &wire_buffer);
    errors = log.GetMessages(ERROR);
  }
  ASSERT_EQ(0, errors.size());
}