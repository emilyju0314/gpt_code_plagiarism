void STM32RTC::setAlarmEpoch(uint32_t ts, Alarm_Match match, uint32_t subSeconds)
{
  if (_configured) {
    if (ts < EPOCH_TIME_OFF) {
      ts = EPOCH_TIME_OFF;
    }

    time_t t = ts;
    struct tm *tmp = gmtime(&t);

    setAlarmDay(tmp->tm_mday);
    setAlarmHours(tmp->tm_hour);
    setAlarmMinutes(tmp->tm_min);
    setAlarmSeconds(tmp->tm_sec);
    setAlarmSubSeconds(subSeconds);
    enableAlarm(match);
  }
}