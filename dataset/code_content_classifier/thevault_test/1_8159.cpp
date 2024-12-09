int64_t ToInt64Nanoseconds(Duration d) {
  if (time_internal::GetRepHi(d) >= 0 && time_internal::GetRepHi(d) >> 33 == 0) {
    return (time_internal::GetRepHi(d) * 1000 * 1000 * 1000) + (time_internal::GetRepLo(d) / kTicksPerNanosecond);
  }
  return d / Nanoseconds(1);
}