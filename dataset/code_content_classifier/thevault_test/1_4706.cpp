TYPED_TEST_P(DwarfCfaTest, cfa_state_cfa_offset_restore) {
  this->memory_.SetMemory(0x3000, std::vector<uint8_t>{0x0a, 0x0e, 0x40, 0x0b});
  DwarfLocations loc_regs;
  loc_regs[CFA_REG] = {.type = DWARF_LOCATION_REGISTER, .values = {5, 100}};

  ASSERT_TRUE(this->cfa_->GetLocationInfo(this->fde_.pc_start, 0x3000, 0x3004, &loc_regs));
  ASSERT_EQ(0x3004U, this->dmem_->cur_offset());
  ASSERT_EQ(1U, loc_regs.size());
  ASSERT_EQ(DWARF_LOCATION_REGISTER, loc_regs[CFA_REG].type);
  ASSERT_EQ(5U, loc_regs[CFA_REG].values[0]);
  ASSERT_EQ(100U, loc_regs[CFA_REG].values[1]);

  ASSERT_EQ("", GetFakeLogPrint());
  ASSERT_EQ("", GetFakeLogBuf());
}