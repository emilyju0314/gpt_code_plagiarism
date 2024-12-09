uint8_t STM32RTC::getMinutes(void)
{
  syncTime();
  return _minutes;
}