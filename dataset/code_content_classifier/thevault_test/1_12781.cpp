unsigned int CSCMotherboard::encodePattern(const int ptn,
                                           const int stripType) const {
  const int kPatternBitWidth = 4;

  // In the TMB07 firmware, LCT pattern is just a 4-bit CLCT pattern.
  unsigned int pattern = (abs(ptn) & ((1<<kPatternBitWidth)-1));

  return pattern;
}