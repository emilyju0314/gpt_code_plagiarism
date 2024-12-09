TEST_F(HpackWholeEntryBufferTest, ValueTooLong) {
  entry_buffer_.OnStartLiteralHeader(HpackEntryType::kIndexedLiteralHeader, 0);
  EXPECT_CALL(listener_,
              OnHpackDecodeError(
                  HpackDecodingError::kValueTooLong,
                  "Value length (21) of [path] is longer than permitted (20)"));
  entry_buffer_.OnNameStart(false, 4);
  entry_buffer_.OnNameData("path", 4);
  entry_buffer_.OnNameEnd();
  entry_buffer_.OnValueStart(false, kMaxStringSize + 1);
}