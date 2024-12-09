void AMS_5600::setOutPut(uint8_t mode)
{
  int _conf_lo = _addr_conf+1; // lower byte address
  uint8_t config_status;
  config_status = readOneByte(_conf_lo);
  if (mode == 1) {
    config_status = config_status & 0xcf;
  } else {
    uint8_t config_status;
    config_status = readOneByte(_conf_lo);
    if (mode == 1)
      config_status = config_status & 0xcf;
    else
      config_status = config_status & 0xef;
    writeOneByte(_conf_lo, lowByte(config_status));
  }
}