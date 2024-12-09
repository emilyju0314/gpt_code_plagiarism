TYPED_TEST_P(DwarfEhFrameWithHdrTest, GetFdeInfoFromIndex_read_pcrel) {
  this->eh_frame_->TestSetTableEncoding(DW_EH_PE_pcrel | DW_EH_PE_udata4);
  this->eh_frame_->TestSetHdrEntriesOffset(0x1000);
  this->eh_frame_->TestSetHdrEntriesDataOffset(0x3000);
  this->eh_frame_->TestSetTableEntrySize(0x10);

  this->memory_.SetData32(0x1040, 0x340);
  this->memory_.SetData32(0x1044, 0x500);

  auto info = this->eh_frame_->GetFdeInfoFromIndex(2);
  ASSERT_TRUE(info != nullptr);
  EXPECT_EQ(0x340U, info->pc);
  EXPECT_EQ(0x500U, info->offset);
}