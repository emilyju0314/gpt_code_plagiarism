bool Mailbox::ReadAux1Temperature(float *aux1_temperature) {
  std::string value_str;
  bool  rtn;

  *aux1_temperature = 0.0;
  rtn = ReadValueString(kMailboxAux1TemperatureFile, &value_str);
  if (rtn == true) {
    rtn = ConvertStringToFloat(value_str, aux1_temperature);
  }
  return rtn;
}