uint8_t STM32RTC::getAlarmMinutes(void)
{
  syncAlarmTime();
  return _alarmMinutes;
}