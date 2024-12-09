u16 ExcaliburFemClient::powerCardAD7998Read(unsigned int aDevice, unsigned int aChan)
{

  // Calculate address pointer to send to ADC
  u8 addrPtr = 0x80 | (aChan << 4);

  // Send channel select command to ADC
  std::vector<u8> cmd(2);
  cmd[0] = 0;
  cmd[1] = addrPtr;

  this->i2cWrite(kPwrCardAD7998Address[aDevice], cmd);

  // Wait 100ms
  struct timespec sleep;
  sleep.tv_sec = 0;
  sleep.tv_nsec = 100000000;
  nanosleep(&sleep, NULL);

  // Read two bytes back
  std::vector<u8> response = this->i2cRead(kPwrCardAD7998Address[aDevice], 2);

  // Decode ADC value to return
  u16 adcVal = ((((u16) response[0]) << 8) | response[1]) & 0xFFF;

  return adcVal;
}