void Timing_Diagnostics::delete_timers() {
  // null map
  std::map<std::string, double> null;

  // swap it with timers
  timers.swap(null);
  Ensure(timers.empty());
}