std::vector<std::vector<std::pair<const char *, float>>> *ChoiceIterator::Timesteps() const {
  unsigned offset = *tstep_index_ + blanks_before_word_;
  if (offset >= word_res_->segmented_timesteps.size() || !oemLSTM_) {
    return nullptr;
  }
  return &word_res_->segmented_timesteps[offset];
}