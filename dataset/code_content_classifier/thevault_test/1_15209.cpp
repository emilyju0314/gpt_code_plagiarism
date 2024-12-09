uint8_t STM32RTC::getWeekDay(void)
{
  syncDate();
  return _wday;
}