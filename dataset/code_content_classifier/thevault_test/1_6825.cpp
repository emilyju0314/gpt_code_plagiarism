int EWdetector::testAlarm() {
  if (!change)
    return(EW_UNCHANGE);
  else 
    return(alarm);
}