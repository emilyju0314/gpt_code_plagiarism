void STM32RTC::syncDate(void)
{
  if (_configured) {
    RTC_GetDate(&_year, &_month, &_day, &_wday);
  }
}