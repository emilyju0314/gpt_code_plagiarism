float *Plumbing::LayerLearningRatePtr(const char *id) {
  char *next_id;
  int index = strtol(id, &next_id, 10);
  if (index < 0 || static_cast<unsigned>(index) >= stack_.size()) {
    return nullptr;
  }
  if (stack_[index]->IsPlumbingType()) {
    auto *plumbing = static_cast<Plumbing *>(stack_[index]);
    ASSERT_HOST(*next_id == ':');
    return plumbing->LayerLearningRatePtr(next_id + 1);
  }
  if (static_cast<unsigned>(index) >= learning_rates_.size()) {
    return nullptr;
  }
  return &learning_rates_[index];
}