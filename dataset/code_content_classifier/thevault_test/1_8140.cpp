void Vl53l1x::writeReg16Bit(uint16_t reg, uint16_t value)
{
  uint8_t writeBuffer[4];

  writeBuffer[0] = ((reg >> 8)   & 0xFF);  // reg high byte
  writeBuffer[1] = ( reg         & 0xFF);  // reg low byte
  writeBuffer[2] = ((value >> 8) & 0xFF);  // value high byte
  writeBuffer[3] = ( value       & 0xFF);  // value low byte

  auto result = write(fd, writeBuffer, sizeof(writeBuffer));
  last_status = (result > 0) ? 0 : 1;
}