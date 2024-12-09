bool Plumbing::SetupNeedsBackprop(bool needs_backprop) {
  if (IsTraining()) {
    needs_to_backprop_ = needs_backprop;
    bool retval = needs_backprop;
    for (auto &i : stack_) {
      if (i->SetupNeedsBackprop(needs_backprop)) {
        retval = true;
      }
    }
    return retval;
  }
  // Frozen networks don't do backprop.
  needs_to_backprop_ = false;
  return false;
}