Timing_Diagnostics::Vec_Keys Timing_Diagnostics::timer_keys() {
  Vec_Keys keys(timers.size()); // keys
  auto v = keys.begin();        // iterators

  // add keys to the vector
  for (auto m = timers.begin(); m != timers.end(); m++, v++) {
    Check(v != keys.end());
    *v = m->first;
  }

  // return the vector
  return keys;
}