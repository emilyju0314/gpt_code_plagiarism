void RFM::setFrequency(uint32_t freqHz)
{
  // TODO: p38 hopping sequence may need to be followed in some cases
  freqHz /= RF69OOK_FSTEP; // divide down by FSTEP to get FRF
  writeReg(RFM69_REG_FRFMSB, freqHz >> 16);
  writeReg(RFM69_REG_FRFMID, freqHz >> 8);
  writeReg(RFM69_REG_FRFLSB, freqHz);
}