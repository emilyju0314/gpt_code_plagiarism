uint32_t littleendian(std::vector<uint8_t> b) {
  assert(b.size() == 4);

  uint32_t x = 0;

  for (size_t i = 0; i < 4; ++i) {
    x = x | (b.at(i) << (8 * i));
  }

  return x;
}