inline std::pair<uint64_t, uint64_t> PowFive(uint64_t num, int expfive) {
  std::pair<uint64_t, uint64_t> result = {num, 0};
  while (expfive >= 13) {
    // 5^13 is the highest power of five that will fit in a 32-bit integer.
    result = Mul32(result, 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5);
    expfive -= 13;
  }
  constexpr int powers_of_five[13] = {1,
                                      5,
                                      5 * 5,
                                      5 * 5 * 5,
                                      5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5,
                                      5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5};
  result = Mul32(result, powers_of_five[expfive & 15]);
  int shift = std::countl_zero(result.first);
  if (shift != 0) {
    result.first = (result.first << shift) + (result.second >> (64 - shift));
    result.second = (result.second << shift);
  }
  return result;
}