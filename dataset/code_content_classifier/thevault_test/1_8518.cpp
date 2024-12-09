std::vector<uint8_t> littleendianInverse(uint32_t x) {
  std::vector<uint8_t> b = {};
  b.push_back((x & 0x000000ff));
  b.push_back((x & 0x0000ff00) >> 8);
  b.push_back((x & 0x00ff0000) >> 16);
  b.push_back((x & 0xff000000) >> 24);

  return b;
}