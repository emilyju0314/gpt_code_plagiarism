static constexpr unsigned short GenerateCrc(unsigned char i) {
  unsigned short crc = i;

  for (size_t bit = 0; bit < 16; ++bit) {
    if (crc & 0x8000) {
      crc = (crc << 1) ^ 0x1021;
    } else {
      crc <<= 1;
    }
  }

  return crc;
}