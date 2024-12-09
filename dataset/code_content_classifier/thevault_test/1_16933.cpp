TEST_F(HpackWholeEntryBufferTest, OnDynamicTableSizeUpdate) {
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnDynamicTableSizeUpdate(4096));
    entry_buffer_.OnDynamicTableSizeUpdate(4096);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnDynamicTableSizeUpdate(0));
    entry_buffer_.OnDynamicTableSizeUpdate(0);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnDynamicTableSizeUpdate(1024));
    entry_buffer_.OnDynamicTableSizeUpdate(1024);
  }
  {
    InSequence seq;
    EXPECT_CALL(listener_, OnDynamicTableSizeUpdate(1024));
    entry_buffer_.OnDynamicTableSizeUpdate(1024);
  }
  StrictMock<MockHpackWholeEntryListener> listener2;
  entry_buffer_.set_listener(&listener2);
  {
    InSequence seq;
    EXPECT_CALL(listener2, OnDynamicTableSizeUpdate(0));
    entry_buffer_.OnDynamicTableSizeUpdate(0);
  }
}