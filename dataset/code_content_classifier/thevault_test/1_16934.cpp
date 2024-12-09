TEST_F(HpackWholeEntryBufferTest, NameTooLong) {
  entry_buffer_.OnStartLiteralHeader(HpackEntryType::kIndexedLiteralHeader, 0);
  EXPECT_CALL(listener_,
              OnHpackDecodeError(HpackDecodingError::kNameTooLong, _));
  entry_buffer_.OnNameStart(false, kMaxStringSize + 1);
}