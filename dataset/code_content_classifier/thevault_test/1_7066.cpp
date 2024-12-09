bool Mailbox::WriteFanDutyCycle(uint16_t duty_cycle) {
  std::string value_str;

  ConvertUint16ToString(duty_cycle, &value_str);
  return WriteValueString(kMailboxFanPercentFile, value_str);
}