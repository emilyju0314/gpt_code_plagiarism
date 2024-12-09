void STM32RTC::setEpoch(uint32_t ts, uint32_t subSeconds)
{
  if (_configured) {
    if (ts < EPOCH_TIME_OFF) {
      ts = EPOCH_TIME_OFF;
    }

    time_t t = ts;
    struct tm *tmp = gmtime(&t);

    _year = tmp->tm_year - EPOCH_TIME_YEAR_OFF;
    _month = tmp->tm_mon + 1;
    _day = tmp->tm_mday;
    if (tmp->tm_wday == 0) {
      _wday = RTC_WEEKDAY_SUNDAY;
    } else {
      _wday = tmp->tm_wday;
    }
    _hours = tmp->tm_hour;
    _minutes = tmp->tm_min;
    _seconds = tmp->tm_sec;
    _subSeconds = subSeconds;

    RTC_SetDate(_year, _month, _day, _wday);
    RTC_SetTime(_hours, _minutes, _seconds, _subSeconds, (_hoursPeriod == AM) ? HOUR_AM : HOUR_PM);
  }
}