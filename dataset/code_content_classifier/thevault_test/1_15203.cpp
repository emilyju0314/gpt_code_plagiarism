void STM32RTC::getPrediv(uint32_t *predivA, int16_t *dummy)
{
  UNUSED(dummy);
  RTC_getPrediv(predivA);
}