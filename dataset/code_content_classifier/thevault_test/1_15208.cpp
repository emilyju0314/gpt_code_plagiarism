uint8_t STM32RTC::getHours(AM_PM *period)
{
  syncTime();
  if (period != nullptr) {
    *period = _hoursPeriod;
  }
  return _hours;
}