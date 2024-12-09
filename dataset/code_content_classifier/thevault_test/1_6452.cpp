TrafficSource * 
Agent::addTrafficSource(TrafficSource * ts) {
  TrafficSource * run, * last;

  run = traffic_sources_;
  last = NULL;

  // Find last traffic source on list
  while (run) {
    last = run;
    run = run->next_;
  }

  // if it exists then add it to the list
  if (last) {
    last->next_ = ts;
  } else {
    traffic_sources_ = ts;
  }  
  return last;
}