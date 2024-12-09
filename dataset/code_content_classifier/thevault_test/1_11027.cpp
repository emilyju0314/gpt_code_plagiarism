bool LTRResultIterator::HasTruthString() const {
  if (it_->word() == nullptr) {
    return false; // Already at the end!
  }
  if (it_->word()->blamer_bundle == nullptr || it_->word()->blamer_bundle->NoTruth()) {
    return false; // no truth information for this word
  }
  return true;
}