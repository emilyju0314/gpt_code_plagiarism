inline Duration MakeDurationFromU128(uint128 u128, bool is_neg) {
  int64_t rep_hi;
  uint32_t rep_lo;
  const uint64_t h64 = Uint128High64(u128);
  const uint64_t l64 = Uint128Low64(u128);
  if (h64 == 0) { // fastpath
    const uint64_t hi = l64 / kTicksPerSecond;
    rep_hi = static_cast<int64_t>(hi);
    rep_lo = static_cast<uint32_t>(l64 - hi * kTicksPerSecond);
  } else {
    // kMaxRepHi64 is the high 64 bits of (2^63 * kTicksPerSecond).
    // Any positive tick count whose high 64 bits are >= kMaxRepHi64
    // is not representable as a Duration.  A negative tick count can
    // have its high 64 bits == kMaxRepHi64 but only when the low 64
    // bits are all zero, otherwise it is not representable either.
    const uint64_t kMaxRepHi64 = 0x77359400UL;
    if (h64 >= kMaxRepHi64) {
      if (is_neg && h64 == kMaxRepHi64 && l64 == 0) {
        // Avoid trying to represent -kint64min below.
        return time_internal::MakeDuration(kint64min);
      }
      return is_neg ? -InfiniteDuration() : InfiniteDuration();
    }
    const uint128 kTicksPerSecond128 = static_cast<uint64_t>(kTicksPerSecond);
    const uint128 hi = u128 / kTicksPerSecond128;
    rep_hi = static_cast<int64_t>(Uint128Low64(hi));
    rep_lo = static_cast<uint32_t>(Uint128Low64(u128 - hi * kTicksPerSecond128));
  }
  if (is_neg) {
    rep_hi = -rep_hi;
    if (rep_lo != 0) {
      --rep_hi;
      rep_lo = kTicksPerSecond - rep_lo;
    }
  }
  return time_internal::MakeDuration(rep_hi, rep_lo);
}