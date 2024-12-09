uint32_t STM32RTC::getSubSeconds(void)
{
  syncTime();
  return _subSeconds;
}