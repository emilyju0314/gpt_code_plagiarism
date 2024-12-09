bool LTRResultIterator::WordIsNumeric() const {
  if (it_->word() == nullptr) {
    return false; // Already at the end!
  }
  int permuter = it_->word()->best_choice->permuter();
  return permuter == NUMBER_PERM;
}