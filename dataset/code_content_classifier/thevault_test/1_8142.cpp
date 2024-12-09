uint8_t Vl53l1x::readReg(uint16_t reg)
{
  uint8_t  writeBuffer[2];

  writeBuffer[0] = ((reg >> 8) & 0xFF);  // reg high byte
  writeBuffer[1] = (reg        & 0xFF);  // reg low byte


  if( write(fd, writeBuffer, sizeof(writeBuffer)) < sizeof(writeBuffer)) {
    //something went wrong
    std::cout << "DEBUG: ERROR on write to i2c" << std::endl;
    return 0x00;
  }

  uint8_t readBuffer[1];
  read(fd, readBuffer, sizeof(readBuffer));

  return readBuffer[0];
}