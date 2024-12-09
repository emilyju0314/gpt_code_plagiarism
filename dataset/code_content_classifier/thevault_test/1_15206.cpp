uint8_t STM32RTC::getSeconds(void)
{
  syncTime();
  return _seconds;
}