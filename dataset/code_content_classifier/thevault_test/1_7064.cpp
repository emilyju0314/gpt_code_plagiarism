bool Mailbox::ReadSocTemperature(float *soc_temperature) {
  std::string value_str;
  bool  rtn;

  *soc_temperature = 0.0;
  rtn = ReadValueString(kMailboxCpuTemperatureFile, &value_str);
  if (rtn == true) {
    rtn = ConvertStringToFloat(value_str, soc_temperature);
  }
  return rtn;
}