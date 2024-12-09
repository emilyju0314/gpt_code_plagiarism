void EWPolicy::detect(Packet *) {
  int alarm_b, alarm_p;

  alarm_b = alarm_p = 0;

  if (!ewP || ! cewB)
    return;
  
  alarm_b = cewB->testAlarm();
  alarm_p = ewP->testAlarm();
  

  if (alarm_p == EW_UNCHANGE || alarm_b == EW_UNCHANGE)
    return;

  // Need to get info from both parts to make a decision
  // Reset change flags
  ewP->resetChange();
  cewB->resetChange();

  change = 1;
  // keep the old value of alarm
  pre_alarm = alarm;

  // As long as alarm_b is 0, reset the alarm
  if (alarm_b == 0)
    alarm = 0;
  else if (alarm_p == 0)
    alarm = 0;
  else 
    alarm = 1;

  printf("ALARM %d %d\n", pre_alarm, alarm);
}