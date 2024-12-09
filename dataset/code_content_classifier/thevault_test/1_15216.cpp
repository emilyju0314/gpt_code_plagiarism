uint8_t STM32RTC::getAlarmHours(AM_PM *period)
{
  syncAlarmTime();
  if (period != nullptr) {
    *period = _alarmPeriod;
  }
  return _alarmHours;
}