void STM32RTC::configForLowPower(Source_Clock source)
{
#if defined(HAL_PWR_MODULE_ENABLED)
#ifdef __HAL_RCC_RTCAPB_CLKAM_ENABLE
  __HAL_RCC_RTCAPB_CLKAM_ENABLE();
#endif
  if (!_configured) {
    _clockSource = source;
    // Enable RTC
    begin();
  } else {
    if (_clockSource != source) {
      // Save current config
      AM_PM period, alarmPeriod = _alarmPeriod;
      uint32_t subSeconds;
      uint8_t seconds, minutes, hours, weekDay, day, month, years;
      uint8_t alarmSeconds, alarmMinutes, alarmHours, alarmDay;
      Alarm_Match alarmMatch = _alarmMatch;
      bool alarmEnabled = _alarmEnabled;

      alarmDay = _alarmDay;
      alarmHours = _alarmHours;
      alarmMinutes = _alarmMinutes;
      alarmSeconds = _alarmSeconds;

      getDate(&weekDay, &day, &month, &years);
      getTime(&seconds, &minutes, &hours, &subSeconds, &period);

      end();
      _clockSource = source;
      // Enable RTC
      begin(period);
      // Restore config
      setTime(seconds, minutes, hours, subSeconds, period);
      setDate(weekDay, day, month, years);
      setAlarmTime(alarmHours, alarmMinutes, alarmSeconds, alarmPeriod);
      setAlarmDay(alarmDay);
      if (alarmEnabled) {
        enableAlarm(alarmMatch);
      }
    }
  }
#endif
}