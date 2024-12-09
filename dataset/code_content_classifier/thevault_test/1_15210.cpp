uint8_t STM32RTC::getDay(void)
{
  syncDate();
  return _day;
}