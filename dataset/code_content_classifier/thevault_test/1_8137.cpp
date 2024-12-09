uint16_t Vl53l1x::readSingle(bool blocking)
{
  writeReg(SYSTEM__INTERRUPT_CLEAR, 0x01); // sys_interrupt_clear_range
  writeReg(SYSTEM__MODE_START, 0x10); // mode_range__single_shot

  if (blocking)
  {
    return read_range(true);
  }
  else
  {
    return 0;
  }
}