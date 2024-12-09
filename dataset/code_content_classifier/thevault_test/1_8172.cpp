inline uint64 Hash128to64(const uint128 &x) {
  // Murmur-inspired hashing.
  const uint64 kMul = 0x9ddfea08eb382d69ULL;
  uint64 a = (bela::Uint128Low64(x) ^ bela::Uint128High64(x)) * kMul;
  a ^= (a >> 47);
  uint64 b = (bela::Uint128High64(x) ^ a) * kMul;
  b ^= (b >> 47);
  b *= kMul;
  return b;
}