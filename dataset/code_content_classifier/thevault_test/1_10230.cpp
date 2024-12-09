uint8_t adns_9800::read_reg(uint8_t const address)
{
  com_begin();
  
  // send adress of the register, with MSBit = 0 to indicate it's a read
  m_spi.write(address & 0x7f );
  wait_us(100); // tSRAD
  // read data
  uint8_t data = m_spi.write(0);
  
  wait_us(1); // tSCLK-NCS for read operation is 120ns
  com_end();
  wait_us(19); //  tSRW/tSRR (=20us) minus tSCLK-NCS

  return data; 
}