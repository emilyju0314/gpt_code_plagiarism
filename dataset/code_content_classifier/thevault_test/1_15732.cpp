static SigactionMap SetSignalHandlers(const SigactionMap &signal_handlers) {
  SigactionMap old_signal_handlers;
  SigactionMap::const_iterator i     = signal_handlers.begin();
  SigactionMap::const_iterator iend  = signal_handlers.end();
  for (; i != iend; ++i) {
    struct sigaction old_signal_handler;
    if (sigaction(i->first, &i->second, &old_signal_handler) != 0) {
      abort();
    }
    old_signal_handlers[i->first] = old_signal_handler;
  }

  return old_signal_handlers;
}