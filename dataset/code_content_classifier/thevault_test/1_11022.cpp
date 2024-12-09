StrongScriptDirection LTRResultIterator::WordDirection() const {
  if (it_->word() == nullptr) {
    return DIR_NEUTRAL;
  }
  bool has_rtl = it_->word()->AnyRtlCharsInWord();
  bool has_ltr = it_->word()->AnyLtrCharsInWord();
  if (has_rtl && !has_ltr) {
    return DIR_RIGHT_TO_LEFT;
  }
  if (has_ltr && !has_rtl) {
    return DIR_LEFT_TO_RIGHT;
  }
  if (!has_ltr && !has_rtl) {
    return DIR_NEUTRAL;
  }
  return DIR_MIX;
}