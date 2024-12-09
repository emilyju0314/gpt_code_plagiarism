bool Series::SetupNeedsBackprop(bool needs_backprop) {
  needs_to_backprop_ = needs_backprop;
  for (auto &i : stack_) {
    needs_backprop = i->SetupNeedsBackprop(needs_backprop);
  }
  return needs_backprop;
}