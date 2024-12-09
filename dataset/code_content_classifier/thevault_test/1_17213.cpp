std::unique_ptr<uint8_t[]> CreateTestBuffer(size_t size, size_t offset) {
  std::unique_ptr<uint8_t[]> buf(new uint8_t[size]);
  for (size_t i = 0; i < size; ++i)
    buf.get()[i] = static_cast<uint8_t>((offset + i) % 253);
  return buf;
}