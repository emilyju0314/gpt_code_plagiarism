void Vl53l1x::writeReg32Bit(uint16_t reg, uint32_t value)
{
  uint8_t writeBuffer[6];

  writeBuffer[0] = ((reg >> 8)   & 0xFF);  // reg high byte
  writeBuffer[1] = ( reg         & 0xFF);  // reg low byte
  writeBuffer[2] = ((value >> 24) & 0xFF);  // value highest byte
  writeBuffer[3] = ((value >> 16) & 0xFF);
  writeBuffer[4] = ((value >>  8) & 0xFF);
  writeBuffer[5] = ( value       & 0xFF);  // value lowest byte

  auto result = write(fd, writeBuffer, sizeof(writeBuffer));
  last_status = (result > 0) ? 0 : 1;
}