inline uint128 MakeU128(int64_t a) {
  uint128 u128 = 0;
  if (a < 0) {
    ++u128;
    ++a; // Makes it safe to negate 'a'
    a = -a;
  }
  u128 += static_cast<uint64_t>(a);
  return u128;
}