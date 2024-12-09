void EWdetectorB::detect() {
  // When ALARM:
  //  detect if it is the time to release the alarm
  // When NO ALARM:
  //  detect if it is the time to trigger the alarm
  if (alarm) {
    // Determine if an alarm should be released
    if (cur_rate > avg_rate * (1 + EW_RELEASE_RANGE)) {
      // reset alarm
      resetAlarm();
    } 
  } else {
    // Determine if an alarm should be triggered
    //   need to be conservative!
    if (cur_rate < avg_rate * (1 - EW_DETECT_RANGE)) {
      setAlarm();
      
      // Initial drop_p to the MAX value whenever alarm triggered
      if (drop_p < EW_MAX_DROP_P)
	drop_p = EW_MAX_DROP_P;
    } else {
    }
  }
  
  // Determine the dropping probability
  //computeDropP();
}