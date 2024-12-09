void STM32RTC::syncTime(void)
{
  if (_configured) {
    hourAM_PM_t p = HOUR_AM;
    RTC_GetTime(&_hours, &_minutes, &_seconds, &_subSeconds, &p);
    _hoursPeriod = (p == HOUR_AM) ? AM : PM;
  }
}