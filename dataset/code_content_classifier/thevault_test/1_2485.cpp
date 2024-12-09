void Timing_Diagnostics::reset_timers() {
  // reset each timer
  for (auto &m : timers)
    m.second = 0.0;
}