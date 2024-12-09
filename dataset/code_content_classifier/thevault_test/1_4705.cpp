TYPED_TEST_P(DwarfCfaTest, cfa_offset) {
  this->memory_.SetMemory(0x2000, std::vector<uint8_t>{0x83, 0x04});
  DwarfLocations loc_regs;

  ASSERT_TRUE(this->cfa_->GetLocationInfo(this->fde_.pc_start, 0x2000, 0x2002, &loc_regs));
  ASSERT_EQ(0x2002U, this->dmem_->cur_offset());
  ASSERT_EQ(1U, loc_regs.size());
  auto location = loc_regs.find(3);
  ASSERT_NE(loc_regs.end(), location);
  ASSERT_EQ(DWARF_LOCATION_OFFSET, location->second.type);
  ASSERT_EQ(32U, location->second.values[0]);

  ASSERT_EQ("", GetFakeLogPrint());
  ASSERT_EQ("", GetFakeLogBuf());

  ResetLogs();
  this->memory_.SetMemory(0x2100, std::vector<uint8_t>{0x83, 0x84, 0x01});
  loc_regs.clear();

  ASSERT_TRUE(this->cfa_->GetLocationInfo(this->fde_.pc_start, 0x2100, 0x2103, &loc_regs));
  ASSERT_EQ(0x2103U, this->dmem_->cur_offset());
  ASSERT_EQ(1U, loc_regs.size());
  location = loc_regs.find(3);
  ASSERT_NE(loc_regs.end(), location);
  ASSERT_EQ(DWARF_LOCATION_OFFSET, location->second.type);
  ASSERT_EQ(1056U, location->second.values[0]);

  ASSERT_EQ("", GetFakeLogPrint());
  ASSERT_EQ("", GetFakeLogBuf());
}