bool LTRResultIterator::EquivalentToTruth(const char *str) const {
  if (!HasTruthString()) {
    return false;
  }
  ASSERT_HOST(it_->word()->uch_set != nullptr);
  WERD_CHOICE str_wd(str, *(it_->word()->uch_set));
  return it_->word()->blamer_bundle->ChoiceIsCorrect(&str_wd);
}