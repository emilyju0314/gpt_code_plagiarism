void STM32RTC::setAlarmTime(uint8_t hours, uint8_t minutes, uint8_t seconds, uint32_t subSeconds, AM_PM period)
{
  if (_configured) {
    setAlarmHours(hours, period);
    setAlarmMinutes(minutes);
    setAlarmSeconds(seconds);
    setAlarmSubSeconds(subSeconds);
  }
}