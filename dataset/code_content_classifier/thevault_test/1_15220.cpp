uint32_t STM32RTC::getEpoch(uint32_t *subSeconds)
{
  struct tm tm;

  syncDate();
  syncTime();

  tm.tm_isdst = -1;
  /*
   * mktime ignores the values supplied by the caller in the
   * tm_wday and tm_yday fields
   */
  tm.tm_yday = 0;
  tm.tm_wday = 0;
  tm.tm_year = _year + EPOCH_TIME_YEAR_OFF;
  tm.tm_mon = _month - 1;
  tm.tm_mday = _day;
  tm.tm_hour = _hours;
  tm.tm_min = _minutes;
  tm.tm_sec = _seconds;
  if (subSeconds != nullptr) {
    *subSeconds = _subSeconds;
  }

  return mktime(&tm);
}