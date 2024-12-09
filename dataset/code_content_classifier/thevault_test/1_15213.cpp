uint32_t STM32RTC::getAlarmSubSeconds(void)
{
  syncAlarmTime();
  return _alarmSubSeconds;
}