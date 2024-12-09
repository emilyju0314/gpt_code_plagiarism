TYPED_TEST_P(DwarfSectionImplTest, GetCieFromOffset_fail_should_not_cache) {
  ASSERT_TRUE(this->section_->GetCieFromOffset(0x4000) == nullptr);
  EXPECT_EQ(DWARF_ERROR_MEMORY_INVALID, this->section_->LastErrorCode());
  EXPECT_EQ(0x4000U, this->section_->LastErrorAddress());

  this->section_->FakeClearError();
  ASSERT_TRUE(this->section_->GetCieFromOffset(0x4000) == nullptr);
  EXPECT_EQ(DWARF_ERROR_MEMORY_INVALID, this->section_->LastErrorCode());
  EXPECT_EQ(0x4000U, this->section_->LastErrorAddress());
}