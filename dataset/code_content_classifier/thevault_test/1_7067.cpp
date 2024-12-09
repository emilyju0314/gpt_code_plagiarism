bool Mailbox::ReadFanDutyCycle(uint16_t *duty_cycle) {
  bool  rtn;
  std::string value_str;

  rtn = ReadValueString(kMailboxFanPercentFile, &value_str);
  if (rtn == true) {
    rtn = ConvertStringToUint16(value_str, duty_cycle);
  }
  return rtn;
}