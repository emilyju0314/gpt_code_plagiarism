int ResultIterator::BlanksBeforeWord() const {
  if (CurrentParagraphIsLtr()) {
    return LTRResultIterator::BlanksBeforeWord();
  }
  return IsAtBeginningOf(RIL_TEXTLINE) ? 0 : 1;
}