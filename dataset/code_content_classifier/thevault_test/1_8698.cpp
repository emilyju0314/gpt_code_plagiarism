static long
cal_reload_delay(long time_diff)
{
  if (time_diff > 3600) {
    return time_diff - 3600;
  } else if (time_diff > 900) {
    return time_diff - 900;
  } else {
    return time_diff;
  }
}