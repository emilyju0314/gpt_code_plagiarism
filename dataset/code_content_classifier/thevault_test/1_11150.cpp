static int RadicalPreHash(const std::vector<int> &rs) {
  size_t result = 0;
  for (int radical : rs) {
    result *= kRadicalRadix;
    result += radical;
  }
  return result;
}