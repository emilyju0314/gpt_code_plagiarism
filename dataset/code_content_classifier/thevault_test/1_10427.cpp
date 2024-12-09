bool ValidateIndic::ConsumeVowelIfValid() {
  if (UseMultiCode(1)) {
    return true;
  }
  while (codes_[codes_used_].first == CharClass::kVowelModifier) {
    if (UseMultiCode(1)) {
      return true;
    }
    // Only Malayalam allows repeated modifiers?
    if (script_ != ViramaScript::kMalayalam) {
      break;
    }
  }
  while (codes_[codes_used_].first == CharClass::kVedicMark) {
    if (UseMultiCode(1)) {
      return true;
    }
  }
  // What we have consumed so far is a valid vowel cluster.
  return true;
}