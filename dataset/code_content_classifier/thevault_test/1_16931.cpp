TEST_F(Utf8ValidationTest, OldVerifyUTF8String) {
  std::string data(kInvalidUTF8String);

  std::vector<std::string> errors;
  {
    ScopedMemoryLog log;
    WireFormat::VerifyUTF8String(data.data(), data.size(),
                                 WireFormat::SERIALIZE);
    errors = log.GetMessages(ERROR);
  }
#ifdef GOOGLE_PROTOBUF_UTF8_VALIDATION_ENABLED
  ASSERT_EQ(1, errors.size());
  EXPECT_TRUE(
      HasPrefixString(errors[0],
                       "String field contains invalid UTF-8 data when "
                       "serializing a protocol buffer. Use the "
                       "'bytes' type if you intend to send raw bytes."));
#else
  ASSERT_EQ(0, errors.size());
#endif
}