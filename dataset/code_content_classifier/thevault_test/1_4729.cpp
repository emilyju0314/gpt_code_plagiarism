TEST_F(SubmissionTrackerTest, MarkCommandBufferEndWontWriteTimestampsInInitialState) {
  EXPECT_CALL(timer_query_pool_, NextReadyQuerySlot)
      .Times(1)
      .WillOnce(Invoke(MockNextReadyQuerySlot1));
  std::vector<uint32_t> actual_slots_to_rollback;
  EXPECT_CALL(timer_query_pool_, RollbackPendingQuerySlots)
      .Times(1)
      .WillOnce(SaveArg<1>(&actual_slots_to_rollback));
  EXPECT_CALL(dispatch_table_, CmdWriteTimestamp)
      .Times(1)
      .WillOnce(Return(dummy_write_timestamp_function));

  producer_->StartCapture();
  tracker_.TrackCommandBuffers(device_, command_pool_, &command_buffer_, 1);
  tracker_.MarkCommandBufferBegin(command_buffer_);
  tracker_.ResetCommandBuffer(command_buffer_);
  tracker_.MarkCommandBufferEnd(command_buffer_);

  EXPECT_THAT(actual_slots_to_rollback, UnorderedElementsAre(kSlotIndex1));
}