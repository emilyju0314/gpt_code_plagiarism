int LTRResultIterator::BlanksBeforeWord() const {
  if (it_->word() == nullptr) {
    return 1;
  }
  return it_->word()->word->space();
}