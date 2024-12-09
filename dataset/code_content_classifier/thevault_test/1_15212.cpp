uint8_t STM32RTC::getYear(void)
{
  syncDate();
  return _year;
}