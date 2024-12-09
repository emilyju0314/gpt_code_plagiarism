time_t RecordFileStat::GetCutDownTime(int maxsize) {
  int offset = total_count_ - maxsize;

  // 3600 (minutes) * 24 hours
  // newest_ uses minute as unit, 
  // very_old_ means the count that before 1000(kDays) days plus 100(kHours) hours
  if (very_old_ >= offset) {
    return newest_ - kDays * 3600 * 24LL - kHours * 3600;
  }

  // days_[i] means the count in the day that is i days plus 100(kHours) hours before.
  int sum = very_old_;
  for (int i = kDays - 1; i >= 0; --i) {
    sum += days_[i];
    if (sum >= offset) {
      return newest_ - i * 3600 * 24LL - kHours * 3600;
    }
  }
 
  // hours_[i] means the count in the hour that is i hours before.
  for (int i = kHours - 1; i >= 0; --i) {
    sum += hours_[i];
    if (sum >= offset) {
      return newest_ - i * 3600;
    }
  }

  return newest_;
}