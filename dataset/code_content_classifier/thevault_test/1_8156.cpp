inline bool SafeAddRepHi(double a_hi, double b_hi, Duration *d) {
  double c = a_hi + b_hi;
  if (c >= static_cast<double>(kint64max)) {
    *d = InfiniteDuration();
    return false;
  }
  if (c <= static_cast<double>(kint64min)) {
    *d = -InfiniteDuration();
    return false;
  }
  *d = time_internal::MakeDuration(static_cast<int64_t>(c), time_internal::GetRepLo(*d));
  return true;
}