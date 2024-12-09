bool ValidateIndic::ConsumeGraphemeIfValid() {
  switch (codes_[codes_used_].first) {
    case CharClass::kConsonant:
      return ConsumeConsonantHeadIfValid() && ConsumeConsonantTailIfValid();
    case CharClass::kVowel:
    case CharClass::kVedicMark:
      return ConsumeVowelIfValid();
    case CharClass::kZeroWidthJoiner:
    case CharClass::kZeroWidthNonJoiner:
      // Apart from within an aksara, joiners are silently dropped.
      if (report_errors_) {
        tprintf("Dropping isolated joiner: 0x%x\n", codes_[codes_used_].second);
      }
      ++codes_used_;
      return true;
    case CharClass::kOther:
      UseMultiCode(1);
      return true;
    default:
      if (report_errors_) {
        tprintf("Invalid start of grapheme sequence:%c=0x%x\n",
                static_cast<int>(codes_[codes_used_].first),
                codes_[codes_used_].second);
      }
      return false;
  }
}