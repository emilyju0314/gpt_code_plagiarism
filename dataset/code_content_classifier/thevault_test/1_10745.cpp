void Plumbing::DebugWeights() {
  for (auto &i : stack_) {
    i->DebugWeights();
  }
}