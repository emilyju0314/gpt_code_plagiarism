bool ValidateIndic::ConsumeConsonantTailIfValid() {
  if (codes_used_ == codes_.size()) {
    return true;
  }
  // No virama: Finish the grapheme.
  // Are multiple matras allowed?
  if (codes_[codes_used_].first == CharClass::kMatra) {
    if (UseMultiCode(1)) {
      return true;
    }
    if (codes_[codes_used_].first == CharClass::kMatraPiece) {
      if (UseMultiCode(1)) {
        return true;
      }
    }
  }
  while (codes_[codes_used_].first == CharClass::kVowelModifier) {
    if (UseMultiCode(1)) {
      return true;
    }
    // Only Malayalam allows only repeated 0xd02.
    if (script_ != ViramaScript::kMalayalam || output_.back() != 0xd02) {
      break;
    }
  }
  while (codes_[codes_used_].first == CharClass::kVedicMark) {
    if (UseMultiCode(1)) {
      return true;
    }
  }
  if (codes_[codes_used_].first == CharClass::kVirama) {
    if (!ConsumeViramaIfValid(IndicPair(CharClass::kOther, 0), true)) {
      return false;
    }
  }
  // What we have consumed so far is a valid consonant cluster.
  if (output_used_ < output_.size()) {
    MultiCodePart(1);
  }

  return true;
}