string debug_options_as_text(unsigned debug_options) {
  string Result;

  if (debug_options & DEBUG_SUMMARY) {
    Result += ", SUMMARY";
  }
  if (debug_options & DEBUG_BALANCE) {
    Result += ", BALANCE";
  }
  if (debug_options & DEBUG_TIMESTEP) {
    Result += ", TIMESTEP";
  }
  if (debug_options & DEBUG_TIMING) {
    Result += ", TIMING";
  }
  if (debug_options & DEBUG_ALGORITHM) {
    Result += ", ALGORITHM";
  }
  if (debug_options & DEBUG_MEMORY) {
    Result += ", MEMORY";
  }
  if (debug_options & DEBUG_PROBLEM) {
    Result += ", PROBLEM";
  }
  if (debug_options & DEBUG_GMV_DUMP) {
    Result += ", GMV_DUMP";
  }
  if (debug_options & DEBUG_RESET_TIMING) {
    Result += ", RESET_TIMING";
  }
  // Mask out standard options and see if any extensions are active
  debug_options =
      debug_options & ~(DEBUG_SUMMARY | DEBUG_BALANCE | DEBUG_TIMESTEP | DEBUG_TIMING |
                        DEBUG_ALGORITHM | DEBUG_MEMORY | DEBUG_PROBLEM | DEBUG_RESET_TIMING);

  if (debug_options) {
    for (const auto &i : extended_debug_option) {
      if (debug_options & i.second) {
        Result += ", " + i.first;
      }
    }
  }

  return Result;
}