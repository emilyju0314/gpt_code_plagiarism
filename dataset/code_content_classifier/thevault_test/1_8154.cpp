inline uint128 MakeU128Ticks(Duration d) {
  int64_t rep_hi = time_internal::GetRepHi(d);
  uint32_t rep_lo = time_internal::GetRepLo(d);
  if (rep_hi < 0) {
    ++rep_hi;
    rep_hi = -rep_hi;
    rep_lo = kTicksPerSecond - rep_lo;
  }
  uint128 u128 = static_cast<uint64_t>(rep_hi);
  u128 *= static_cast<uint64_t>(kTicksPerSecond);
  u128 += rep_lo;
  return u128;
}