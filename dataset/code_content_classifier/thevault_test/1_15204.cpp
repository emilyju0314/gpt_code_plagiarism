void STM32RTC::getPrediv(int8_t *predivA, int16_t *predivS)
{
  if ((predivA != nullptr) && (predivS != nullptr)) {
    RTC_getPrediv(predivA, predivS);
  }
}