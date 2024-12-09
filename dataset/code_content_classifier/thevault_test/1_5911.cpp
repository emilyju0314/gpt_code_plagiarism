constexpr std::size_t fmtLength(int i) {
  std::size_t digits{i < 0 ? 1u : 0u};
  while (i != 0) {
    i /= 10;
    ++digits;
  }
  return digits;
}