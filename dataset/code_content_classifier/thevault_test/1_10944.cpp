void Series::SplitAt(unsigned last_start, Series **start, Series **end) {
  *start = nullptr;
  *end = nullptr;
  if (last_start >= stack_.size()) {
    tprintf("Invalid split index %u must be in range [0,%zu]!\n", last_start, stack_.size() - 1);
    return;
  }
  auto *master_series = new Series("MasterSeries");
  auto *boosted_series = new Series("BoostedSeries");
  for (unsigned s = 0; s <= last_start; ++s) {
    if (s + 1 == stack_.size() && stack_[s]->type() == NT_SOFTMAX) {
      // Change the softmax to a tanh.
      auto *fc = static_cast<FullyConnected *>(stack_[s]);
      fc->ChangeType(NT_TANH);
    }
    master_series->AddToStack(stack_[s]);
    stack_[s] = nullptr;
  }
  for (unsigned s = last_start + 1; s < stack_.size(); ++s) {
    boosted_series->AddToStack(stack_[s]);
    stack_[s] = nullptr;
  }
  *start = master_series;
  *end = boosted_series;
  delete this;
}