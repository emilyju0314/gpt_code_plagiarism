void TimeCommander::keepTime()
{
  unsigned timeDiff = (millis() - lastTime);
  int timersLength = (sizeof(timers)/sizeof(*timers));
  int n = 0;

  // increment each timer 1 second N times
  while(timeDiff>=1000) {
    // increment each timer one second (be aware, they need to be consumed to not rollover)
    while(n<timersLength) {
      // timers roll over at 65534, because 65535 is a reached flag
      // do nothing if is 65535 (halt)
      if (timers[n] < 65534) {
        timers[n]++;
      } else if (timers[n] == 65534) {
        timers[n] = 0;
      }
      n++;
    }
    timeDiff = timeDiff - 1000;
  }

  // track time since last update
  lastTime = millis() - timeDiff;

}