uint8_t STM32RTC::getAlarmSeconds(void)
{
  syncAlarmTime();
  return _alarmSeconds;
}