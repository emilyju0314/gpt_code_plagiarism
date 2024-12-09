void Vl53l1x::writeReg(uint16_t reg, uint8_t value)
{
  uint8_t writeBuffer[3];

  writeBuffer[0] = ((reg >> 8) & 0xFF);  // reg high byte
  writeBuffer[1] = ( reg       & 0xFF);  // reg low byte
  writeBuffer[2] = value;

  auto result = write(fd, writeBuffer, sizeof(writeBuffer));
  last_status = (result > 0) ? 0 : 1;
}