inline bool IDivFastPath(const Duration num, const Duration den, int64_t *q, Duration *rem) {
  // Bail if num or den is an infinity.
  if (time_internal::IsInfiniteDuration(num) || time_internal::IsInfiniteDuration(den))
    return false;

  int64_t num_hi = time_internal::GetRepHi(num);
  uint32_t num_lo = time_internal::GetRepLo(num);
  int64_t den_hi = time_internal::GetRepHi(den);
  uint32_t den_lo = time_internal::GetRepLo(den);

  if (den_hi == 0 && den_lo == kTicksPerNanosecond) {
    // Dividing by 1ns
    if (num_hi >= 0 && num_hi < (kint64max - kTicksPerSecond) / 1000000000) {
      *q = num_hi * 1000000000 + num_lo / kTicksPerNanosecond;
      *rem = time_internal::MakeDuration(0, num_lo % den_lo);
      return true;
    }
  } else if (den_hi == 0 && den_lo == 100 * kTicksPerNanosecond) {
    // Dividing by 100ns (common when converting to Universal time)
    if (num_hi >= 0 && num_hi < (kint64max - kTicksPerSecond) / 10000000) {
      *q = num_hi * 10000000 + num_lo / (100 * kTicksPerNanosecond);
      *rem = time_internal::MakeDuration(0, num_lo % den_lo);
      return true;
    }
  } else if (den_hi == 0 && den_lo == 1000 * kTicksPerNanosecond) {
    // Dividing by 1us
    if (num_hi >= 0 && num_hi < (kint64max - kTicksPerSecond) / 1000000) {
      *q = num_hi * 1000000 + num_lo / (1000 * kTicksPerNanosecond);
      *rem = time_internal::MakeDuration(0, num_lo % den_lo);
      return true;
    }
  } else if (den_hi == 0 && den_lo == 1000000 * kTicksPerNanosecond) {
    // Dividing by 1ms
    if (num_hi >= 0 && num_hi < (kint64max - kTicksPerSecond) / 1000) {
      *q = num_hi * 1000 + num_lo / (1000000 * kTicksPerNanosecond);
      *rem = time_internal::MakeDuration(0, num_lo % den_lo);
      return true;
    }
  } else if (den_hi > 0 && den_lo == 0) {
    // Dividing by positive multiple of 1s
    if (num_hi >= 0) {
      if (den_hi == 1) {
        *q = num_hi;
        *rem = time_internal::MakeDuration(0, num_lo);
        return true;
      }
      *q = num_hi / den_hi;
      *rem = time_internal::MakeDuration(num_hi % den_hi, num_lo);
      return true;
    }
    if (num_lo != 0) {
      num_hi += 1;
    }
    int64_t quotient = num_hi / den_hi;
    int64_t rem_sec = num_hi % den_hi;
    if (rem_sec > 0) {
      rem_sec -= den_hi;
      quotient += 1;
    }
    if (num_lo != 0) {
      rem_sec -= 1;
    }
    *q = quotient;
    *rem = time_internal::MakeDuration(rem_sec, num_lo);
    return true;
  }

  return false;
}