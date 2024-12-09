bool ValidateIndic::ConsumeViramaIfValid(IndicPair joiner, bool post_matra) {
  const unsigned num_codes = codes_.size();
  if (joiner.first == CharClass::kOther) {
    CodeOnlyToOutput();
    if (codes_used_ < num_codes && codes_[codes_used_].second == kZeroWidthJoiner) {
      // Post-matra viramas must be explicit, so no joiners allowed here.
      if (post_matra) {
        if (report_errors_) {
          tprintf("ZWJ after a post-matra virama!!\n");
        }
        return false;
      }
      if (codes_used_ + 1 < num_codes && codes_[codes_used_ - 2].second != kRayana &&
          (codes_[codes_used_ + 1].second == kZeroWidthNonJoiner ||
           codes_[codes_used_ + 1].second == kYayana ||
           codes_[codes_used_ + 1].second == kRayana)) {
        // This combination will be picked up later.
        ASSERT_HOST(!CodeOnlyToOutput());
      } else {
        // Half-form with optional Nukta.
        unsigned len = output_.size() + 1 - output_used_;
        if (UseMultiCode(len)) {
          return true;
        }
      }
      if (codes_used_ < num_codes && codes_[codes_used_].second == kZeroWidthNonJoiner) {
        if (output_used_ == output_.size() || output_[output_used_] != kRayana) {
          if (report_errors_) {
            tprintf("Virama ZWJ ZWNJ in non-Sinhala: base=0x%x!\n", static_cast<int>(script_));
          }
          return false;
        }
        // Special Sinhala case of Stand-alone Repaya. ['RA' H Z z]
        if (UseMultiCode(4)) {
          return true;
        }
      }
    } else if (codes_used_ == num_codes || codes_[codes_used_].first != CharClass::kConsonant ||
               post_matra) {
      if (codes_used_ == num_codes || codes_[codes_used_].second != kZeroWidthNonJoiner) {
        // It is valid to have an unterminated virama at the end of a word, but
        // for consistency, we will always add ZWNJ if not present.
        output_.push_back(kZeroWidthNonJoiner);
      } else {
        CodeOnlyToOutput();
      }
      // Explicit virama [H z]
      MultiCodePart(2);
    }
  } else {
    // Pre-virama joiner [{Z|z} H] requests specific conjunct.
    if (UseMultiCode(2)) {
      if (report_errors_) {
        tprintf("Invalid pre-virama joiner with no 2nd consonant!!\n");
      }
      return false;
    }
    if (codes_[codes_used_].second == kZeroWidthJoiner ||
        codes_[codes_used_].second == kZeroWidthNonJoiner) {
      if (report_errors_) {
        tprintf("JHJ!!: 0x%x 0x%x 0x%x\n", joiner.second, output_.back(),
                codes_[codes_used_].second);
      }
      return false;
    }
  }
  // It is good so far as it goes.
  return true;
}