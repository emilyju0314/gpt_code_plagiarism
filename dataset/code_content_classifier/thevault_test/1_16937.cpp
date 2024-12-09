TEST_F(HpackWholeEntryBufferTest, ValueHuffmanError) {
  const char data[] = "\x00\x00\x00";
  entry_buffer_.OnStartLiteralHeader(HpackEntryType::kNeverIndexedLiteralHeader,
                                     61);
  entry_buffer_.OnValueStart(true, 3);
  entry_buffer_.OnValueData(data, 3);

  EXPECT_CALL(listener_,
              OnHpackDecodeError(HpackDecodingError::kValueHuffmanError, _));

  entry_buffer_.OnValueEnd();

  // After an error is reported, the listener is not called again.
  EXPECT_CALL(listener_, OnIndexedHeader(17)).Times(0);
  entry_buffer_.OnIndexedHeader(17);
}