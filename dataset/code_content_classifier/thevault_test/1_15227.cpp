void STM32RTC::syncAlarmTime(void)
{
  if (_configured) {
    hourAM_PM_t p = HOUR_AM;
    uint8_t match;
    RTC_GetAlarm(&_alarmDay, &_alarmHours, &_alarmMinutes, &_alarmSeconds,
                 &_alarmSubSeconds, &p, &match);
    _alarmPeriod = (p == HOUR_AM) ? AM : PM;
    switch (static_cast<Alarm_Match>(match)) {
      case MATCH_OFF:
      case MATCH_YYMMDDHHMMSS://kept for compatibility
      case MATCH_MMDDHHMMSS:  //kept for compatibility
      case MATCH_DHHMMSS:
      case MATCH_HHMMSS:
      case MATCH_MMSS:
      case MATCH_SS:
        _alarmMatch = static_cast<Alarm_Match>(match);
        break;
      default:
        _alarmMatch = MATCH_OFF;
        break;
    }
  }
}