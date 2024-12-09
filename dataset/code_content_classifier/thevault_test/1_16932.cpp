TEST_F(HpackWholeEntryBufferTest, OnIndexedHeader) {
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnIndexedHeader(17));
    entry_buffer_.OnIndexedHeader(17);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnIndexedHeader(62));
    entry_buffer_.OnIndexedHeader(62);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnIndexedHeader(62));
    entry_buffer_.OnIndexedHeader(62);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnIndexedHeader(128));
    entry_buffer_.OnIndexedHeader(128);
  }
  StrictMock<MockHpackWholeEntryListener> listener2;
  entry_buffer_.set_listener(&listener2);
  {
    InSequence seq;
    EXPECT_CALL(listener2, OnIndexedHeader(100));
    entry_buffer_.OnIndexedHeader(100);
  }
}