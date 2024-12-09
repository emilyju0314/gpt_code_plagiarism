TEST_F(HpackWholeEntryBufferTest, NameHuffmanError) {
  const char data[] = "\xff\xff\xff";
  entry_buffer_.OnStartLiteralHeader(HpackEntryType::kUnindexedLiteralHeader,
                                     0);
  entry_buffer_.OnNameStart(true, 4);
  entry_buffer_.OnNameData(data, 3);

  EXPECT_CALL(listener_,
              OnHpackDecodeError(HpackDecodingError::kNameHuffmanError, _));

  entry_buffer_.OnNameData(data, 1);

  // After an error is reported, the listener is not called again.
  EXPECT_CALL(listener_, OnDynamicTableSizeUpdate(8096)).Times(0);
  entry_buffer_.OnDynamicTableSizeUpdate(8096);
}