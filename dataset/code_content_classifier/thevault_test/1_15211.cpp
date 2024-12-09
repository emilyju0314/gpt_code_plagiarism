uint8_t STM32RTC::getMonth(void)
{
  syncDate();
  return _month;
}