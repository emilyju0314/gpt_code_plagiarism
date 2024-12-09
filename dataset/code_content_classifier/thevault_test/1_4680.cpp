TYPED_TEST_P(DwarfEhFrameWithHdrTest, Init) {
  this->memory_.SetMemory(
      0x1000, std::vector<uint8_t>{0x1, DW_EH_PE_udata2, DW_EH_PE_udata4, DW_EH_PE_sdata4});
  this->memory_.SetData16(0x1004, 0x500);
  this->memory_.SetData32(0x1006, 126);

  ASSERT_TRUE(this->eh_frame_->Init(0x1000, 0x100, 0));
  EXPECT_EQ(1U, this->eh_frame_->TestGetVersion());
  EXPECT_EQ(DW_EH_PE_sdata4, this->eh_frame_->TestGetTableEncoding());
  EXPECT_EQ(4U, this->eh_frame_->TestGetTableEntrySize());
  EXPECT_EQ(126U, this->eh_frame_->TestGetFdeCount());
  EXPECT_EQ(0x100aU, this->eh_frame_->TestGetHdrEntriesOffset());
  EXPECT_EQ(0x1000U, this->eh_frame_->TestGetHdrEntriesDataOffset());

  // Verify a zero table entry size fails to init.
  this->memory_.SetData8(0x1003, 0x1);
  ASSERT_FALSE(this->eh_frame_->Init(0x1000, 0x100, 0));
  ASSERT_EQ(DWARF_ERROR_ILLEGAL_VALUE, this->eh_frame_->LastErrorCode());
  // Reset the value back to the original.
  this->memory_.SetData8(0x1003, DW_EH_PE_sdata4);

  // Verify a zero fde count fails to init.
  this->memory_.SetData32(0x1006, 0);
  ASSERT_FALSE(this->eh_frame_->Init(0x1000, 0x100, 0));
  ASSERT_EQ(DWARF_ERROR_NO_FDES, this->eh_frame_->LastErrorCode());

  // Verify an unexpected version will cause a fail.
  this->memory_.SetData32(0x1006, 126);
  this->memory_.SetData8(0x1000, 0);
  ASSERT_FALSE(this->eh_frame_->Init(0x1000, 0x100, 0));
  ASSERT_EQ(DWARF_ERROR_UNSUPPORTED_VERSION, this->eh_frame_->LastErrorCode());
  this->memory_.SetData8(0x1000, 2);
  ASSERT_FALSE(this->eh_frame_->Init(0x1000, 0x100, 0));
  ASSERT_EQ(DWARF_ERROR_UNSUPPORTED_VERSION, this->eh_frame_->LastErrorCode());
}