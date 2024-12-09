uint8_t STM32RTC::getAlarmDay(void)
{
  syncAlarmTime();
  return _alarmDay;
}