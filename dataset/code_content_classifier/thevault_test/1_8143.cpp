uint16_t Vl53l1x::readReg16Bit(uint16_t reg) {

  uint8_t  writeBuffer[2];
  writeBuffer[0] = ((reg >> 8) & 0xFF);  // reg high byte
  writeBuffer[1] = (reg        & 0xFF);  // reg low byte

  if( write(fd, writeBuffer, sizeof(writeBuffer)) < sizeof(writeBuffer)) {
    //something went wrong
    std::cout << "ERROR on write to i2c" << std::endl;
    return 0x0000;
  }

  uint8_t readBuffer[2];
  if( read(fd, readBuffer, sizeof(readBuffer)) < sizeof(readBuffer)) {
    std::cout << "Error on read from i2c" << std::endl;
    return 0x0000;
  }

  uint16_t value = (uint16_t)readBuffer[0] << 8;  //value high byte
  value |= readBuffer[1];                         // value low byte

  return value;
}