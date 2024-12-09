int64_t IDivDuration(bool satq, const Duration num, const Duration den, Duration *rem) {
  int64_t q = 0;
  if (IDivFastPath(num, den, &q, rem)) {
    return q;
  }

  const bool num_neg = num < ZeroDuration();
  const bool den_neg = den < ZeroDuration();
  const bool quotient_neg = num_neg != den_neg;

  if (time_internal::IsInfiniteDuration(num) || den == ZeroDuration()) {
    *rem = num_neg ? -InfiniteDuration() : InfiniteDuration();
    return quotient_neg ? kint64min : kint64max;
  }
  if (time_internal::IsInfiniteDuration(den)) {
    *rem = num;
    return 0;
  }

  const uint128 a = MakeU128Ticks(num);
  const uint128 b = MakeU128Ticks(den);
  uint128 quotient128 = a / b;

  if (satq) {
    // Limits the quotient to the range of int64_t.
    if (quotient128 > uint128(static_cast<uint64_t>(kint64max))) {
      quotient128 =
          quotient_neg ? uint128(static_cast<uint64_t>(kint64min)) : uint128(static_cast<uint64_t>(kint64max));
    }
  }

  const uint128 remainder128 = a - quotient128 * b;
  *rem = MakeDurationFromU128(remainder128, num_neg);

  if (!quotient_neg || quotient128 == 0) {
    return Uint128Low64(quotient128) & kint64max;
  }
  // The quotient needs to be negated, but we need to carefully handle
  // quotient128s with the top bit on.
  return -static_cast<int64_t>(Uint128Low64(quotient128 - 1) & kint64max) - 1;
}