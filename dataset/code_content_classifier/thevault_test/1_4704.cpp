TYPED_TEST_P(DwarfCfaTest, cfa_illegal) {
  for (uint8_t i = 0x17; i < 0x3f; i++) {
    if (i == 0x2d || i == 0x2e || i == 0x2f) {
      // Skip gnu extension ops and aarch64 specialized op.
      continue;
    }
    this->memory_.SetMemory(0x2000, std::vector<uint8_t>{i});
    DwarfLocations loc_regs;

    ASSERT_FALSE(this->cfa_->GetLocationInfo(this->fde_.pc_start, 0x2000, 0x2001, &loc_regs));
    ASSERT_EQ(DWARF_ERROR_ILLEGAL_VALUE, this->cfa_->LastErrorCode());
    ASSERT_EQ(0x2001U, this->dmem_->cur_offset());

    ASSERT_EQ("", GetFakeLogPrint());
    ASSERT_EQ("", GetFakeLogBuf());
  }
}