bool TimeCommander::countTo(short int timerID, unsigned int seconds, bool reset)
{
  this->keepTime();

  // max seconds 65534
  if (seconds >= 65535) {
    seconds = 65534;
  }

  // required time reached?
  if (timers[timerID] >= seconds) {
    if (reset) {
      // we want to trigger the event (return true) and start over
      timers[timerID] = 0;
      return true;
      
    } else {
      // time reached, decide if this was already triggered
      if (timers[timerID] == 65535) {
        // was already triggered
        return false;
      } else {
        // set a triggered flag and return true
        timers[timerID] = 65535;
        return true;
      }
      
    }

  } else {
    // time not reached
    return false;
  }

}