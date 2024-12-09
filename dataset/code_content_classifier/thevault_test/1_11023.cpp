bool LTRResultIterator::WordIsFromDictionary() const {
  if (it_->word() == nullptr) {
    return false; // Already at the end!
  }
  int permuter = it_->word()->best_choice->permuter();
  return permuter == SYSTEM_DAWG_PERM || permuter == FREQ_DAWG_PERM || permuter == USER_DAWG_PERM;
}