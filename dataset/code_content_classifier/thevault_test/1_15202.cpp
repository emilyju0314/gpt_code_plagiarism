void STM32RTC::end(void)
{
  if (_configured == true) {
    RTC_DeInit();
    _configured = false;
    _alarmEnabled = false;
  }
}